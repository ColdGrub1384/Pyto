"""
Port of "function defines".
"""
from Foundation import NSBundle, NSProcessInfo

def NSLocalizedString(key, comment):
    return NSBundle.mainBundle().localizedStringForKey_value_table_(key, '', None)

def NSLocalizedStringFromTable(key, tbl, comment):
    return NSBundle.mainBundle().localizedStringForKey_value_table_(key, '', tbl)

def NSLocalizedStringFromTableInBundle(key, tbl, bundle, comment):
    return bundle.localizedStringForKey_value_table_(key, '', tbl)

def NSLocalizedStringWithDefaultValue(key, tbl, bundle, val, comment):
    return bundle.localizedStringForKey_value_table_(key, val, tbl)


def MIN(a, b):
    if a < b:
        return a
    else:
        return b

def MAX(a, b):
    if a < b:
        return b
    else:
        return a

ABS = abs
