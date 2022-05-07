from setuptools import setup
from make_sphinx_documentation import BuildDocsCommand

BuildDocsCommand.sourcedir = "docs"

setup(
    cmdclass={
        'build_docs': BuildDocsCommand, # Run to build the documentation
    },
)
