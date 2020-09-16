'''
Classes from the 'FeedbackLogger' framework.
'''

try:
    from rubicon.objc import ObjCClass
except ValueError:
    def ObjCClass(name):
        return None


def _Class(name):
    try:
        return ObjCClass(name)
    except NameError:
        return None

    
FLLoggingContext = _Class('FLLoggingContext')
FLSQLitePersistence = _Class('FLSQLitePersistence')
BatchMetadata = _Class('BatchMetadata')
FLLogger = _Class('FLLogger')
