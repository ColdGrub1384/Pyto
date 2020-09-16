'''
Classes from the 'TCC' framework.
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

    
OS_tcc_object = _Class('OS_tcc_object')
OS_tcc_events_subscription = _Class('OS_tcc_events_subscription')
OS_tcc_events_filter = _Class('OS_tcc_events_filter')
OS_tcc_runtime = _Class('OS_tcc_runtime')
OS_tcc_server = _Class('OS_tcc_server')
OS_tcc_service = _Class('OS_tcc_service')
OS_tcc_message_options = _Class('OS_tcc_message_options')
OS_tcc_authorization_record = _Class('OS_tcc_authorization_record')
OS_tcc_attributed_entity = _Class('OS_tcc_attributed_entity')
OS_tcc_credential = _Class('OS_tcc_credential')
OS_tcc_identity = _Class('OS_tcc_identity')
