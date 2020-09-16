'''
Classes from the 'Categories' framework.
'''

try:
    from rubicon.objc import ObjCClass
except ValueError:
    def ObjCClass(name):
        return None


def _Class(name):
    try:
        return ObjCClass(name)
    except NameError:
        return None

    
CTUtilities = _Class('CTUtilities')
CTLogging = _Class('CTLogging')
CTCategory = _Class('CTCategory')
CTCategories = _Class('CTCategories')
CTError = _Class('CTError')
