import os
import io
import jedi
import sys
import json
import shlex
import traceback
import threading
import shutil
import cmd
from _shell import shell
from Foundation import NSBundle
from pygments import highlight
from pygments import lexers
from pygments.formatters.terminal256 import TerminalTrueColorFormatter
from pygments.token import Keyword, Name, Comment, String, Number, Operator
from pygments.style import Style
from pyto import ConsoleViewController
from _shell.bin.which import commands
from _shell.shell import get_scripts

_completions_queue = 0

lexer = lexers.get_lexer_by_name('python')

downloadable_path = str(NSBundle.mainBundle.pathForResource("Lib/_downloadable_packages", ofType=""))

def highlightedCode(code, _theme):

    theme = json.loads(_theme)

    style = type("CodeStyle", (Style,), { "styles": {
        Comment:                'italic '+theme["comment"],
        Keyword:                'bold '+theme["keyword"],
        Name:                   theme["name"],
        Name.Function:          theme["function"],
        Name.Class:             'bold '+theme["class"],
        String:                 theme["string"],
        Number:                 theme["number"],
        Operator:               theme["number"],
    }})
    formatter = TerminalTrueColorFormatter(full=True, style=style)
    return highlight(code, lexer, formatter)


completion_objects = []

def suggestForCode(code, index, path, get_definitions=False):
    global _completions_queue

    try:
        visibles = ConsoleViewController.objcVisibles
    except AttributeError:
        visibles = []

    if not downloadable_path in sys.path:
        sys.path.append(downloadable_path)

    for console in visibles:

        try:
            try:
                if console.editorSplitViewController is None:
                    continue
            except AttributeError:
                return

            try:
                visibleEditor = console.editorSplitViewController.editor
            except AttributeError:
                visibleEditor = console.editorSplitViewController().editor

            if visibleEditor is None:
                continue

            try:
                if visibleEditor.document.fileURL.path != path:
                    continue
            except AttributeError:
                if visibleEditor.document().fileURL.path != path:
                    continue

            if code.endswith(");\n"):
                if visibleEditor is None:
                    return

                visibleEditor.completions = []
                visibleEditor.suggestions = []
                visibleEditor.docStrings = None
                return
        except Exception as e:
            #sys.__stdout__.write("Code completion:\n " + traceback.format_exc() + "\n")
            return

        try:
            script = jedi.Script(code, path=path)

            if get_definitions:
                definitions = []
                for _def in script.get_names():
                
                    if _def.type == "statement" or _def.type == "keyword":
                        continue
                
                    decl = _def.description
                    line = _def.line
                    if "=" in decl:
                        decl = decl.split("=")[0]
                    if ":" in decl:
                        decl = decl.split(":")[0]
                    
                    signatures = []
                    for signature in _def.get_signatures():
                        signatures.append(signature.to_string())
                    
                    defined_names = []
                    try:
                        for name in _def.defined_names():
                    
                            if not name.is_definition():
                                continue
                        
                            _signatures = []
                            for signature in name.get_signatures():
                                _signatures.append(signature.to_string())
                        
                            doc = name.docstring(raw=True)
                            defined_names.append([name.description, name.line if name.line is not None else 0, doc if doc is not None else "", name.name, _signatures, [], name.module_name, name.type])
                    except NotImplementedError:
                        pass
                    
                    doc = _def.docstring(raw=True)
                    arr = [decl, line, doc if doc is not None else "", _def.name, signatures, defined_names, _def.module_name, _def.type]
                    definitions.append(arr)

                visibleEditor.definitions = definitions

            suggestions = []
            completions = []

            docs = {}

            line = 1
            column = 0

            for i in range(index):
                char = code[i]
                if char == "\n":
                    line += 1
                    column = 0
                else:
                    column += 1

            signature = ""

            infer = script.infer(line, column)
            for _infer in infer:
                for __infer in _infer.get_signatures():
                    signature = __infer.to_string()
                    break
                break

            if signature == "":
                context = script.get_context(line, column)
                for _signature in context.get_signatures():
                    signature = _signature.to_string()
                    break

            types = {}
            signatures = {}


            param_suggestions = []
            param_completions = []

            fuzzy_suggestions = []
            fuzzy_completions = []

            _completions = script.complete(line, column)
            _fuzzy_completions = script.complete(line, column, fuzzy=True)

            global completion_objects
            completion_objects = _completions+_fuzzy_completions

            for completion in completion_objects:
                suggestion = completion.name

                if suggestion in suggestions or suggestion in param_suggestions or suggestion in fuzzy_suggestions:
                    continue

                complete = completion.complete
                if complete is None:
                    complete = suggestion

                if complete.startswith("."):
                    suggestion = "." + suggestion
                
                if complete.endswith("="):
                    complete = complete[:-1]

                if completion._is_fuzzy:
                    complete = "__is_fuzzy__"
                    fuzzy_suggestions.append(suggestion)
                    fuzzy_completions.append(complete)
                elif not suggestion.endswith("="):
                    suggestions.append(suggestion)
                    completions.append(complete)
                else:
                    param_suggestions.append(suggestion)
                    param_completions.append(complete)

                #docstring = completion.docstring(raw=True, fast=True)
                docstring = ""
                types[suggestion] = completion.type

                #for _signature in completion.get_signatures():
                #    if _signature.to_string() == "NoneType()":
                #        continue

                #    signatures[suggestion] = _signature.to_string()
                
                signatures[suggestion] = ""
                
                try:
                    lines = docstring.split("\n")
                    if lines[0].endswith(")") and lines[0].startswith(suggestion):
                        lines.pop(0)

                    while len(lines) > 0 and lines[0] == "":
                        lines.pop(0)
                    
                    docstring = "\n".join(lines)
                except IndexError:
                    pass

                docs[suggestion] = docstring
            
            if path.endswith(".py") and visibleEditor.text != code:
                return
            
            suggestions = param_suggestions+suggestions+fuzzy_suggestions
            completions = param_completions+completions+fuzzy_completions

            visibleEditor.lastCodeFromCompletions = code
            visibleEditor.signature = signature
            visibleEditor.suggestionsType = types
            visibleEditor.completions = completions
            visibleEditor.suggestions = suggestions
            visibleEditor.docStrings = docs
            visibleEditor.signatures = signatures

        except Exception as e:

            #sys.__stdout__.write("Code completion:\n " + traceback.format_exc() + "\n")

            if visibleEditor is None:
                return

            visibleEditor.completions = []
            visibleEditor.suggestions = []
            visibleEditor.signature = ""
            visibleEditor.docStrings = None

    if downloadable_path in sys.path:
        sys.path.remove(downloadable_path)


