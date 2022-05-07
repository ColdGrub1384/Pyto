# Minimal makefile for Sphinx documentation
#

# You can set these variables from the command line, and also
# from the environment for the first two.
SPHINXOPTS    ?=
SPHINXBUILD   ?= sphinx-build
SOURCEDIR     = .
BUILDDIR      = ../documentations/pyto

# Put it first so that "make" without argument is like "make help".
help:
	@$(SPHINXBUILD) -M help "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)

.PHONY: help Makefile

# Catch-all target: route all unknown targets to Sphinx using the new
# "make mode" option.  $(O) is meant as a shortcut for $(SPHINXOPTS).
%: Makefile
	./list_bundled_libs.sh > third_party.rst
	./list_licenses.sh > licenses.rst
	./replace_versions.py
	@$(SPHINXBUILD) -M $@ "$(SOURCEDIR)" "$(BUILDDIR)" $(SPHINXOPTS) $(O)
	mv "$(BUILDDIR)/html" "$(BUILDDIR)/../_pyto"
	rm -rf "$(BUILDDIR)"/*
	mv "$(BUILDDIR)/../_pyto/"* "$(BUILDDIR)"
	rm -rf "$(BUILDDIR)/../_pyto"
