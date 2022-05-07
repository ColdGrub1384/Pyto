import traceback
import json
import ctypes
import os
import random
import console
import weakref
from extensionsimporter import BitcodeValue

offer_suggestion_prototype = ctypes.PYFUNCTYPE(    
    ctypes.c_char_p,                
    ctypes.py_object
)
offer_suggestion = offer_suggestion_prototype(('_offer_suggestions', ctypes.CDLL(None)))


class Breakpoint(BaseException):
    pass


class NamespaceHolder:

    def __init__(self, local, _global):
        self.local = local
        self._global = _global


def get_json(tb, exc, text, remove, offset=0, end_offset=0, _globals=None):
        
    if isinstance(tb, list): # tb can be a traceback or a list of frames
        msg = ""
    else:
        tb_exc = traceback.TracebackException(exc.__class__, exc, tb)
        msg = " ".join(tb_exc.format_exception_only())
    
    try:
        msg = exc.msg
    except AttributeError:
        msg = ": ".join(msg.split(": ")[1:]).split("\n")
        try:
            del msg[1]
        except IndexError:
            pass
        msg = "\n".join(msg)
    
    name = None
    suggestion = None
    try:
        if isinstance(exc, AttributeError) or isinstance(exc, NameError):
            name = exc.name
            suggestion = offer_suggestion(exc)
            if suggestion is not None:
                suggestion = suggestion.decode("utf-8")
    except AttributeError:
        pass

    traceback_json = {
        "exc_type": exc.__class__.__name__,
        "msg": msg,
        "as_text": text,
        "suggestion": suggestion,
        "name": name,
        "offset": offset,
        "end_offset": end_offset
    }
    
    stack_json = []
    
    if isinstance(tb, list):
        stack = tb
    else:
        stack = traceback.extract_tb(tb)

    for _ in range(remove):
        del stack[0]

    try:
        frame_stack = [exc.__traceback__]
        while frame_stack[-1].tb_next is not None:
            frame_stack.append(frame_stack[-1].tb_next)

        frame_stack.reverse()
    except AttributeError:
        frame_stack = None


    try:
        def get_filename():
            if isinstance(tb, list):
                return os.path.abspath(stack[0].f_code.co_filename)
            else:
                return stack[0].filename
        

        while len(stack) > 0 and (get_filename().endswith("/Lib/console.py") or get_filename().startswith("<frozen importlib")):
            del stack[0]
            del frame_stack[0]
    except IndexError:
        pass
        
    if isinstance(exc, SyntaxError):
        if len(stack) == 0 or (stack[-1].filename != exc.filename or stack[-1].lineno != exc.lineno):
            frame = traceback.FrameSummary(exc.filename, exc.lineno, None, line=exc.text)
            stack.append(frame)

    stack.reverse()
    i = 0

    if frame_stack is not None:
        _id = ''.join(random.choice([chr(i) for i in range(ord('a'),ord('z'))]) for _ in range(10))
        holders = []
        strong = []
        for _frame in frame_stack:
            _frame = _frame.tb_frame
            holder = NamespaceHolder(_frame.f_locals, _frame.f_globals)
            strong.append(holder)
            holders.append(weakref.ref(holder))

        if _globals is not None:
            _globals["__namespaces__"] = strong

        console.namespaces[_id] = holders
    else:
        _id = None

    for frame in stack:

        if isinstance(tb, list):
            
            path = os.path.abspath(frame.f_code.co_filename)
            line = ""
            try:
                with open(path, "r", encoding="utf-8") as f:
                    line = f.read().split("\n")[frame.f_lineno-1]
            except (FileNotFoundError, IndexError):
                pass
            
            while line.startswith(" ") or line.startswith("\t"):
                line = line[1:]

            stack_json.append({
                "file_path": path,
                "lineno": frame.f_lineno,
                "line": line,
                "name": frame.f_code.co_name,
                "index": i,
                "_id": None,
            })
        else:
            stack_json.append({
                "file_path": frame.filename,
                "lineno": frame.lineno,
                "line": frame.line,
                "name": frame.name,
                "index": i,
                "_id": _id
            })
        i += 1
    
    traceback_json["stack"] = stack_json
    
    data = json.dumps(traceback_json, indent=True)
    return data
