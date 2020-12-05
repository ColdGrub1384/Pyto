"""
Classes from the 'RawCamera' framework.
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


RAWKernels = _Class("RAWKernels")
V8VIEWKernels = _Class("V8VIEWKernels")
V8CNRKernels = _Class("V8CNRKernels")
V8LNRKernels = _Class("V8LNRKernels")
GainMapKernels = _Class("GainMapKernels")
BoostKernels = _Class("BoostKernels")
HMKernels = _Class("HMKernels")
GMKernels = _Class("GMKernels")
DMKernels = _Class("DMKernels")
LCKernels = _Class("LCKernels")
NRKernels = _Class("NRKernels")
FujiSuperCCDReconstructionImageProvider = _Class(
    "FujiSuperCCDReconstructionImageProvider"
)
Curve = _Class("Curve")
BayerImageProvider = _Class("BayerImageProvider")
RAWOpcodeMapPolynomial = _Class("RAWOpcodeMapPolynomial")
RAWOpcodeMapTable = _Class("RAWOpcodeMapTable")
RAWOpcodeTrimBounds = _Class("RAWOpcodeTrimBounds")
RAWOpcodeDeltaPerRow = _Class("RAWOpcodeDeltaPerRow")
RAWOpcodeFixVignetteRadial = _Class("RAWOpcodeFixVignetteRadial")
RAWOpcodeScalePerColumn = _Class("RAWOpcodeScalePerColumn")
RAWOpcodeGainMap = _Class("RAWOpcodeGainMap")
RAWOpcodeWarpRectilinear = _Class("RAWOpcodeWarpRectilinear")
RAWOpcodeDeltaPerColumn = _Class("RAWOpcodeDeltaPerColumn")
RAWOpcodeWarpFisheye = _Class("RAWOpcodeWarpFisheye")
RAWSimpleLensCorrectionFilter = _Class("RAWSimpleLensCorrectionFilter")
RAWOpcodeFixBadPixelsConstant = _Class("RAWOpcodeFixBadPixelsConstant")
RAWOpcodeFixBadPixelsList = _Class("RAWOpcodeFixBadPixelsList")
RAWOpcodeScalePerRow = _Class("RAWOpcodeScalePerRow")
RAWLensCorrectionDistortionFilter = _Class("RAWLensCorrectionDistortionFilter")
RAWLensCorrectionLateralCAFilter = _Class("RAWLensCorrectionLateralCAFilter")
RAWLensCorrectionVignetteFilter = _Class("RAWLensCorrectionVignetteFilter")
RAWFilter = _Class("RAWFilter")
RAWEdgeSharpen = _Class("RAWEdgeSharpen")
RAWLensCorrectionDNG = _Class("RAWLensCorrectionDNG")
RAWGainMap = _Class("RAWGainMap")
RAWCropFilter = _Class("RAWCropFilter")
RAWDefringeFilter = _Class("RAWDefringeFilter")
RAWConvert = _Class("RAWConvert")
RAWVignetteRadial = _Class("RAWVignetteRadial")
RAWAdjustExposureAndBias = _Class("RAWAdjustExposureAndBias")
RAWTemperatureAdjust = _Class("RAWTemperatureAdjust")
RAWPreserveHueGamutMap = _Class("RAWPreserveHueGamutMap")
RAWReduceNoise = _Class("RAWReduceNoise")
RAWHueMagnet = _Class("RAWHueMagnet")
RAWConvertLinearToSRGB = _Class("RAWConvertLinearToSRGB")
RAWConvertSRGBtoLinear = _Class("RAWConvertSRGBtoLinear")
RAWAdjustColorTRC = _Class("RAWAdjustColorTRC")
RAWAdjustColors = _Class("RAWAdjustColors")
RAWLinearSpacePlaceholder = _Class("RAWLinearSpacePlaceholder")
RAWDemosaicFilter = _Class("RAWDemosaicFilter")
RAWBayerInterleavedFilter = _Class("RAWBayerInterleavedFilter")
RAWGamutMap = _Class("RAWGamutMap")
RAWProfileGainTableMapFilter = _Class("RAWProfileGainTableMapFilter")
RAWRadialLensCorrectionRB = _Class("RAWRadialLensCorrectionRB")
RAWRadialLensCorrection = _Class("RAWRadialLensCorrection")
RAWVignetteTable = _Class("RAWVignetteTable")
RAWLTMFilter = _Class("RAWLTMFilter")
