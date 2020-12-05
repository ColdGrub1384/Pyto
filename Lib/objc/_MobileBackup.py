"""
Classes from the 'MobileBackup' framework.
"""

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


MBStartBackupOptions = _Class("MBStartBackupOptions")
MBBackgroundRestoreInfo = _Class("MBBackgroundRestoreInfo")
MBRestoreInfo = _Class("MBRestoreInfo")
MBRestoreFailure = _Class("MBRestoreFailure")
MBStateInfo = _Class("MBStateInfo")
MBFileInfo = _Class("MBFileInfo")
MBDomainInfo = _Class("MBDomainInfo")
MBSnapshot = _Class("MBSnapshot")
MBBackup = _Class("MBBackup")
MBMessage = _Class("MBMessage")
MBConnection = _Class("MBConnection")
MBDigest = _Class("MBDigest")
MBDigestSHA256 = _Class("MBDigestSHA256")
MBDigestSHA1 = _Class("MBDigestSHA1")
MBDeviceTransferConnectionInfo = _Class("MBDeviceTransferConnectionInfo")
MBDeviceTransferProgress = _Class("MBDeviceTransferProgress")
MBDeviceTransferPreflight = _Class("MBDeviceTransferPreflight")
MBDeviceTransferKeychain = _Class("MBDeviceTransferKeychain")
MBDeviceTransferSession = _Class("MBDeviceTransferSession")
MBFileManager = _Class("MBFileManager")
MBBehaviorOptions = _Class("MBBehaviorOptions")
MBFileSystemManager = _Class("MBFileSystemManager")
MBFileSystemSnapshot = _Class("MBFileSystemSnapshot")
MBManager = _Class("MBManager")
MBManagerClient = _Class("MBManagerClient")
MBDeviceLockInfo = _Class("MBDeviceLockInfo")
MBDebugContext = _Class("MBDebugContext")
MBFileManagerDelegate = _Class("MBFileManagerDelegate")
MBDeviceTransferTask = _Class("MBDeviceTransferTask")
MBTargetDeviceTransferTask = _Class("MBTargetDeviceTransferTask")
MBSourceDeviceTransferTask = _Class("MBSourceDeviceTransferTask")
MBError = _Class("MBError")
MBContainer = _Class("MBContainer")
MBAppGroup = _Class("MBAppGroup")
MBAppPlugin = _Class("MBAppPlugin")
MBApp = _Class("MBApp")
MBSystemContainer = _Class("MBSystemContainer")
MBDomain = _Class("MBDomain")
MBAppManager = _Class("MBAppManager")
MBProperties = _Class("MBProperties")
MBSizeInfo = _Class("MBSizeInfo")
MBException = _Class("MBException")
