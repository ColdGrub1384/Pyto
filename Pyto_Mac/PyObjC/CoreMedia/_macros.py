import CoreMedia

def CMTIMERANGE_IS_VALID(range):
    return CMTIME_IS_VALID(range.start) and CMTIME_IS_VALID(range.duration) and range.duration.epoch == 0 and range.duration.value >= 0

def CMTIMERANGE_IS_INVALID(range):
    return not CMTIMERANGE_IS_VALID(range)

def CMTIMERANGE_IS_INDEFINITE(range):
    return CMTIMERANGE_IS_VALID(range) and (CMTIME_IS_INDEFINITE(range.start) or CMTIME_IS_INDEFINITE(range.duration))

def CMTIMERANGE_IS_EMPTY(range):
    return CMTIMERANGE_IS_VALID(range) and range.duration == kCMTimeZero

def CMTIMEMAPPING_IS_VALID(mapping):
    return CMTIMERANGE_IS_VALID(mapping.target)

def CMTIMEMAPPING_IS_INVALID(mapping):
    return not CMTIMEMAPPING_IS_VALID(mapping)

def CMTIMEMAPPING_IS_EMPTY(mapping):
    return not CMTIME_IS_NUMERIC(mapping.source.start) and CMTIMERANGE_IS_VALID(mapping.target)

def CMSimpleQueueGetFullness(queue):
    if CMSimpleQueueGetCapacity(queue):
        return CMSimpleQueueGetCount(queue) / CMSimpleQueueGetCapacity(queue)
    else:
        return 0.0

def CMTIME_IS_VALID(time):
    return (time.flags & CoreMedia.kCMTimeFlags_Valid) != 0

def CMTIME_IS_INVALID(time):
    return not CMTIME_IS_VALID(time)

def CMTIME_IS_POSITIVE_INFINITY(time):
    return CMTIME_IS_VALID(time) and (time.flags & CoreMedia.kCMTimeFlags_PositiveInfinity) != 0

def CMTIME_IS_NEGATIVE_INFINITY(time):
    return CMTIME_IS_VALID(time) and (time.flags & CoreMedia.kCMTimeFlags_NegativeInfinity) != 0

def CMTIME_IS_INDEFINITE(time):
    return CMTIME_IS_VALID(time) and (time.flags & CoreMedia.kCMTimeFlags_Indefinite) != 0

def CMTIME_IS_NUMERIC(time):
    return (time.flags & (CoreMedia.kCMTimeFlags_Valid | CoreMedia.kCMTimeFlags_ImpliedValueFlagsMask)) == CoreMedia.kCMTimeFlags_Valid

def CMTIME_HAS_BEEN_ROUNDED(time):
    return CMTIME_IS_NUMERIC(time) and (time.flags & CoreMedia.kCMTimeFlags_HasBeenRounded) != 0
