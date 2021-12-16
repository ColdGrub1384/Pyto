import json

with open("items.json", "r") as f:
    window = json.loads(f.read())

keywords = """
False await else import pass None break	except in raise True class finally is return and continue for lambda try as def from nonlocal while assert del global not with async elif if or yield
""".split(" ")


def make_class(object, name, lvl=1):
    code = ("    "*(lvl-1))+"class "+name+":\n"
    
    called = False
    for key in object.keys():
        called = True
        
        if isinstance(object[key], dict) and lvl < 3:
            code += make_class(object[key], key, lvl+1)+"\n"
        else:
            code += ("    "*lvl)+key+" = None\n"
    
    if not called:
        code = ("    "*(lvl-1))+name+" = None\n"
    
    return code

code = make_class(window, "window")

with open("../_window.py", "w") as f:
    f.write(code)