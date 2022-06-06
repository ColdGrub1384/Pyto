#ifdef GET_SVE_IMMEDIATE_CHECK
case SVE::BI__builtin_sve_svasrd_n_s16_m:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svasrd_n_s16_x:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svasrd_n_s16_z:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svasrd_n_s32_m:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svasrd_n_s32_x:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svasrd_n_s32_z:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svasrd_n_s64_m:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svasrd_n_s64_x:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svasrd_n_s64_z:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svasrd_n_s8_m:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svasrd_n_s8_x:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svasrd_n_s8_z:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svbfdot_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 15, 0));
  break;
case SVE::BI__builtin_sve_svbfmlalb_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 6, 0));
  break;
case SVE::BI__builtin_sve_svbfmlalt_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 6, 0));
  break;
case SVE::BI__builtin_sve_svcadd_f16_m:
ImmChecks.push_back(std::make_tuple(3, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_f16_x:
ImmChecks.push_back(std::make_tuple(3, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_f16_z:
ImmChecks.push_back(std::make_tuple(3, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_f32_m:
ImmChecks.push_back(std::make_tuple(3, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_f32_x:
ImmChecks.push_back(std::make_tuple(3, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_f32_z:
ImmChecks.push_back(std::make_tuple(3, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_f64_m:
ImmChecks.push_back(std::make_tuple(3, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_f64_x:
ImmChecks.push_back(std::make_tuple(3, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_f64_z:
ImmChecks.push_back(std::make_tuple(3, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_s16:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_s32:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_s64:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_s8:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_u16:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_u32:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_u64:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svcadd_u8:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svcdot_lane_s32:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
ImmChecks.push_back(std::make_tuple(3, 9, 8));
  break;
case SVE::BI__builtin_sve_svcdot_lane_s64:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
ImmChecks.push_back(std::make_tuple(3, 9, 16));
  break;
case SVE::BI__builtin_sve_svcdot_s32:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcdot_s64:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_f16_m:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_f16_x:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_f16_z:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_f32_m:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_f32_x:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_f32_z:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_f64_m:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_f64_x:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_f64_z:
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_lane_f16:
ImmChecks.push_back(std::make_tuple(3, 8, 16));
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 8, 32));
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_lane_s16:
ImmChecks.push_back(std::make_tuple(3, 8, 16));
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 8, 32));
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_lane_u16:
ImmChecks.push_back(std::make_tuple(3, 8, 16));
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_lane_u32:
ImmChecks.push_back(std::make_tuple(3, 8, 32));
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_s16:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_s32:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_s64:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_s8:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_u16:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_u32:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_u64:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcmla_u8:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svcntb_pat:
ImmChecks.push_back(std::make_tuple(0, 0, 0));
  break;
case SVE::BI__builtin_sve_svcntd_pat:
ImmChecks.push_back(std::make_tuple(0, 0, 0));
  break;
case SVE::BI__builtin_sve_svcnth_pat:
ImmChecks.push_back(std::make_tuple(0, 0, 0));
  break;
case SVE::BI__builtin_sve_svcntw_pat:
ImmChecks.push_back(std::make_tuple(0, 0, 0));
  break;
case SVE::BI__builtin_sve_svdot_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 9, 8));
  break;
case SVE::BI__builtin_sve_svdot_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 9, 16));
  break;
case SVE::BI__builtin_sve_svdot_lane_u32:
ImmChecks.push_back(std::make_tuple(3, 9, 8));
  break;
case SVE::BI__builtin_sve_svdot_lane_u64:
ImmChecks.push_back(std::make_tuple(3, 9, 16));
  break;
case SVE::BI__builtin_sve_svext_bf16:
ImmChecks.push_back(std::make_tuple(2, 2, 16));
  break;
case SVE::BI__builtin_sve_svext_f16:
ImmChecks.push_back(std::make_tuple(2, 2, 16));
  break;
case SVE::BI__builtin_sve_svext_f32:
ImmChecks.push_back(std::make_tuple(2, 2, 32));
  break;
case SVE::BI__builtin_sve_svext_f64:
ImmChecks.push_back(std::make_tuple(2, 2, 64));
  break;
case SVE::BI__builtin_sve_svext_s16:
ImmChecks.push_back(std::make_tuple(2, 2, 16));
  break;
case SVE::BI__builtin_sve_svext_s32:
ImmChecks.push_back(std::make_tuple(2, 2, 32));
  break;
case SVE::BI__builtin_sve_svext_s64:
ImmChecks.push_back(std::make_tuple(2, 2, 64));
  break;
case SVE::BI__builtin_sve_svext_s8:
ImmChecks.push_back(std::make_tuple(2, 2, 8));
  break;
case SVE::BI__builtin_sve_svext_u16:
ImmChecks.push_back(std::make_tuple(2, 2, 16));
  break;
case SVE::BI__builtin_sve_svext_u32:
ImmChecks.push_back(std::make_tuple(2, 2, 32));
  break;
case SVE::BI__builtin_sve_svext_u64:
ImmChecks.push_back(std::make_tuple(2, 2, 64));
  break;
case SVE::BI__builtin_sve_svext_u8:
ImmChecks.push_back(std::make_tuple(2, 2, 8));
  break;
case SVE::BI__builtin_sve_svget2_bf16:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_f16:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_f32:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_f64:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_s16:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_s32:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_s64:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_s8:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_u16:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_u32:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_u64:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget2_u8:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svget3_bf16:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_f16:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_f32:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_f64:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_s16:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_s32:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_s64:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_s8:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_u16:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_u32:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_u64:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget3_u8:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svget4_bf16:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_f16:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_f32:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_f64:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_s16:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_s32:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_s64:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_s8:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_u16:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_u32:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_u64:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svget4_u8:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svmla_lane_f16:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmla_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmla_lane_f64:
ImmChecks.push_back(std::make_tuple(3, 7, 64));
  break;
case SVE::BI__builtin_sve_svmla_lane_s16:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmla_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmla_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 64));
  break;
case SVE::BI__builtin_sve_svmla_lane_u16:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmla_lane_u32:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmla_lane_u64:
ImmChecks.push_back(std::make_tuple(3, 7, 64));
  break;
case SVE::BI__builtin_sve_svmlalb_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlalb_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlalb_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmlalb_lane_u32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlalb_lane_u64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmlalt_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlalt_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlalt_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmlalt_lane_u32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlalt_lane_u64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmls_lane_f16:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmls_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmls_lane_f64:
ImmChecks.push_back(std::make_tuple(3, 7, 64));
  break;
case SVE::BI__builtin_sve_svmls_lane_s16:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmls_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmls_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 64));
  break;
case SVE::BI__builtin_sve_svmls_lane_u16:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmls_lane_u32:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmls_lane_u64:
ImmChecks.push_back(std::make_tuple(3, 7, 64));
  break;
case SVE::BI__builtin_sve_svmlslb_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlslb_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlslb_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmlslb_lane_u32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlslb_lane_u64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmlslt_lane_f32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlslt_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlslt_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmlslt_lane_u32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svmlslt_lane_u64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svmul_lane_f16:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svmul_lane_f32:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svmul_lane_f64:
ImmChecks.push_back(std::make_tuple(2, 7, 64));
  break;
case SVE::BI__builtin_sve_svmul_lane_s16:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svmul_lane_s32:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svmul_lane_s64:
ImmChecks.push_back(std::make_tuple(2, 7, 64));
  break;
case SVE::BI__builtin_sve_svmul_lane_u16:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svmul_lane_u32:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svmul_lane_u64:
ImmChecks.push_back(std::make_tuple(2, 7, 64));
  break;
case SVE::BI__builtin_sve_svmullb_lane_s32:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svmullb_lane_s64:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svmullb_lane_u32:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svmullb_lane_u64:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svmullt_lane_s32:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svmullt_lane_s64:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svmullt_lane_u32:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svmullt_lane_u64:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svprfb:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfb_gather_s32offset:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfb_gather_s64offset:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfb_gather_u32base:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfb_gather_u32base_offset:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfb_gather_u32offset:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfb_gather_u64base:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfb_gather_u64base_offset:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfb_gather_u64offset:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfb_vnum:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd_gather_s32index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd_gather_s64index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd_gather_u32base:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd_gather_u32base_index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd_gather_u32index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd_gather_u64base:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd_gather_u64base_index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd_gather_u64index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfd_vnum:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh_gather_s32index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh_gather_s64index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh_gather_u32base:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh_gather_u32base_index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh_gather_u32index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh_gather_u64base:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh_gather_u64base_index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh_gather_u64index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfh_vnum:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw_gather_s32index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw_gather_s64index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw_gather_u32base:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw_gather_u32base_index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw_gather_u32index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw_gather_u64base:
ImmChecks.push_back(std::make_tuple(2, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw_gather_u64base_index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw_gather_u64index:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svprfw_vnum:
ImmChecks.push_back(std::make_tuple(3, 12, 0));
  break;
case SVE::BI__builtin_sve_svptrue_pat_b16:
ImmChecks.push_back(std::make_tuple(0, 0, 0));
  break;
case SVE::BI__builtin_sve_svptrue_pat_b32:
ImmChecks.push_back(std::make_tuple(0, 0, 0));
  break;
case SVE::BI__builtin_sve_svptrue_pat_b64:
ImmChecks.push_back(std::make_tuple(0, 0, 0));
  break;
case SVE::BI__builtin_sve_svptrue_pat_b8:
ImmChecks.push_back(std::make_tuple(0, 0, 0));
  break;
case SVE::BI__builtin_sve_svqcadd_s16:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svqcadd_s32:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svqcadd_s64:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svqcadd_s8:
ImmChecks.push_back(std::make_tuple(2, 10, 0));
  break;
case SVE::BI__builtin_sve_svqdecb_n_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecb_n_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecb_n_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecb_n_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecb_pat_n_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecb_pat_n_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecb_pat_n_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecb_pat_n_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_n_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_n_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_n_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_n_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_pat_n_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_pat_n_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_pat_n_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_pat_n_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_pat_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_pat_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecd_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdech_n_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdech_n_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdech_n_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdech_n_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdech_pat_n_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdech_pat_n_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdech_pat_n_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdech_pat_n_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdech_pat_s16:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdech_pat_u16:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdech_s16:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdech_u16:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_n_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_n_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_n_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_n_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_pat_n_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_pat_n_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_pat_n_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_pat_n_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_pat_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_pat_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdecw_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqdmlalb_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svqdmlalb_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svqdmlalt_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svqdmlalt_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svqdmlslb_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svqdmlslb_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svqdmlslt_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svqdmlslt_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svqdmulh_lane_s16:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svqdmulh_lane_s32:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svqdmulh_lane_s64:
ImmChecks.push_back(std::make_tuple(2, 7, 64));
  break;
case SVE::BI__builtin_sve_svqdmullb_lane_s32:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svqdmullb_lane_s64:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svqdmullt_lane_s32:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svqdmullt_lane_s64:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svqincb_n_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincb_n_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincb_n_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincb_n_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincb_pat_n_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincb_pat_n_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincb_pat_n_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincb_pat_n_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincd_n_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincd_n_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincd_n_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincd_n_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincd_pat_n_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincd_pat_n_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincd_pat_n_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincd_pat_n_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincd_pat_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincd_pat_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincd_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincd_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqinch_n_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqinch_n_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqinch_n_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqinch_n_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqinch_pat_n_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqinch_pat_n_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqinch_pat_n_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqinch_pat_n_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqinch_pat_s16:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqinch_pat_u16:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqinch_s16:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqinch_u16:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincw_n_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincw_n_s64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincw_n_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincw_n_u64:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincw_pat_n_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincw_pat_n_s64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincw_pat_n_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincw_pat_n_u64:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincw_pat_s32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincw_pat_u32:
ImmChecks.push_back(std::make_tuple(2, 1, 0));
ImmChecks.push_back(std::make_tuple(1, 0, 0));
  break;
case SVE::BI__builtin_sve_svqincw_s32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqincw_u32:
ImmChecks.push_back(std::make_tuple(1, 1, 0));
  break;
case SVE::BI__builtin_sve_svqrdcmlah_lane_s16:
ImmChecks.push_back(std::make_tuple(3, 8, 16));
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svqrdcmlah_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 8, 32));
ImmChecks.push_back(std::make_tuple(4, 11, 0));
  break;
case SVE::BI__builtin_sve_svqrdcmlah_s16:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svqrdcmlah_s32:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svqrdcmlah_s64:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svqrdcmlah_s8:
ImmChecks.push_back(std::make_tuple(3, 11, 0));
  break;
case SVE::BI__builtin_sve_svqrdmlah_lane_s16:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svqrdmlah_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svqrdmlah_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 64));
  break;
case SVE::BI__builtin_sve_svqrdmlsh_lane_s16:
ImmChecks.push_back(std::make_tuple(3, 7, 16));
  break;
case SVE::BI__builtin_sve_svqrdmlsh_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 7, 32));
  break;
case SVE::BI__builtin_sve_svqrdmlsh_lane_s64:
ImmChecks.push_back(std::make_tuple(3, 7, 64));
  break;
case SVE::BI__builtin_sve_svqrdmulh_lane_s16:
ImmChecks.push_back(std::make_tuple(2, 7, 16));
  break;
case SVE::BI__builtin_sve_svqrdmulh_lane_s32:
ImmChecks.push_back(std::make_tuple(2, 7, 32));
  break;
case SVE::BI__builtin_sve_svqrdmulh_lane_s64:
ImmChecks.push_back(std::make_tuple(2, 7, 64));
  break;
case SVE::BI__builtin_sve_svqrshrnb_n_s16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svqrshrnb_n_s32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svqrshrnb_n_s64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svqrshrnb_n_u16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svqrshrnb_n_u32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svqrshrnb_n_u64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svqrshrnt_n_s16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svqrshrnt_n_s32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svqrshrnt_n_s64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svqrshrnt_n_u16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svqrshrnt_n_u32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svqrshrnt_n_u64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svqrshrunb_n_s16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svqrshrunb_n_s32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svqrshrunb_n_s64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svqrshrunt_n_s16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svqrshrunt_n_s32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svqrshrunt_n_s64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s16_m:
ImmChecks.push_back(std::make_tuple(2, 5, 16));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s16_x:
ImmChecks.push_back(std::make_tuple(2, 5, 16));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s16_z:
ImmChecks.push_back(std::make_tuple(2, 5, 16));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s32_m:
ImmChecks.push_back(std::make_tuple(2, 5, 32));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s32_x:
ImmChecks.push_back(std::make_tuple(2, 5, 32));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s32_z:
ImmChecks.push_back(std::make_tuple(2, 5, 32));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s64_m:
ImmChecks.push_back(std::make_tuple(2, 5, 64));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s64_x:
ImmChecks.push_back(std::make_tuple(2, 5, 64));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s64_z:
ImmChecks.push_back(std::make_tuple(2, 5, 64));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s8_m:
ImmChecks.push_back(std::make_tuple(2, 5, 8));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s8_x:
ImmChecks.push_back(std::make_tuple(2, 5, 8));
  break;
case SVE::BI__builtin_sve_svqshlu_n_s8_z:
ImmChecks.push_back(std::make_tuple(2, 5, 8));
  break;
case SVE::BI__builtin_sve_svqshrnb_n_s16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svqshrnb_n_s32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svqshrnb_n_s64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svqshrnb_n_u16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svqshrnb_n_u32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svqshrnb_n_u64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svqshrnt_n_s16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svqshrnt_n_s32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svqshrnt_n_s64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svqshrnt_n_u16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svqshrnt_n_u32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svqshrnt_n_u64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svqshrunb_n_s16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svqshrunb_n_s32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svqshrunb_n_s64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svqshrunt_n_s16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svqshrunt_n_s32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svqshrunt_n_s64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svrshr_n_s16_m:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svrshr_n_s16_x:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svrshr_n_s16_z:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svrshr_n_s32_m:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svrshr_n_s32_x:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svrshr_n_s32_z:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svrshr_n_s64_m:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svrshr_n_s64_x:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svrshr_n_s64_z:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svrshr_n_s8_m:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svrshr_n_s8_x:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svrshr_n_s8_z:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svrshr_n_u16_m:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svrshr_n_u16_x:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svrshr_n_u16_z:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svrshr_n_u32_m:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svrshr_n_u32_x:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svrshr_n_u32_z:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svrshr_n_u64_m:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svrshr_n_u64_x:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svrshr_n_u64_z:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svrshr_n_u8_m:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svrshr_n_u8_x:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svrshr_n_u8_z:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svrshrnb_n_s16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svrshrnb_n_s32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svrshrnb_n_s64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svrshrnb_n_u16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svrshrnb_n_u32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svrshrnb_n_u64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svrshrnt_n_s16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svrshrnt_n_s32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svrshrnt_n_s64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svrshrnt_n_u16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svrshrnt_n_u32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svrshrnt_n_u64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svrsra_n_s16:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svrsra_n_s32:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svrsra_n_s64:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svrsra_n_s8:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svrsra_n_u16:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svrsra_n_u32:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svrsra_n_u64:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svrsra_n_u8:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svset2_bf16:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_f16:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_f32:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_f64:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_s16:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_s32:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_s64:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_s8:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_u16:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_u32:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_u64:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset2_u8:
ImmChecks.push_back(std::make_tuple(1, 13, 0));
  break;
case SVE::BI__builtin_sve_svset3_bf16:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_f16:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_f32:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_f64:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_s16:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_s32:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_s64:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_s8:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_u16:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_u32:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_u64:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset3_u8:
ImmChecks.push_back(std::make_tuple(1, 14, 0));
  break;
case SVE::BI__builtin_sve_svset4_bf16:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_f16:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_f32:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_f64:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_s16:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_s32:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_s64:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_s8:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_u16:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_u32:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_u64:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svset4_u8:
ImmChecks.push_back(std::make_tuple(1, 15, 0));
  break;
case SVE::BI__builtin_sve_svshllb_n_s16:
ImmChecks.push_back(std::make_tuple(1, 5, 8));
  break;
case SVE::BI__builtin_sve_svshllb_n_s32:
ImmChecks.push_back(std::make_tuple(1, 5, 16));
  break;
case SVE::BI__builtin_sve_svshllb_n_s64:
ImmChecks.push_back(std::make_tuple(1, 5, 32));
  break;
case SVE::BI__builtin_sve_svshllb_n_u16:
ImmChecks.push_back(std::make_tuple(1, 5, 8));
  break;
case SVE::BI__builtin_sve_svshllb_n_u32:
ImmChecks.push_back(std::make_tuple(1, 5, 16));
  break;
case SVE::BI__builtin_sve_svshllb_n_u64:
ImmChecks.push_back(std::make_tuple(1, 5, 32));
  break;
case SVE::BI__builtin_sve_svshllt_n_s16:
ImmChecks.push_back(std::make_tuple(1, 5, 8));
  break;
case SVE::BI__builtin_sve_svshllt_n_s32:
ImmChecks.push_back(std::make_tuple(1, 5, 16));
  break;
case SVE::BI__builtin_sve_svshllt_n_s64:
ImmChecks.push_back(std::make_tuple(1, 5, 32));
  break;
case SVE::BI__builtin_sve_svshllt_n_u16:
ImmChecks.push_back(std::make_tuple(1, 5, 8));
  break;
case SVE::BI__builtin_sve_svshllt_n_u32:
ImmChecks.push_back(std::make_tuple(1, 5, 16));
  break;
case SVE::BI__builtin_sve_svshllt_n_u64:
ImmChecks.push_back(std::make_tuple(1, 5, 32));
  break;
case SVE::BI__builtin_sve_svshrnb_n_s16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svshrnb_n_s32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svshrnb_n_s64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svshrnb_n_u16:
ImmChecks.push_back(std::make_tuple(1, 4, 16));
  break;
case SVE::BI__builtin_sve_svshrnb_n_u32:
ImmChecks.push_back(std::make_tuple(1, 4, 32));
  break;
case SVE::BI__builtin_sve_svshrnb_n_u64:
ImmChecks.push_back(std::make_tuple(1, 4, 64));
  break;
case SVE::BI__builtin_sve_svshrnt_n_s16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svshrnt_n_s32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svshrnt_n_s64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svshrnt_n_u16:
ImmChecks.push_back(std::make_tuple(2, 4, 16));
  break;
case SVE::BI__builtin_sve_svshrnt_n_u32:
ImmChecks.push_back(std::make_tuple(2, 4, 32));
  break;
case SVE::BI__builtin_sve_svshrnt_n_u64:
ImmChecks.push_back(std::make_tuple(2, 4, 64));
  break;
case SVE::BI__builtin_sve_svsli_n_s16:
ImmChecks.push_back(std::make_tuple(2, 5, 16));
  break;
case SVE::BI__builtin_sve_svsli_n_s32:
ImmChecks.push_back(std::make_tuple(2, 5, 32));
  break;
case SVE::BI__builtin_sve_svsli_n_s64:
ImmChecks.push_back(std::make_tuple(2, 5, 64));
  break;
case SVE::BI__builtin_sve_svsli_n_s8:
ImmChecks.push_back(std::make_tuple(2, 5, 8));
  break;
case SVE::BI__builtin_sve_svsli_n_u16:
ImmChecks.push_back(std::make_tuple(2, 5, 16));
  break;
case SVE::BI__builtin_sve_svsli_n_u32:
ImmChecks.push_back(std::make_tuple(2, 5, 32));
  break;
case SVE::BI__builtin_sve_svsli_n_u64:
ImmChecks.push_back(std::make_tuple(2, 5, 64));
  break;
case SVE::BI__builtin_sve_svsli_n_u8:
ImmChecks.push_back(std::make_tuple(2, 5, 8));
  break;
case SVE::BI__builtin_sve_svsra_n_s16:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svsra_n_s32:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svsra_n_s64:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svsra_n_s8:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svsra_n_u16:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svsra_n_u32:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svsra_n_u64:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svsra_n_u8:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svsri_n_s16:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svsri_n_s32:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svsri_n_s64:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svsri_n_s8:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svsri_n_u16:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svsri_n_u32:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svsri_n_u64:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svsri_n_u8:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svsudot_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 9, 8));
  break;
