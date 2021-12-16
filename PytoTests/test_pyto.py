"""
Tests for Pyto before submitting to the App Store.
"""

import unittest
import runpy
import sys
import os

class TestPyto(unittest.TestCase):

    def test_lib(self):
        from Lib import (apps, location, mainthread, motion,
        multipeer, music, notifications,
        pasteboard, photos, pyto_core, pyto_ui,
        remote_notifications, sharing, sound, speech, userkeys,
        xcallback)

    def test_modules(self):
        runpy.run_module("download_all")
        
    def test_pip(self):
        import pip
        pip.main(["install", "sympy"])
        
        import sympy
        
        pip.main(["uninstall", "sympy"])

    def test_command_runner(self):
        
        expected_result = "usage: pip.py [-h] [--verbose] [-6]\n              sub-command ...\npip.py: error: argument sub-command: invalid choice: '—-help' (choose from 'list', 'install', 'download', 'search', 'versions', 'uninstall', 'update')\n0"
        
        out_path = os.path.join(os.path.expanduser("~/tmp"), "out.txt")
        
        out = open(out_path, "w+")
        _out = sys.stdout
        _err = sys.stderr
        sys.stdout = out
        sys.stderr = out
        
        sys.argv = ["pyto", "pip", "—-help"]
        runpy.run_module("command_runner")
        
        sys.stdout = _out
        sys.stderr = _err
        
        out.close()
        out = open(out_path, "r")
        res = out.read()
        out.close()
        
        res = res.replace(" ", "")
        res = res.replace("\n", "")
        res = res.replace("\t", "")
        expected_result = expected_result.replace(" ", "")
        expected_result = expected_result.replace("\n", "")
        expected_result = expected_result.replace("\t", "")
        self.assertEqual(res, expected_result)

if __name__ == '__main__':

    try:
        unittest.main()
    except SystemExit:
        pass
