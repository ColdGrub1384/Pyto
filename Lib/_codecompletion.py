try:
    from pyto import ConsoleViewController, Python
except:
    pass
import jedi
import sys
import traceback
from rubicon.objc import at
from Foundation import NSAutoreleasePool
from pygments import highlight
from pygments import lexers
from pygments.formatters.terminal256 import TerminalTrueColorFormatter
from pygments.styles import get_style_by_name

_completions_queue = 0

lexer = lexers.get_lexer_by_name('python')
style = get_style_by_name('default')
formatter = TerminalTrueColorFormatter(full=True, style=style)

def printHighlightedCode(code):
    print(highlight(code, lexer, formatter), end="")

def suggestForCode(code, index, path):
    global _completions_queue

    try:
        visibles = ConsoleViewController.objcVisibles
    except AttributeError:
        visibles = []

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
            sys.__stdout__.write("Code completion:\n " + traceback.format_exc() + "\n")
            return

        try:
            script = jedi.Script(code, path=path)

            definitions = []
            for _def in script.get_names():
                decl = _def.description
                line = _def.line
                if "=" in decl:
                    decl = decl.split("=")[0]
                if ":" in decl:
                    decl = decl.split(":")[0]
                definitions.append([decl, line])

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

            _completions = script.complete(line, column)
            for completion in _completions:
                suggestion = completion.name

                if completion.complete.startswith("."):
                    suggestion = "." + suggestion

                if completion.name in __builtins__["deprecated"]:
                    continue

                complete = completion.complete
                if complete.endswith("="):
                    complete = complete[:-1]

                suggestions.append(suggestion)
                completions.append(complete)

                docs[suggestion] = ""

                if complete == "" and signature != "":
                    completions = []
                    suggestions = []
                    break
            
            if visibleEditor.text != code:
                return
            
            visibleEditor.lastCodeFromCompletions = code
            visibleEditor.signature = signature
            visibleEditor.completions = completions
            visibleEditor.suggestions = suggestions
            visibleEditor.docStrings = docs

        except Exception as e:

            sys.__stdout__.write("Code completion:\n " + traceback.format_exc() + "\n")

            if visibleEditor is None:
                return

            visibleEditor.completions = []
            visibleEditor.suggestions = []
            visibleEditor.signature = ""
            visibleEditor.docStrings = None


def suggestionsForCode(code, path=None):

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

            if (
                completion.name.startswith("_")
                or completion.name in __builtins__["deprecated"]
            ):
                continue

            suggestions[completion.name] = completion.complete

        return suggestions
    except Exception as e:
        return {}
