'''
Classes from the 'Frameworks' framework.
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

    
WK_RTCLocalVideoH264H265Encoder = _Class('WK_RTCLocalVideoH264H265Encoder')
WK_RTCLocalVideoH264H265Decoder = _Class('WK_RTCLocalVideoH264H265Decoder')
WK_RTCWrappedNativeVideoEncoder = _Class('WK_RTCWrappedNativeVideoEncoder')
WK_RTCWrappedNativeVideoDecoder = _Class('WK_RTCWrappedNativeVideoDecoder')
WK_RTCVideoFrame = _Class('WK_RTCVideoFrame')
WK_RTCVideoEncoderVP9 = _Class('WK_RTCVideoEncoderVP9')
WK_RTCVideoEncoderVP8 = _Class('WK_RTCVideoEncoderVP8')
WK_RTCVideoEncoderSettings = _Class('WK_RTCVideoEncoderSettings')
WK_RTCVideoEncoderQpThresholds = _Class('WK_RTCVideoEncoderQpThresholds')
WK_RTCVideoEncoderH265 = _Class('WK_RTCVideoEncoderH265')
WK_RTCVideoEncoderH264 = _Class('WK_RTCVideoEncoderH264')
WK_RTCVideoEncoderFactoryH264 = _Class('WK_RTCVideoEncoderFactoryH264')
WK_RTCVideoDecoderVP9 = _Class('WK_RTCVideoDecoderVP9')
WK_RTCVideoDecoderVP8 = _Class('WK_RTCVideoDecoderVP8')
WK_RTCVideoDecoderH265 = _Class('WK_RTCVideoDecoderH265')
WK_RTCVideoDecoderH264 = _Class('WK_RTCVideoDecoderH264')
WK_RTCVideoDecoderFactoryH264 = _Class('WK_RTCVideoDecoderFactoryH264')
WK_RTCVideoCodecInfo = _Class('WK_RTCVideoCodecInfo')
WK_RTCRtpFragmentationHeader = _Class('WK_RTCRtpFragmentationHeader')
WK_RTCRtpEncodingParameters = _Class('WK_RTCRtpEncodingParameters')
WK_RTCI420Buffer = _Class('WK_RTCI420Buffer')
WK_RTCMutableI420Buffer = _Class('WK_RTCMutableI420Buffer')
WK_RTCH264ProfileLevelId = _Class('WK_RTCH264ProfileLevelId')
WK_RTCEncodedImage = _Class('WK_RTCEncodedImage')
WK_RTCWrappedEncodedImageBuffer = _Class('WK_RTCWrappedEncodedImageBuffer')
WK_RTCDefaultVideoEncoderFactory = _Class('WK_RTCDefaultVideoEncoderFactory')
WK_RTCDefaultVideoDecoderFactory = _Class('WK_RTCDefaultVideoDecoderFactory')
WK_RTCCVPixelBuffer = _Class('WK_RTCCVPixelBuffer')
WK_RTCCodecSpecificInfoH265 = _Class('WK_RTCCodecSpecificInfoH265')
WK_RTCCodecSpecificInfoH264 = _Class('WK_RTCCodecSpecificInfoH264')