case SVE::BI__builtin_sve_svtmad_f16:
ImmChecks.push_back(std::make_tuple(2, 6, 0));
  break;
case SVE::BI__builtin_sve_svtmad_f32:
ImmChecks.push_back(std::make_tuple(2, 6, 0));
  break;
case SVE::BI__builtin_sve_svtmad_f64:
ImmChecks.push_back(std::make_tuple(2, 6, 0));
  break;
case SVE::BI__builtin_sve_svusdot_lane_s32:
ImmChecks.push_back(std::make_tuple(3, 9, 8));
  break;
case SVE::BI__builtin_sve_svxar_n_s16:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svxar_n_s32:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svxar_n_s64:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svxar_n_s8:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
case SVE::BI__builtin_sve_svxar_n_u16:
ImmChecks.push_back(std::make_tuple(2, 3, 16));
  break;
case SVE::BI__builtin_sve_svxar_n_u32:
ImmChecks.push_back(std::make_tuple(2, 3, 32));
  break;
case SVE::BI__builtin_sve_svxar_n_u64:
ImmChecks.push_back(std::make_tuple(2, 3, 64));
  break;
case SVE::BI__builtin_sve_svxar_n_u8:
ImmChecks.push_back(std::make_tuple(2, 3, 8));
  break;
#endif

