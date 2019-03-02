"""
Helper module that will enable lazy imports of Cocoa wrapper items.

This should improve startup times and memory usage, at the cost
of not being able to use 'from Cocoa import *'
"""
__all__ = ('ObjCLazyModule',)

import sys
import re
import struct

from objc import lookUpClass, getClassList, nosuchclass_error, loadBundle
import objc
import warnings
ModuleType = type(sys)

_name_re = re.compile('^[A-Za-z_][A-Za-z_0-9]*$')

def _check_deprecated(name, deprecation_version):
    if objc.options.deprecation_warnings and objc.options.deprecation_warnings >= deprecation_version:
        warnings.warn("%r is deprecated in macOS %d.%d"%(name, deprecation_version / 100, deprecation_version % 100),
                objc.ApiDeprecationWarning, stacklevel=2)

def _loadBundle(frameworkName, frameworkIdentifier, frameworkPath):
    if frameworkIdentifier is None:
        bundle = loadBundle(
            frameworkName,
            {},
            bundle_path=frameworkPath,
            scan_classes=False)

    else:
        try:
            bundle = loadBundle(
                frameworkName,
                {},
                bundle_identifier=frameworkIdentifier,
                scan_classes=False)

        except ImportError:
            bundle = loadBundle(
                frameworkName,
                {},
                bundle_path=frameworkPath,
                scan_classes=False)

    return bundle

class GetAttrMap (object):
    __slots__ = ('_container',)
    def __init__(self, container):
        self._container = container

    def __getitem__(self, key):
        try:
            return getattr(self._container, key)
        except AttributeError:
            raise KeyError(key)

