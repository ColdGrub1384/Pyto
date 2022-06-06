static const IntrinToName MapData[] = {
  { ARM::BI__builtin_arm_cde_cx1, 0, -1},
  { ARM::BI__builtin_arm_cde_cx1a, 4, -1},
  { ARM::BI__builtin_arm_cde_cx1d, 9, -1},
  { ARM::BI__builtin_arm_cde_cx1da, 14, -1},
  { ARM::BI__builtin_arm_cde_cx2, 20, -1},
  { ARM::BI__builtin_arm_cde_cx2a, 24, -1},
  { ARM::BI__builtin_arm_cde_cx2d, 29, -1},
  { ARM::BI__builtin_arm_cde_cx2da, 34, -1},
  { ARM::BI__builtin_arm_cde_cx3, 40, -1},
  { ARM::BI__builtin_arm_cde_cx3a, 44, -1},
  { ARM::BI__builtin_arm_cde_cx3d, 49, -1},
  { ARM::BI__builtin_arm_cde_cx3da, 54, -1},
  { ARM::BI__builtin_arm_cde_vcx1_u32, 60, -1},
  { ARM::BI__builtin_arm_cde_vcx1a_u32, 69, -1},
  { ARM::BI__builtin_arm_cde_vcx1d_u64, 79, -1},
  { ARM::BI__builtin_arm_cde_vcx1da_u64, 89, -1},
  { ARM::BI__builtin_arm_cde_vcx1q_m_f16, 108, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_m_f32, 120, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_m_s16, 132, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_m_s32, 144, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_m_s64, 156, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_m_s8, 168, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_m_u16, 179, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_m_u32, 191, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_m_u64, 203, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_m_u8, 215, 100},
  { ARM::BI__builtin_arm_cde_vcx1q_u8, 226, -1},
  { ARM::BI__builtin_arm_cde_vcx1qa_f16, 242, 235},
  { ARM::BI__builtin_arm_cde_vcx1qa_f32, 253, 235},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_f16, 273, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_f32, 286, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_s16, 299, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_s32, 312, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_s64, 325, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_s8, 338, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_u16, 350, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_u32, 363, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_u64, 376, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_m_u8, 389, 264},
  { ARM::BI__builtin_arm_cde_vcx1qa_s16, 401, 235},
  { ARM::BI__builtin_arm_cde_vcx1qa_s32, 412, 235},
  { ARM::BI__builtin_arm_cde_vcx1qa_s64, 423, 235},
  { ARM::BI__builtin_arm_cde_vcx1qa_s8, 434, 235},
  { ARM::BI__builtin_arm_cde_vcx1qa_u16, 444, 235},
  { ARM::BI__builtin_arm_cde_vcx1qa_u32, 455, 235},
  { ARM::BI__builtin_arm_cde_vcx1qa_u64, 466, 235},
  { ARM::BI__builtin_arm_cde_vcx1qa_u8, 477, 235},
  { ARM::BI__builtin_arm_cde_vcx2_u32, 487, -1},
  { ARM::BI__builtin_arm_cde_vcx2a_u32, 496, -1},
  { ARM::BI__builtin_arm_cde_vcx2d_u64, 506, -1},
  { ARM::BI__builtin_arm_cde_vcx2da_u64, 516, -1},
  { ARM::BI__builtin_arm_cde_vcx2q_f16, 533, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_f32, 543, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_f16, 566, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_f32, 583, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_s16, 600, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_s32, 617, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_s64, 634, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_s8, 651, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_u16, 667, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_u32, 684, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_u64, 701, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_m_impl_u8, 718, 553},
  { ARM::BI__builtin_arm_cde_vcx2q_s16, 734, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_s32, 744, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_s64, 754, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_s8, 764, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_u16, 773, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_u32, 783, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_u64, 793, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_u8, 803, 527},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_f16, 812, 803},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_f32, 825, 803},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_s16, 838, 803},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_s32, 851, 803},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_s64, 864, 803},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_s8, 877, 803},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_u16, 889, 803},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_u32, 902, 803},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_u64, 915, 803},
  { ARM::BI__builtin_arm_cde_vcx2q_u8_u8, 928, 803},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_f16, 952, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_f32, 968, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_s16, 984, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_s32, 1000, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_s64, 1016, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_s8, 1032, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_u16, 1047, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_u32, 1063, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_u64, 1079, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_impl_u8, 1095, 940},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_f16, 1124, 1110},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_f32, 1142, 1110},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_s16, 1160, 1110},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_s32, 1178, 1110},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_s64, 1196, 1110},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_s8, 1214, 1110},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_u16, 1231, 1110},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_u32, 1249, 1110},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_u64, 1267, 1110},
  { ARM::BI__builtin_arm_cde_vcx2qa_m_impl_u8, 1285, 1110},
  { ARM::BI__builtin_arm_cde_vcx3_u32, 1302, -1},
  { ARM::BI__builtin_arm_cde_vcx3a_u32, 1311, -1},
  { ARM::BI__builtin_arm_cde_vcx3d_u64, 1321, -1},
  { ARM::BI__builtin_arm_cde_vcx3da_u64, 1331, -1},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_f16, 1353, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_f32, 1368, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_s16, 1383, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_s32, 1398, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_s64, 1413, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_s8, 1428, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_u16, 1442, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_u32, 1457, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_u64, 1472, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_impl_u8, 1487, 1342},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_f16, 1514, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_f32, 1531, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_s16, 1548, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_s32, 1565, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_s64, 1582, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_s8, 1599, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_u16, 1615, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_u32, 1632, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_u64, 1649, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_m_impl_u8, 1666, 1501},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_f16, 1696, 1682},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_f32, 1714, 1682},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_s16, 1732, 1682},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_s32, 1750, 1682},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_s64, 1768, 1682},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_s8, 1786, 1682},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_u16, 1803, 1682},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_u32, 1821, 1682},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_u64, 1839, 1682},
  { ARM::BI__builtin_arm_cde_vcx3q_u8_impl_u8, 1857, 1682},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_f16, 1886, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_f32, 1902, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_s16, 1918, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_s32, 1934, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_s64, 1950, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_s8, 1966, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_u16, 1981, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_u32, 1997, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_u64, 2013, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_impl_u8, 2029, 1874},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_f16, 2058, 2044},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_f32, 2076, 2044},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_s16, 2094, 2044},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_s32, 2112, 2044},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_s64, 2130, 2044},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_s8, 2148, 2044},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_u16, 2165, 2044},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_u32, 2183, 2044},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_u64, 2201, 2044},
  { ARM::BI__builtin_arm_cde_vcx3qa_m_impl_u8, 2219, 2044},
  { ARM::BI__builtin_arm_cde_vreinterpretq_u8_u8, 2253, 2236},
};

