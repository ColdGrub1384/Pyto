import traceback
import json
import ctypes

offer_suggestion_prototype = ctypes.PYFUNCTYPE(    
    ctypes.c_char_p,                
    ctypes.py_object
)
offer_suggestion = offer_suggestion_prototype(('_offer_suggestions', ctypes.CDLL(None)))

def main():
    return 0/0

def get_json(tb, exc, text, remove, offset=0, end_offset=0):
        
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
    
    stack = traceback.extract_tb(tb)

    for _ in range(remove):
        del stack[0]

    try:
        while len(stack) > 0 and stack[0].filename.endswith("/Lib/console.py") or stack[0].filename.startswith("<frozen importlib"):
            del stack[0]
    except IndexError:
        pass
        
    if isinstance(exc, SyntaxError):
        if len(stack) == 0 or (stack[-1].filename != exc.filename or stack[-1].lineno != exc.lineno):
            frame = traceback.FrameSummary(exc.filename, exc.lineno, None, line=exc.text)
            stack.append(frame)

    stack.reverse()
    i = 0
    for frame in stack:
        stack_json.append({
            "file_path": frame.filename,
            "lineno": frame.lineno,
            "line": frame.line,
            "name": frame.name,
            "index": i
        })
        i += 1
    
    traceback_json["stack"] = stack_json
    
    data = json.dumps(traceback_json, indent=True)
    return data