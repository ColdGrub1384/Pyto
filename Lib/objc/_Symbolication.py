'''
Classes from the 'Symbolication' framework.
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

    
VMUVMRegion = _Class('VMUVMRegion')
VMUClassInfoMap = _Class('VMUClassInfoMap')
VMUTaskThreadStates = _Class('VMUTaskThreadStates')
VMUDirectedGraph = _Class('VMUDirectedGraph')
VMUObjectGraph = _Class('VMUObjectGraph')
VMUProcessObjectGraph = _Class('VMUProcessObjectGraph')
VMUProcInfo = _Class('VMUProcInfo')
VMUBacktrace = _Class('VMUBacktrace')
VMUObjectIdentifier = _Class('VMUObjectIdentifier')
VMUObjectLabelHandlerInfo = _Class('VMUObjectLabelHandlerInfo')
VMUVMRegionIdentifier = _Class('VMUVMRegionIdentifier')
VMUFieldInfo = _Class('VMUFieldInfo')
VMUMutableFieldInfo = _Class('VMUMutableFieldInfo')
__VMULeaksMarkerObject = _Class('__VMULeaksMarkerObject')
VMUDebugTimer = _Class('VMUDebugTimer')
VMUSwiftRuntimeInfo = _Class('VMUSwiftRuntimeInfo')
VMUFieldValue = _Class('VMUFieldValue')
VMUClassInfo = _Class('VMUClassInfo')
VMUMutableClassInfo = _Class('VMUMutableClassInfo')
VMURangeArray = _Class('VMURangeArray')
VMUNonOverlappingRangeArray = _Class('VMUNonOverlappingRangeArray')
VMUAbstractSerializer = _Class('VMUAbstractSerializer')
VMUSimpleDeserializer = _Class('VMUSimpleDeserializer')
VMUSimpleSerializer = _Class('VMUSimpleSerializer')
VMUTaskMemoryCache = _Class('VMUTaskMemoryCache')
VMUSampler = _Class('VMUSampler')
VMUProcList = _Class('VMUProcList')
VMUStackLogConsolidator = _Class('VMUStackLogConsolidator')
VMURangeToStringMap = _Class('VMURangeToStringMap')
VMUScanOverlay = _Class('VMUScanOverlay')
VMUNodeToStringMap = _Class('VMUNodeToStringMap')
VMUOptionParser = _Class('VMUOptionParser')
VMUProcessDescription = _Class('VMUProcessDescription')
VMUVMRegionTracker = _Class('VMUVMRegionTracker')
VMUVMRegionRangeInfo = _Class('VMUVMRegionRangeInfo')
VMULeakDetector = _Class('VMULeakDetector')
VMUCallTreeNode = _Class('VMUCallTreeNode')
VMUCallTreeLeafNode = _Class('VMUCallTreeLeafNode')
VMUCallTreePseudoNode = _Class('VMUCallTreePseudoNode')
VMUCallTreeRoot = _Class('VMUCallTreeRoot')
VMUCallTreeRootWithBacktrace = _Class('VMUCallTreeRootWithBacktrace')
VMUStackLogReaderBase = _Class('VMUStackLogReaderBase')
VMUGraphStackLogReader = _Class('VMUGraphStackLogReader')
VMUTaskStackLogReader = _Class('VMUTaskStackLogReader')
VMUTaskMemoryScanner = _Class('VMUTaskMemoryScanner')
VMURuntimeMetadataChunkInfo = _Class('VMURuntimeMetadataChunkInfo')
VMUArchitecture = _Class('VMUArchitecture')