class ObjCLazyModule (ModuleType):
    """
    A module type that loads PyObjC metadata lazily, that is constants, global
    variables and functions are created from the metadata as needed. This
    reduces the resource usage of PyObjC (both in time and memory), as most
    symbols exported by frameworks are never used in programs.

    The loading code assumes that the metadata dictionary is valid, and invalid
    metadata may cause exceptions other than AttributeError when accessing module
    attributes.
    """

    # Define slots for all attributes, that way they don't end up it __dict__.
    __slots__ = (
                '_ObjCLazyModule__bundle', '_ObjCLazyModule__enummap', '_ObjCLazyModule__funcmap',
                '_ObjCLazyModule__parents', '_ObjCLazyModule__varmap', '_ObjCLazyModule__inlinelist',
                '_ObjCLazyModule__aliases', '_ObjCLazyModule__informal_protocols',
            )

    def __init__(self, name, frameworkIdentifier, frameworkPath, metadict=None, inline_list=None, initialdict=None, parents=()):
        super(ObjCLazyModule, self).__init__(name)

        if frameworkIdentifier is not None or frameworkPath is not None:
            self.__bundle = self.__dict__['__bundle__'] = _loadBundle(name, frameworkIdentifier, frameworkPath)
        else:
            self.__bundle = None

        pfx = name + '.'
        for nm in list(sys.modules.keys()):
            # See issue #95: there can be objects that aren't strings in
            # sys.modules.
            if hasattr(nm, 'startswith') and nm.startswith(pfx):
                rest = nm[len(pfx):]
                if '.' in rest: continue
                if sys.modules[nm] is not None:
                    self.__dict__[rest] = sys.modules[nm]

        if metadict is None:
            metadict = {}

        if initialdict:
            self.__dict__.update(initialdict)
        self.__dict__.update(metadict.get('misc', {}))
        self.__parents = parents
        self.__varmap = metadict.get('constants')
        self.__varmap_deprecated = metadict.get('deprecated_constants', {})
        self.__varmap_dct = metadict.get('constants_dict', {})
        self.__enummap = metadict.get('enums')
        self.__enum_deprecated = metadict.get('deprecated_enums', {})
        self.__funcmap = metadict.get('functions')
        self.__aliases = metadict.get('aliases')
        self.__aliases_deprecated = metadict.get('deprecated_aliases', {})
        self.__inlinelist = inline_list

        # informal protocols are not exposed, but added here
        # for completeness sake.
        self.__informal_protocols = metadict.get('protocols')

        self.__expressions = metadict.get('expressions')
        self.__expressions_mapping = GetAttrMap(self)

        self.__load_cftypes(metadict.get('cftypes'))


    def __dir__(self):
        return self.__all__

    def __getattr__(self, name):
        if name == "__all__":
            # Load everything immediately
            value = self.__calc_all()
            self.__dict__[name] = value
            return value

        # First try parent module, as if we had done
        # 'from parents import *'
        for p in self.__parents:
            try:
                value = getattr(p, name)
            except AttributeError:
                pass

            else:
                self.__dict__[name] = value
                if '__all__' in self.__dict__:
                    del self.__dict__['__all__']
                return value

        if not _name_re.match(name):
            # Name is not a valid identifier and cannot
            # match.
            raise AttributeError(name)

        # Check if the name is a constant from
        # the metadata files
        try:
            value = self.__get_constant(name)
        except AttributeError:
            pass
        else:
            self.__dict__[name] = value
            if '__all__' in self.__dict__:
                del self.__dict__['__all__']
            return value

        # Then check if the name is class
        try:
            value = lookUpClass(name)
        except nosuchclass_error:
            pass

        else:
            self.__dict__[name] = value
            if '__all__' in self.__dict__:
                del self.__dict__['__all__']
            return value

        # Finally give up and raise AttributeError
        raise AttributeError(name)

    def __calc_all(self):

        # Ensure that all dynamic entries get loaded
        if self.__varmap_dct:
            dct = {}
            objc.loadBundleVariables(self.__bundle, dct,
                    [ (nm, self.__varmap_dct[nm].encode('ascii'))
                        for nm in self.__varmap_dct if not self.__varmap_dct[nm].startswith('=')])
            for nm in dct:
                if nm not in self.__dict__:
                    self.__dict__[nm] = dct[nm]

            for nm, tp in self.__varmap_dct.items():
                if tp.startswith('=='):
                    try:
                        self.__dict__[nm] = objc._loadConstant(nm, tp[2:], 2)
                    except AttributeError:
                        raise
                        pass
                elif tp.startswith('='):
                    try:
                        self.__dict__[nm] = objc._loadConstant(nm, tp[1:], 1)
                    except AttributeError:
                        pass


            self.__varmap_dct = {}

        if self.__varmap:
            varmap = []
            specials = []
            for nm, tp in re.findall(r"\$([A-Z0-9a-z_]*)(@[^$]*)?(?=\$)", self.__varmap):
                if tp and tp.startswith('@='):
                    specials.append((nm, tp[2:]))
                else:
                    varmap.append((nm, b'@' if not tp else tp[1:].encode('ascii')))

            dct = {}
            objc.loadBundleVariables(self.__bundle, dct, varmap)

            for nm in dct:
                if nm not in self.__dict__:
                    self.__dict__[nm] = dct[nm]

            for nm, tp in specials:
                try:
                    if tp.startswith('='):
                        self.__dict__[nm] = objc._loadConstant(nm, tp[1:], 2)
                    else:
                        self.__dict__[nm] = objc._loadConstant(nm, tp, 1)
                except AttributeError:
                    pass

            self.__varmap = ""

        if self.__enummap:
            for nm, val in re.findall(r"\$([A-Z0-9a-z_]*)@([^$]*)(?=\$)", self.__enummap):
                if nm not in self.__dict__:
                    self.__dict__[nm] = self.__prs_enum(val)

            self.__enummap = ""

        if self.__funcmap:
            func_list = []
            for nm in self.__funcmap:
                if nm not in self.__dict__:
                    func_list.append((nm,) + self.__funcmap[nm])

            dct = {}
            objc.loadBundleFunctions(self.__bundle, dct, func_list)
            for nm in dct:
                if nm not in self.__dict__:
                    self.__dict__[nm] = dct[nm]

            if self.__inlinelist is not None:
                dct = {}
                objc.loadFunctionList(
                    self.__inlinelist, dct, func_list, skip_undefined=True)
                for nm in dct:
                    if nm not in self.__dict__:
                        self.__dict__[nm] = dct[nm]

            self.__funcmap = {}

        if self.__expressions:
            for nm in list(self.__expressions):
                try:
                    getattr(self, nm)
                except AttributeError:
                    pass

        if self.__aliases:
            for nm in list(self.__aliases):
                try:
                    getattr(self, nm)
                except AttributeError:
                    pass

        all_names = set()

        # Add all names that are already in our __dict__
        all_names.update(self.__dict__)

        # Merge __all__of parents ('from parent import *')
        for p in self.__parents:
            try:
                all_names.update(p.__all__)
            except AttributeError:
                all_names.update(dir(p))

        # Add all class names
        all_names.update(cls.__name__ for cls in getClassList())

        return [ v for v in all_names if not v.startswith('_') ]

    def __prs_enum(self, val):
        if val.startswith("'"):
            if isinstance(val, bytes): # pragma: no 3.x cover
                val, = struct.unpack('>l', val[1:-1])
            else: # pragma: no 2.x cover
                val, = struct.unpack('>l', val[1:-1].encode('latin1'))

        elif '.' in val or 'e' in val:
            val = float(val)

        else:
            val = int(val)

        return val

    def __get_constant(self, name):
        if self.__varmap_dct:
            if name in self.__varmap_dct:
                tp = self.__varmap_dct.pop(name)
                if tp.startswith('=='):
                    tp = tp[2:]
                    magic = 2
                elif tp.startswith('='):
                    tp = tp[1:]
                    magic = 1
                else:
                    magic = 0
                result = objc._loadConstant(name, tp, magic)
                if name in self.__varmap_deprecated:
                    _check_deprecated(name, self.__varmap_deprecated[name])

                return result

        if self.__varmap:
            m = re.search(r"\$%s(@[^$]*)?\$"%(name,), self.__varmap)
            if m is not None:
                tp = m.group(1)
                if not tp:
                    tp = '@'
                else:
                    tp = tp[1:]

                d = {}
                if tp.startswith('=='):
                    magic = 2
                    tp = tp[2:]
                elif tp.startswith('='):
                    tp = tp[1:]
                    magic = 1
                else:
                    magic = 0

                result =  objc._loadConstant(name, tp, magic)

                if name in self.__varmap_deprecated:
                    _check_deprecated(name, self.__varmap_deprecated[name])

                return result

        if self.__enummap:
            m = re.search(r"\$%s@([^$]*)\$"%(name,), self.__enummap)
            if m is not None:
                result =  self.__prs_enum(m.group(1))
                if name in self.__enum_deprecated:
                    _check_deprecated(name, self.__enum_deprecated[name])
                return result

        if self.__funcmap:
            if name in self.__funcmap:
                # NOTE: Remove 'name' from funcmap because
                #       it won't be needed anymore (either the
                #       function doesn't exist, or it is loaded)
                #       Should use slightly less memory.
                info = self.__funcmap.pop(name)

                func_list = [ (name,) + info ]

                d = {}
                objc.loadBundleFunctions(self.__bundle, d, func_list)
                if name in d:
                    return d[name]

                if self.__inlinelist is not None:
                    objc.loadFunctionList(
                        self.__inlinelist, d, func_list, skip_undefined=True)
                    if name in d:
                        return d[name]

        if self.__expressions:
            if name in self.__expressions:
                # NOTE: 'name' is popped because it is no longer needed
                #       in the metadata and popping should slightly reduce
                #       memory usage.
                info = self.__expressions.pop(name)
                try:
                    return eval(info, {}, self.__expressions_mapping)
                except: # Ignore all errors in evaluation the expression.
                    pass

        if self.__aliases:
            if name in self.__aliases:
                alias = self.__aliases.pop(name)
                if alias == 'ULONG_MAX':
                    result = (sys.maxsize * 2) + 1
                elif alias == 'LONG_MAX':
                    result = sys.maxsize
                elif alias == 'LONG_MIN':
                    result = -sys.maxsize-1
                elif alias == 'DBL_MAX':
                    result = sys.float_info.max
                elif alias == 'DBL_MIN':
                    result = sys.float_info.min
                elif alias == 'FLT_MAX':
                    result = objc._FLT_MAX
                elif alias == 'FLT_MIN':
                    result = objc._FLT_MIN
                else:
                    result = getattr(self, alias)

                if name in self.__aliases_deprecated:
                    _check_deprecated(name, self.__aliases_deprecated[name])
                return result

        raise AttributeError(name)

    def __load_cftypes(self, cftypes):
        if not cftypes: return

        for name, type, gettypeid_func, tollfree in cftypes:
            if tollfree:
                for nm in tollfree.split(','):  # pragma: no branch
                    try:
                        objc.lookUpClass(nm)
                    except objc.error:
                        pass
                    else:
                        tollfree = nm
                        break
                try:
                    v = objc.registerCFSignature(name, type, None, tollfree)
                    self.__dict__[name] = v
                    continue
                except objc.nosuchclass_error:
                    pass

            if gettypeid_func is None:
                func = None

            else:
                try:
                    func = getattr(self, gettypeid_func)
                except AttributeError:
                    func = None

            if func is None:
                # GetTypeID function not found, this is either
                # a CFType that isn't present on the current
                # platform, or a CFType without a public GetTypeID
                # function. Proxy using the generic CFType
                if tollfree is None:
                    v = objc.registerCFSignature(name, type, None, 'NSCFType')
                    self.__dict__[name] = v

                continue

            v = objc.registerCFSignature(name, type, func())
            self.__dict__[name] = v