def suggestionsForCode(code, path=None):

    if not downloadable_path in sys.path:
        sys.path.append(downloadable_path)

    try:
        if path is None:
            script = jedi.Script(
                code, len(code.splitlines()), len(code.splitlines()[-1]) - 1
            )
        else:
            script = jedi.Script(
                code, len(code.splitlines()), len(code.splitlines()[-1]) - 1, path
            )

        suggestions = {}

        for completion in script.completions():

            if completion.complete.startswith("."):
                suggestion = "." + suggestion

            if completion.name.startswith("_"):
                continue

            suggestions[completion.name] = completion.complete

        if downloadable_path in sys.path:
            sys.path.remove(downloadable_path)

        return suggestions
    except Exception as e:
        if downloadable_path in sys.path:
            sys.path.remove(downloadable_path)

        return {}


def complete_files(arg, cwd):

    os.chdir(cwd)

    files = []

    path = arg.split("/")

    if len(path) == 1: # foo
        try:
            for file in os.listdir(cwd): # look in cwd
                if file.startswith("."):
                    continue

                files.append(file)
        except OSError:
            return ([], [])
    elif arg.endswith("/"):
        dir_path = os.path.join(*tuple(path))
        try:
            for file in os.listdir(dir_path): # look in arg

                if file.startswith("."):
                    continue

                files.append(os.path.join(dir_path, file))
        except OSError:
            return  ([], [])
    else:
        return  ([], [])
    
    def add_slashes_to_dirs(file):
        if os.path.isdir(file) or os.path.isdir(os.path.join(*tuple(path), file)):
            return file+"/"
        else:
            return file

    files = list(filter(lambda file: file.startswith(arg), files))
    completions = list(map(lambda file: file.replace(arg, "", 1), files))
    files = list(map(lambda file: os.path.basename(file), files))
    files = list(map(add_slashes_to_dirs, files))

    slashed_completions = []
    i = 0
    for file in files:
        if file.endswith("/"):
            slashed_completions.append(completions[i].replace(" ", "\\ ")+"/")
        else:
            slashed_completions.append(completions[i].replace(" ", "\\ "))
        i += 1

    return (files, slashed_completions)


def complete_shell_command(command, shell_id=None):

    if " " in command:
        # Files

        try:
            if shell_id is None or shell_id not in shell.working_directories:
                key = threading.current_thread().script_path
            else:
                key = shell_id
            cwd = shell.working_directories[key]
        except (AttributeError, KeyError):
            cwd = "/"

        args = shlex.split(command)
        if len(args) == 1:
            return complete_files("", cwd)
        else:
            return complete_files(args[-1], cwd)

    # Modules

    def filter_llvm(prog):
        return prog != "clang" and prog != "llvm-link" and prog != "lli"

    modules = list(filter(filter_llvm, list(commands.keys())))+list(get_scripts().keys())

    pyto_lib = os.path.dirname(os.path.abspath(__file__))
    shell_commands = os.path.join(pyto_lib, "_shell", "bin")
    for cmd in os.listdir(shell_commands):
        if cmd == "_link_modules.py" or cmd == "llvm-link.py" or cmd == "_system.py" or cmd == "clang.py":
            continue
        modules.append(cmd)

    user_bin = os.path.join(os.path.expanduser("~"), "Documents", "bin")
    
    try:
        modules += os.listdir(user_bin)
    except OSError:
        pass

    def filter_other_files(module):
        ext = os.path.splitext(module)[1]
        return ((ext == "" or ext == ".py" or ext == ".bc" or ext == ".ll") and not module.startswith(".") and not (module.startswith("__") and module.endswith("__")))
    
    def remove_extension(module):
        if module.endswith(".py") or module.endswith(".bc") or module.endswith(".ll"):
            return module[:-3]
        else:
            return module

    modules = map(remove_extension, modules)
    modules = list(filter(filter_other_files, modules))
    
    no_duplicates = []
    for module in modules:
        if "_" in module and module.replace("_", "-") in modules:
            # Use youtube-dl instead of youtube_dl for example
            continue

        if module not in no_duplicates and module != "python3.10":
            no_duplicates.append(module)
    
    modules = no_duplicates
    modules.sort()

    modules = list(filter(lambda module: module.startswith(command), modules))

    # yout
    # youtube-dl -> ube-dl
    completions = list(map(lambda module: module.replace(command, "", 1), modules))
    return (modules, completions)


def columnize_suggestions(suggestions):
    suggestions = json.loads(suggestions)

    buf = io.StringIO()
    cli = cmd.Cmd(stdout=buf)

    cli.columnize(suggestions, displaywidth=shutil.get_terminal_size().columns)

    buf.seek(0)
    ret = buf.read()
    buf.close()

    return ret