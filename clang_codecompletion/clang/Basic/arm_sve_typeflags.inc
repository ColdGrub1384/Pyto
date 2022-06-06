#ifdef LLVM_GET_SVE_TYPEFLAGS
const uint64_t IsStructLoad = 131072;
const uint64_t IsInsertOp1SVALL = 67108864;
const uint64_t IsTupleGet = 8589934592;
const uint64_t IsOverloadNone = 1048576;
const uint64_t IsGatherPrefetch = 268435456;
const uint64_t ReverseUSDOT = 1073741824;
const uint64_t IsStructStore = 262144;
const uint64_t FirstEltType = 1;
const uint64_t OverloadKindMask = 14680064;
const uint64_t IsTupleSet = 17179869184;
const uint64_t EltTypeMask = 15;
const uint64_t IsAppendSVALL = 33554432;
const uint64_t IsGatherLoad = 32768;
const uint64_t IsOverloadWhileRW = 4194304;
const uint64_t IsTupleCreate = 4294967296;
const uint64_t MergeTypeMask = 896;
const uint64_t ReverseCompare = 536870912;
const uint64_t IsOverloadCvt = 8388608;
const uint64_t FirstMergeTypeMask = 128;
const uint64_t IsZExtReturn = 524288;
const uint64_t IsStore = 16384;
const uint64_t NoFlags = 0;
const uint64_t IsPrefetch = 134217728;
const uint64_t FirstMemEltType = 16;
const uint64_t IsUndef = 2147483648;
const uint64_t IsByteIndexed = 16777216;
const uint64_t IsOverloadWhile = 2097152;
const uint64_t MemEltTypeMask = 112;
const uint64_t FirstSplatOperand = 1024;
const uint64_t SplatOperandMask = 7168;
const uint64_t IsLoad = 8192;
const uint64_t IsScatterStore = 65536;
#endif

#ifdef LLVM_GET_SVE_ELTTYPES
  EltTyInt32 = 3,
  EltTyBool32 = 10,
  EltTyInt16 = 2,
  EltTyBool16 = 9,
  EltTyInt64 = 4,
  EltTyBool64 = 11,
  EltTyFloat32 = 6,
  EltTyFloat16 = 5,
  EltTyBFloat16 = 12,
  EltTyFloat64 = 7,
  EltTyInt8 = 1,
  EltTyBool8 = 8,
  EltTyInvalid = 0,
#endif

#ifdef LLVM_GET_SVE_MEMELTTYPES
  MemEltTyInt32 = 3,
  MemEltTyInt16 = 2,
  MemEltTyInt8 = 1,
  MemEltTyDefault = 0,
  MemEltTyInt64 = 4,
#endif

#ifdef LLVM_GET_SVE_MERGETYPES
  MergeNone = 0,
  MergeOp1 = 2,
  MergeZero = 3,
  MergeAnyExp = 4,
  MergeAny = 1,
  MergeZeroExp = 5,
#endif

#ifdef LLVM_GET_SVE_IMMCHECKTYPES
  ImmCheckLaneIndexDot = 9,
  ImmCheck0_1 = 13,
  ImmCheck0_2 = 14,
  ImmCheck0_3 = 15,
  ImmCheck0_7 = 6,
  ImmCheckShiftLeft = 5,
  ImmCheckComplexRot90_270 = 10,
  ImmCheckComplexRotAll90 = 11,
  ImmCheck0_13 = 12,
  ImmCheck0_31 = 0,
  ImmCheckShiftRightNarrow = 4,
  ImmCheckLaneIndexCompRotate = 8,
  ImmCheck1_16 = 1,
  ImmCheckLaneIndex = 7,
  ImmCheckExtract = 2,
  ImmCheckShiftRight = 3,
#endif

