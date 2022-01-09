"""
Support for running Python scripts with 'subprocess.Popen' when the program is 'sys.executable'.
"""

from outputredirector import Reader
import subprocess
import threading
import os
import io
import sys


def close():
    pass

sys.stdin.close = close


class OutputReader(Reader):

    def __init__(self):
        self.output = ""

    def write(self, txt):
        if txt.__class__ is str:
            self.output += txt
        elif txt.__class__ is bytes:
            text = txt.decode()
            self.write(text)


_Popen = subprocess.Popen

class Popen(_Popen):

    def __init__(self, args, bufsize=-1, executable=None,
                 stdin=None, stdout=None, stderr=None,
                 preexec_fn=None, close_fds=True,
                 shell=False, cwd=None, env=None, universal_newlines=None,
                 startupinfo=None, creationflags=0,
                 restore_signals=True, start_new_session=False,
                 pass_fds=(), *, user=None, group=None, extra_groups=None,
                 encoding=None, errors=None, text=None, umask=-1, pipesize=-1):
        
        sys = __import__("sys")

        if (len(args) > 0 and args[0] == sys.executable) or (executable == sys.executable):
            if executable == sys.executable and args[0] != sys.executable:
                args.insert(0, sys.executable)
            
            args.pop(0)
            args.insert(0, "python")

            self.args = args

            _stdin = sys.stdin
            _stdout = sys.stdout
            _stderr = sys.stderr
            _argv = sys.argv
            _env = os.environ
            _cwd = os.getcwd()

            if stdin is None or isinstance(stdin, int):
                stdin = sys.stdin
            
            if isinstance(stdout, int):
                stdout = OutputReader()

            if isinstance(stderr, int):
                stderr = OutputReader()

            if stdout is None:
                stdout = sys.stdout

            if stderr is None:
                stderr = sys.stderr
            
            if env is None:
                env = os.environ

            sys.stdin = stdin
            sys.stdout = stdout
            sys.stderr = stderr
            sys.argv = args
            os.environ = env
            if cwd is not None:
                os.chdir(cwd)

            self.args = args
            self.stdin = stdin
            self.stdout = stdout
            self.stderr = stderr
            self.pid = None
            self.returncode = None
            self.encoding = encoding
            self.errors = errors
            self.pipesize = pipesize
            self._communication_started = False
            self._waitpid_lock = threading.Lock()
            self._input = None

            try:
                from _shell.bin import python
                python.main()
                self.returncode = 0
            except SystemExit as e:
                if e.code is not None and isinstance(e.code, int):
                    print(e.code)
                    self.returncode = e.code
                else:
                    self.returncode = 0
            except Exception as e:
                print(e)
                self.returncode = 1
            finally:
                sys.stdin = _stdin
                sys.stdout = _stdout
                sys.stderr = _stderr
                sys.argv = _argv
                os.environ = _env
                os.chdir(_cwd)

                self.stdout, self.stderr = self.communicate()
        else:
            super().__init__(args=args, bufsize=bufsize, executable=executable, 
                             stdin=stdin, stdout=stdout, stderr=stderr, 
                             preexec_fn=preexec_fn, close_fds=close_fds, 
                             shell=shell, cwd=cwd, env=env, universal_newlines=universal_newlines, 
                             startupinfo=startupinfo, creationflags=creationflags,
                             restore_signals=restore_signals, start_new_session=start_new_session,
                             pass_fds=pass_fds, user=user, group=group, extra_groups=extra_groups,
                             encoding=encoding, errors=errors, text=text, umask=umask, pipesize=pipesize)
    
    def kill(self):
        pass

    def terminate(self):
        pass

    def wait(self, timeout=None):
        return self.returncode

    def communicate(self, input=None, timeout=None):

        if isinstance(self.stdout, OutputReader):
            stdout = io.StringIO(self.stdout.output)
        else:
            stdout = self.stdout


        if isinstance(self.stderr, OutputReader):
            stderr = io.StringIO(self.stderr.output)
        else:
            stderr = self.stderr

        return (stdout, stderr)

    def __enter__(self):
        return self
    
    def __exit__(self, exc_type, value, traceback):
        pass