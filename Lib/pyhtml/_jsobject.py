import pyto_ui as ui
import base64
import random
import json
import weakref

def _random_string(length):
    s = ''.join(random.choice([chr(i) for i in range(ord('a'),ord('z'))]) for _ in range(10))
    return s

_objects = {}

class JSObject:
    
    def __new__(cls, id: str, web_view: ui.WebView):
        code = f"_object_holder['{id}']"

        if id != "window":
        
            info = json.loads(base64.b64decode(id[7:]))
            type = info[0]
            is_array = bool(int(info[1]))
            
            if is_array:
                try:
                    return json.loads(info[3])
                except (ui.WebView.JavaScriptException, IndexError):
                    pass
                    
            if type == "string":
                return info[2]
            elif type == "number":
                return float(info[2])
            elif type == "boolean":
                value = info[2]
                if value == "1" or value == "true" or value == 1:
                    return True
                else:
                    return False
            
            try:
                instance = _objects[id]()
                return instance
            except KeyError:
                pass
        
        obj = super().__new__(cls)
        obj.__init__(id, web_view)
        _objects[id] = weakref.ref(obj)
        return obj
    
    def __init__(self, id: str, web_view: ui.WebView):
        self._id = id
        self._web_view = web_view
    
    _garbage_collector = []

    def __del__(self):
        self.__class__._garbage_collector.append(self._id)

        del _objects[self._id]

        if len(self.__class__._garbage_collector) < 20:
            return

        self._web_view.evaluate_js(f"_free({repr(self.__class__._garbage_collector)})")
        self.__class__._garbage_collector = []
    
    def _convert_object(self, object: object):
        if isinstance(object, str):
            base64_bytes = base64.b64encode(object.encode("utf-8"))
            base64_string = base64_bytes.decode("ascii")
            return f"decodeURIComponent(escape(window.atob('{base64_string}')))"
        elif isinstance(object, bool):
            if object:
                return "true"
            else:
                return "false"
        elif isinstance(object, int) or isinstance(object, float):
            return str(object)
        elif isinstance(object, list):
            _list = []
            for item in object:
                _list.append(self._convert_object(item))
            return str(_list)
        elif isinstance(object, dict):
            _dict = {}
            for key, value in object.items():
                _dict[self._convert_object(key)] = self._convert_object(value)
            return str(_dict)
        elif object is None:
            return "null"
        elif callable(object) and not isinstance(object, self.__class__):
            id = _random_string(5)
            _function_holder[id] = object
            _function_holder._web_views[id] = self._web_view
            code = f"""
            var args = [];
            for (const arg of arguments) { "{" }
                args.push("'"+_return_object(arg)+"'");
            { "}" }
            _run("_function_holder.call('{id}', ["+args.join(",")+"])");
            """
            function = f"Function({self._convert_object(code)})"
            return function
        else:
            raise TypeError("Cannot bridge value")
    
    def __repr__(self):
        return self._web_view.evaluate_js(f"""
        var object = _object_holder['{self._id}'];
        if (object === undefined) {
            '"undefined";'
        } else {
            'object.toString();'
        }
        """)
    
    def __getitem__(self, object):
        id = self._web_view.evaluate_js(f"_return_object(_object_holder['{self._id}'][{self._convert_object(object)}])")
        return self.__class__(id, self._web_view)

    def __setitem__(self, name, value):
        self._web_view.evaluate_js(f"_object_holder['{self._id}']['{name}'] = {self._convert_object(value)}; true")

    def __getattribute__(self, name):
        names = ["_id", "_web_view", "_convert_object", "_attributes"]
        if name in names or name in dir(object()):
            return super().__getattribute__(name)  
        
        id = self._web_view.evaluate_js(f"getAttribute('{self._id}', '{name}')")
        return self.__class__(id, self._web_view)
            

    def __setattr__(self, name, value):
        if name == "_id" or name == "_web_view":
            super().__setattr__(name, value)
        else:
            self._web_view.evaluate_js(f"_object_holder['{self._id}']['{name}'] = {self._convert_object(value)}; true")

    def __call__(self, *kwargs):
        args = []
        for v in kwargs:
            if isinstance(v, self.__class__):
                args.append(f"_object_holder['{v._id}']")
            else:
                args.append(self._convert_object(v))
        
        parent = f"_parents_holder['{self._id}']"
        #try:
        #    parent_code = f"_parents_holder['{self._id}']"
        #    if self._web_view.evaluate_js(f"{parent_code} !== undefined"):
        #        parent = parent_code
        #except ui.WebView.JavaScriptException:
        #    pass
        
        code = f"_object_holder['{self._id}'].apply({parent}, [{','.join(args)}])"
        id = self._web_view.evaluate_js(f"_return_object({code})")
        if id == "":
            return
        else:
            return self.__class__(id, self._web_view)
    
    def _attributes(self):
        attributes = self._web_view.evaluate_js(f"JSON.stringify(Object.keys(_object_holder['{self._id}']))")
        return json.loads(attributes)
    
    def __dir__(self):
        return super().__dir__()+_attributes