'''
Classes from the 'introspection' framework.
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

    
OS_dispatch_data = _Class('OS_dispatch_data')
OS_dispatch_data_empty = _Class('OS_dispatch_data_empty')
OS_object = _Class('OS_object')
OS_os_eventlink = _Class('OS_os_eventlink')
OS_os_workgroup = _Class('OS_os_workgroup')
OS_os_workgroup_parallel = _Class('OS_os_workgroup_parallel')
OS_os_workgroup_interval = _Class('OS_os_workgroup_interval')
OS_voucher = _Class('OS_voucher')
OS_dispatch_object = _Class('OS_dispatch_object')
OS_dispatch_disk = _Class('OS_dispatch_disk')
OS_dispatch_operation = _Class('OS_dispatch_operation')
OS_dispatch_io = _Class('OS_dispatch_io')
OS_dispatch_mach_msg = _Class('OS_dispatch_mach_msg')
OS_dispatch_queue_attr = _Class('OS_dispatch_queue_attr')
OS_dispatch_group = _Class('OS_dispatch_group')
OS_dispatch_semaphore = _Class('OS_dispatch_semaphore')
OS_dispatch_mach = _Class('OS_dispatch_mach')
OS_dispatch_source = _Class('OS_dispatch_source')
OS_dispatch_channel = _Class('OS_dispatch_channel')
OS_dispatch_queue = _Class('OS_dispatch_queue')
OS_dispatch_queue_pthread_root = _Class('OS_dispatch_queue_pthread_root')
OS_dispatch_queue_global = _Class('OS_dispatch_queue_global')
OS_dispatch_queue_concurrent = _Class('OS_dispatch_queue_concurrent')
OS_dispatch_workloop = _Class('OS_dispatch_workloop')
OS_dispatch_queue_serial = _Class('OS_dispatch_queue_serial')
OS_dispatch_queue_mgr = _Class('OS_dispatch_queue_mgr')
OS_dispatch_queue_main = _Class('OS_dispatch_queue_main')
OS_dispatch_queue_runloop = _Class('OS_dispatch_queue_runloop')
