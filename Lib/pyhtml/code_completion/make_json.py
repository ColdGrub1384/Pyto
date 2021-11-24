from pyhtml import window, JSObject, WebView
import pyto_ui as ui
import json
from os.path import dirname
import sys

if __name__ == "__main__":
    web_view = WebView()
    web_view.register_message_handler("webView")
    web_view.load_file(dirname(__file__)+"/page.html")
    sys.exit(0)


window.localStorage.clear()
exclude = ["_object_holder", "_parents_holder", "constructor", "prototype"]

getProperties = window.eval("""
const isGetter = (x, name) => (Object.getOwnPropertyDescriptor(x, name) || {}).get
    const deepProperties = x =>
    x && x !== Object.prototype &&
    Object.getOwnPropertyNames(x)
    .filter(name => isGetter(x, name))
    .concat(deepProperties(Object.getPrototypeOf(x)) || []);
    const distinctDeepProperties = x => Array.from(new Set(deepProperties(x)));
    
(obj) => distinctDeepProperties(obj).filter(
        name => name !== "constructor" && !~name.indexOf("__"));
""")

getAllFuncs = window.eval("""
(toCheck) => {
    const props = [];
    let obj = toCheck;
    do {
        props.push(...Object.getOwnPropertyNames(obj));
    } while (obj = Object.getPrototypeOf(obj));

    return props.sort().filter((e, i, arr) => {
        if (e != arr[i + 1] && typeof toCheck[e] == 'function') return true;
    });
}
""")

items = {}

def getitems(object, lvl=0, a=True):
    _dict = {}
    
    if repr(object) == "undefined":
        return _dict
    
    props = getProperties(object)
    
    try:
        _dict = items[",".join(props)]
        print("Recycled:", object)
        return _dict
    except KeyError:
        pass
    
    print(object)
    
    for key in props:
        value = object[key]
        if value is window or key in exclude or "-" in key:
            continue
        
        try:
            if lvl > 2:
                _dict[key] = {}
            elif isinstance(value, JSObject):
                _dict[key] = getitems(value, lvl+1)
            else:
                _dict[key] = value
        except WebView.JavaScriptException:
            pass
    
    for func in getAllFuncs(object):
        if func in exclude or "-" in func:
            continue
        
        _dict[func] = {}
            
    items[",".join(props)] = _dict
    return _dict

items = getitems(window, 0, False)
string = json.dumps(items)

f = open("pyhtml/code_completion/items.json", "w")
f.write(string)
f.close()

print("Done!")