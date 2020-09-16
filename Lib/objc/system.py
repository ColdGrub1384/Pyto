'''
Classes from the 'system' framework.
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

    
OSLogCoder = _Class('OSLogCoder')
__NSGlobalBlock__ = _Class('__NSGlobalBlock__')
__NSAutoBlock__ = _Class('__NSAutoBlock__')
__NSFinalizingBlock__ = _Class('__NSFinalizingBlock__')
__NSMallocBlock__ = _Class('__NSMallocBlock__')
__NSStackBlock__ = _Class('__NSStackBlock__')
OS_xpc_payload = _Class('OS_xpc_payload')
OS_xpc_event_publisher = _Class('OS_xpc_event_publisher')
OS_os_transaction = _Class('OS_os_transaction')
OS_os_activity = _Class('OS_os_activity')
OS_os_log = _Class('OS_os_log')
OS_xpc_object = _Class('OS_xpc_object')
OS_xpc_uint64 = _Class('OS_xpc_uint64')
OS_xpc_int64 = _Class('OS_xpc_int64')
OS_xpc_file_transfer = _Class('OS_xpc_file_transfer')
OS_xpc_activity = _Class('OS_xpc_activity')
OS_xpc_service_instance = _Class('OS_xpc_service_instance')
OS_xpc_bundle = _Class('OS_xpc_bundle')
OS_xpc_mach_recv = _Class('OS_xpc_mach_recv')
OS_xpc_pipe = _Class('OS_xpc_pipe')
OS_xpc_serializer = _Class('OS_xpc_serializer')
OS_xpc_endpoint = _Class('OS_xpc_endpoint')
OS_xpc_error = _Class('OS_xpc_error')
OS_xpc_dictionary = _Class('OS_xpc_dictionary')
OS_xpc_array = _Class('OS_xpc_array')
OS_xpc_mach_send = _Class('OS_xpc_mach_send')
OS_xpc_shmem = _Class('OS_xpc_shmem')
OS_xpc_fd = _Class('OS_xpc_fd')
OS_xpc_uuid = _Class('OS_xpc_uuid')
OS_xpc_string = _Class('OS_xpc_string')
OS_xpc_data = _Class('OS_xpc_data')
OS_xpc_date = _Class('OS_xpc_date')
OS_xpc_pointer = _Class('OS_xpc_pointer')
OS_xpc_double = _Class('OS_xpc_double')
OS_xpc_bool = _Class('OS_xpc_bool')
OS_xpc_null = _Class('OS_xpc_null')
OS_xpc_service = _Class('OS_xpc_service')
OS_xpc_connection = _Class('OS_xpc_connection')
__NSBlockVariable__ = _Class('__NSBlockVariable__')
