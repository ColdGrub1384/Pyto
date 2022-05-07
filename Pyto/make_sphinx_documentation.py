# A replacement to Makefile written in pure Python
# Use this instead of 'make' in Pyto

import sys
import shlex
import os
import json
import shutil
import distutils.cmd
import warnings
from sphinx.cmd.build import main as sphinx_main

class BuildDocsCommand(distutils.cmd.Command):
  description = 'build Sphinx documentation'
  user_options = [
      # The format is (long option, short option, description).
      ('sourcedir=', None, 'path to the documentation'),
  ]
  sourcedir = "docs"

  def initialize_options(self):
    self.sourcedir = type(self).sourcedir

  def finalize_options(self):
    if self.sourcedir:
      assert os.path.exists(self.sourcedir), (
          '%s does not exist.' % self.sourcedir)

  def run(self):
    os.chdir(self.sourcedir)
    run_sphinx(["html"])


def getenv(key, default):
    try:
        return os.environ[key]
    except KeyError:
        return default


SPHINXOPTS    = getenv("SPHINXOPTS", "")
SPHINXBUILD   = getenv("SPHINXBUILD", "sphinx-build")
SOURCEDIR     = "."
BUILDDIR      = "_build"

DOCUMENTATIONS_PATH = os.path.expanduser("~/Library/documentations")


def save_documentation():
    
    with open("conf.py", mode="r", encoding="utf-8") as f:
        code = f.read()
        exec(code, globals(), globals())
    
    try:
        release
    except NameError:
        release = "unknown version"
    
    info = {
        "name": project,
        "tag": f"{project}-docs",
        "version": release,
        "filename": f"{project}.zip"
    }
    
    with open(os.path.join(BUILDDIR, "html", "pyto_documentation.json"), "w+") as f:
        f.write(json.dumps(info))

    target = os.path.join(DOCUMENTATIONS_PATH, f"{project}-sphinx-docs")
    if os.path.isdir(target):
        shutil.rmtree(target)
    shutil.copytree(os.path.join(BUILDDIR, "html"), target)


def run_sphinx(args):
    sys.argv = [SPHINXBUILD, "-M"]+args+[SOURCEDIR, BUILDDIR]+shlex.split(SPHINXOPTS)
    exit_code = sphinx_main(sys.argv[1:])
    
    if "html" in args:
        save_documentation()
        print("The documentation is now accessible from the 'Documentation' tab.")
    
    sys.exit(exit_code)


def main():
    args = sys.argv
    args.pop(0)
    if len(args) == 0:
        args = ["help"]

    with warnings.catch_warnings():
        run_sphinx(args)


if __name__ == "__main__":
    main()