ArrayRef<IntrinToName> Map(MapData);

static const char IntrinNames[] = {
    "cx1\000cx1a\000cx1d\000cx1da\000cx2\000cx2a\000cx2d\000cx2da\000cx3\000"
    "cx3a\000cx3d\000cx3da\000vcx1_u32\000vcx1a_u32\000vcx1d_u64\000vcx1da_u"
    "64\000vcx1q_m\000vcx1q_m_f16\000vcx1q_m_f32\000vcx1q_m_s16\000vcx1q_m_s"
    "32\000vcx1q_m_s64\000vcx1q_m_s8\000vcx1q_m_u16\000vcx1q_m_u32\000vcx1q_"
    "m_u64\000vcx1q_m_u8\000vcx1q_u8\000vcx1qa\000vcx1qa_f16\000vcx1qa_f32\000"
    "vcx1qa_m\000vcx1qa_m_f16\000vcx1qa_m_f32\000vcx1qa_m_s16\000vcx1qa_m_s3"
    "2\000vcx1qa_m_s64\000vcx1qa_m_s8\000vcx1qa_m_u16\000vcx1qa_m_u32\000vcx"
    "1qa_m_u64\000vcx1qa_m_u8\000vcx1qa_s16\000vcx1qa_s32\000vcx1qa_s64\000v"
    "cx1qa_s8\000vcx1qa_u16\000vcx1qa_u32\000vcx1qa_u64\000vcx1qa_u8\000vcx2"
    "_u32\000vcx2a_u32\000vcx2d_u64\000vcx2da_u64\000vcx2q\000vcx2q_f16\000v"
    "cx2q_f32\000vcx2q_m_impl\000vcx2q_m_impl_f16\000vcx2q_m_impl_f32\000vcx"
    "2q_m_impl_s16\000vcx2q_m_impl_s32\000vcx2q_m_impl_s64\000vcx2q_m_impl_s"
    "8\000vcx2q_m_impl_u16\000vcx2q_m_impl_u32\000vcx2q_m_impl_u64\000vcx2q_"
    "m_impl_u8\000vcx2q_s16\000vcx2q_s32\000vcx2q_s64\000vcx2q_s8\000vcx2q_u"
    "16\000vcx2q_u32\000vcx2q_u64\000vcx2q_u8\000vcx2q_u8_f16\000vcx2q_u8_f3"
    "2\000vcx2q_u8_s16\000vcx2q_u8_s32\000vcx2q_u8_s64\000vcx2q_u8_s8\000vcx"
    "2q_u8_u16\000vcx2q_u8_u32\000vcx2q_u8_u64\000vcx2q_u8_u8\000vcx2qa_impl"
    "\000vcx2qa_impl_f16\000vcx2qa_impl_f32\000vcx2qa_impl_s16\000vcx2qa_imp"
    "l_s32\000vcx2qa_impl_s64\000vcx2qa_impl_s8\000vcx2qa_impl_u16\000vcx2qa"
    "_impl_u32\000vcx2qa_impl_u64\000vcx2qa_impl_u8\000vcx2qa_m_impl\000vcx2"
    "qa_m_impl_f16\000vcx2qa_m_impl_f32\000vcx2qa_m_impl_s16\000vcx2qa_m_imp"
    "l_s32\000vcx2qa_m_impl_s64\000vcx2qa_m_impl_s8\000vcx2qa_m_impl_u16\000"
    "vcx2qa_m_impl_u32\000vcx2qa_m_impl_u64\000vcx2qa_m_impl_u8\000vcx3_u32\000"
    "vcx3a_u32\000vcx3d_u64\000vcx3da_u64\000vcx3q_impl\000vcx3q_impl_f16\000"
    "vcx3q_impl_f32\000vcx3q_impl_s16\000vcx3q_impl_s32\000vcx3q_impl_s64\000"
    "vcx3q_impl_s8\000vcx3q_impl_u16\000vcx3q_impl_u32\000vcx3q_impl_u64\000"
    "vcx3q_impl_u8\000vcx3q_m_impl\000vcx3q_m_impl_f16\000vcx3q_m_impl_f32\000"
    "vcx3q_m_impl_s16\000vcx3q_m_impl_s32\000vcx3q_m_impl_s64\000vcx3q_m_imp"
    "l_s8\000vcx3q_m_impl_u16\000vcx3q_m_impl_u32\000vcx3q_m_impl_u64\000vcx"
    "3q_m_impl_u8\000vcx3q_u8_impl\000vcx3q_u8_impl_f16\000vcx3q_u8_impl_f32"
    "\000vcx3q_u8_impl_s16\000vcx3q_u8_impl_s32\000vcx3q_u8_impl_s64\000vcx3"
    "q_u8_impl_s8\000vcx3q_u8_impl_u16\000vcx3q_u8_impl_u32\000vcx3q_u8_impl"
    "_u64\000vcx3q_u8_impl_u8\000vcx3qa_impl\000vcx3qa_impl_f16\000vcx3qa_im"
    "pl_f32\000vcx3qa_impl_s16\000vcx3qa_impl_s32\000vcx3qa_impl_s64\000vcx3"
    "qa_impl_s8\000vcx3qa_impl_u16\000vcx3qa_impl_u32\000vcx3qa_impl_u64\000"
    "vcx3qa_impl_u8\000vcx3qa_m_impl\000vcx3qa_m_impl_f16\000vcx3qa_m_impl_f"
    "32\000vcx3qa_m_impl_s16\000vcx3qa_m_impl_s32\000vcx3qa_m_impl_s64\000vc"
    "x3qa_m_impl_s8\000vcx3qa_m_impl_u16\000vcx3qa_m_impl_u32\000vcx3qa_m_im"
    "pl_u64\000vcx3qa_m_impl_u8\000vreinterpretq_u8\000vreinterpretq_u8_u8\000"};

