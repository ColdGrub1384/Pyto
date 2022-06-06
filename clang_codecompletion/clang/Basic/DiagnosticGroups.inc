
#ifdef GET_DIAG_ARRAYS
static const int16_t DiagArrays[] = {
  /* Empty */ -1,
  /* DiagArray1 */ diag::warn_pragma_message, -1,
  /* DiagArray2 */ diag::pp_hash_warning, -1,
  /* DiagArray3 */ diag::warn_cfstring_truncated, -1,
  /* DiagArray5 */ diag::warn_independentclass_attribute, diag::warn_ptr_independentclass_attribute, -1,
  /* DiagArray6 */ diag::warn_nsobject_attribute, -1,
  /* DiagArray8 */ diag::warn_abs_too_small, diag::warn_pointer_abs, diag::warn_unsigned_abs, diag::warn_wrong_absolute_value_type, -1,
  /* DiagArray9 */ diag::warn_abstract_final_class, -1,
  /* DiagArray10 */ diag::warn_abstract_vbase_init_ignored, -1,
  /* DiagArray12 */ diag::warn_taking_address_of_packed_member, -1,
  /* DiagArray13 */ diag::ext_typecheck_addrof_temporary, -1,
  /* DiagArray15 */ diag::warn_not_xl_compatible, diag::warn_pragma_align_not_xl_compatible, -1,
  /* DiagArray16 */ diag::warn_param_mismatched_alignment, -1,
  /* DiagArray18 */ diag::warn_alloca, -1,
  /* DiagArray19 */ diag::warn_alloca_align_alignof, -1,
  /* DiagArray20 */ diag::warn_ambiguous_suitable_delete_function_found, -1,
  /* DiagArray21 */ diag::warn_misplaced_ellipsis_vararg, -1,
  /* DiagArray22 */ diag::warn_pp_ambiguous_macro, -1,
  /* DiagArray23 */ diag::ext_nested_name_member_ref_lookup_ambiguous, -1,
  /* DiagArray24 */ diag::ext_ovl_ambiguous_oper_binary_reversed, -1,
  /* DiagArray25 */ diag::warn_incompatible_analyzer_plugin_api, -1,
  /* DiagArray26 */ diag::warn_arith_conv_mixed_anon_enum_types, -1,
  /* DiagArray27 */ diag::ext_abstract_pack_declarator_parens, -1,
  /* DiagArray29 */ diag::warn_arc_bridge_cast_nonarc, -1,
  /* DiagArray30 */ diag::warn_arc_possible_repeated_use_of_weak, -1,
  /* DiagArray31 */ diag::warn_arc_object_memaccess, -1,
  /* DiagArray32 */ diag::warn_arc_perform_selector_leaks, -1,
  /* DiagArray33 */ diag::warn_arc_repeated_use_of_weak, -1,
  /* DiagArray34 */ diag::warn_arc_retain_cycle, -1,
  /* DiagArray35 */ diag::warn_arc_literal_assign, diag::warn_arc_retained_assign, diag::warn_arc_retained_property_assign, -1,
  /* DiagArray36 */ diag::warn_argument_invalid_range, -1,
  /* DiagArray37 */ diag::warn_argument_undefined_behaviour, -1,
  /* DiagArray38 */ diag::warn_array_index_exceeds_bounds, diag::warn_array_index_exceeds_max_addressable_bounds, diag::warn_array_index_precedes_bounds, diag::warn_ptr_arith_exceeds_max_addressable_bounds, diag::warn_static_array_too_small, -1,
  /* DiagArray39 */ diag::warn_ptr_arith_exceeds_bounds, diag::warn_ptr_arith_precedes_bounds, -1,
  /* DiagArray41 */ diag::warn_asm_mismatched_size_modifier, -1,
  /* DiagArray42 */ diag::warn_not_in_enum_assignment, -1,
  /* DiagArray43 */ diag::warn_assume_side_effects, -1,
  /* DiagArray45 */ diag::warn_atimport_in_framework_header, -1,
  /* DiagArray46 */ diag::warn_atomic_op_misaligned, diag::warn_atomic_op_oversized, -1,
  /* DiagArray47 */ diag::warn_atomic_implicit_seq_cst, -1,
  /* DiagArray48 */ diag::warn_atomic_op_has_invalid_memory_order, -1,
  /* DiagArray50 */ diag::warn_atomic_property_rule, -1,
  /* DiagArray51 */ diag::warn_attribute_packed_for_bitfield, -1,
  /* DiagArray52 */ diag::warn_fe_backend_warning_attr, -1,
  /* DiagArray54 */ diag::warn_drv_disabling_vptr_no_rtti_default, -1,
  /* DiagArray55 */ diag::warn_auto_module_import, -1,
  /* DiagArray56 */ diag::ext_auto_storage_class, -1,
  /* DiagArray57 */ diag::warn_auto_var_is_id, -1,
  /* DiagArray58 */ diag::warn_availability_and_unavailable, diag::warn_availability_fuchsia_unavailable_minor, diag::warn_availability_on_static_initializer, diag::warn_availability_swift_unavailable_deprecated_only, diag::warn_availability_unknown_platform, diag::warn_availability_version_ordering, diag::warn_expected_consistent_version_separator, diag::warn_mismatched_availability, diag::warn_mismatched_availability_override, diag::warn_mismatched_availability_override_unavail, -1,
  /* DiagArray59 */ diag::warn_drv_avr_family_linking_stdlibs_not_implemented, diag::warn_drv_avr_gcc_not_found, diag::warn_drv_avr_libc_not_found, diag::warn_drv_avr_linker_section_addresses_not_implemented, diag::warn_drv_avr_mcu_not_specified, diag::warn_drv_avr_stdlib_not_linked, -1,
  /* DiagArray60 */ diag::warn_fe_backend_plugin, -1,
  /* DiagArray61 */ diag::backslash_newline_space, -1,
  /* DiagArray62 */ diag::warn_bad_function_cast, -1,
  /* DiagArray64 */ diag::ext_rvalue_to_reference_access_ctor, diag::ext_rvalue_to_reference_temp_copy_no_viable, -1,
  /* DiagArray65 */ diag::ext_decomp_decl_cond, -1,
  /* DiagArray66 */ diag::ext_bit_int, -1,
  /* DiagArray67 */ diag::warn_impcast_bitfield_precision_constant, -1,
  /* DiagArray68 */ diag::warn_bitfield_too_small_for_enum, diag::warn_signed_bitfield_enum_conversion, diag::warn_unsigned_bitfield_assigned_signed_enum, -1,
  /* DiagArray69 */ diag::warn_bitfield_width_exceeds_type_width, -1,
  /* DiagArray70 */ diag::warn_precedence_bitwise_conditional, -1,
  /* DiagArray71 */ diag::warn_bitwise_instead_of_logical, -1,
  /* DiagArray72 */ diag::warn_bitwise_op_in_bitwise_op, -1,
  /* DiagArray73 */ diag::warn_block_capture_autoreleasing, -1,
  /* DiagArray74 */ diag::warn_impcast_bool_to_null_pointer, -1,
  /* DiagArray76 */ diag::warn_bitwise_negation_bool, -1,
  /* DiagArray77 */ diag::warn_braces_around_init, -1,
  /* DiagArray78 */ diag::warn_unsupported_branch_protection, diag::warn_unsupported_branch_protection_spec, -1,
  /* DiagArray79 */ diag::warn_objc_invalid_bridge, diag::warn_objc_invalid_bridge_to_cf, -1,
  /* DiagArray80 */ diag::warn_assume_aligned_too_great, -1,
  /* DiagArray81 */ diag::ext_pp_redef_builtin_macro, diag::ext_pp_undef_builtin_macro, -1,
  /* DiagArray82 */ diag::warn_builtin_chk_overflow, -1,
  /* DiagArray83 */ diag::warn_implicit_decl_requires_sysheader, -1,
  /* DiagArray84 */ diag::warn_zero_size_struct_union_compat, -1,
  /* DiagArray88 */ diag::ext_old_implicitly_unsigned_long_cxx, diag::warn_auto_storage_class, diag::warn_cxx11_compat_user_defined_literal, diag::warn_cxx11_keyword, diag::warn_cxx11_right_shift_in_template_arg, diag::warn_explicit_instantiation_inline_0x, diag::warn_explicit_instantiation_must_be_global_0x, diag::warn_explicit_instantiation_out_of_scope_0x, diag::warn_explicit_instantiation_unqualified_wrong_namespace_0x, diag::warn_old_implicitly_unsigned_long_cxx, -1,
  /* DiagArray89 */ diag::warn_deprecated_string_literal_conversion, -1,
  /* DiagArray91 */ diag::warn_cxx11_compat_reserved_user_defined_literal, -1,
  /* DiagArray92 */ diag::ext_alias_declaration, diag::ext_array_size_conversion, diag::ext_auto_type_specifier, diag::ext_cxx11_enum_fixed_underlying_type, diag::ext_defaulted_deleted_function, diag::ext_enum_friend, diag::ext_enumerator_list_comma_cxx, diag::ext_explicit_conversion_functions, diag::ext_extern_template, diag::ext_for_range, diag::ext_generalized_initializer_lists, diag::ext_nested_name_spec_is_enum, diag::ext_nonclass_type_friend, diag::ext_nonstatic_member_init, diag::ext_override_control_keyword, diag::ext_ref_qualifier, diag::ext_rvalue_reference, diag::ext_scoped_enum, diag::ext_static_data_member_in_union, diag::ext_template_arg_object_internal, diag::ext_template_outside_of_template, diag::ext_template_parameter_default_in_function_template, diag::ext_typename_outside_of_template, diag::ext_unelaborated_friend_type, diag::ext_variadic_templates, -1,
  /* DiagArray93 */ diag::ext_extra_semi_cxx11, -1,
  /* DiagArray94 */ diag::ext_inline_namespace, -1,
  /* DiagArray95 */ diag::ext_cxx11_longlong, -1,
  /* DiagArray96 */ diag::ext_cce_narrowing, diag::ext_init_list_constant_narrowing, diag::ext_init_list_type_narrowing, diag::ext_init_list_variable_narrowing, diag::warn_init_list_constant_narrowing, diag::warn_init_list_type_narrowing, diag::warn_init_list_variable_narrowing, -1,
  /* DiagArray97 */ diag::ext_cxx14_attr, -1,
  /* DiagArray98 */ diag::ext_binary_literal_cxx14, -1,
  /* DiagArray101 */ diag::ext_constexpr_body_invalid_stmt, diag::ext_constexpr_body_multiple_return, diag::ext_constexpr_local_var, diag::ext_constexpr_type_definition, diag::ext_decltype_auto_type_specifier, diag::ext_init_capture, diag::ext_variable_template, -1,
  /* DiagArray102 */ diag::ext_cxx17_attr, -1,
  /* DiagArray104 */ diag::warn_cxx17_compat_exception_spec_in_signature, -1,
  /* DiagArray106 */ diag::ext_auto_new_list_init, diag::ext_constexpr_if, diag::ext_constexpr_on_lambda_cxx17, diag::ext_cxx_static_assert_no_message, diag::ext_decomp_decl, diag::ext_fold_expression, diag::ext_for_range_begin_end_types_differ, diag::ext_hex_literal_invalid, diag::ext_init_statement, diag::ext_inline_variable, diag::ext_multi_using_declaration, diag::ext_nested_namespace_definition, diag::ext_ns_enum_attribute, diag::ext_star_this_lambda_capture_cxx17, diag::ext_template_template_param_typename, diag::ext_using_attribute_ns, diag::ext_using_declaration_pack, -1,
  /* DiagArray111 */ diag::ext_cxx20_attr, -1,
  /* DiagArray112 */ diag::warn_cxx20_compat_aggregate_init_with_ctors, diag::warn_cxx20_compat_consteval, diag::warn_cxx20_compat_constinit, diag::warn_cxx20_compat_explicit_bool, diag::warn_cxx20_compat_spaceship, diag::warn_cxx20_compat_utf8_string, diag::warn_cxx20_keyword, -1,
  /* DiagArray114 */ diag::ext_cxx_designated_init, -1,
  /* DiagArray115 */ diag::ext_adl_only_template_id, diag::ext_bitfield_member_init, diag::ext_constexpr_body_invalid_stmt_cxx20, diag::ext_constexpr_ctor_missing_init, diag::ext_constexpr_function_try_block_cxx20, diag::ext_constexpr_local_var_no_init, diag::ext_constexpr_union_ctor_no_init, diag::ext_decomp_decl_spec, diag::ext_defaulted_comparison, diag::ext_equals_this_lambda_capture_cxx20, diag::ext_explicit_bool, diag::ext_for_range_init_stmt, diag::ext_init_capture_pack, diag::ext_inline_nested_namespace_definition, diag::ext_lambda_template_parameter_list, diag::ext_pointer_to_const_ref_member_on_rvalue, diag::ext_using_decl_class_member_enumerator, diag::ext_using_decl_scoped_enumerator, diag::ext_using_enum_declaration, -1,
  /* DiagArray119 */ diag::ext_alias_in_init_statement, diag::ext_consteval_if, diag::ext_cxx2b_size_t_suffix, diag::ext_decl_attrs_on_lambda, diag::ext_lambda_missing_parens, -1,
  /* DiagArray125 */ diag::warn_cxx11_compat_binary_literal, -1,
  /* DiagArray127 */ diag::warn_cxx98_compat_alias_declaration, diag::warn_cxx98_compat_alignas, diag::warn_cxx98_compat_alignof, diag::warn_cxx98_compat_attribute, diag::warn_cxx98_compat_auto_type_specifier, diag::warn_cxx98_compat_constexpr, diag::warn_cxx98_compat_ctor_list_init, diag::warn_cxx98_compat_decltype, diag::warn_cxx98_compat_defaulted_deleted_function, diag::warn_cxx98_compat_delegating_ctor, diag::warn_cxx98_compat_empty_scalar_initializer, diag::warn_cxx98_compat_empty_sizeless_initializer, diag::warn_cxx98_compat_enum_fixed_underlying_type, diag::warn_cxx98_compat_enum_friend, diag::warn_cxx98_compat_enum_nested_name_spec, diag::warn_cxx98_compat_explicit_conversion_functions, diag::warn_cxx98_compat_for_range, diag::warn_cxx98_compat_friend_is_member, diag::warn_cxx98_compat_generalized_initializer_lists, diag::warn_cxx98_compat_goto_into_protected_scope, diag::warn_cxx98_compat_indirect_goto_in_protected_scope, diag::warn_cxx98_compat_initializer_list_init, diag::warn_cxx98_compat_inline_namespace, diag::warn_cxx98_compat_lambda, diag::warn_cxx98_compat_less_colon_colon, diag::warn_cxx98_compat_literal_operator, diag::warn_cxx98_compat_literal_ucn_control_character, diag::warn_cxx98_compat_literal_ucn_escape_basic_scs, diag::warn_cxx98_compat_noexcept_decl, diag::warn_cxx98_compat_noexcept_expr, diag::warn_cxx98_compat_non_static_member_use, diag::warn_cxx98_compat_nonclass_type_friend, diag::warn_cxx98_compat_nonstatic_member_init, diag::warn_cxx98_compat_nontrivial_union_or_anon_struct_member, diag::warn_cxx98_compat_nullptr, diag::warn_cxx98_compat_override_control_keyword, diag::warn_cxx98_compat_pass_non_pod_arg_to_vararg, diag::warn_cxx98_compat_raw_string_literal, diag::warn_cxx98_compat_ref_qualifier, diag::warn_cxx98_compat_reference_list_init, diag::warn_cxx98_compat_rvalue_reference, diag::warn_cxx98_compat_scoped_enum, diag::warn_cxx98_compat_sfinae_access_control, diag::warn_cxx98_compat_static_assert, diag::warn_cxx98_compat_static_data_member_in_union, diag::warn_cxx98_compat_switch_into_protected_scope, diag::warn_cxx98_compat_template_arg_extra_parens, diag::warn_cxx98_compat_template_arg_null, diag::warn_cxx98_compat_template_arg_object_internal, diag::warn_cxx98_compat_template_outside_of_template, diag::warn_cxx98_compat_template_parameter_default_in_function_template, diag::warn_cxx98_compat_trailing_return_type, diag::warn_cxx98_compat_two_right_angle_brackets, diag::warn_cxx98_compat_typename_outside_of_template, diag::warn_cxx98_compat_unelaborated_friend_type, diag::warn_cxx98_compat_unicode_literal, diag::warn_cxx98_compat_unicode_type, diag::warn_cxx98_compat_using_decl_constructor, diag::warn_cxx98_compat_variadic_templates, -1,
  /* DiagArray128 */ diag::warn_cxx98_compat_temp_copy, -1,
  /* DiagArray129 */ diag::warn_cxx98_compat_top_level_semi, -1,
  /* DiagArray130 */ diag::warn_cxx98_compat_template_arg_local_type, -1,
  /* DiagArray131 */ diag::warn_cxx98_compat_array_size_conversion, diag::warn_cxx98_compat_cast_fn_obj, diag::warn_cxx98_compat_empty_fnmacro_arg, diag::warn_cxx98_compat_enumerator_list_comma, diag::warn_cxx98_compat_extern_template, diag::warn_cxx98_compat_longlong, diag::warn_cxx98_compat_no_newline_eof, diag::warn_cxx98_compat_pp_line_too_big, diag::warn_cxx98_compat_variadic_macro, -1,
  /* DiagArray132 */ diag::warn_cxx98_compat_template_arg_unnamed_type, -1,
  /* DiagArray133 */ diag::ext_anonymous_union, diag::ext_c11_anonymous_struct, diag::ext_c11_feature, diag::ext_typecheck_compare_complete_incomplete_pointers, -1,
  /* DiagArray134 */ diag::ext_c_static_assert_no_message, diag::ext_parameter_name_omitted_c2x, -1,
  /* DiagArray135 */ diag::warn_c99_compat_unicode_id, diag::warn_c99_compat_unicode_literal, diag::warn_old_implicitly_unsigned_long, -1,
  /* DiagArray136 */ diag::ext_designated_init, diag::ext_designated_init_array, diag::ext_designated_init_brace_elision, diag::ext_designated_init_mixed, diag::ext_designated_init_nested, -1,
  /* DiagArray137 */ diag::ext_aggregate_init_not_constant, diag::ext_c99_array_usage, diag::ext_c99_compound_literal, diag::ext_c99_feature, diag::ext_c99_flexible_array_member, diag::ext_c99_variable_decl_in_for_loop, diag::ext_c99_whitespace_required_after_macro_name, diag::ext_empty_fnmacro_arg, diag::ext_enumerator_list_comma_c, diag::ext_hex_constant_invalid, -1,
  /* DiagArray138 */ diag::warn_call_to_pure_virtual_member_function_from_ctor_dtor, -1,
  /* DiagArray139 */ diag::warn_called_once_gets_called_twice, diag::warn_called_once_never_called, diag::warn_called_once_never_called_when, -1,
  /* DiagArray140 */ diag::warn_cast_align, -1,
  /* DiagArray141 */ diag::warn_cast_calling_conv, -1,
  /* DiagArray142 */ diag::warn_cast_function_type, -1,
  /* DiagArray143 */ diag::warn_cast_pointer_from_sel, -1,
  /* DiagArray144 */ diag::warn_cast_qual, diag::warn_cast_qual2, -1,
  /* DiagArray145 */ diag::ext_bad_cxx_cast_qualifiers_away_incoherent, -1,
  /* DiagArray147 */ diag::warn_omp_section_is_char, diag::warn_subscript_is_char, -1,
  /* DiagArray148 */ diag::warn_drv_yc_multiple_inputs_clang_cl, diag::warn_drv_ycyu_different_arg_clang_cl, diag::warn_pp_hdrstop_filename_ignored, diag::warn_pp_macro_def_mismatch_with_pch, -1,
  /* DiagArray149 */ diag::warn_conv_to_base_not_used, diag::warn_conv_to_self_not_used, diag::warn_conv_to_void_not_used, -1,
  /* DiagArray150 */ diag::warn_pass_class_arg_to_vararg, -1,
  /* DiagArray151 */ diag::warn_cmse_nonsecure_union, -1,
  /* DiagArray152 */ diag::warn_comma_operator, -1,
  /* DiagArray153 */ diag::escaped_newline_block_comment_end, diag::ext_line_comment, diag::ext_multi_line_line_comment, diag::warn_nested_block_comment, -1,
  /* DiagArray155 */ diag::ext_typecheck_comparison_of_distinct_pointers, -1,
  /* DiagArray156 */ diag::warn_completion_handler_called_twice, diag::warn_completion_handler_never_called, diag::warn_completion_handler_never_called_when, -1,
  /* DiagArray157 */ diag::ext_complex_component_init, -1,
  /* DiagArray159 */ diag::warn_compound_token_split_by_macro, -1,
  /* DiagArray160 */ diag::warn_compound_token_split_by_whitespace, -1,
  /* DiagArray161 */ diag::ext_concept_legacy_bool_keyword, -1,
  /* DiagArray162 */ diag::ext_typecheck_cond_pointer_integer_mismatch, -1,
  /* DiagArray163 */ diag::warn_maybe_uninit_var, -1,
  /* DiagArray164 */ diag::warn_module_config_macro_undef, -1,
  /* DiagArray165 */ diag::warn_impcast_integer_precision_constant, -1,
  /* DiagArray166 */ diag::warn_is_constant_evaluated_always_true_constexpr, -1,
  /* DiagArray167 */ diag::warn_logical_instead_of_bitwise, -1,
  /* DiagArray168 */ diag::warn_cxx14_compat_constexpr_not_const, -1,
  /* DiagArray169 */ diag::warn_attr_on_unconsumable_class, diag::warn_loop_state_mismatch, diag::warn_param_return_typestate_mismatch, diag::warn_param_typestate_mismatch, diag::warn_return_typestate_for_unconsumable_type, diag::warn_return_typestate_mismatch, diag::warn_use_in_invalid_state, diag::warn_use_of_temp_in_invalid_state, -1,
  /* DiagArray170 */ diag::warn_impcast_complex_scalar, diag::warn_impcast_vector_scalar, diag::warn_opencl_generic_address_space_arg, diag::warn_template_arg_negative, diag::warn_template_arg_too_large, -1,
  /* DiagArray172 */ diag::warn_coroutine_handle_address_invalid_return_type, -1,
  /* DiagArray173 */ diag::warn_coroutine_promise_unhandled_exception_required_with_exceptions, -1,
  /* DiagArray174 */ diag::warn_unreachable_default, -1,
  /* DiagArray176 */ diag::warn_objc_cdirective_format_string, -1,
  /* DiagArray177 */ diag::warn_ctad_maybe_unsupported, -1,
  /* DiagArray179 */ diag::warn_ctu_incompat_triple, -1,
  /* DiagArray180 */ diag::warn_attribute_argument_n_negative, diag::warn_cuda_attr_lambda_position, diag::warn_kern_is_inline, diag::warn_kern_is_method, diag::warn_pragma_unroll_cuda_value_in_parens, -1,
  /* DiagArray181 */ diag::warn_default_atomic_custom_getter_setter, -1,
  /* DiagArray182 */ diag::ext_cxx11_attr_placement, -1,
  /* DiagArray183 */ diag::warn_dangling_variable, diag::warn_unsupported_lifetime_extension, -1,
  /* DiagArray184 */ diag::warn_dangling_else, -1,
  /* DiagArray185 */ diag::warn_bind_ref_member_to_parameter, diag::warn_dangling_member, diag::warn_init_ptr_member_to_parameter_addr, diag::warn_new_dangling_reference, -1,
  /* DiagArray186 */ diag::warn_dangling_lifetime_pointer, diag::warn_dangling_lifetime_pointer_member, -1,
  /* DiagArray187 */ diag::warn_new_dangling_initializer_list, -1,
  /* DiagArray188 */ diag::warn_drv_darwin_sdk_invalid_settings, -1,
  /* DiagArray189 */ diag::warn_pp_date_time, -1,
  /* DiagArray190 */ diag::warn_dealloc_in_category, -1,
  /* DiagArray191 */ diag::warn_debug_compression_unavailable, -1,
  /* DiagArray192 */ diag::ext_mixed_decls_code, -1,
  /* DiagArray193 */ diag::warn_defaulted_comparison_deleted, diag::warn_defaulted_method_deleted, -1,
  /* DiagArray194 */ diag::warn_delegating_ctor_cycle, -1,
  /* DiagArray195 */ diag::warn_delete_abstract_non_virtual_dtor, -1,
  /* DiagArray196 */ diag::ext_delete_void_ptr_operand, diag::warn_delete_incomplete, -1,
  /* DiagArray197 */ diag::warn_delete_non_virtual_dtor, -1,
  /* DiagArray199 */ diag::ext_delimited_escape_sequence, -1,
  /* DiagArray200 */ diag::warn_O4_is_O3, diag::warn_access_decl_deprecated, diag::warn_deprecated_redundant_constexpr_static_def, diag::warn_drv_deprecated_arg, diag::warn_drv_treating_input_as_cxx, diag::warn_fe_concepts_ts_flag, diag::warn_option_invalid_ocl_version, diag::warn_vector_long_decl_spec_combination, -1,
  /* DiagArray201 */ diag::warn_deprecated_altivec_src_compat, -1,
  /* DiagArray202 */ diag::warn_arith_conv_mixed_anon_enum_types_cxx20, -1,
  /* DiagArray203 */ diag::warn_depr_array_comparison, -1,
  /* DiagArray204 */ diag::warn_vector_mode_deprecated, -1,
  /* DiagArray205 */ diag::warn_deprecated_comma_subscript, -1,
  /* DiagArray206 */ diag::warn_deprecated_copy, -1,
  /* DiagArray208 */ diag::warn_deprecated_copy_with_dtor, -1,
  /* DiagArray209 */ diag::warn_deprecated_copy_with_user_provided_copy, -1,
  /* DiagArray210 */ diag::warn_deprecated_copy_with_user_provided_dtor, -1,
  /* DiagArray211 */ diag::warn_deprecated_for_co_await, -1,
  /* DiagArray212 */ diag::warn_atl_uuid_deprecated, diag::warn_cstyle_param, diag::warn_deprecated, diag::warn_deprecated_fwdclass_message, diag::warn_deprecated_message, diag::warn_property_method_deprecated, -1,
  /* DiagArray213 */ diag::warn_exception_spec_deprecated, -1,
  /* DiagArray214 */ diag::warn_comparison_mixed_enum_types_cxx20, -1,
  /* DiagArray215 */ diag::warn_conditional_mixed_enum_types_cxx20, -1,
  /* DiagArray216 */ diag::warn_arith_conv_mixed_enum_types_cxx20, -1,
  /* DiagArray217 */ diag::warn_arith_conv_enum_float_cxx20, -1,
  /* DiagArray218 */ diag::warn_deprecated_coroutine_namespace, -1,
  /* DiagArray219 */ diag::warn_deprecated_def, diag::warn_unavailable_def, -1,
  /* DiagArray220 */ diag::warn_increment_bool, -1,
  /* DiagArray221 */ diag::warn_objc_isa_assign, diag::warn_objc_isa_use, -1,
  /* DiagArray222 */ diag::warn_objc_pointer_masking, -1,
  /* DiagArray223 */ diag::warn_objc_pointer_masking_performSelector, -1,
  /* DiagArray224 */ diag::warn_pragma_deprecated_macro_use, -1,
  /* DiagArray225 */ diag::warn_deprecated_register, -1,
  /* DiagArray226 */ diag::warn_deprecated_this_capture, -1,
  /* DiagArray227 */ diag::warn_ext_int_deprecated, -1,
  /* DiagArray228 */ diag::warn_deprecated_compound_assign_volatile, diag::warn_deprecated_increment_decrement_volatile, diag::warn_deprecated_simple_assign_volatile, diag::warn_deprecated_volatile_param, diag::warn_deprecated_volatile_return, diag::warn_deprecated_volatile_structured_binding, -1,
  /* DiagArray230 */ diag::warn_direct_ivar_access, -1,
  /* DiagArray231 */ diag::pp_disabled_macro_expansion, -1,
  /* DiagArray234 */ diag::warn_conflicting_param_modifiers, diag::warn_conflicting_ret_type_modifiers, -1,
  /* DiagArray236 */ diag::warn_remainder_division_by_zero, -1,
  /* DiagArray237 */ diag::warn_attribute_dll_redeclaration, -1,
  /* DiagArray238 */ diag::warn_attribute_dllexport_explicit_instantiation_decl, -1,
  /* DiagArray239 */ diag::warn_attribute_dllimport_static_field_definition, -1,
  /* DiagArray240 */ diag::warn_doc_api_container_decl_mismatch, diag::warn_doc_block_command_duplicate, diag::warn_doc_block_command_empty_paragraph, diag::warn_doc_container_decl_mismatch, diag::warn_doc_function_method_decl_mismatch, diag::warn_doc_html_start_tag_expected_ident_or_greater, diag::warn_doc_html_start_tag_expected_quoted_string, diag::warn_doc_inline_contents_no_argument, diag::warn_doc_param_duplicate, diag::warn_doc_param_invalid_direction, diag::warn_doc_param_not_attached_to_a_function_decl, diag::warn_doc_param_not_found, diag::warn_doc_returns_attached_to_a_void_function, diag::warn_doc_returns_not_attached_to_a_function_decl, diag::warn_doc_tparam_duplicate, diag::warn_doc_tparam_not_attached_to_a_template_decl, diag::warn_doc_tparam_not_found, diag::warn_not_a_doxygen_trailing_member_comment, diag::warn_verbatim_block_end_without_start, -1,
  /* DiagArray241 */ diag::warn_doc_deprecated_not_sync, -1,
  /* DiagArray242 */ diag::warn_doc_html_end_forbidden, diag::warn_doc_html_end_unbalanced, diag::warn_doc_html_missing_end_tag, diag::warn_doc_html_start_end_mismatch, -1,
  /* DiagArray243 */ diag::warn_doc_param_spaces_in_direction, -1,
  /* DiagArray244 */ diag::warn_correct_comment_command_name, diag::warn_unknown_comment_command_name, -1,
  /* DiagArray245 */ diag::ext_dollar_in_identifier, -1,
  /* DiagArray246 */ diag::warn_impcast_double_promotion, -1,
  /* DiagArray247 */ diag::ext_dtor_name_ambiguous, diag::ext_dtor_named_in_wrong_scope, diag::ext_qualified_dtor_named_in_lexical_scope, -1,
  /* DiagArray248 */ diag::ext_destructor_typedef_name, -1,
  /* DiagArray249 */ diag::ext_duplicate_declspec, diag::ext_warn_duplicate_declspec, diag::warn_attribute_address_multiple_identical_qualifiers, diag::warn_duplicate_declspec, -1,
  /* DiagArray250 */ diag::warn_duplicate_enum_values, -1,
  /* DiagArray251 */ diag::warn_method_param_declaration, -1,
  /* DiagArray252 */ diag::warn_duplicate_method_decl, -1,
  /* DiagArray253 */ diag::warn_duplicate_protocol_def, -1,
  /* DiagArray254 */ diag::warn_dyn_class_memaccess, -1,
  /* DiagArray255 */ diag::ext_dynamic_exception_spec, -1,
  /* DiagArray257 */ diag::ext_enum_base_in_type_specifier, -1,
  /* DiagArray258 */ diag::ext_elaborated_enum_class, -1,
  /* DiagArray259 */ diag::ext_embedded_directive, -1,
  /* DiagArray260 */ diag::warn_empty_for_body, diag::warn_empty_if_body, diag::warn_empty_range_based_for_body, diag::warn_empty_switch_body, diag::warn_empty_while_body, -1,
  /* DiagArray261 */ diag::ext_decomp_decl_empty, -1,
  /* DiagArray262 */ diag::warn_empty_init_statement, -1,
  /* DiagArray263 */ diag::ext_empty_translation_unit, -1,
  /* DiagArray264 */ diag::warn_incomplete_encoded_type, -1,
  /* DiagArray266 */ diag::warn_comparison_mixed_enum_types, -1,
  /* DiagArray267 */ diag::warn_conditional_mixed_enum_types, -1,
  /* DiagArray268 */ diag::warn_comparison_of_mixed_enum_types_switch, -1,
  /* DiagArray269 */ diag::warn_impcast_different_enum_types, -1,
  /* DiagArray270 */ diag::warn_arith_conv_mixed_enum_types, -1,
  /* DiagArray271 */ diag::warn_arith_conv_enum_float, -1,
  /* DiagArray272 */ diag::ext_enum_too_large, diag::ext_enumerator_increment_too_large, -1,
  /* DiagArray273 */ diag::warn_cdtor_function_try_handler_mem_expr, diag::warn_exception_caught_by_earlier_handler, diag::warn_throw_in_noexcept_func, -1,
  /* DiagArray274 */ diag::ext_excess_initializers, diag::ext_excess_initializers_for_sizeless_type, diag::ext_excess_initializers_in_char_array_initializer, diag::ext_initializer_string_for_char_array_too_long, -1,
  /* DiagArray275 */ diag::warn_exit_time_destructor, -1,
  /* DiagArray276 */ diag::warn_defined_in_function_type_macro, diag::warn_defined_in_object_type_macro, -1,
  /* DiagArray277 */ diag::warn_direct_initialize_call, diag::warn_direct_super_initialize_call, -1,
  /* DiagArray278 */ diag::warn_arc_strong_pointer_objc_pointer, -1,
  /* DiagArray279 */ diag::ext_export_no_name_block, diag::ext_export_no_names, -1,
  /* DiagArray280 */ diag::ext_export_using_directive, -1,
  /* DiagArray281 */ diag::warn_zero_size_struct_union_in_extern_c, -1,
  /* DiagArray282 */ diag::warn_extern_init, -1,
  /* DiagArray283 */ diag::warn_arm_interrupt_calling_convention, -1,
  /* DiagArray284 */ diag::warn_namespace_member_extra_qualification, -1,
  /* DiagArray285 */ diag::ext_extra_semi, diag::warn_extra_semi_after_mem_fn_def, -1,
  /* DiagArray286 */ diag::warn_null_statement, -1,
  /* DiagArray287 */ diag::ext_pp_extra_tokens_at_eol, diag::warn_omp_extra_tokens_at_eol, -1,
  /* DiagArray288 */ diag::warn_final_dtor_non_final_class, -1,
  /* DiagArray289 */ diag::warn_pragma_final_macro, -1,
  /* DiagArray290 */ diag::ext_clang_c_enum_fixed_underlying_type, -1,
  /* DiagArray291 */ diag::warn_fixedpoint_constant_overflow, -1,
  /* DiagArray292 */ diag::warn_flag_enum_constant_out_of_range, -1,
  /* DiagArray293 */ diag::ext_flexible_array_in_array, diag::ext_flexible_array_in_struct, -1,
  /* DiagArray294 */ diag::warn_impcast_float_integer, -1,
  /* DiagArray295 */ diag::warn_floatingpoint_eq, -1,
  /* DiagArray296 */ diag::warn_impcast_float_to_integer, diag::warn_impcast_float_to_integer_out_of_range, -1,
  /* DiagArray297 */ diag::warn_impcast_float_to_integer_zero, -1,
  /* DiagArray298 */ diag::warn_redundant_loop_iteration, diag::warn_variables_not_in_loop_body, -1,
  /* DiagArray299 */ diag::warn_format_P_no_precision, diag::warn_format_argument_needs_cast, diag::warn_format_bool_as_character, diag::warn_format_conversion_argument_type_mismatch, diag::warn_format_invalid_annotation, diag::warn_format_invalid_positional_specifier, diag::warn_format_mix_positional_nonpositional_args, diag::warn_format_nonsensical_length, diag::warn_format_string_is_wide_literal, diag::warn_format_zero_positional_specifier, diag::warn_missing_format_string, diag::warn_printf_ObjCflags_without_ObjCConversion, diag::warn_printf_asterisk_missing_arg, diag::warn_printf_asterisk_wrong_type, diag::warn_printf_empty_objc_flag, diag::warn_printf_format_string_contains_null_char, diag::warn_printf_format_string_not_null_terminated, diag::warn_printf_ignored_flag, diag::warn_printf_incomplete_specifier, diag::warn_printf_invalid_objc_flag, diag::warn_printf_nonsensical_flag, diag::warn_printf_nonsensical_optional_amount, diag::warn_printf_positional_arg_exceeds_data_args, diag::warn_scanf_nonzero_width, diag::warn_scanf_scanlist_incomplete, -1,
  /* DiagArray300 */ diag::warn_printf_data_arg_not_used, -1,
  /* DiagArray301 */ diag::warn_printf_insufficient_data_args, -1,
  /* DiagArray302 */ diag::warn_format_invalid_conversion, -1,
  /* DiagArray303 */ diag::warn_format_non_standard, diag::warn_format_non_standard_conversion_spec, diag::warn_format_non_standard_positional_arg, -1,
  /* DiagArray304 */ diag::warn_format_nonliteral, -1,
  /* DiagArray305 */ diag::warn_format_argument_needs_cast_pedantic, diag::warn_format_conversion_argument_type_mismatch_pedantic, -1,
  /* DiagArray306 */ diag::warn_format_nonliteral_noargs, -1,
  /* DiagArray307 */ diag::warn_format_conversion_argument_type_mismatch_confusion, -1,
  /* DiagArray309 */ diag::warn_empty_format_string, -1,
  /* DiagArray311 */ diag::warn_fortify_scanf_overflow, diag::warn_fortify_source_format_overflow, diag::warn_fortify_source_overflow, diag::warn_fortify_source_size_mismatch, diag::warn_fortify_strlen_overflow, -1,
  /* DiagArray312 */ diag::warn_four_char_character_literal, -1,
  /* DiagArray313 */ diag::warn_frame_address, -1,
  /* DiagArray314 */ diag::warn_fe_backend_frame_larger_than, diag::warn_fe_frame_larger_than, -1,
  /* DiagArray316 */ diag::warn_framework_include_private_from_public, -1,
  /* DiagArray317 */ diag::warn_free_nonheap_object, -1,
  /* DiagArray318 */ diag::warn_function_def_in_objc_container, -1,
  /* DiagArray319 */ diag::warn_dispatch_body_ignored, diag::warn_multiversion_duplicate_entries, diag::warn_target_clone_duplicate_options, -1,
  /* DiagArray320 */ diag::warn_drv_fuse_ld_path, -1,
  /* DiagArray323 */ diag::ext_clang_diagnose_if, diag::ext_clang_enable_if, diag::ext_warn_gnu_final, diag::warn_attribute_on_function_definition, diag::warn_break_binds_to_switch, diag::warn_cleanup_ext, diag::warn_gcc_attribute_location, diag::warn_gcc_ignores_type_attr, diag::warn_gcc_variable_decl_in_for_loop, diag::warn_loop_ctrl_binds_to_inner, -1,
  /* DiagArray324 */ diag::warn_global_constructor, diag::warn_global_destructor, -1,
  /* DiagArray325 */ diag::warn_drv_global_isel_incomplete, diag::warn_drv_global_isel_incomplete_opt, -1,
  /* DiagArray327 */ diag::ext_alignof_expr, -1,
  /* DiagArray328 */ diag::ext_gnu_anonymous_struct, -1,
  /* DiagArray329 */ diag::ext_array_init_parens, -1,
  /* DiagArray330 */ diag::ext_auto_type, -1,
  /* DiagArray331 */ diag::ext_binary_literal, -1,
  /* DiagArray332 */ diag::ext_gnu_case_range, -1,
  /* DiagArray333 */ diag::ext_integer_complex, -1,
  /* DiagArray334 */ diag::ext_array_init_copy, -1,
  /* DiagArray335 */ diag::ext_gnu_conditional_expr, -1,
  /* DiagArray336 */ diag::ext_gnu_array_range, diag::ext_gnu_missing_equal_designator, diag::ext_gnu_old_style_field_designator, -1,
  /* DiagArray337 */ diag::ext_gnu_empty_initializer, -1,
  /* DiagArray338 */ diag::ext_empty_struct_union, diag::ext_flexible_array_empty_aggregate_gnu, diag::ext_no_named_members_in_struct_union, -1,
  /* DiagArray339 */ diag::ext_flexible_array_init, -1,
  /* DiagArray340 */ diag::ext_flexible_array_union_gnu, -1,
  /* DiagArray341 */ diag::ext_expr_not_ice, diag::ext_in_class_initializer_non_constant, diag::ext_vla_folded_to_constant, -1,
  /* DiagArray342 */ diag::ext_imaginary_constant, -1,
  /* DiagArray343 */ diag::ext_pp_include_next_directive, -1,
  /* DiagArray344 */ diag::warn_gnu_inline_cplusplus_without_extern, -1,
  /* DiagArray345 */ diag::ext_gnu_address_of_label, diag::ext_gnu_indirect_goto, -1,
  /* DiagArray346 */ diag::ext_forward_ref_enum_def, -1,
  /* DiagArray347 */ diag::ext_gnu_statement_expr, -1,
  /* DiagArray348 */ diag::ext_in_class_initializer_float_type, -1,
  /* DiagArray349 */ diag::ext_string_literal_operator_template, -1,
  /* DiagArray350 */ diag::ext_typecheck_cast_to_union, -1,
  /* DiagArray351 */ diag::ext_variable_sized_type_in_struct, -1,
  /* DiagArray352 */ diag::ext_pp_line_zero, -1,
  /* DiagArray353 */ diag::ext_missing_varargs_arg, diag::ext_paste_comma, -1,
  /* DiagArray354 */ diag::warn_maybe_capture_bad_target_this_ptr, -1,
  /* DiagArray355 */ diag::warn_header_guard, -1,
  /* DiagArray356 */ diag::warn_using_directive_in_header, -1,
  /* DiagArray357 */ diag::warn_ignored_hip_only_option, -1,
  /* DiagArray358 */ diag::warn_condition_is_idiomatic_assignment, -1,
  /* DiagArray359 */ diag::ext_cannot_use_trivial_abi, diag::warn_alias_to_weak_alias, diag::warn_alias_with_section, diag::warn_aligned_attr_underaligned, diag::warn_attr_abi_tag_namespace, diag::warn_attribute_after_definition_ignored, diag::warn_attribute_cmse_entry_static, diag::warn_attribute_dllexport_explicit_instantiation_def, diag::warn_attribute_has_no_effect_on_compile_time_if, diag::warn_attribute_has_no_effect_on_infinite_loop, diag::warn_attribute_iboutlet, diag::warn_attribute_ignored, diag::warn_attribute_ignored_for_field_of_type, diag::warn_attribute_ignored_on_inline, diag::warn_attribute_ignored_on_non_definition, diag::warn_attribute_invalid_on_definition, diag::warn_attribute_no_decl, diag::warn_attribute_nonnull_no_pointers, diag::warn_attribute_nonnull_parm_no_args, diag::warn_attribute_not_on_decl, diag::warn_attribute_pointer_or_reference_only, diag::warn_attribute_pointers_only, diag::warn_attribute_precede_definition, diag::warn_attribute_return_pointers_only, diag::warn_attribute_return_pointers_refs_only, diag::warn_attribute_sentinel_named_arguments, diag::warn_attribute_sentinel_not_variadic, diag::warn_attribute_type_not_supported, diag::warn_attribute_unknown_visibility, diag::warn_attribute_void_function_method, diag::warn_attribute_weak_on_field, diag::warn_attribute_weak_on_local, diag::warn_attribute_wrong_decl_type, diag::warn_attribute_wrong_decl_type_str, diag::warn_attributes_likelihood_ifstmt_conflict, diag::warn_block_literal_attributes_on_omitted_return_type, diag::warn_cconv_unsupported, diag::warn_cxx11_gnu_attribute_on_type, diag::warn_declspec_allocator_nonpointer, diag::warn_declspec_attribute_ignored, diag::warn_deprecated_anonymous_namespace, diag::warn_deprecated_ignored_on_using, diag::warn_dllimport_dropped_from_inline_function, diag::warn_duplicate_attribute, diag::warn_duplicate_attribute_exact, diag::warn_gc_attribute_weak_on_local, diag::warn_gnu_inline_attribute_requires_inline, diag::warn_ignored_ms_inheritance, diag::warn_ignored_objc_externally_retained, diag::warn_import_on_definition, diag::warn_internal_linkage_local_storage, diag::warn_interrupt_attribute_invalid, diag::warn_microsoft_qualifiers_ignored, diag::warn_mig_server_routine_does_not_return_kern_return_t, diag::warn_mismatched_import, diag::warn_mmap_unknown_attribute, diag::warn_nocf_check_attribute_ignored, diag::warn_noderef_on_non_pointer_or_array, diag::warn_nomerge_attribute_ignored_in_stmt, diag::warn_nothrow_attribute_ignored, diag::warn_ns_attribute_wrong_parameter_type, diag::warn_ns_attribute_wrong_return_type, diag::warn_objc_direct_ignored, diag::warn_objc_direct_property_ignored, diag::warn_opencl_attr_deprecated_ignored, diag::warn_require_const_init_added_too_late, diag::warn_riscv_repeated_interrupt_attribute, diag::warn_sycl_kernel_invalid_template_param_type, diag::warn_sycl_kernel_num_of_function_params, diag::warn_sycl_kernel_num_of_template_params, diag::warn_sycl_kernel_return_type, diag::warn_transparent_union_attribute_field_size_align, diag::warn_transparent_union_attribute_floating, diag::warn_transparent_union_attribute_not_definition, diag::warn_transparent_union_attribute_zero_fields, diag::warn_type_attribute_wrong_type, diag::warn_unhandled_ms_attribute_ignored, diag::warn_unsupported_target_attribute, diag::warn_wrong_clang_attr_namespace, -1,
  /* DiagArray360 */ diag::warn_missing_sdksettings_for_availability_checking, -1,
  /* DiagArray361 */ diag::warn_drv_unsupported_opt_for_target, diag::warn_ignored_gcc_optimization, -1,
  /* DiagArray362 */ diag::warn_pragma_intrinsic_builtin, -1,
  /* DiagArray363 */ diag::warn_pragma_optimize, -1,
  /* DiagArray364 */ diag::warn_pragma_align_expected_equal, diag::warn_pragma_align_invalid_option, diag::warn_pragma_comment_ignored, diag::warn_pragma_debug_missing_argument, diag::warn_pragma_debug_unexpected_command, diag::warn_pragma_debug_unknown_module, diag::warn_pragma_expected_action_or_r_paren, diag::warn_pragma_expected_colon, diag::warn_pragma_expected_colon_r_paren, diag::warn_pragma_expected_comma, diag::warn_pragma_expected_identifier, diag::warn_pragma_expected_init_seg, diag::warn_pragma_expected_integer, diag::warn_pragma_expected_lparen, diag::warn_pragma_expected_non_wide_string, diag::warn_pragma_expected_predicate, diag::warn_pragma_expected_punc, diag::warn_pragma_expected_rparen, diag::warn_pragma_expected_section_label_or_name, diag::warn_pragma_expected_section_name, diag::warn_pragma_expected_section_push_pop_or_name, diag::warn_pragma_expected_string, diag::warn_pragma_extra_tokens_at_eol, diag::warn_pragma_force_cuda_host_device_bad_arg, diag::warn_pragma_fp_ignored, diag::warn_pragma_init_seg_unsupported_target, diag::warn_pragma_invalid_action, diag::warn_pragma_invalid_argument, diag::warn_pragma_invalid_specific_action, diag::warn_pragma_missing_argument, diag::warn_pragma_ms_fenv_access, diag::warn_pragma_ms_struct, diag::warn_pragma_options_align_reset_failed, diag::warn_pragma_options_expected_align, diag::warn_pragma_pack_invalid_alignment, diag::warn_pragma_pack_malformed, diag::warn_pragma_pop_failed, diag::warn_pragma_pop_macro_no_push, diag::warn_pragma_unknown_extension, diag::warn_pragma_unsupported_action, diag::warn_pragma_unsupported_extension, diag::warn_pragma_unused_expected_var, diag::warn_pragma_unused_expected_var_arg, diag::warn_pragma_unused_undeclared_var, diag::warn_stdc_unknown_rounding_mode, -1,
  /* DiagArray365 */ diag::warn_arc_lifetime_result_type, diag::warn_block_literal_qualifiers_on_omitted_return_type, diag::warn_qual_return_type, diag::warn_typecheck_function_qualifiers_ignored, -1,
  /* DiagArray366 */ diag::warn_typecheck_reference_qualifiers, -1,
  /* DiagArray368 */ diag::warn_auto_implicit_atomic_property, diag::warn_implicit_atomic_property, -1,
  /* DiagArray369 */ diag::warn_impcast_integer_float_precision_constant, -1,
  /* DiagArray370 */ diag::warn_impcast_floating_point_to_bool, -1,
  /* DiagArray371 */ diag::ext_implicit_exception_spec_mismatch, -1,
  /* DiagArray372 */ diag::warn_unannotated_fallthrough, -1,
  /* DiagArray373 */ diag::warn_unannotated_fallthrough_per_function, -1,
  /* DiagArray374 */ diag::warn_impcast_fixed_point_range, -1,
  /* DiagArray375 */ diag::warn_impcast_float_precision, diag::warn_impcast_float_result_precision, -1,
  /* DiagArray376 */ diag::ext_implicit_function_decl, diag::ext_implicit_lib_function_decl, diag::warn_builtin_unknown, diag::warn_implicit_function_decl, -1,
  /* DiagArray377 */ diag::ext_missing_type_specifier, -1,
  /* DiagArray378 */ diag::warn_impcast_high_order_zero_bits, diag::warn_impcast_integer_precision, -1,
  /* DiagArray379 */ diag::warn_impcast_integer_float_precision, -1,
  /* DiagArray380 */ diag::warn_implicitly_retains_self, -1,
  /* DiagArray381 */ diag::ext_integer_literal_too_large_for_signed, -1,
  /* DiagArray383 */ diag::ext_pp_import_directive, -1,
  /* DiagArray384 */ diag::warn_inaccessible_base_class, -1,
  /* DiagArray385 */ diag::pp_include_next_absolute_path, -1,
  /* DiagArray386 */ diag::pp_include_next_in_primary, -1,
  /* DiagArray387 */ diag::warn_deep_exception_specs_differ, diag::warn_incompatible_exception_specs, -1,
  /* DiagArray388 */ diag::ext_typecheck_convert_incompatible_function_pointer, -1,
  /* DiagArray389 */ diag::warn_redecl_library_builtin, -1,
  /* DiagArray390 */ diag::warn_cxx_ms_struct, diag::warn_npot_ms_struct, -1,
  /* DiagArray391 */ diag::ext_typecheck_convert_incompatible_pointer, -1,
  /* DiagArray392 */ diag::ext_nested_pointer_qualifier_mismatch, diag::ext_typecheck_convert_discards_qualifiers, diag::warn_bad_cxx_cast_nested_pointer_addr_space, -1,
  /* DiagArray393 */ diag::warn_property_types_are_incompatible, -1,
  /* DiagArray394 */ diag::warn_incompatible_sysroot, -1,
  /* DiagArray395 */ diag::warn_mmap_incomplete_framework_module_declaration, -1,
  /* DiagArray396 */ diag::warn_undef_method_impl, -1,
  /* DiagArray398 */ diag::warn_implicit_decl_no_jmp_buf, -1,
  /* DiagArray399 */ diag::warn_missing_submodule, diag::warn_mmap_umbrella_dir_not_found, diag::warn_uncovered_module_header, -1,
  /* DiagArray400 */ diag::warn_redeclaration_without_attribute_prev_attribute_ignored, diag::warn_redeclaration_without_import_attribute, -1,
  /* DiagArray401 */ diag::warn_inconsistent_destructor_marked_not_override_overriding, -1,
  /* DiagArray402 */ diag::warn_inconsistent_function_marked_not_override_overriding, -1,
  /* DiagArray403 */ diag::ext_increment_bool, -1,
  /* DiagArray404 */ diag::warn_infinite_recursive_function, -1,
  /* DiagArray406 */ diag::ext_initializer_overrides, diag::warn_initializer_overrides, -1,
  /* DiagArray407 */ diag::ext_out_of_line_qualified_id_type_names_constructor, -1,
  /* DiagArray409 */ diag::warn_fe_inline_asm, -1,
  /* DiagArray410 */ diag::warn_inline_namespace_reopened_noninline, -1,
  /* DiagArray411 */ diag::ext_operator_new_delete_declared_inline, -1,
  /* DiagArray412 */ diag::warn_explicit_instantiation_after_specialization, -1,
  /* DiagArray413 */ diag::ext_typecheck_convert_int_pointer, diag::ext_typecheck_convert_pointer_int, -1,
  /* DiagArray415 */ diag::warn_enum_constant_in_bool_context, diag::warn_left_shift_in_bool_context, -1,
  /* DiagArray416 */ diag::warn_int_to_pointer_cast, -1,
  /* DiagArray417 */ diag::warn_int_to_void_pointer_cast, -1,
  /* DiagArray418 */ diag::warn_integer_constant_overflow, -1,
  /* DiagArray419 */ diag::warn_anyx86_interrupt_regsave, -1,
  /* DiagArray420 */ diag::warn_drv_missing_plugin_arg, diag::warn_drv_missing_plugin_name, diag::warn_drv_msp430_hwmult_mismatch, diag::warn_drv_msp430_hwmult_no_device, diag::warn_drv_msp430_hwmult_unsupported, diag::warn_drv_object_size_disabled_O0, diag::warn_drv_optimization_value, diag::warn_target_unsupported_extension, -1,
  /* DiagArray421 */ diag::ext_constexpr_function_never_constant_expr, -1,
  /* DiagArray422 */ diag::warn_iboutlet_object_type, diag::warn_iboutletcollection_property_assign, -1,
  /* DiagArray423 */ diag::warn_invalid_initializer_from_system_header, -1,
  /* DiagArray424 */ diag::warn_invalid_ios_deployment_target, -1,
  /* DiagArray425 */ diag::warn_attribute_no_builtin_invalid_builtin_name, -1,
  /* DiagArray426 */ diag::warn_falloff_noreturn_function, diag::warn_noreturn_function_has_return_expr, -1,
  /* DiagArray427 */ diag::ext_offsetof_non_pod_type, diag::ext_offsetof_non_standardlayout_type, -1,
  /* DiagArray428 */ diag::warn_drv_ps4_sdk_dir, diag::warn_drv_unable_to_find_directory_expected, -1,
  /* DiagArray429 */ diag::ext_partial_spec_not_more_specialized_than_primary, -1,
  /* DiagArray431 */ diag::ext_empty_character, diag::ext_unterminated_char_or_string, -1,
  /* DiagArray432 */ diag::warn_bad_character_encoding, diag::warn_bad_string_encoding, -1,
  /* DiagArray433 */ diag::ext_pp_bad_paste_ms, -1,
  /* DiagArray434 */ diag::warn_jump_out_of_seh_finally, -1,
  /* DiagArray435 */ diag::ext_keyword_as_ident, -1,
  /* DiagArray436 */ diag::warn_pp_macro_hides_keyword, -1,
  /* DiagArray437 */ diag::ext_param_promoted_not_compatible_with_prototype, -1,
  /* DiagArray438 */ diag::ext_token_used, -1,
  /* DiagArray439 */ diag::warn_parameter_size, diag::warn_return_value_size, -1,
  /* DiagArray441 */ diag::warn_fe_linking_module, -1,
  /* DiagArray442 */ diag::warn_impcast_literal_float_to_integer, diag::warn_impcast_literal_float_to_integer_out_of_range, -1,
  /* DiagArray443 */ diag::warn_float_overflow, diag::warn_float_underflow, -1,
  /* DiagArray444 */ diag::ext_template_arg_local_type, -1,
  /* DiagArray445 */ diag::warn_logical_not_on_lhs_of_check, -1,
  /* DiagArray446 */ diag::warn_logical_and_in_logical_or, -1,
  /* DiagArray447 */ diag::ext_c99_longlong, -1,
  /* DiagArray449 */ diag::ext_pp_macro_redef, -1,
  /* DiagArray450 */ diag::ext_main_used, diag::ext_noreturn_main, diag::ext_variadic_main, diag::warn_main_one_arg, diag::warn_main_redefined, diag::warn_main_returns_bool_literal, diag::warn_static_main, -1,
  /* DiagArray451 */ diag::ext_main_returns_nonint, -1,
  /* DiagArray452 */ diag::warn_has_warning_invalid_option, -1,
  /* DiagArray453 */ diag::ext_many_braces_around_init, -1,
  /* DiagArray454 */ diag::warn_max_tokens, diag::warn_max_tokens_total, -1,
  /* DiagArray455 */ diag::warn_max_unsigned_zero, -1,
  /* DiagArray456 */ diag::warn_suspicious_sizeof_memset, -1,
  /* DiagArray457 */ diag::warn_memsize_comparison, -1,
  /* DiagArray458 */ diag::warn_non_contravariant_param_types, diag::warn_non_covariant_ret_types, -1,
  /* DiagArray460 */ diag::ext_ms_abstract_keyword, -1,
  /* DiagArray461 */ diag::ext_anonymous_record_with_type, diag::ext_ms_anonymous_record, -1,
  /* DiagArray462 */ diag::ext_ms_cast_fn_obj, diag::ext_ms_impcast_fn_obj, -1,
  /* DiagArray463 */ diag::ext_charize_microsoft, -1,
  /* DiagArray464 */ diag::ext_comment_paste_microsoft, -1,
  /* DiagArray465 */ diag::ext_default_init_const, -1,
  /* DiagArray466 */ diag::ext_pp_operator_used_as_macro_name, -1,
  /* DiagArray467 */ diag::ext_param_default_argument_redefinition, -1,
  /* DiagArray468 */ diag::warn_attribute_section_drectve, -1,
  /* DiagArray469 */ diag::ext_ctrl_z_eof_microsoft, -1,
  /* DiagArray470 */ diag::ext_ms_forward_ref_enum, -1,
  /* DiagArray471 */ diag::ext_enumerator_too_large, -1,
  /* DiagArray472 */ diag::ext_ellipsis_exception_spec, diag::ext_incomplete_in_exception_spec, diag::ext_mismatched_exception_spec, diag::ext_mismatched_exception_spec_explicit_instantiation, diag::ext_override_exception_spec, -1,
  /* DiagArray473 */ diag::warn_microsoft_dependent_exists, -1,
  /* DiagArray474 */ diag::ext_ms_explicit_constructor_call, -1,
  /* DiagArray475 */ diag::warn_member_extra_qualification, -1,
  /* DiagArray476 */ diag::ext_ms_c_enum_fixed_underlying_type, -1,
  /* DiagArray477 */ diag::ext_flexible_array_empty_aggregate_ms, diag::ext_flexible_array_union_ms, -1,
  /* DiagArray478 */ diag::ext_goto_into_protected_scope, -1,
  /* DiagArray479 */ diag::ext_ms_ambiguous_direct_base, -1,
  /* DiagArray480 */ diag::ext_pp_include_search_ms, -1,
  /* DiagArray481 */ diag::ext_mutable_reference, -1,
  /* DiagArray482 */ diag::ext_pure_function_definition, -1,
  /* DiagArray483 */ diag::ext_static_non_static, -1,
  /* DiagArray484 */ diag::ext_ms_sealed_keyword, -1,
  /* DiagArray485 */ diag::ext_ms_static_assert, -1,
  /* DiagArray486 */ diag::ext_explicit_instantiation_duplicate, diag::ext_found_in_dependent_base, diag::ext_found_later_in_class, diag::ext_ms_delayed_template_argument, diag::ext_ms_deref_template_argument, diag::ext_ms_template_spec_redecl_out_of_scope, diag::ext_ms_template_type_arg_missing_typename, diag::ext_static_out_of_line, diag::ext_undeclared_unqual_id_with_dependent_base, -1,
  /* DiagArray487 */ diag::ext_template_param_shadow, -1,
  /* DiagArray488 */ diag::ext_union_member_of_reference_type, -1,
  /* DiagArray489 */ diag::ext_friend_tag_redecl_outside_namespace, -1,
  /* DiagArray490 */ diag::ext_ms_using_declaration_inaccessible, -1,
  /* DiagArray491 */ diag::ext_pseudo_dtor_on_void, -1,
  /* DiagArray492 */ diag::warn_misleading_indentation, -1,
  /* DiagArray493 */ diag::warn_mismatched_delete_new, -1,
  /* DiagArray494 */ diag::warn_conflicting_param_types, -1,
  /* DiagArray495 */ diag::warn_conflicting_ret_types, -1,
  /* DiagArray496 */ diag::warn_struct_class_previous_tag_mismatch, diag::warn_struct_class_tag_mismatch, -1,
  /* DiagArray497 */ diag::warn_missing_braces, -1,
  /* DiagArray498 */ diag::ext_constinit_missing, -1,
  /* DiagArray499 */ diag::ext_no_declarators, diag::ext_standalone_specifier, diag::ext_typedef_without_a_name, diag::warn_standalone_specifier, -1,
  /* DiagArray500 */ diag::ext_missing_exception_specification, -1,
  /* DiagArray501 */ diag::warn_missing_field_initializers, -1,
  /* DiagArray504 */ diag::warn_missing_method_return_type, -1,
  /* DiagArray505 */ diag::warn_overriding_method_missing_noescape, -1,
  /* DiagArray506 */ diag::warn_suggest_noreturn_block, diag::warn_suggest_noreturn_function, -1,
  /* DiagArray507 */ diag::warn_cconv_knr, -1,
  /* DiagArray508 */ diag::warn_missing_prototype, -1,
  /* DiagArray509 */ diag::warn_missing_selector_name, -1,
  /* DiagArray510 */ diag::warn_missing_sysroot, -1,
  /* DiagArray511 */ diag::warn_missing_variable_declarations, -1,
  /* DiagArray512 */ diag::warn_assume_attribute_string_unknown_suggested, -1,
  /* DiagArray513 */ diag::remark_module_build, diag::remark_module_build_done, diag::remark_module_lock_failure, diag::remark_module_lock_timeout, -1,
  /* DiagArray514 */ diag::warn_module_conflict, diag::warn_module_system_bit_conflict, -1,
  /* DiagArray515 */ diag::warn_module_config_mismatch, -1,
  /* DiagArray516 */ diag::warn_duplicate_module_file_extension, -1,
  /* DiagArray517 */ diag::remark_module_import, -1,
  /* DiagArray518 */ diag::ext_module_import_in_extern_c, -1,
  /* DiagArray519 */ diag::remark_module_lock, -1,
  /* DiagArray520 */ diag::ext_equivalent_internal_linkage_decl_in_modules, -1,
  /* DiagArray521 */ diag::ext_module_import_not_at_top_level_noop, -1,
  /* DiagArray525 */ diag::warn_drv_msvc_not_found, -1,
  /* DiagArray526 */ diag::warn_multichar_character_literal, -1,
  /* DiagArray527 */ diag::warn_vbase_moved_multiple_times, -1,
  /* DiagArray529 */ diag::ext_anonymous_record_with_anonymous_type, -1,
  /* DiagArray531 */ diag::warn_operator_new_returns_null, -1,
  /* DiagArray532 */ diag::ext_no_newline_eof, diag::warn_no_newline_eof, -1,
  /* DiagArray533 */ diag::warn_dereference_of_noderef_type, diag::warn_dereference_of_noderef_type_no_decl, diag::warn_noderef_to_dereferenceable_pointer, -1,
  /* DiagArray535 */ diag::ext_non_c_like_anon_struct_in_typedef, -1,
  /* DiagArray537 */ diag::warn_non_literal_null_pointer, -1,
  /* DiagArray538 */ diag::warn_non_modular_include_in_framework_module, -1,
  /* DiagArray539 */ diag::warn_non_modular_include_in_module, -1,
  /* DiagArray540 */ diag::warn_cannot_pass_non_pod_arg_to_vararg, diag::warn_non_pod_vararg_with_format_string, diag::warn_second_parameter_to_va_arg_not_pod, diag::warn_second_parameter_to_va_arg_ownership_qualified, -1,
  /* DiagArray541 */ diag::warn_alignment_not_power_of_two, -1,
  /* DiagArray542 */ diag::warn_non_virtual_dtor, -1,
  /* DiagArray543 */ diag::warn_null_arg, diag::warn_null_ret, -1,
  /* DiagArray545 */ diag::pp_nonportable_path, -1,
  /* DiagArray546 */ diag::pp_nonportable_system_path, -1,
  /* DiagArray547 */ diag::warn_neon_vector_initializer_non_portable, -1,
  /* DiagArray548 */ diag::warn_cstruct_memaccess, -1,
  /* DiagArray549 */ diag::warn_nsconsumed_attribute_mismatch, -1,
  /* DiagArray550 */ diag::warn_nsreturns_retained_attribute_mismatch, -1,
  /* DiagArray551 */ diag::warn_null_in_arithmetic_operation, diag::warn_null_in_comparison_operation, -1,
  /* DiagArray552 */ diag::null_in_char_or_string, diag::null_in_file, -1,
  /* DiagArray553 */ diag::warn_impcast_null_pointer_to_integer, -1,
  /* DiagArray554 */ diag::warn_binding_null_to_reference, diag::warn_indirection_through_null, -1,
  /* DiagArray555 */ diag::warn_gnu_null_ptr_arith, diag::warn_pointer_arith_null_ptr, -1,
  /* DiagArray556 */ diag::warn_pointer_sub_null_ptr, -1,
  /* DiagArray557 */ diag::warn_conflicting_nullability_attr_overriding_param_types, diag::warn_conflicting_nullability_attr_overriding_ret_types, diag::warn_mismatched_nullability_attr, diag::warn_null_resettable_setter, diag::warn_nullability_duplicate, -1,
  /* DiagArray558 */ diag::warn_nullability_missing, -1,
  /* DiagArray559 */ diag::warn_nullability_missing_array, -1,
  /* DiagArray560 */ diag::warn_nullability_declspec, -1,
  /* DiagArray561 */ diag::ext_nullability, -1,
  /* DiagArray562 */ diag::warn_nullability_inferred_on_nested_type, -1,
  /* DiagArray563 */ diag::warn_nullability_lost, -1,
  /* DiagArray564 */ diag::warn_autosynthesis_property_ivar_match, -1,
  /* DiagArray565 */ diag::warn_impcast_constant_value_to_objc_bool, -1,
  /* DiagArray566 */ diag::warn_objc_boxing_invalid_utf8_string, -1,
  /* DiagArray567 */ diag::warn_objc_circular_container, -1,
  /* DiagArray569 */ diag::warn_objc_designated_init_missing_super_call, diag::warn_objc_designated_init_non_designated_init_call, diag::warn_objc_designated_init_non_super_designated_init_call, diag::warn_objc_implementation_missing_designated_init_override, diag::warn_objc_secondary_init_missing_init_call, diag::warn_objc_secondary_init_super_init_call, -1,
  /* DiagArray570 */ diag::warn_nsdictionary_duplicate_key, -1,
  /* DiagArray571 */ diag::warn_superclass_variable_sized_type_not_at_end, diag::warn_variable_sized_ivar_visibility, -1,
  /* DiagArray572 */ diag::warn_forward_class_redefinition, -1,
  /* DiagArray573 */ diag::warn_ivars_in_interface, -1,
  /* DiagArray574 */ diag::warn_objc_literal_comparison, -1,
  /* DiagArray575 */ diag::warn_impcast_objective_c_literal_to_bool, diag::warn_objc_collection_literal_element, -1,
  /* DiagArray576 */ diag::warn_pp_objc_macro_redef_ignored, -1,
  /* DiagArray577 */ diag::warn_messaging_unqualified_id, -1,
  /* DiagArray578 */ diag::warn_class_method_not_found, diag::warn_class_method_not_found_with_typo, diag::warn_inst_method_not_found, diag::warn_instance_method_not_found_with_typo, diag::warn_instance_method_on_class_found, diag::warn_root_inst_method_not_found, -1,
  /* DiagArray579 */ diag::warn_missing_explicit_synthesis, -1,
  /* DiagArray580 */ diag::warn_objc_missing_super_call, -1,
  /* DiagArray581 */ diag::warn_multiple_method_decl, -1,
  /* DiagArray582 */ diag::warn_objc_property_retain_of_block, -1,
  /* DiagArray583 */ diag::warn_objc_pointer_cxx_catch_fragile, -1,
  /* DiagArray584 */ diag::warn_objc_property_assign_on_object, -1,
  /* DiagArray585 */ diag::warn_impl_required_for_class_property, diag::warn_impl_required_in_category_for_class_property, diag::warn_setter_getter_impl_required, diag::warn_setter_getter_impl_required_in_category, -1,
  /* DiagArray586 */ diag::warn_property_implicitly_mismatched, -1,
  /* DiagArray587 */ diag::warn_cocoa_naming_owned_rule, -1,
  /* DiagArray588 */ diag::warn_objc_property_default_assign_on_object, diag::warn_objc_property_no_assignment_attribute, -1,
  /* DiagArray589 */ diag::warn_autosynthesis_property_in_superclass, diag::warn_no_autosynthesis_property, diag::warn_no_autosynthesis_shared_ivar_property, -1,
  /* DiagArray590 */ diag::warn_category_method_impl_match, -1,
  /* DiagArray591 */ diag::warn_auto_synthesizing_protocol_property, -1,
  /* DiagArray592 */ diag::warn_objc_redundant_qualified_class_type, -1,
  /* DiagArray593 */ diag::warn_objc_readonly_property_has_setter, -1,
  /* DiagArray595 */ diag::warn_objc_redundant_literal_use, -1,
  /* DiagArray596 */ diag::warn_objc_root_class_missing, -1,
  /* DiagArray598 */ diag::warn_impcast_float_to_objc_signed_char_bool, -1,
  /* DiagArray599 */ diag::warn_impcast_int_to_objc_signed_char_bool, -1,
  /* DiagArray600 */ diag::warn_objc_string_literal_comparison, -1,
  /* DiagArray601 */ diag::warn_concatenated_nsarray_literal, -1,
  /* DiagArray602 */ diag::warn_objc_unsafe_perform_selector, -1,
  /* DiagArray603 */ diag::warn_odr_different_num_template_parameters, diag::warn_odr_different_template_parameter_kind, diag::warn_odr_field_type_inconsistent, diag::warn_odr_function_type_inconsistent, diag::warn_odr_ivar_type_inconsistent, diag::warn_odr_non_type_parameter_type_inconsistent, diag::warn_odr_objc_method_num_params_inconsistent, diag::warn_odr_objc_method_param_type_inconsistent, diag::warn_odr_objc_method_result_type_inconsistent, diag::warn_odr_objc_method_variadic_inconsistent, diag::warn_odr_objc_property_impl_kind_inconsistent, diag::warn_odr_objc_property_type_inconsistent, diag::warn_odr_objc_superclass_inconsistent, diag::warn_odr_objc_synthesize_ivar_inconsistent, diag::warn_odr_parameter_pack_non_pack, diag::warn_odr_tag_type_inconsistent, diag::warn_odr_variable_multiple_def, diag::warn_odr_variable_type_inconsistent, -1,
  /* DiagArray604 */ diag::warn_old_style_cast, -1,
  /* DiagArray606 */ diag::ext_opencl_ext_vector_type_rgba_selector, -1,
  /* DiagArray608 */ diag::ext_omp_attributes, -1,
  /* DiagArray609 */ diag::warn_omp_alignment_not_power_of_two, diag::warn_omp_allocate_thread_on_task_target_directive, diag::warn_omp_ctx_incompatible_property_for_selector, diag::warn_omp_ctx_incompatible_score_for_property, diag::warn_omp_ctx_incompatible_selector_for_set, diag::warn_omp_ctx_selector_without_properties, diag::warn_omp_declare_variant_ctx_mutiple_use, diag::warn_omp_declare_variant_ctx_not_a_property, diag::warn_omp_declare_variant_ctx_not_a_selector, diag::warn_omp_declare_variant_ctx_not_a_set, diag::warn_omp_declare_variant_expected, diag::warn_omp_declare_variant_string_literal_or_identifier, diag::warn_omp_linear_step_zero, diag::warn_omp_more_one_device_type_clause, diag::warn_omp_more_one_interop_type, diag::warn_omp_unknown_assumption_clause_missing_id, diag::warn_omp_unknown_assumption_clause_without_args, diag::warn_omp_used_different_allocator, -1,
  /* DiagArray610 */ diag::ext_omp_loop_not_canonical_init, diag::warn_omp_loop_64_bit_var, -1,
  /* DiagArray611 */ diag::warn_omp_non_trivial_type_mapped, -1,
  /* DiagArray612 */ diag::warn_drv_omp_offload_target_duplicate, diag::warn_omp_declare_target_after_first_use, diag::warn_omp_not_in_target_context, -1,
  /* DiagArray613 */ diag::warn_drv_fine_grained_bitfield_accesses_ignored, diag::warn_drv_moutline_atomics_unsupported_opt, diag::warn_drv_moutline_unsupported_opt, diag::warn_drv_needs_hvx, diag::warn_drv_ps4_force_pic, diag::warn_drv_spirv_linking_multiple_inputs_unsupported, diag::warn_drv_unsupported_longcalls, diag::warn_drv_unsupported_option_for_offload_arch_req_feature, diag::warn_drv_unsupported_option_for_target, diag::warn_drv_unsupported_pic_with_mabicalls, diag::warn_drv_unsupported_sdata, -1,
  /* DiagArray614 */ diag::ext_typecheck_ordered_comparison_of_function_pointers, diag::warn_typecheck_ordered_comparison_of_function_pointers, -1,
  /* DiagArray615 */ diag::ext_out_of_line_declaration, -1,
  /* DiagArray616 */ diag::ext_use_out_of_scope_declaration, -1,
  /* DiagArray617 */ diag::warn_overaligned_type, -1,
  /* DiagArray619 */ diag::ext_string_too_long, -1,
  /* DiagArray620 */ diag::warn_overloaded_shift_in_comparison, -1,
  /* DiagArray621 */ diag::warn_overloaded_virtual, -1,
  /* DiagArray623 */ diag::warn_fe_override_module, -1,
  /* DiagArray624 */ diag::warn_conflicting_overriding_param_modifiers, diag::warn_conflicting_overriding_param_types, diag::warn_conflicting_overriding_ret_type_modifiers, diag::warn_conflicting_overriding_ret_types, diag::warn_conflicting_overriding_variadic, diag::warn_non_contravariant_overriding_param_types, diag::warn_non_covariant_overriding_ret_types, -1,
  /* DiagArray625 */ diag::warn_drv_overriding_flag_option, -1,
  /* DiagArray626 */ diag::warn_unnecessary_packed, -1,
  /* DiagArray627 */ diag::warn_padded_struct_anon_field, diag::warn_padded_struct_field, diag::warn_padded_struct_size, -1,
  /* DiagArray628 */ diag::warn_condition_is_assignment, diag::warn_precedence_bitwise_rel, diag::warn_precedence_conditional, -1,
  /* DiagArray629 */ diag::warn_equality_with_extra_parens, -1,
  /* DiagArray631 */ diag::remark_fe_backend_optimization_remark, -1,
  /* DiagArray632 */ diag::remark_fe_backend_optimization_remark_analysis, diag::remark_fe_backend_optimization_remark_analysis_aliasing, diag::remark_fe_backend_optimization_remark_analysis_fpcommute, -1,
  /* DiagArray633 */ diag::warn_fe_backend_optimization_failure, -1,
  /* DiagArray634 */ diag::remark_fe_backend_optimization_remark_missed, -1,
  /* DiagArray635 */ diag::warn_module_uses_date_time, -1,
  /* DiagArray636 */ diag::ext_aggregate_init_not_constant, diag::ext_anonymous_record_with_type, diag::ext_anonymous_struct_union_qualified, diag::ext_array_size_conversion, diag::ext_auto_new_list_init, diag::ext_c99_array_usage, diag::ext_c99_compound_literal, diag::ext_c99_feature, diag::ext_c99_flexible_array_member, diag::ext_c99_variable_decl_in_for_loop, diag::ext_cast_fn_obj, diag::ext_clang_diagnose_if, diag::ext_clang_enable_if, diag::ext_cxx11_enum_fixed_underlying_type, diag::ext_designated_init, diag::ext_dtor_name_ambiguous, diag::ext_dtor_named_in_wrong_scope, diag::ext_duplicate_declspec, diag::ext_ellipsis_exception_spec, diag::ext_empty_fnmacro_arg, diag::ext_enum_value_not_int, diag::ext_enumerator_list_comma_c, diag::ext_enumerator_list_comma_cxx, diag::ext_explicit_instantiation_without_qualified_id, diag::ext_expr_not_ice, diag::ext_extern_template, diag::ext_extra_semi, diag::ext_forward_ref_enum, diag::ext_freestanding_complex, diag::ext_gnu_array_range, diag::ext_gnu_ptr_func_arith, diag::ext_gnu_subscript_void_type, diag::ext_gnu_void_ptr, diag::ext_hex_constant_invalid, diag::ext_hex_literal_invalid, diag::ext_ident_list_in_param, diag::ext_in_class_initializer_non_constant, diag::ext_integer_complement_complex, diag::ext_integer_increment_complex, diag::ext_internal_in_extern_inline_quiet, diag::ext_line_comment, diag::ext_main_used, diag::ext_multi_line_line_comment, diag::ext_named_variadic_macro, diag::ext_no_newline_eof, diag::ext_nonstandard_escape, diag::ext_ns_enum_attribute, diag::ext_opencl_double_without_pragma, diag::ext_param_not_declared, diag::ext_pointer_to_const_ref_member_on_rvalue, diag::ext_pp_bad_vaargs_use, diag::ext_pp_comma_expr, diag::ext_pp_ident_directive, diag::ext_pp_line_too_big, diag::ext_pp_opencl_variadic_macros, diag::ext_pp_warning_directive, diag::ext_return_has_void_expr, diag::ext_rvalue_to_reference_access_ctor, diag::ext_rvalue_to_reference_temp_copy_no_viable, diag::ext_sizeof_alignof_function_type, diag::ext_sizeof_alignof_void_type, diag::ext_subscript_non_lvalue, diag::ext_thread_before, diag::ext_typecheck_addrof_void, diag::ext_typecheck_cast_nonscalar, diag::ext_typecheck_comparison_of_fptr_to_void, diag::ext_typecheck_cond_one_void, diag::ext_typecheck_convert_pointer_void_func, diag::ext_typecheck_ordered_comparison_of_pointer_and_zero, diag::ext_variadic_macro, diag::warn_defined_in_function_type_macro, diag::warn_format_conversion_argument_type_mismatch_pedantic, diag::warn_kern_is_method, -1,
  /* DiagArray637 */ diag::warn_opencl_unsupported_core_feature, diag::warn_pragma_extension_is_core, -1,
  /* DiagArray639 */ diag::warn_pessimizing_move_on_initialization, diag::warn_pessimizing_move_on_return, -1,
  /* DiagArray640 */ diag::ext_gnu_ptr_func_arith, diag::ext_gnu_subscript_void_type, diag::ext_gnu_void_ptr, diag::ext_sizeof_alignof_function_type, diag::ext_sizeof_alignof_void_type, diag::warn_sub_ptr_zero_size_types, -1,
  /* DiagArray641 */ diag::warn_cast_nonnull_to_bool, diag::warn_impcast_pointer_to_bool, -1,
  /* DiagArray642 */ diag::warn_pointer_compare, -1,
  /* DiagArray643 */ diag::ext_typecheck_comparison_of_pointer_integer, -1,
  /* DiagArray644 */ diag::ext_typecheck_convert_incompatible_pointer_sign, -1,
  /* DiagArray645 */ diag::warn_pointer_to_enum_cast, -1,
  /* DiagArray646 */ diag::warn_pointer_to_int_cast, -1,
  /* DiagArray647 */ diag::ext_typecheck_cond_incompatible_pointers, -1,
  /* DiagArray648 */ diag::warn_poison_system_directories, -1,
  /* DiagArray649 */ diag::warn_potentially_direct_selector_expression, -1,
  /* DiagArray650 */ diag::warn_side_effects_typeid, -1,
  /* DiagArray651 */ diag::warn_pragma_attribute_unused, -1,
  /* DiagArray652 */ diag::pp_pragma_once_in_main_file, -1,
  /* DiagArray653 */ diag::warn_pragma_pack_modified_after_include, diag::warn_pragma_pack_no_pop_eof, -1,
  /* DiagArray654 */ diag::warn_pragma_pack_non_default_at_include, -1,
  /* DiagArray655 */ diag::pp_pragma_sysheader_in_main_file, -1,
  /* DiagArray656 */ diag::warn_redefine_extname_not_applied, -1,
  /* DiagArray657 */ diag::warn_cxx11_compat_constexpr_body_invalid_stmt, diag::warn_cxx11_compat_constexpr_body_multiple_return, diag::warn_cxx11_compat_constexpr_body_no_return, diag::warn_cxx11_compat_constexpr_local_var, diag::warn_cxx11_compat_constexpr_type_definition, diag::warn_cxx11_compat_decltype_auto_type_specifier, diag::warn_cxx11_compat_deduced_return_type, diag::warn_cxx11_compat_digit_separator, diag::warn_cxx11_compat_generic_lambda, diag::warn_cxx11_compat_init_capture, diag::warn_cxx11_compat_variable_template, -1,
  /* DiagArray659 */ diag::warn_cxx14_compat_class_template_argument_deduction, diag::warn_cxx14_compat_constexpr_if, diag::warn_cxx14_compat_constexpr_on_lambda, diag::warn_cxx14_compat_decomp_decl, diag::warn_cxx14_compat_fold_expression, diag::warn_cxx14_compat_init_statement, diag::warn_cxx14_compat_inline_variable, diag::warn_cxx14_compat_nested_namespace_definition, diag::warn_cxx14_compat_star_this_lambda_capture, diag::warn_cxx14_compat_static_assert_no_message, diag::warn_cxx14_compat_template_nontype_parm_auto_type, diag::warn_cxx14_compat_template_template_param_typename, diag::warn_cxx14_compat_u8_character_literal, diag::warn_cxx14_compat_using_attribute_ns, diag::warn_cxx17_compat_multi_using_declaration, diag::warn_cxx17_compat_using_declaration_pack, diag::warn_for_range_begin_end_types_differ, -1,
  /* DiagArray660 */ diag::warn_cxx14_compat_ns_enum_attribute, diag::warn_cxx17_hex_literal, -1,
  /* DiagArray661 */ diag::warn_cxx17_compat_adl_only_template_id, diag::warn_cxx17_compat_bitfield_member_init, diag::warn_cxx17_compat_constexpr_body_invalid_stmt, diag::warn_cxx17_compat_constexpr_ctor_missing_init, diag::warn_cxx17_compat_constexpr_function_try_block, diag::warn_cxx17_compat_constexpr_local_var_no_init, diag::warn_cxx17_compat_constexpr_union_ctor_no_init, diag::warn_cxx17_compat_constexpr_virtual, diag::warn_cxx17_compat_decomp_decl_spec, diag::warn_cxx17_compat_defaulted_comparison, diag::warn_cxx17_compat_defaulted_method_type_mismatch, diag::warn_cxx17_compat_equals_this_lambda_capture, diag::warn_cxx17_compat_explicit_bool, diag::warn_cxx17_compat_for_range_init_stmt, diag::warn_cxx17_compat_init_capture_pack, diag::warn_cxx17_compat_inline_nested_namespace_definition, diag::warn_cxx17_compat_lambda_def_ctor_assign, diag::warn_cxx17_compat_lambda_template_parameter_list, diag::warn_cxx17_compat_missing_varargs_arg, diag::warn_cxx17_compat_spaceship, diag::warn_cxx17_compat_template_nontype_parm_type, diag::warn_cxx17_compat_unicode_type, diag::warn_cxx17_compat_using_decl_class_member_enumerator, diag::warn_cxx17_compat_using_decl_non_member_enumerator, diag::warn_cxx17_compat_using_decl_scoped_enumerator, diag::warn_cxx17_compat_using_enum_declaration, -1,
  /* DiagArray662 */ diag::warn_cxx17_compat_designated_init, diag::warn_cxx17_compat_pointer_to_const_ref_member_on_rvalue, -1,
  /* DiagArray663 */ diag::warn_cxx20_alias_in_init_statement, diag::warn_cxx20_compat_consteval_if, diag::warn_cxx20_compat_decl_attrs_on_lambda, diag::warn_cxx20_compat_size_t_suffix, -1,
  /* DiagArray665 */ diag::warn_c17_compat_bit_int, diag::warn_c17_compat_static_assert_no_message, diag::warn_c2x_compat_digit_separator, -1,
  /* DiagArray667 */ diag::warn_omp51_compat_attributes, -1,
  /* DiagArray668 */ diag::ext_predef_outside_function, -1,
  /* DiagArray669 */ diag::warn_private_extern, -1,
  /* DiagArray670 */ diag::warn_use_of_private_header_outside_module, -1,
  /* DiagArray671 */ diag::warn_mmap_mismatched_private_module_name, diag::warn_mmap_mismatched_private_submodule, diag::warn_mmap_redundant_export_as, diag::warn_no_priv_submodule_use_toplevel, -1,
  /* DiagArray672 */ diag::warn_profile_data_missing, -1,
  /* DiagArray673 */ diag::warn_profile_data_out_of_date, -1,
  /* DiagArray674 */ diag::warn_profile_data_unprofiled, -1,
  /* DiagArray675 */ diag::warn_property_access_suggest, -1,
  /* DiagArray676 */ diag::warn_property_attr_mismatch, diag::warn_property_attribute, diag::warn_property_redecl_getter_mismatch, diag::warn_readonly_property, -1,
  /* DiagArray677 */ diag::warn_unimplemented_protocol_method, -1,
  /* DiagArray678 */ diag::warn_protocol_property_mismatch, -1,
  /* DiagArray679 */ diag::warn_avx_calling_convention, -1,
  /* DiagArray680 */ diag::err_func_returning_qualified_void, -1,
  /* DiagArray681 */ diag::warn_quoted_include_in_framework_header, -1,
  /* DiagArray683 */ diag::warn_for_range_ref_binds_ret_temp, -1,
  /* DiagArray684 */ diag::warn_for_range_const_ref_binds_temp_built_from_ref, diag::warn_for_range_copy, -1,
  /* DiagArray685 */ diag::warn_auto_readonly_iboutlet_property, -1,
  /* DiagArray686 */ diag::warn_bad_receiver_type, -1,
  /* DiagArray687 */ diag::warn_receiver_forward_class, diag::warn_receiver_forward_instance, -1,
  /* DiagArray688 */ diag::ext_member_redeclared, -1,
  /* DiagArray689 */ diag::warn_consteval_if_always_true, -1,
  /* DiagArray691 */ diag::warn_redundant_move_on_return, -1,
  /* DiagArray692 */ diag::warn_redundant_parens_around_declarator, -1,
  /* DiagArray693 */ diag::ext_register_storage_class, -1,
  /* DiagArray694 */ diag::warn_reinterpret_different_from_static, -1,
  /* DiagArray695 */ diag::remark_fe_backend_plugin, -1,
  /* DiagArray697 */ diag::warn_initializer_out_of_order, diag::warn_some_initializers_out_of_order, -1,
  /* DiagArray698 */ diag::ext_designated_init_reordered, -1,
  /* DiagArray699 */ diag::warn_objc_requires_super_protocol, -1,
  /* DiagArray701 */ diag::warn_reserved_extern_symbol, -1,
  /* DiagArray702 */ diag::warn_pp_macro_is_reserved_id, -1,
  /* DiagArray703 */ diag::ext_ms_reserved_user_defined_literal, diag::ext_reserved_user_defined_literal, -1,
  /* DiagArray704 */ diag::warn_pragma_restrict_expansion_macro_use, -1,
  /* DiagArray705 */ diag::ext_retained_language_linkage, -1,
  /* DiagArray706 */ diag::warn_ret_addr_label, diag::warn_ret_local_temp_addr_ref, diag::warn_ret_stack_addr_ref, -1,
  /* DiagArray708 */ diag::ext_return_has_expr, diag::ext_return_missing_expr, diag::warn_falloff_nonvoid_coroutine, diag::warn_falloff_nonvoid_function, diag::warn_falloff_nonvoid_lambda, diag::warn_maybe_falloff_nonvoid_coroutine, diag::warn_maybe_falloff_nonvoid_function, diag::warn_maybe_falloff_nonvoid_lambda, diag::warn_return_missing_expr, -1,
  /* DiagArray709 */ diag::warn_return_value_udt, diag::warn_return_value_udt_incomplete, -1,
  /* DiagArray710 */ diag::ext_ovl_rewrite_equalequal_not_bool, -1,
  /* DiagArray711 */ diag::remark_cc1_round_trip_generated, -1,
  /* DiagArray712 */ diag::warn_no_dynamic_cast_with_rtti_disabled, diag::warn_no_typeid_with_rtti_disabled, -1,
  /* DiagArray713 */ diag::remark_sanitize_address_insert_extra_padding_accepted, diag::remark_sanitize_address_insert_extra_padding_rejected, -1,
  /* DiagArray714 */ diag::remark_pp_search_path_usage, -1,
  /* DiagArray715 */ diag::warn_attribute_section_on_redeclaration, diag::warn_duplicate_codeseg_attribute, diag::warn_mismatched_section, -1,
  /* DiagArray716 */ diag::warn_unimplemented_selector, -1,
  /* DiagArray717 */ diag::warn_multiple_selectors, -1,
  /* DiagArray718 */ diag::warn_self_assignment_builtin, -1,
  /* DiagArray719 */ diag::warn_identity_field_assign, -1,
  /* DiagArray720 */ diag::warn_self_assignment_overloaded, -1,
  /* DiagArray721 */ diag::warn_self_move, -1,
  /* DiagArray722 */ diag::warn_semicolon_before_method_body, -1,
  /* DiagArray723 */ diag::warn_missing_sentinel, diag::warn_not_enough_argument, -1,
  /* DiagArray725 */ diag::warn_fe_serialized_diag_failure, diag::warn_fe_serialized_diag_failure_during_finalisation, diag::warn_fe_serialized_diag_merge_failure, -1,
  /* DiagArray726 */ diag::warn_decl_shadow, -1,
  /* DiagArray728 */ diag::warn_shadow_field, -1,
  /* DiagArray729 */ diag::warn_ctor_parm_shadows_field, -1,
  /* DiagArray730 */ diag::warn_modifying_shadowing_decl, -1,
  /* DiagArray731 */ diag::warn_ivar_use_hidden, -1,
  /* DiagArray732 */ diag::warn_decl_shadow_uncaptured_local, -1,
  /* DiagArray733 */ diag::warn_shift_negative, -1,
  /* DiagArray734 */ diag::warn_shift_gt_typewidth, -1,
  /* DiagArray735 */ diag::warn_shift_lhs_negative, -1,
  /* DiagArray736 */ diag::warn_addition_in_bitshift, -1,
  /* DiagArray737 */ diag::warn_shift_result_gt_typewidth, -1,
  /* DiagArray738 */ diag::warn_shift_result_sets_sign_bit, -1,
  /* DiagArray739 */ diag::warn_impcast_integer_64_32, -1,
  /* DiagArray740 */ diag::warn_mixed_sign_comparison, -1,
  /* DiagArray741 */ diag::warn_impcast_integer_sign, diag::warn_impcast_integer_sign_conditional, diag::warn_impcast_nonnegative_result, -1,
  /* DiagArray743 */ diag::warn_no_underlying_type_specified_for_enum_bitfield, -1,
  /* DiagArray744 */ diag::ext_wchar_t_sign_spec, -1,
  /* DiagArray745 */ diag::warn_sizeof_array_param, -1,
  /* DiagArray746 */ diag::warn_sizeof_array_decay, -1,
  /* DiagArray747 */ diag::warn_division_sizeof_array, -1,
  /* DiagArray748 */ diag::warn_division_sizeof_ptr, -1,
  /* DiagArray749 */ diag::warn_sizeof_pointer_expr_memaccess, diag::warn_sizeof_pointer_type_memaccess, -1,
  /* DiagArray750 */ diag::warn_slash_u_filename, -1,
  /* DiagArray751 */ diag::warn_slh_does_not_support_asm_goto, -1,
  /* DiagArray752 */ diag::warn_sometimes_uninit_var, -1,
  /* DiagArray753 */ diag::warn_fe_source_mgr, -1,
  /* DiagArray754 */ diag::warn_omp_declare_variant_after_emitted, diag::warn_omp_declare_variant_after_used, diag::warn_omp_declare_variant_marked_as_declare_variant, diag::warn_omp_declare_variant_score_not_constant, diag::warn_omp_nesting_simd, diag::warn_pragma_omp_ignored, diag::warn_unknown_begin_declare_variant_isa_trait, diag::warn_unknown_declare_variant_isa_trait, -1,
  /* DiagArray755 */ diag::warn_sampler_initializer_invalid_bits, -1,
  /* DiagArray757 */ diag::warn_stack_exhausted, -1,
  /* DiagArray758 */ diag::warn_stack_clash_protection_inline_asm, -1,
  /* DiagArray759 */ diag::ext_in_class_initializer_float_type_cxx11, -1,
  /* DiagArray760 */ diag::ext_internal_in_extern_inline, diag::ext_internal_in_extern_inline_quiet, -1,
  /* DiagArray761 */ diag::warn_static_inline_explicit_inst_ignored, -1,
  /* DiagArray762 */ diag::warn_static_local_in_extern_inline, -1,
  /* DiagArray763 */ diag::warn_static_self_reference_in_init, -1,
  /* DiagArray764 */ diag::warn_drv_libstdcxx_not_found, -1,
  /* DiagArray776 */ diag::warn_strict_potentially_direct_selector_expression, -1,
  /* DiagArray777 */ diag::warn_strict_prototypes, -1,
  /* DiagArray778 */ diag::warn_strict_multiple_method_decl, -1,
  /* DiagArray779 */ diag::warn_stringcompare, -1,
  /* DiagArray780 */ diag::warn_concatenated_literal_array_init, -1,
  /* DiagArray781 */ diag::warn_impcast_string_literal_to_bool, -1,
  /* DiagArray782 */ diag::warn_string_plus_char, -1,
  /* DiagArray783 */ diag::warn_string_plus_int, -1,
  /* DiagArray784 */ diag::warn_strlcpycat_wrong_size, -1,
  /* DiagArray785 */ diag::warn_strncat_large_size, diag::warn_strncat_src_size, diag::warn_strncat_wrong_size, -1,
  /* DiagArray786 */ diag::warn_suggest_destructor_marked_not_override_overriding, -1,
  /* DiagArray787 */ diag::warn_suggest_function_marked_not_override_overriding, -1,
  /* DiagArray788 */ diag::ext_typecheck_base_super, -1,
  /* DiagArray789 */ diag::warn_suspicious_bzero_size, -1,
  /* DiagArray791 */ diag::warn_attr_swift_name_decl_kind, diag::warn_attr_swift_name_decl_missing_params, diag::warn_attr_swift_name_function, diag::warn_attr_swift_name_getter_parameters, diag::warn_attr_swift_name_invalid_identifier, diag::warn_attr_swift_name_missing_parameters, diag::warn_attr_swift_name_multiple_selfs, diag::warn_attr_swift_name_num_params, diag::warn_attr_swift_name_setter_parameters, diag::warn_attr_swift_name_subscript_getter_newValue, diag::warn_attr_swift_name_subscript_invalid_parameter, diag::warn_attr_swift_name_subscript_setter_multiple_newValues, diag::warn_attr_swift_name_subscript_setter_no_newValue, -1,
  /* DiagArray792 */ diag::warn_case_value_overflow, diag::warn_missing_case, diag::warn_not_in_enum, -1,
  /* DiagArray793 */ diag::warn_bool_switch_condition, -1,
  /* DiagArray795 */ diag::warn_def_missing_case, -1,
  /* DiagArray796 */ diag::warn_sync_fetch_and_nand_semantics_change, -1,
  /* DiagArray798 */ diag::warn_target_clone_mixed_values, -1,
  /* DiagArray799 */ diag::warn_comparison_bitwise_always, diag::warn_comparison_bitwise_or, -1,
  /* DiagArray800 */ diag::warn_alignment_builtin_useless, diag::warn_comparison_always, -1,
  /* DiagArray801 */ diag::warn_integer_constants_in_conditional_always_true, diag::warn_left_shift_always, diag::warn_tautological_bool_compare, -1,
  /* DiagArray803 */ diag::warn_out_of_range_compare, -1,
  /* DiagArray804 */ diag::warn_tautological_compare_objc_bool, -1,
  /* DiagArray805 */ diag::warn_tautological_overlap_comparison, -1,
  /* DiagArray806 */ diag::warn_nonnull_expr_compare, diag::warn_null_pointer_compare, -1,
  /* DiagArray807 */ diag::warn_tautological_constant_compare, -1,
  /* DiagArray808 */ diag::warn_address_of_reference_null_compare, diag::warn_this_null_compare, -1,
  /* DiagArray809 */ diag::warn_unsigned_char_always_true_comparison, -1,
  /* DiagArray810 */ diag::warn_unsigned_enum_always_true_comparison, -1,
  /* DiagArray811 */ diag::warn_unsigned_always_true_comparison, -1,
  /* DiagArray812 */ diag::warn_tautological_compare_value_range, -1,
  /* DiagArray813 */ diag::warn_tcb_enforcement_violation, -1,
  /* DiagArray814 */ diag::ext_typecheck_decl_incomplete_type, -1,
  /* DiagArray816 */ diag::warn_acquired_before, diag::warn_acquired_before_after_cycle, diag::warn_cannot_resolve_lock, diag::warn_double_lock, diag::warn_expecting_lock_held_on_loop, diag::warn_expecting_locked, diag::warn_fun_excludes_mutex, diag::warn_fun_requires_lock, diag::warn_fun_requires_negative_cap, diag::warn_lock_exclusive_and_shared, diag::warn_lock_some_predecessors, diag::warn_no_unlock, diag::warn_unlock_but_no_lock, diag::warn_unlock_kind_mismatch, diag::warn_var_deref_requires_any_lock, diag::warn_var_deref_requires_lock, diag::warn_variable_requires_any_lock, diag::warn_variable_requires_lock, -1,
  /* DiagArray817 */ diag::warn_thread_attribute_argument_not_lockable, diag::warn_thread_attribute_decl_not_lockable, diag::warn_thread_attribute_decl_not_pointer, diag::warn_thread_attribute_ignored, diag::warn_thread_attribute_not_on_capability_member, diag::warn_thread_attribute_not_on_non_static_member, -1,
  /* DiagArray818 */ diag::warn_thread_safety_beta, -1,
  /* DiagArray819 */ diag::warn_acquire_requires_negative_cap, -1,
  /* DiagArray820 */ diag::warn_fun_requires_lock_precise, diag::warn_var_deref_requires_lock_precise, diag::warn_variable_requires_lock_precise, -1,
  /* DiagArray821 */ diag::warn_guarded_pass_by_reference, diag::warn_pt_guarded_pass_by_reference, -1,
  /* DiagArray822 */ diag::warn_thread_safety_verbose, -1,
  /* DiagArray823 */ diag::trigraph_converted, diag::trigraph_ends_block_comment, diag::trigraph_ignored, diag::trigraph_ignored_block_comment, -1,
  /* DiagArray825 */ diag::warn_type_safety_null_pointer_required, diag::warn_type_safety_type_mismatch, diag::warn_type_tag_for_datatype_wrong_kind, -1,
  /* DiagArray826 */ diag::ext_redefinition_of_typedef, -1,
  /* DiagArray827 */ diag::ext_typename_missing, -1,
  /* DiagArray828 */ diag::warn_fe_unable_to_open_stats_file, -1,
  /* DiagArray829 */ diag::warn_unavailable_fwdclass_message, -1,
  /* DiagArray830 */ diag::warn_undeclared_selector, diag::warn_undeclared_selector_with_typo, -1,
  /* DiagArray831 */ diag::warn_pp_undef_identifier, -1,
  /* DiagArray832 */ diag::warn_pp_undef_prefix, -1,
  /* DiagArray833 */ diag::warn_address_of_reference_bool_conversion, diag::warn_this_bool_conversion, -1,
  /* DiagArray834 */ diag::warn_func_template_missing, -1,
  /* DiagArray835 */ diag::warn_undefined_inline, -1,
  /* DiagArray836 */ diag::warn_undefined_internal, -1,
  /* DiagArray837 */ diag::ext_undefined_internal_type, -1,
  /* DiagArray838 */ diag::warn_pointer_indirection_from_incompatible_type, diag::warn_undefined_reinterpret_cast, -1,
  /* DiagArray839 */ diag::warn_var_template_missing, -1,
  /* DiagArray840 */ diag::warn_throw_underaligned_obj, -1,
  /* DiagArray841 */ diag::warn_side_effects_unevaluated_context, -1,
  /* DiagArray842 */ diag::warn_unguarded_availability, -1,
  /* DiagArray843 */ diag::warn_unguarded_availability_new, -1,
  /* DiagArray844 */ diag::warn_delimited_ucn_empty, diag::warn_delimited_ucn_incomplete, diag::warn_ucn_escape_incomplete, diag::warn_ucn_escape_no_digits, diag::warn_ucn_escape_surrogate, diag::warn_ucn_not_valid_in_c89, diag::warn_ucn_not_valid_in_c89_literal, -1,
  /* DiagArray845 */ diag::warn_utf8_symbol_homoglyph, -1,
  /* DiagArray846 */ diag::ext_unicode_whitespace, -1,
  /* DiagArray847 */ diag::warn_utf8_symbol_zero_width, -1,
  /* DiagArray848 */ diag::warn_base_class_is_uninit, diag::warn_field_is_uninit, diag::warn_reference_field_is_uninit, diag::warn_uninit_byref_blockvar_captured_by_block, diag::warn_uninit_self_reference_in_init, diag::warn_uninit_self_reference_in_reference_init, diag::warn_uninit_var, -1,
  /* DiagArray849 */ diag::warn_uninit_const_reference, -1,
  /* DiagArray850 */ diag::warn_drv_unknown_argument_clang_cl, diag::warn_drv_unknown_argument_clang_cl_with_suggestion, -1,
  /* DiagArray851 */ diag::warn_assume_attribute_string_unknown, -1,
  /* DiagArray852 */ diag::warn_unknown_attribute_ignored, -1,
  /* DiagArray853 */ diag::warn_drv_new_cuda_version, diag::warn_drv_partially_supported_cuda_version, -1,
  /* DiagArray854 */ diag::ext_unknown_escape, -1,
  /* DiagArray855 */ diag::ext_on_off_switch_syntax, diag::ext_pragma_syntax_eod, diag::ext_stdc_pragma_ignored, diag::warn_pragma_diagnostic_cannot_pop, diag::warn_pragma_diagnostic_invalid, diag::warn_pragma_diagnostic_invalid_option, diag::warn_pragma_diagnostic_invalid_token, diag::warn_pragma_exec_charset_expected, diag::warn_pragma_exec_charset_push_invalid, diag::warn_pragma_exec_charset_spec_invalid, diag::warn_pragma_ignored, diag::warn_pragma_include_alias_expected, diag::warn_pragma_include_alias_expected_filename, diag::warn_pragma_include_alias_mismatch_angle, diag::warn_pragma_include_alias_mismatch_quote, diag::warn_pragma_warning_expected, diag::warn_pragma_warning_expected_number, diag::warn_pragma_warning_push_level, diag::warn_pragma_warning_spec_invalid, diag::warn_stdc_fenv_round_not_supported, -1,
  /* DiagArray856 */ diag::warn_unknown_sanitizer_ignored, -1,
  /* DiagArray857 */ diag::warn_pragma_diagnostic_unknown_warning, diag::warn_unknown_diag_option, diag::warn_unknown_warning_specifier, -1,
  /* DiagArray858 */ diag::ext_template_arg_unnamed_type, -1,
  /* DiagArray859 */ diag::warn_unneeded_internal_decl, diag::warn_unneeded_static_internal_decl, -1,
  /* DiagArray860 */ diag::warn_unneeded_member_function, -1,
  /* DiagArray861 */ diag::warn_unreachable, -1,
  /* DiagArray863 */ diag::warn_unreachable_break, -1,
  /* DiagArray864 */ diag::warn_unreachable_fallthrough_attr, -1,
  /* DiagArray865 */ diag::warn_unreachable_loop_increment, -1,
  /* DiagArray866 */ diag::warn_unreachable_return, -1,
  /* DiagArray867 */ diag::warn_unsequenced_mod_mod, diag::warn_unsequenced_mod_use, -1,
  /* DiagArray868 */ diag::warn_target_unsupported_abs2008, diag::warn_target_unsupported_abslegacy, -1,
  /* DiagArray869 */ diag::warn_at_available_unchecked_use, -1,
  /* DiagArray870 */ diag::warn_target_unsupported_compact_branches, -1,
  /* DiagArray871 */ diag::warn_attribute_dll_instantiated_base_class, -1,
  /* DiagArray872 */ diag::warn_fe_backend_unsupported_fp_exceptions, diag::warn_fe_backend_unsupported_fp_rounding, -1,
  /* DiagArray873 */ diag::warn_template_qualified_friend_ignored, diag::warn_template_qualified_friend_unsupported, -1,
  /* DiagArray874 */ diag::warn_drv_unsupported_gpopt, -1,
  /* DiagArray875 */ diag::warn_target_unsupported_nan2008, diag::warn_target_unsupported_nanlegacy, -1,
  /* DiagArray876 */ diag::warn_drv_dwarf_version_limited_by_target, diag::warn_drv_unsupported_debug_info_opt_for_target, -1,
  /* DiagArray877 */ diag::warn_attribute_protected_visibility, -1,
  /* DiagArray878 */ diag::ext_partial_specs_not_deducible, -1,
  /* DiagArray881 */ diag::warn_unused_but_set_parameter, -1,
  /* DiagArray882 */ diag::warn_unused_but_set_variable, -1,
  /* DiagArray883 */ diag::warn_drv_diagnostics_hotness_requires_pgo, diag::warn_drv_empty_joined_argument, diag::warn_drv_input_file_unused, diag::warn_drv_input_file_unused_by_cpp, diag::warn_drv_invalid_arch_name_with_suggestion, diag::warn_drv_preprocessed_input_file_unused, diag::warn_drv_unused_argument, diag::warn_ignored_clang_option, diag::warn_ignoring_fdiscard_for_bitcode, diag::warn_ignoring_verify_debuginfo_preserve_export, -1,
  /* DiagArray884 */ diag::warn_unused_comparison, -1,
  /* DiagArray885 */ diag::warn_unused_const_variable, -1,
  /* DiagArray886 */ diag::warn_unused_exception_param, -1,
  /* DiagArray887 */ diag::warn_unused_function, -1,
  /* DiagArray888 */ diag::warn_unused_property_expr, -1,
  /* DiagArray889 */ diag::warn_unused_label, -1,
  /* DiagArray890 */ diag::warn_unused_lambda_capture, -1,
  /* DiagArray891 */ diag::warn_unused_local_typedef, -1,
  /* DiagArray893 */ diag::pp_macro_not_used, -1,
  /* DiagArray894 */ diag::warn_unused_member_function, -1,
  /* DiagArray895 */ diag::warn_unused_parameter, -1,
  /* DiagArray896 */ diag::warn_unused_private_field, -1,
  /* DiagArray897 */ diag::warn_unused_property_backing_ivar, -1,
  /* DiagArray898 */ diag::warn_unused_result, diag::warn_unused_result_msg, -1,
  /* DiagArray899 */ diag::warn_unused_template, -1,
  /* DiagArray900 */ diag::warn_unused_call, diag::warn_unused_comma_left_operand, diag::warn_unused_constructor, diag::warn_unused_constructor_msg, diag::warn_unused_container_subscript_expr, diag::warn_unused_expr, diag::warn_unused_voidptr, -1,
  /* DiagArray901 */ diag::warn_unused_variable, -1,
  /* DiagArray902 */ diag::warn_unused_volatile, -1,
  /* DiagArray903 */ diag::warn_used_but_marked_unused, -1,
  /* DiagArray904 */ diag::warn_user_literal_reserved, -1,
  /* DiagArray905 */ diag::warn_diagnose_if_succeeded, -1,
  /* DiagArray906 */ diag::warn_second_arg_of_va_start_not_last_named_param, diag::warn_second_parameter_to_va_arg_never_compatible, diag::warn_va_start_type_is_undefined, -1,
  /* DiagArray907 */ diag::ext_named_variadic_macro, diag::ext_pp_bad_vaopt_use, diag::ext_variadic_macro, -1,
  /* DiagArray908 */ diag::warn_typecheck_vector_element_sizes_not_equal, -1,
  /* DiagArray909 */ diag::warn_incompatible_vectors, -1,
  /* DiagArray911 */ diag::warn_empty_parens_are_function_decl, diag::warn_parens_disambiguated_as_function_declaration, diag::warn_parens_disambiguated_as_variable_declaration, -1,
  /* DiagArray912 */ diag::warn_decl_in_param_list, diag::warn_redefinition_in_param_list, -1,
  /* DiagArray913 */ diag::warn_vla_used, -1,
  /* DiagArray914 */ diag::ext_vla, -1,
  /* DiagArray915 */ diag::warn_void_pointer_to_enum_cast, -1,
  /* DiagArray916 */ diag::warn_void_pointer_to_int_cast, -1,
  /* DiagArray917 */ diag::ext_typecheck_indirection_through_void_pointer, -1,
  /* DiagArray919 */ diag::warn_wasm_dynamic_exception_spec_ignored, -1,
  /* DiagArray920 */ diag::warn_weak_template_vtable, -1,
  /* DiagArray921 */ diag::warn_weak_vtable, -1,
  /* DiagArray922 */ diag::ext_deprecated_string_literal_conversion, -1,
  /* DiagArray924 */ diag::warn_xor_used_as_pow, diag::warn_xor_used_as_pow_base, diag::warn_xor_used_as_pow_base_extra, -1,
  /* DiagArray925 */ diag::warn_zero_as_null_pointer_constant, -1,
  /* DiagArray926 */ diag::ext_typecheck_zero_array_size, -1,
};

static const int16_t DiagSubGroups[] = {
  /* Empty */ -1,
  /* DiagSubGroup0 */ 283, -1,
  /* DiagSubGroup4 */ 17, 283, -1,
  /* DiagSubGroup11 */ 641, 779, 806, -1,
  /* DiagSubGroup17 */ 522, 628, 792, 793, 492, -1,
  /* DiagSubGroup26 */ 202, -1,
  /* DiagSubGroup28 */ 35, 34, 31, -1,
  /* DiagSubGroup33 */ 30, -1,
  /* DiagSubGroup40 */ 41, -1,
  /* DiagSubGroup49 */ 368, 181, -1,
  /* DiagSubGroup53 */ 852, 359, -1,
  /* DiagSubGroup63 */ 98, 125, 331, -1,
  /* DiagSubGroup64 */ 128, -1,
  /* DiagSubGroup74 */ 641, 833, -1,
  /* DiagSubGroup75 */ 74, -1,
  /* DiagSubGroup76 */ 71, -1,
  /* DiagSubGroup85 */ 88, -1,
  /* DiagSubGroup86 */ 92, -1,
  /* DiagSubGroup87 */ 96, -1,
  /* DiagSubGroup88 */ 96, 91, 89, 657, 659, 661, 663, -1,
  /* DiagSubGroup90 */ 88, 658, 660, 662, 664, -1,
  /* DiagSubGroup92 */ 93, 94, 95, -1,
  /* DiagSubGroup99 */ 659, 661, 663, -1,
  /* DiagSubGroup100 */ 99, 660, 662, 664, -1,
  /* DiagSubGroup101 */ 98, 97, -1,
  /* DiagSubGroup103 */ 225, 220, 104, 661, 663, -1,
  /* DiagSubGroup105 */ 103, 662, 664, -1,
  /* DiagSubGroup106 */ 102, -1,
  /* DiagSubGroup107 */ 101, -1,
  /* DiagSubGroup108 */ 103, -1,
  /* DiagSubGroup109 */ 104, -1,
  /* DiagSubGroup110 */ 106, -1,
  /* DiagSubGroup112 */ 663, -1,
  /* DiagSubGroup113 */ 112, 664, -1,
  /* DiagSubGroup115 */ 114, 111, -1,
  /* DiagSubGroup116 */ 112, -1,
  /* DiagSubGroup117 */ 113, -1,
  /* DiagSubGroup118 */ 115, -1,
  /* DiagSubGroup120 */ 661, -1,
  /* DiagSubGroup121 */ 662, -1,
  /* DiagSubGroup122 */ 659, -1,
  /* DiagSubGroup123 */ 660, -1,
  /* DiagSubGroup124 */ 657, -1,
  /* DiagSubGroup126 */ 658, -1,
  /* DiagSubGroup127 */ 130, 132, 657, 659, 661, 663, -1,
  /* DiagSubGroup131 */ 127, 128, 129, 658, 660, 662, 664, -1,
  /* DiagSubGroup136 */ 114, -1,
  /* DiagSubGroup137 */ 136, -1,
  /* DiagSubGroup139 */ 156, -1,
  /* DiagSubGroup150 */ 540, -1,
  /* DiagSubGroup154 */ 153, -1,
  /* DiagSubGroup158 */ 159, 160, -1,
  /* DiagSubGroup165 */ 67, 565, -1,
  /* DiagSubGroup170 */ 74, 165, 269, 68, 294, 739, 413, 378, 375, 442, 537, 553, 575, 741, 781, -1,
  /* DiagSubGroup171 */ 553, -1,
  /* DiagSubGroup172 */ 173, 211, -1,
  /* DiagSubGroup175 */ 2, -1,
  /* DiagSubGroup183 */ 185, 187, 186, 706, -1,
  /* DiagSubGroup198 */ 197, 195, -1,
  /* DiagSubGroup200 */ 202, 203, 204, 205, 206, 208, 212, 213, 214, 215, 216, 217, 220, 224, 225, 226, 227, 228, 229, -1,
  /* DiagSubGroup206 */ 209, -1,
  /* DiagSubGroup207 */ 208, -1,
  /* DiagSubGroup208 */ 210, -1,
  /* DiagSubGroup211 */ 218, -1,
  /* DiagSubGroup222 */ 223, -1,
  /* DiagSubGroup229 */ 89, -1,
  /* DiagSubGroup235 */ 236, -1,
  /* DiagSubGroup240 */ 242, 241, -1,
  /* DiagSubGroup243 */ 244, -1,
  /* DiagSubGroup255 */ 213, -1,
  /* DiagSubGroup256 */ 542, -1,
  /* DiagSubGroup265 */ 287, -1,
  /* DiagSubGroup266 */ 268, 214, -1,
  /* DiagSubGroup267 */ 215, -1,
  /* DiagSubGroup269 */ 270, 271, 267, -1,
  /* DiagSubGroup270 */ 216, -1,
  /* DiagSubGroup271 */ 217, -1,
  /* DiagSubGroup283 */ 206, 501, 365, 406, 722, 504, 740, 895, 881, 555, 556, 262, 780, 320, -1,
  /* DiagSubGroup285 */ 129, 93, -1,
  /* DiagSubGroup286 */ 262, -1,
  /* DiagSubGroup294 */ 296, 297, -1,
  /* DiagSubGroup299 */ 300, 309, 543, 306, 308, 302, 301, -1,
  /* DiagSubGroup310 */ 304, 306, 308, -1,
  /* DiagSubGroup315 */ 314, -1,
  /* DiagSubGroup319 */ 798, -1,
  /* DiagSubGroup321 */ 97, 102, 111, -1,
  /* DiagSubGroup326 */ 327, 328, 330, 331, 332, 333, 334, 335, 336, 337, 338, 914, 339, 340, 341, 342, 343, 345, 688, 346, 347, 348, 349, 350, 351, 926, 352, 353, -1,
  /* DiagSubGroup364 */ 362, 363, -1,
  /* DiagSubGroup365 */ 366, -1,
  /* DiagSubGroup367 */ 376, 377, -1,
  /* DiagSubGroup372 */ 373, -1,
  /* DiagSubGroup375 */ 379, 598, -1,
  /* DiagSubGroup378 */ 599, -1,
  /* DiagSubGroup379 */ 369, -1,
  /* DiagSubGroup391 */ 392, 388, -1,
  /* DiagSubGroup397 */ 399, 539, -1,
  /* DiagSubGroup403 */ 220, -1,
  /* DiagSubGroup414 */ 413, -1,
  /* DiagSubGroup416 */ 417, -1,
  /* DiagSubGroup420 */ 361, -1,
  /* DiagSubGroup444 */ 130, -1,
  /* DiagSubGroup447 */ 95, -1,
  /* DiagSubGroup448 */ 298, 682, -1,
  /* DiagSubGroup459 */ 463, 468, 480, 466, 476, 484, 460, 489, 472, 490, 481, 482, 488, 474, 471, 467, 486, 483, 470, 478, 477, 475, 462, 465, 491, 461, 464, 469, 485, 400, -1,
  /* DiagSubGroup486 */ 487, -1,
  /* DiagSubGroup522 */ 76, 147, 153, 198, 299, 298, 313, 367, 404, 415, 496, 497, 523, 526, 684, 696, 708, 718, 721, 745, 746, 783, 800, 823, 848, 855, 879, 918, 580, 569, 571, 621, 669, 143, 281, 905, -1,
  /* DiagSubGroup523 */ 639, 691, 707, 721, -1,
  /* DiagSubGroup524 */ 480, -1,
  /* DiagSubGroup528 */ 96, -1,
  /* DiagSubGroup534 */ 104, -1,
  /* DiagSubGroup536 */ 740, 170, 443, -1,
  /* DiagSubGroup539 */ 538, -1,
  /* DiagSubGroup558 */ 559, -1,
  /* DiagSubGroup568 */ 594, -1,
  /* DiagSubGroup574 */ 600, -1,
  /* DiagSubGroup594 */ 595, -1,
  /* DiagSubGroup597 */ 599, 598, 565, 804, -1,
  /* DiagSubGroup607 */ 754, 609, 610, 612, 611, 608, -1,
  /* DiagSubGroup612 */ 611, -1,
  /* DiagSubGroup622 */ 406, -1,
  /* DiagSubGroup628 */ 446, 445, 70, 72, 736, 620, 629, 184, -1,
  /* DiagSubGroup630 */ 842, -1,
  /* DiagSubGroup636 */ 133, 93, 95, 97, 98, 102, 111, 114, 293, 321, 328, 330, 331, 332, 333, 334, 335, 337, 338, 339, 340, 342, 343, 345, 346, 347, 350, 352, 353, 436, 447, 463, 464, 466, 469, 471, 476, 477, 483, 619, 914, 926, 383, 259, 263, 561, 290, 66, 837, 705, 157, 529, 192, 245, 438, 199, -1,
  /* DiagSubGroup638 */ 224, 449, 81, 704, 289, -1,
  /* DiagSubGroup645 */ 915, -1,
  /* DiagSubGroup646 */ 645, 916, -1,
  /* DiagSubGroup653 */ 654, -1,
  /* DiagSubGroup656 */ 855, 364, 651, 653, -1,
  /* DiagSubGroup658 */ 657, 125, -1,
  /* DiagSubGroup660 */ 659, -1,
  /* DiagSubGroup662 */ 661, -1,
  /* DiagSubGroup664 */ 663, -1,
  /* DiagSubGroup666 */ 665, -1,
  /* DiagSubGroup682 */ 684, 683, -1,
  /* DiagSubGroup693 */ 225, -1,
  /* DiagSubGroup696 */ 697, 698, -1,
  /* DiagSubGroup700 */ 702, -1,
  /* DiagSubGroup701 */ 702, -1,
  /* DiagSubGroup703 */ 91, -1,
  /* DiagSubGroup708 */ 709, -1,
  /* DiagSubGroup716 */ 717, -1,
  /* DiagSubGroup718 */ 720, 719, -1,
  /* DiagSubGroup724 */ 867, -1,
  /* DiagSubGroup726 */ 730, 731, -1,
  /* DiagSubGroup727 */ 726, 729, 732, 728, -1,
  /* DiagSubGroup729 */ 730, -1,
  /* DiagSubGroup756 */ 755, -1,
  /* DiagSubGroup759 */ 348, -1,
  /* DiagSubGroup776 */ 649, -1,
  /* DiagSubGroup790 */ 749, 254, 548, 456, 789, -1,
  /* DiagSubGroup800 */ 801, 806, 805, 799, 808, 804, -1,
  /* DiagSubGroup801 */ 803, -1,
  /* DiagSubGroup802 */ 824, 812, -1,
  /* DiagSubGroup815 */ 817, 816, 820, 821, -1,
  /* DiagSubGroup824 */ 807, 811, 809, 810, -1,
  /* DiagSubGroup841 */ 650, -1,
  /* DiagSubGroup842 */ 843, -1,
  /* DiagSubGroup848 */ 752, 763, 849, -1,
  /* DiagSubGroup858 */ 132, -1,
  /* DiagSubGroup861 */ 865, 864, -1,
  /* DiagSubGroup862 */ 861, 863, 866, -1,
  /* DiagSubGroup879 */ 880, 887, 889, 896, 890, 891, 900, 901, 882, 897, -1,
  /* DiagSubGroup887 */ 859, -1,
  /* DiagSubGroup892 */ 891, -1,
  /* DiagSubGroup894 */ 860, -1,
  /* DiagSubGroup899 */ 859, -1,
  /* DiagSubGroup900 */ 884, 898, 841, -1,
  /* DiagSubGroup901 */ 885, -1,
  /* DiagSubGroup910 */ 909, -1,
  /* DiagSubGroup913 */ 914, -1,
  /* DiagSubGroup916 */ 915, -1,
  /* DiagSubGroup922 */ 229, -1,
  /* DiagSubGroup923 */ 922, -1,
};

static const char DiagGroupNames[] = {
    "\000\020#pragma-messages\t#warnings\020CFString-literal\003CL4\032Indep"
    "endentClass-attribute\022NSObject-attribute\003abi\016absolute-value\024"
    "abstract-final-class\023abstract-vbase-init\007address\030address-of-pa"
    "cked-member\024address-of-temporary\020aggregate-return\naix-compat\016"
    "align-mismatch\003all\006alloca\031alloca-with-align-alignof\020ambiguo"
    "us-delete\022ambiguous-ellipsis\017ambiguous-macro\031ambiguous-member-"
    "template\033ambiguous-reversed-operator\034analyzer-incompatible-plugin"
    "\031anon-enum-enum-conversion\025anonymous-pack-parens\003arc%arc-bridg"
    "e-casts-disallowed-in-nonarc\036arc-maybe-repeated-use-of-weak\025arc-n"
    "on-pod-memaccess\031arc-performSelector-leaks\030arc-repeated-use-of-we"
    "ak\021arc-retain-cycles\032arc-unsafe-retained-assign\026argument-outsi"
    "de-range\034argument-undefined-behaviour\014array-bounds\037array-bound"
    "s-pointer-arithmetic\003asm\022asm-operand-widths\013assign-enum\006ass"
    "ume\013at-protocol\034atimport-in-framework-header\020atomic-alignment\027"
    "atomic-implicit-seq-cst\026atomic-memory-ordering\021atomic-properties*"
    "atomic-property-with-user-defined-accessor\035attribute-packed-for-bitf"
    "ield\021attribute-warning\nattributes\033auto-disable-vptr-sanitizer\013"
    "auto-import\022auto-storage-class\013auto-var-id\014availability\030avr"
    "-rtlib-linking-quirks\016backend-plugin\030backslash-newline-escape\021"
    "bad-function-cast\016binary-literal\026bind-to-temporary-copy\024bindin"
    "g-in-condition\021bit-int-extension\034bitfield-constant-conversion\030"
    "bitfield-enum-conversion\016bitfield-width\037bitwise-conditional-paren"
    "theses\032bitwise-instead-of-logical\026bitwise-op-parentheses\033block"
    "-capture-autoreleasing\017bool-conversion\020bool-conversions\016bool-o"
    "peration\022braced-scalar-init\021branch-protection\013bridge-cast buil"
    "tin-assume-aligned-alignment\027builtin-macro-redefined\027builtin-memc"
    "py-chk-size\027builtin-requires-header\nc++-compat\014c++0x-compat\020c"
    "++0x-extensions\017c++0x-narrowing\014c++11-compat(c++11-compat-depreca"
    "ted-writable-strings\025c++11-compat-pedantic*c++11-compat-reserved-use"
    "r-defined-literal\020c++11-extensions\020c++11-extra-semi\026c++11-inli"
    "ne-namespace\017c++11-long-long\017c++11-narrowing\032c++14-attribute-e"
    "xtensions\024c++14-binary-literal\014c++14-compat\025c++14-compat-pedan"
    "tic\020c++14-extensions\032c++17-attribute-extensions\014c++17-compat\025"
    "c++17-compat-mangling\025c++17-compat-pedantic\020c++17-extensions\020c"
    "++1y-extensions\014c++1z-compat\025c++1z-compat-mangling\020c++1z-exten"
    "sions\032c++20-attribute-extensions\014c++20-compat\025c++20-compat-ped"
    "antic\020c++20-designator\020c++20-extensions\014c++2a-compat\025c++2a-"
    "compat-pedantic\020c++2a-extensions\020c++2b-extensions\036c++98-c++11-"
    "c++14-c++17-compat'c++98-c++11-c++14-c++17-compat-pedantic\030c++98-c++"
    "11-c++14-compat!c++98-c++11-c++14-compat-pedantic\022c++98-c++11-compat"
    "!c++98-c++11-compat-binary-literal\033c++98-c++11-compat-pedantic\014c+"
    "+98-compat#c++98-compat-bind-to-temporary-copy\027c++98-compat-extra-se"
    "mi%c++98-compat-local-type-template-args\025c++98-compat-pedantic'c++98"
    "-compat-unnamed-type-template-args\016c11-extensions\016c2x-extensions\n"
    "c99-compat\016c99-designator\016c99-extensions#call-to-pure-virtual-fro"
    "m-ctor-dtor\025called-once-parameter\ncast-align\027cast-calling-conven"
    "tion\022cast-function-type\020cast-of-sel-type\tcast-qual\023cast-qual-"
    "unrelated\nchar-align\017char-subscripts\014clang-cl-pch\020class-conve"
    "rsion\015class-varargs\017cmse-union-leak\005comma\007comment\010commen"
    "ts\036compare-distinct-pointer-types\022completion-handler\026complex-c"
    "omponent-init\024compound-token-split\035compound-token-split-by-macro\035"
    "compound-token-split-by-space\022concepts-ts-compat\031conditional-type"
    "-mismatch\031conditional-uninitialized\015config-macros\023constant-con"
    "version\022constant-evaluated\030constant-logical-operand\023constexpr-"
    "not-const\010consumed\nconversion\017conversion-null\tcoroutine%corouti"
    "ne-missing-unhandled-exception\026covered-switch-default\003cpp\030cstr"
    "ing-format-directive\026ctad-maybe-unsupported\021ctor-dtor-privacy\003"
    "ctu\013cuda-compat\030custom-atomic-properties\027cxx-attribute-extensi"
    "on\010dangling\015dangling-else\016dangling-field\014dangling-gsl\031da"
    "ngling-initializer-list\023darwin-sdk-settings\tdate-time\023dealloc-in"
    "-category\035debug-compression-unavailable\033declaration-after-stateme"
    "nt\032defaulted-function-deleted\026delegating-ctor-cycles delete-abstr"
    "act-non-virtual-dtor\021delete-incomplete$delete-non-abstract-non-virtu"
    "al-dtor\027delete-non-virtual-dtor#delimited-escape-sequence-extension\n"
    "deprecated\035deprecated-altivec-src-compat$deprecated-anon-enum-enum-c"
    "onversion\030deprecated-array-compare\025deprecated-attributes\032depre"
    "cated-comma-subscript\017deprecated-copy\024deprecated-copy-dtor\031dep"
    "recated-copy-with-dtor'deprecated-copy-with-user-provided-copy'deprecat"
    "ed-copy-with-user-provided-dtor\024deprecated-coroutine\027deprecated-d"
    "eclarations!deprecated-dynamic-exception-spec\027deprecated-enum-compar"
    "e#deprecated-enum-compare-conditional\037deprecated-enum-enum-conversio"
    "n deprecated-enum-float-conversion!deprecated-experimental-coroutine\032"
    "deprecated-implementations\031deprecated-increment-bool\031deprecated-o"
    "bjc-isa-usage%deprecated-objc-pointer-introspection5deprecated-objc-poi"
    "nter-introspection-performSelector\021deprecated-pragma\023deprecated-r"
    "egister\027deprecated-this-capture\017deprecated-type\023deprecated-vol"
    "atile\033deprecated-writable-strings\022direct-ivar-access\030disabled-"
    "macro-expansion\025disabled-optimization\014discard-qual\034distributed"
    "-object-modifiers\013div-by-zero\020division-by-zero\036dll-attribute-o"
    "n-redeclaration%dllexport-explicit-instantiation-decl\032dllimport-stat"
    "ic-field-def\015documentation\035documentation-deprecated-sync\022docum"
    "entation-html\026documentation-pedantic\035documentation-unknown-comman"
    "d\036dollar-in-identifier-extension\020double-promotion\tdtor-name\014d"
    "tor-typedef\030duplicate-decl-specifier\016duplicate-enum\024duplicate-"
    "method-arg\026duplicate-method-match\022duplicate-protocol\027dynamic-c"
    "lass-memaccess\026dynamic-exception-spec\006effc++\024elaborated-enum-b"
    "ase\025elaborated-enum-class\022embedded-directive\nempty-body\023empty"
    "-decomposition\017empty-init-stmt\026empty-translation-unit\013encode-t"
    "ype\014endif-labels\014enum-compare\030enum-compare-conditional\023enum"
    "-compare-switch\017enum-conversion\024enum-enum-conversion\025enum-floa"
    "t-conversion\016enum-too-large\nexceptions\023excess-initializers\025ex"
    "it-time-destructors\024expansion-to-defined\030explicit-initialize-call"
    "\027explicit-ownership-type\016export-unnamed\026export-using-directive"
    "\017extern-c-compat\022extern-initializer\005extra\023extra-qualificati"
    "on\nextra-semi\017extra-semi-stmt\014extra-tokens\032final-dtor-non-fin"
    "al-class\013final-macro\024fixed-enum-extension\024fixed-point-overflow"
    "\tflag-enum\031flexible-array-extensions\020float-conversion\013float-e"
    "qual\031float-overflow-conversion\025float-zero-conversion\021for-loop-"
    "analysis\006format\021format-extra-args\030format-insufficient-args\030"
    "format-invalid-specifier\016format-non-iso\021format-nonliteral\017form"
    "at-pedantic\017format-security\025format-type-confusion\nformat-y2k\022"
    "format-zero-length\010format=2\016fortify-source\023four-char-constants"
    "\015frame-address\021frame-larger-than\022frame-larger-than=%framework-"
    "include-private-from-public\023free-nonheap-object\036function-def-in-o"
    "bjc-container\025function-multiversion\014fuse-ld-path\033future-attrib"
    "ute-extensions\015future-compat\ngcc-compat\023global-constructors\013g"
    "lobal-isel\003gnu\026gnu-alignof-expression\024gnu-anonymous-struct\033"
    "gnu-array-member-paren-init\015gnu-auto-type\022gnu-binary-literal\016g"
    "nu-case-range\023gnu-complex-integer gnu-compound-literal-initializer\037"
    "gnu-conditional-omitted-operand\016gnu-designator\025gnu-empty-initiali"
    "zer\020gnu-empty-struct\036gnu-flexible-array-initializer\037gnu-flexib"
    "le-array-union-member\024gnu-folding-constant\026gnu-imaginary-constant"
    "\020gnu-include-next\035gnu-inline-cpp-without-extern\022gnu-label-as-v"
    "alue\023gnu-redeclared-enum\030gnu-statement-expression\025gnu-static-f"
    "loat-init$gnu-string-literal-operator-template\016gnu-union-cast\"gnu-v"
    "ariable-sized-type-not-at-end\027gnu-zero-line-directive!gnu-zero-varia"
    "dic-macro-arguments\024gpu-maybe-wrong-side\014header-guard\016header-h"
    "ygiene\010hip-only\025idiomatic-parentheses\022ignored-attributes)ignor"
    "ed-availability-without-sdk-settings\035ignored-optimization-argument\030"
    "ignored-pragma-intrinsic\027ignored-pragma-optimize\017ignored-pragmas\022"
    "ignored-qualifiers\034ignored-reference-qualifiers\010implicit\032impli"
    "cit-atomic-properties#implicit-const-int-float-conversion*implicit-conv"
    "ersion-floating-point-to-bool implicit-exception-spec-mismatch\024impli"
    "cit-fallthrough!implicit-fallthrough-per-function\037implicit-fixed-poi"
    "nt-conversion\031implicit-float-conversion\035implicit-function-declara"
    "tion\014implicit-int\027implicit-int-conversion\035implicit-int-float-c"
    "onversion\024implicit-retain-self\033implicitly-unsigned-literal\006imp"
    "ort&import-preprocessor-directive-pedantic\021inaccessible-base\032incl"
    "ude-next-absolute-path\033include-next-outside-header\033incompatible-e"
    "xception-spec#incompatible-function-pointer-types\"incompatible-library"
    "-redeclaration\026incompatible-ms-struct\032incompatible-pointer-types."
    "incompatible-pointer-types-discards-qualifiers\032incompatible-property"
    "-type\024incompatible-sysroot'incomplete-framework-module-declaration\031"
    "incomplete-implementation\021incomplete-module\035incomplete-setjmp-dec"
    "laration\023incomplete-umbrella\026inconsistent-dllimport(inconsistent-"
    "missing-destructor-override\035inconsistent-missing-override\016increme"
    "nt-bool\022infinite-recursion\tinit-self\025initializer-overrides\023in"
    "jected-class-name\006inline\ninline-asm#inline-namespace-reopened-nonin"
    "line\021inline-new-delete\"instantiation-after-specialization\016int-co"
    "nversion\017int-conversions\023int-in-bool-context\023int-to-pointer-ca"
    "st\030int-to-void-pointer-cast\020integer-overflow\031interrupt-service"
    "-routine\035invalid-command-line-argument\021invalid-constexpr\020inval"
    "id-iboutlet&invalid-initializer-from-system-header\035invalid-ios-deplo"
    "yment-target\030invalid-no-builtin-names\020invalid-noreturn\020invalid"
    "-offsetof invalid-or-nonexistent-directory\036invalid-partial-specializ"
    "ation\013invalid-pch\020invalid-pp-token\027invalid-source-encoding\023"
    "invalid-token-paste\020jump-seh-finally\016keyword-compat\015keyword-ma"
    "cro\026knr-promoted-parameter\030language-extension-token\023large-by-v"
    "alue-copy\006liblto\017linker-warnings\022literal-conversion\015literal"
    "-range\030local-type-template-args\027logical-not-parentheses\026logica"
    "l-op-parentheses\tlong-long\015loop-analysis\017macro-redefined\004main"
    "\020main-return-type\027malformed-warning-check\036many-braces-around-s"
    "calar-init\nmax-tokens\021max-unsigned-zero\026memset-transposed-args\022"
    "memsize-comparison\021method-signatures\tmicrosoft\022microsoft-abstrac"
    "t\022microsoft-anon-tag\016microsoft-cast\021microsoft-charize\027micro"
    "soft-comment-paste\024microsoft-const-init\023microsoft-cpp-macro\"micr"
    "osoft-default-arg-redefinition\031microsoft-drectve-section\025microsof"
    "t-end-of-file microsoft-enum-forward-reference\024microsoft-enum-value\030"
    "microsoft-exception-spec\020microsoft-exists#microsoft-explicit-constru"
    "ctor-call\035microsoft-extra-qualification\024microsoft-fixed-enum\030m"
    "icrosoft-flexible-array\016microsoft-goto\033microsoft-inaccessible-bas"
    "e\021microsoft-include\033microsoft-mutable-reference\031microsoft-pure"
    "-definition\032microsoft-redeclare-static\020microsoft-sealed\027micros"
    "oft-static-assert\022microsoft-template\031microsoft-template-shadow mi"
    "crosoft-union-member-reference\034microsoft-unqualified-friend\024micro"
    "soft-using-decl\032microsoft-void-pseudo-dtor\026misleading-indentation"
    "\025mismatched-new-delete\032mismatched-parameter-types\027mismatched-r"
    "eturn-types\017mismatched-tags\016missing-braces\021missing-constinit\024"
    "missing-declarations\026missing-exception-spec\032missing-field-initial"
    "izers\030missing-format-attribute\024missing-include-dirs\032missing-me"
    "thod-return-type\020missing-noescape\020missing-noreturn\030missing-pro"
    "totype-for-cc\022missing-prototypes\025missing-selector-name\017missing"
    "-sysroot\035missing-variable-declarations\025misspelled-assumption\014m"
    "odule-build\017module-conflict\033module-file-config-mismatch\025module"
    "-file-extension\015module-import\031module-import-in-extern-c\013module"
    "-lock\"modules-ambiguous-internal-linkage\037modules-import-nested-redu"
    "ndant\004most\004move\014msvc-include\016msvc-not-found\tmultichar\023m"
    "ultiple-move-vbase\tnarrowing\021nested-anon-types\016nested-externs\020"
    "new-returns-null\013newline-eof\007noderef\015noexcept-type\031non-c-ty"
    "pedef-for-linkage\007non-gcc\033non-literal-null-conversion'non-modular"
    "-include-in-framework-module\035non-modular-include-in-module\017non-po"
    "d-varargs\032non-power-of-two-alignment\020non-virtual-dtor\007nonnull\025"
    "nonportable-cfstrings\030nonportable-include-path\037nonportable-system"
    "-include-path!nonportable-vector-initialization\024nontrivial-memaccess"
    "\023nsconsumed-mismatch\022nsreturns-mismatch\017null-arithmetic\016nul"
    "l-character\017null-conversion\020null-dereference\027null-pointer-arit"
    "hmetic\030null-pointer-subtraction\013nullability\030nullability-comple"
    "teness\"nullability-completeness-on-arrays\024nullability-declspec\025n"
    "ullability-extension#nullability-inferred-on-nested-type\036nullable-to"
    "-nonnull-conversion+objc-autosynthesis-property-ivar-name-match\035objc"
    "-bool-constant-conversion\013objc-boxing\027objc-circular-container\016"
    "objc-cocoa-api\034objc-designated-initializers\036objc-dictionary-dupli"
    "cate-keys\023objc-flexible-array\037objc-forward-class-redefinition\024"
    "objc-interface-ivars\024objc-literal-compare\027objc-literal-conversion"
    "\027objc-macro-redefinition\021objc-messaging-id\022objc-method-access\037"
    "objc-missing-property-synthesis\030objc-missing-super-calls\032objc-mul"
    "tiple-method-names\"objc-noncopy-retain-block-property\032objc-nonunifi"
    "ed-exceptions#objc-property-assign-on-object-type\034objc-property-impl"
    "ementation\037objc-property-implicit-mismatch*objc-property-matches-coc"
    "oa-ownership-rule\032objc-property-no-attribute\027objc-property-synthe"
    "sis#objc-protocol-method-implementation objc-protocol-property-synthesi"
    "s\030objc-protocol-qualifiers\"objc-readonly-with-setter-property\026ob"
    "jc-redundant-api-use\032objc-redundant-literal-use\017objc-root-class\025"
    "objc-signed-char-bool/objc-signed-char-bool-implicit-float-conversion-o"
    "bjc-signed-char-bool-implicit-int-conversion\023objc-string-compare\031"
    "objc-string-concatenation\034objc-unsafe-perform-selector\003odr\016old"
    "-style-cast\024old-style-definition\027opencl-unsupported-rgba\006openm"
    "p\024openmp-51-extensions\016openmp-clauses\020openmp-loop-form\016open"
    "mp-mapping\015openmp-target\016option-ignored!ordered-compare-function-"
    "pointers\027out-of-line-declaration\025out-of-scope-function\014over-al"
    "igned\010overflow\022overlength-strings\037overloaded-shift-op-parenthe"
    "ses\022overloaded-virtual\015override-init\017override-module\032overri"
    "ding-method-mismatch\023overriding-t-option\006packed\006padded\013pare"
    "ntheses\024parentheses-equality\024partial-availability\004pass\015pass"
    "-analysis\013pass-failed\013pass-missed\015pch-date-time\010pedantic\026"
    "pedantic-core-features\017pedantic-macros\020pessimizing-move\015pointe"
    "r-arith\027pointer-bool-conversion\017pointer-compare\027pointer-intege"
    "r-compare\014pointer-sign\024pointer-to-enum-cast\023pointer-to-int-cas"
    "t\025pointer-type-mismatch\031poison-system-directories\033potentially-"
    "direct-selector potentially-evaluated-expression\026pragma-clang-attrib"
    "ute\032pragma-once-outside-header\013pragma-pack\036pragma-pack-suspici"
    "ous-include#pragma-system-header-outside-header\007pragmas\020pre-c++14"
    "-compat\031pre-c++14-compat-pedantic\020pre-c++17-compat\031pre-c++17-c"
    "ompat-pedantic\020pre-c++20-compat\031pre-c++20-compat-pedantic\020pre-"
    "c++2b-compat\031pre-c++2b-compat-pedantic\016pre-c2x-compat\027pre-c2x-"
    "compat-pedantic\024pre-openmp-51-compat&predefined-identifier-outside-f"
    "unction\016private-extern\016private-header\016private-module\025profil"
    "e-instr-missing\031profile-instr-out-of-date\030profile-instr-unprofile"
    "d\032property-access-dot-syntax\033property-attribute-mismatch\010proto"
    "col%protocol-property-synthesis-ambiguity\005psabi\032qualified-void-re"
    "turn-type\"quoted-include-in-framework-header\023range-loop-analysis\031"
    "range-loop-bind-reference\024range-loop-construct\032readonly-iboutlet-"
    "property\015receiver-expr\026receiver-forward-class\027redeclared-class"
    "-member\026redundant-consteval-if\017redundant-decls\016redundant-move\020"
    "redundant-parens\010register\026reinterpret-base-class\025remark-backen"
    "d-plugin\007reorder\014reorder-ctor\021reorder-init-list\030requires-su"
    "per-attribute\021reserved-id-macro\023reserved-identifier\031reserved-m"
    "acro-identifier\035reserved-user-defined-literal\022restrict-expansion\031"
    "retained-language-linkage\024return-stack-address\017return-std-move\013"
    "return-type\025return-type-c-linkage\020rewrite-not-bool\023round-trip-"
    "cc1-args\004rtti\020sanitize-address\021search-path-usage\007section\010"
    "selector\026selector-type-mismatch\013self-assign\021self-assign-field\026"
    "self-assign-overloaded\tself-move\034semicolon-before-method-body\010se"
    "ntinel\016sequence-point\026serialized-diagnostics\006shadow\nshadow-al"
    "l\014shadow-field\033shadow-field-in-constructor$shadow-field-in-constr"
    "uctor-modified\013shadow-ivar\027shadow-uncaptured-local\024shift-count"
    "-negative\024shift-count-overflow\024shift-negative-value\024shift-op-p"
    "arentheses\016shift-overflow\023shift-sign-overflow\020shorten-64-to-32"
    "\014sign-compare\017sign-conversion\nsign-promo\024signed-enum-bitfield"
    "\025signed-unsigned-wchar\025sizeof-array-argument\022sizeof-array-deca"
    "y\020sizeof-array-div\022sizeof-pointer-div\030sizeof-pointer-memaccess"
    "\020slash-u-filename\014slh-asm-goto\027sometimes-uninitialized\nsource"
    "-mgr\022source-uses-openmp\013spir-compat\014spirv-compat\017stack-exha"
    "usted\017stack-protector\021static-float-init\020static-in-inline$stati"
    "c-inline-explicit-instantiation\026static-local-in-inline\020static-sel"
    "f-init\023stdlibcxx-not-found\017strict-aliasing\021strict-aliasing=0\021"
    "strict-aliasing=1\021strict-aliasing=2\017strict-overflow\021strict-ove"
    "rflow=0\021strict-overflow=1\021strict-overflow=2\021strict-overflow=3\021"
    "strict-overflow=4\021strict-overflow=5\"strict-potentially-direct-selec"
    "tor\021strict-prototypes\025strict-selector-match\016string-compare\024"
    "string-concatenation\021string-conversion\020string-plus-char\017string"
    "-plus-int\024strlcpy-strlcat-size\014strncat-size\033suggest-destructor"
    "-override\020suggest-override\033super-class-method-mismatch\020suspici"
    "ous-bzero\024suspicious-memaccess\024swift-name-attribute\006switch\013"
    "switch-bool\016switch-default\013switch-enum%sync-fetch-and-nand-semant"
    "ics-changed\005synth\036target-clones-mixed-specifiers\034tautological-"
    "bitwise-compare\024tautological-compare\035tautological-constant-compar"
    "e&tautological-constant-in-range-compare*tautological-constant-out-of-r"
    "ange-compare\036tautological-objc-bool-compare\034tautological-overlap-"
    "compare\034tautological-pointer-compare\037tautological-type-limit-comp"
    "are\036tautological-undefined-compare'tautological-unsigned-char-zero-c"
    "ompare'tautological-unsigned-enum-zero-compare\"tautological-unsigned-z"
    "ero-compare tautological-value-range-compare\017tcb-enforcement$tentati"
    "ve-definition-incomplete-type\015thread-safety\026thread-safety-analysi"
    "s\030thread-safety-attributes\022thread-safety-beta\026thread-safety-ne"
    "gative\025thread-safety-precise\027thread-safety-reference\025thread-sa"
    "fety-verbose\ttrigraphs\013type-limits\013type-safety\024typedef-redefi"
    "nition\020typename-missing\031unable-to-open-stats-file\030unavailable-"
    "declarations\023undeclared-selector\005undef\014undef-prefix\031undefin"
    "ed-bool-conversion\027undefined-func-template\020undefined-inline\022un"
    "defined-internal\027undefined-internal-type\032undefined-reinterpret-ca"
    "st\026undefined-var-template\035underaligned-exception-object\026uneval"
    "uated-expression\026unguarded-availability\032unguarded-availability-ne"
    "w\007unicode\021unicode-homoglyph\022unicode-whitespace\022unicode-zero"
    "-width\015uninitialized\035uninitialized-const-reference\020unknown-arg"
    "ument\022unknown-assumption\022unknown-attributes\024unknown-cuda-versi"
    "on\027unknown-escape-sequence\017unknown-pragmas\022unknown-sanitizers\026"
    "unknown-warning-option\032unnamed-type-template-args\035unneeded-intern"
    "al-declaration\030unneeded-member-function\020unreachable-code\033unrea"
    "chable-code-aggressive\026unreachable-code-break\034unreachable-code-fa"
    "llthrough\037unreachable-code-loop-increment\027unreachable-code-return"
    "\013unsequenced\017unsupported-abs\036unsupported-availability-guard\016"
    "unsupported-cb#unsupported-dll-base-class-template\036unsupported-float"
    "ing-point-opt\022unsupported-friend\021unsupported-gpopt\017unsupported"
    "-nan\026unsupported-target-opt\026unsupported-visibility\037unusable-pa"
    "rtial-specialization\006unused\017unused-argument\030unused-but-set-par"
    "ameter\027unused-but-set-variable\034unused-command-line-argument\021un"
    "used-comparison\025unused-const-variable\032unused-exception-parameter\017"
    "unused-function\032unused-getter-return-value\014unused-label\025unused"
    "-lambda-capture\024unused-local-typedef\025unused-local-typedefs\015unu"
    "sed-macros\026unused-member-function\020unused-parameter\024unused-priv"
    "ate-field\024unused-property-ivar\015unused-result\017unused-template\014"
    "unused-value\017unused-variable\026unused-volatile-lvalue\026used-but-m"
    "arked-unused\025user-defined-literals\025user-defined-warnings\007varar"
    "gs\017variadic-macros\015vec-elem-size\021vector-conversion\022vector-c"
    "onversions\014vexing-parse\nvisibility\003vla\015vla-extension\031void-"
    "pointer-to-enum-cast\030void-pointer-to-int-cast\024void-ptr-dereferenc"
    "e\025volatile-register-var\023wasm-exception-spec\025weak-template-vtab"
    "les\014weak-vtables\020writable-strings\015write-strings\017xor-used-as"
    "-pow\035zero-as-null-pointer-constant\021zero-length-array"};

#endif // GET_DIAG_ARRAYS


#ifdef DIAG_ENTRY
DIAG_ENTRY(anonymous_53 /*  */, 0, 0, /* DiagSubGroup0 */ 1)
DIAG_ENTRY(PoundPragmaMessage /* #pragma-messages */, 1, /* DiagArray1 */ 1, 0)
DIAG_ENTRY(PoundWarning /* #warnings */, 18, /* DiagArray2 */ 3, 0)
DIAG_ENTRY(anonymous_249 /* CFString-literal */, 28, /* DiagArray3 */ 5, 0)
DIAG_ENTRY(anonymous_52 /* CL4 */, 45, 0, /* DiagSubGroup4 */ 3)
DIAG_ENTRY(IndependentClassAttribute /* IndependentClass-attribute */, 49, /* DiagArray5 */ 7, 0)
DIAG_ENTRY(NSobjectAttribute /* NSObject-attribute */, 76, /* DiagArray6 */ 10, 0)
DIAG_ENTRY(anonymous_0 /* abi */, 95, 0, 0)
DIAG_ENTRY(AbsoluteValue /* absolute-value */, 99, /* DiagArray8 */ 12, 0)
DIAG_ENTRY(AbstractFinalClass /* abstract-final-class */, 114, /* DiagArray9 */ 17, 0)
DIAG_ENTRY(anonymous_243 /* abstract-vbase-init */, 135, /* DiagArray10 */ 19, 0)
DIAG_ENTRY(anonymous_51 /* address */, 155, 0, /* DiagSubGroup11 */ 6)
DIAG_ENTRY(anonymous_223 /* address-of-packed-member */, 163, /* DiagArray12 */ 21, 0)
DIAG_ENTRY(AddressOfTemporary /* address-of-temporary */, 188, /* DiagArray13 */ 23, 0)
DIAG_ENTRY(anonymous_1 /* aggregate-return */, 209, 0, 0)
DIAG_ENTRY(AIXCompat /* aix-compat */, 226, /* DiagArray15 */ 25, 0)
DIAG_ENTRY(anonymous_224 /* align-mismatch */, 237, /* DiagArray16 */ 28, 0)
DIAG_ENTRY(All /* all */, 252, 0, /* DiagSubGroup17 */ 10)
DIAG_ENTRY(anonymous_169 /* alloca */, 256, /* DiagArray18 */ 30, 0)
DIAG_ENTRY(anonymous_170 /* alloca-with-align-alignof */, 263, /* DiagArray19 */ 32, 0)
DIAG_ENTRY(anonymous_230 /* ambiguous-delete */, 289, /* DiagArray20 */ 34, 0)
DIAG_ENTRY(anonymous_124 /* ambiguous-ellipsis */, 306, /* DiagArray21 */ 36, 0)
DIAG_ENTRY(AmbiguousMacro /* ambiguous-macro */, 325, /* DiagArray22 */ 38, 0)
DIAG_ENTRY(AmbigMemberTemplate /* ambiguous-member-template */, 341, /* DiagArray23 */ 40, 0)
DIAG_ENTRY(anonymous_190 /* ambiguous-reversed-operator */, 367, /* DiagArray24 */ 42, 0)
DIAG_ENTRY(anonymous_86 /* analyzer-incompatible-plugin */, 395, /* DiagArray25 */ 44, 0)
DIAG_ENTRY(AnonEnumEnumConversion /* anon-enum-enum-conversion */, 424, /* DiagArray26 */ 46, /* DiagSubGroup26 */ 16)
DIAG_ENTRY(anonymous_125 /* anonymous-pack-parens */, 450, /* DiagArray27 */ 48, 0)
DIAG_ENTRY(AutomaticReferenceCounting /* arc */, 472, 0, /* DiagSubGroup28 */ 18)
DIAG_ENTRY(anonymous_123 /* arc-bridge-casts-disallowed-in-nonarc */, 476, /* DiagArray29 */ 50, 0)
DIAG_ENTRY(ARCRepeatedUseOfWeakMaybe /* arc-maybe-repeated-use-of-weak */, 514, /* DiagArray30 */ 52, 0)
DIAG_ENTRY(ARCNonPodMemAccess /* arc-non-pod-memaccess */, 545, /* DiagArray31 */ 54, 0)
DIAG_ENTRY(anonymous_154 /* arc-performSelector-leaks */, 567, /* DiagArray32 */ 56, 0)
DIAG_ENTRY(ARCRepeatedUseOfWeak /* arc-repeated-use-of-weak */, 593, /* DiagArray33 */ 58, /* DiagSubGroup33 */ 22)
DIAG_ENTRY(ARCRetainCycles /* arc-retain-cycles */, 618, /* DiagArray34 */ 60, 0)
DIAG_ENTRY(ARCUnsafeRetainedAssign /* arc-unsafe-retained-assign */, 636, /* DiagArray35 */ 62, 0)
DIAG_ENTRY(anonymous_251 /* argument-outside-range */, 663, /* DiagArray36 */ 66, 0)
DIAG_ENTRY(anonymous_252 /* argument-undefined-behaviour */, 686, /* DiagArray37 */ 68, 0)
DIAG_ENTRY(ArrayBounds /* array-bounds */, 715, /* DiagArray38 */ 70, 0)
DIAG_ENTRY(ArrayBoundsPointerArithmetic /* array-bounds-pointer-arithmetic */, 728, /* DiagArray39 */ 76, 0)
DIAG_ENTRY(ASM /* asm */, 760, 0, /* DiagSubGroup40 */ 24)
DIAG_ENTRY(ASMOperandWidths /* asm-operand-widths */, 764, /* DiagArray41 */ 79, 0)
DIAG_ENTRY(anonymous_250 /* assign-enum */, 783, /* DiagArray42 */ 81, 0)
DIAG_ENTRY(anonymous_141 /* assume */, 795, /* DiagArray43 */ 83, 0)
DIAG_ENTRY(anonymous_50 /* at-protocol */, 802, 0, 0)
DIAG_ENTRY(FrameworkHdrAtImport /* atimport-in-framework-header */, 814, /* DiagArray45 */ 85, 0)
DIAG_ENTRY(AtomicAlignment /* atomic-alignment */, 843, /* DiagArray46 */ 87, 0)
DIAG_ENTRY(anonymous_236 /* atomic-implicit-seq-cst */, 860, /* DiagArray47 */ 90, 0)
DIAG_ENTRY(anonymous_235 /* atomic-memory-ordering */, 884, /* DiagArray48 */ 92, 0)
DIAG_ENTRY(AtomicProperties /* atomic-properties */, 907, 0, /* DiagSubGroup49 */ 26)
DIAG_ENTRY(anonymous_149 /* atomic-property-with-user-defined-accessor */, 925, /* DiagArray50 */ 94, 0)
DIAG_ENTRY(anonymous_186 /* attribute-packed-for-bitfield */, 968, /* DiagArray51 */ 96, 0)
DIAG_ENTRY(BackendWarningAttributes /* attribute-warning */, 998, /* DiagArray52 */ 98, 0)
DIAG_ENTRY(Attributes /* attributes */, 1016, 0, /* DiagSubGroup53 */ 29)
DIAG_ENTRY(AutoDisableVptrSanitizer /* auto-disable-vptr-sanitizer */, 1027, /* DiagArray54 */ 100, 0)
DIAG_ENTRY(AutoImport /* auto-import */, 1055, /* DiagArray55 */ 102, 0)
DIAG_ENTRY(anonymous_121 /* auto-storage-class */, 1067, /* DiagArray56 */ 104, 0)
DIAG_ENTRY(anonymous_166 /* auto-var-id */, 1086, /* DiagArray57 */ 106, 0)
DIAG_ENTRY(Availability /* availability */, 1098, /* DiagArray58 */ 108, 0)
DIAG_ENTRY(AVRRtlibLinkingQuirks /* avr-rtlib-linking-quirks */, 1111, /* DiagArray59 */ 119, 0)
DIAG_ENTRY(BackendPlugin /* backend-plugin */, 1136, /* DiagArray60 */ 126, 0)
DIAG_ENTRY(anonymous_89 /* backslash-newline-escape */, 1151, /* DiagArray61 */ 128, 0)
DIAG_ENTRY(BadFunctionCast /* bad-function-cast */, 1176, /* DiagArray62 */ 130, 0)
DIAG_ENTRY(BinaryLiteral /* binary-literal */, 1194, 0, /* DiagSubGroup63 */ 32)
DIAG_ENTRY(BindToTemporaryCopy /* bind-to-temporary-copy */, 1209, /* DiagArray64 */ 132, /* DiagSubGroup64 */ 36)
DIAG_ENTRY(anonymous_136 /* binding-in-condition */, 1232, /* DiagArray65 */ 135, 0)
DIAG_ENTRY(anonymous_128 /* bit-int-extension */, 1253, /* DiagArray66 */ 137, 0)
DIAG_ENTRY(BitFieldConstantConversion /* bitfield-constant-conversion */, 1271, /* DiagArray67 */ 139, 0)
DIAG_ENTRY(BitFieldEnumConversion /* bitfield-enum-conversion */, 1300, /* DiagArray68 */ 141, 0)
DIAG_ENTRY(BitFieldWidth /* bitfield-width */, 1325, /* DiagArray69 */ 145, 0)
DIAG_ENTRY(BitwiseConditionalParentheses /* bitwise-conditional-parentheses */, 1340, /* DiagArray70 */ 147, 0)
DIAG_ENTRY(BitwiseInsteadOfLogical /* bitwise-instead-of-logical */, 1372, /* DiagArray71 */ 149, 0)
DIAG_ENTRY(BitwiseOpParentheses /* bitwise-op-parentheses */, 1399, /* DiagArray72 */ 151, 0)
DIAG_ENTRY(BlockCaptureAutoReleasing /* block-capture-autoreleasing */, 1422, /* DiagArray73 */ 153, 0)
DIAG_ENTRY(BoolConversion /* bool-conversion */, 1450, /* DiagArray74 */ 155, /* DiagSubGroup74 */ 38)
DIAG_ENTRY(anonymous_58 /* bool-conversions */, 1466, 0, /* DiagSubGroup75 */ 41)
DIAG_ENTRY(BoolOperation /* bool-operation */, 1483, /* DiagArray76 */ 157, /* DiagSubGroup76 */ 43)
DIAG_ENTRY(anonymous_207 /* braced-scalar-init */, 1498, /* DiagArray77 */ 159, 0)
DIAG_ENTRY(BranchProtection /* branch-protection */, 1517, /* DiagArray78 */ 161, 0)
DIAG_ENTRY(ObjCBridge /* bridge-cast */, 1535, /* DiagArray79 */ 164, 0)
DIAG_ENTRY(anonymous_172 /* builtin-assume-aligned-alignment */, 1547, /* DiagArray80 */ 167, 0)
DIAG_ENTRY(BuiltinMacroRedefined /* builtin-macro-redefined */, 1580, /* DiagArray81 */ 169, 0)
DIAG_ENTRY(anonymous_142 /* builtin-memcpy-chk-size */, 1604, /* DiagArray82 */ 172, 0)
DIAG_ENTRY(BuiltinRequiresHeader /* builtin-requires-header */, 1628, /* DiagArray83 */ 174, 0)
DIAG_ENTRY(CXXCompat /* c++-compat */, 1652, /* DiagArray84 */ 176, 0)
DIAG_ENTRY(anonymous_18 /* c++0x-compat */, 1663, 0, /* DiagSubGroup85 */ 45)
DIAG_ENTRY(anonymous_62 /* c++0x-extensions */, 1676, 0, /* DiagSubGroup86 */ 47)
DIAG_ENTRY(anonymous_16 /* c++0x-narrowing */, 1693, 0, /* DiagSubGroup87 */ 49)
DIAG_ENTRY(CXX11Compat /* c++11-compat */, 1709, /* DiagArray88 */ 178, /* DiagSubGroup88 */ 51)
DIAG_ENTRY(CXX11CompatDeprecatedWritableStr /* c++11-compat-deprecated-writable-strings */, 1722, /* DiagArray89 */ 189, 0)
DIAG_ENTRY(CXX11CompatPedantic /* c++11-compat-pedantic */, 1763, 0, /* DiagSubGroup90 */ 59)
DIAG_ENTRY(CXX11CompatReservedUserDefinedLiteral /* c++11-compat-reserved-user-defined-literal */, 1785, /* DiagArray91 */ 191, 0)
DIAG_ENTRY(CXX11 /* c++11-extensions */, 1828, /* DiagArray92 */ 193, /* DiagSubGroup92 */ 65)
DIAG_ENTRY(CXX11ExtraSemi /* c++11-extra-semi */, 1845, /* DiagArray93 */ 219, 0)
DIAG_ENTRY(CXX11InlineNamespace /* c++11-inline-namespace */, 1862, /* DiagArray94 */ 221, 0)
DIAG_ENTRY(CXX11LongLong /* c++11-long-long */, 1885, /* DiagArray95 */ 223, 0)
DIAG_ENTRY(CXX11Narrowing /* c++11-narrowing */, 1901, /* DiagArray96 */ 225, 0)
DIAG_ENTRY(CXX14Attrs /* c++14-attribute-extensions */, 1917, /* DiagArray97 */ 233, 0)
DIAG_ENTRY(CXX14BinaryLiteral /* c++14-binary-literal */, 1944, /* DiagArray98 */ 235, 0)
DIAG_ENTRY(CXX14Compat /* c++14-compat */, 1965, 0, /* DiagSubGroup99 */ 69)
DIAG_ENTRY(CXX14CompatPedantic /* c++14-compat-pedantic */, 1978, 0, /* DiagSubGroup100 */ 73)
DIAG_ENTRY(CXX14 /* c++14-extensions */, 2000, /* DiagArray101 */ 237, /* DiagSubGroup101 */ 78)
DIAG_ENTRY(CXX17Attrs /* c++17-attribute-extensions */, 2017, /* DiagArray102 */ 245, 0)
DIAG_ENTRY(CXX17Compat /* c++17-compat */, 2044, 0, /* DiagSubGroup103 */ 81)
DIAG_ENTRY(CXX17CompatMangling /* c++17-compat-mangling */, 2057, /* DiagArray104 */ 247, 0)
DIAG_ENTRY(CXX17CompatPedantic /* c++17-compat-pedantic */, 2079, 0, /* DiagSubGroup105 */ 87)
DIAG_ENTRY(CXX17 /* c++17-extensions */, 2101, /* DiagArray106 */ 249, /* DiagSubGroup106 */ 91)
DIAG_ENTRY(anonymous_63 /* c++1y-extensions */, 2118, 0, /* DiagSubGroup107 */ 93)
DIAG_ENTRY(anonymous_19 /* c++1z-compat */, 2135, 0, /* DiagSubGroup108 */ 95)
DIAG_ENTRY(anonymous_9 /* c++1z-compat-mangling */, 2148, 0, /* DiagSubGroup109 */ 97)
DIAG_ENTRY(anonymous_64 /* c++1z-extensions */, 2170, 0, /* DiagSubGroup110 */ 99)
DIAG_ENTRY(CXX20Attrs /* c++20-attribute-extensions */, 2187, /* DiagArray111 */ 267, 0)
DIAG_ENTRY(CXX20Compat /* c++20-compat */, 2214, /* DiagArray112 */ 269, /* DiagSubGroup112 */ 101)
DIAG_ENTRY(CXX20CompatPedantic /* c++20-compat-pedantic */, 2227, 0, /* DiagSubGroup113 */ 103)
DIAG_ENTRY(CXX20Designator /* c++20-designator */, 2249, /* DiagArray114 */ 277, 0)
DIAG_ENTRY(CXX20 /* c++20-extensions */, 2266, /* DiagArray115 */ 279, /* DiagSubGroup115 */ 106)
DIAG_ENTRY(anonymous_20 /* c++2a-compat */, 2283, 0, /* DiagSubGroup116 */ 109)
DIAG_ENTRY(anonymous_21 /* c++2a-compat-pedantic */, 2296, 0, /* DiagSubGroup117 */ 111)
DIAG_ENTRY(anonymous_65 /* c++2a-extensions */, 2318, 0, /* DiagSubGroup118 */ 113)
DIAG_ENTRY(CXX2b /* c++2b-extensions */, 2335, /* DiagArray119 */ 299, 0)
DIAG_ENTRY(anonymous_14 /* c++98-c++11-c++14-c++17-compat */, 2352, 0, /* DiagSubGroup120 */ 115)
DIAG_ENTRY(anonymous_15 /* c++98-c++11-c++14-c++17-compat-pedantic */, 2383, 0, /* DiagSubGroup121 */ 117)
DIAG_ENTRY(anonymous_12 /* c++98-c++11-c++14-compat */, 2423, 0, /* DiagSubGroup122 */ 119)
DIAG_ENTRY(anonymous_13 /* c++98-c++11-c++14-compat-pedantic */, 2448, 0, /* DiagSubGroup123 */ 121)
DIAG_ENTRY(anonymous_10 /* c++98-c++11-compat */, 2482, 0, /* DiagSubGroup124 */ 123)
DIAG_ENTRY(CXXPre14CompatBinaryLiteral /* c++98-c++11-compat-binary-literal */, 2501, /* DiagArray125 */ 305, 0)
DIAG_ENTRY(anonymous_11 /* c++98-c++11-compat-pedantic */, 2535, 0, /* DiagSubGroup126 */ 125)
DIAG_ENTRY(CXX98Compat /* c++98-compat */, 2563, /* DiagArray127 */ 307, /* DiagSubGroup127 */ 127)
DIAG_ENTRY(CXX98CompatBindToTemporaryCopy /* c++98-compat-bind-to-temporary-copy */, 2576, /* DiagArray128 */ 367, 0)
DIAG_ENTRY(CXX98CompatExtraSemi /* c++98-compat-extra-semi */, 2612, /* DiagArray129 */ 369, 0)
DIAG_ENTRY(CXX98CompatLocalTypeTemplateArgs /* c++98-compat-local-type-template-args */, 2636, /* DiagArray130 */ 371, 0)
DIAG_ENTRY(CXX98CompatPedantic /* c++98-compat-pedantic */, 2674, /* DiagArray131 */ 373, /* DiagSubGroup131 */ 134)
DIAG_ENTRY(CXX98CompatUnnamedTypeTemplateArgs /* c++98-compat-unnamed-type-template-args */, 2696, /* DiagArray132 */ 383, 0)
DIAG_ENTRY(C11 /* c11-extensions */, 2736, /* DiagArray133 */ 385, 0)
DIAG_ENTRY(C2x /* c2x-extensions */, 2751, /* DiagArray134 */ 390, 0)
DIAG_ENTRY(C99Compat /* c99-compat */, 2766, /* DiagArray135 */ 393, 0)
DIAG_ENTRY(C99Designator /* c99-designator */, 2777, /* DiagArray136 */ 397, /* DiagSubGroup136 */ 142)
DIAG_ENTRY(C99 /* c99-extensions */, 2792, /* DiagArray137 */ 403, /* DiagSubGroup137 */ 144)
DIAG_ENTRY(PureVirtualCallFromCtorDtor /* call-to-pure-virtual-from-ctor-dtor */, 2807, /* DiagArray138 */ 414, 0)
DIAG_ENTRY(CalledOnceParameter /* called-once-parameter */, 2843, /* DiagArray139 */ 416, /* DiagSubGroup139 */ 146)
DIAG_ENTRY(CastAlign /* cast-align */, 2865, /* DiagArray140 */ 420, 0)
DIAG_ENTRY(anonymous_238 /* cast-calling-convention */, 2876, /* DiagArray141 */ 422, 0)
DIAG_ENTRY(CastFunctionType /* cast-function-type */, 2900, /* DiagArray142 */ 424, 0)
DIAG_ENTRY(SelTypeCast /* cast-of-sel-type */, 2919, /* DiagArray143 */ 426, 0)
DIAG_ENTRY(CastQual /* cast-qual */, 2936, /* DiagArray144 */ 428, 0)
DIAG_ENTRY(anonymous_228 /* cast-qual-unrelated */, 2946, /* DiagArray145 */ 431, 0)
DIAG_ENTRY(anonymous_2 /* char-align */, 2966, 0, 0)
DIAG_ENTRY(CharSubscript /* char-subscripts */, 2977, /* DiagArray147 */ 433, 0)
DIAG_ENTRY(ClangClPch /* clang-cl-pch */, 2993, /* DiagArray148 */ 436, 0)
DIAG_ENTRY(ClassConversion /* class-conversion */, 3006, /* DiagArray149 */ 441, 0)
DIAG_ENTRY(ClassVarargs /* class-varargs */, 3023, /* DiagArray150 */ 445, /* DiagSubGroup150 */ 148)
DIAG_ENTRY(anonymous_173 /* cmse-union-leak */, 3037, /* DiagArray151 */ 447, 0)
DIAG_ENTRY(anonymous_131 /* comma */, 3053, /* DiagArray152 */ 449, 0)
DIAG_ENTRY(Comment /* comment */, 3059, /* DiagArray153 */ 451, 0)
DIAG_ENTRY(anonymous_56 /* comments */, 3067, 0, /* DiagSubGroup154 */ 150)
DIAG_ENTRY(CompareDistinctPointerType /* compare-distinct-pointer-types */, 3076, /* DiagArray155 */ 456, 0)
DIAG_ENTRY(CompletionHandler /* completion-handler */, 3107, /* DiagArray156 */ 458, 0)
DIAG_ENTRY(anonymous_209 /* complex-component-init */, 3126, /* DiagArray157 */ 462, 0)
DIAG_ENTRY(CompoundTokenSplit /* compound-token-split */, 3149, 0, /* DiagSubGroup158 */ 152)
DIAG_ENTRY(CompoundTokenSplitByMacro /* compound-token-split-by-macro */, 3170, /* DiagArray159 */ 464, 0)
DIAG_ENTRY(CompoundTokenSplitBySpace /* compound-token-split-by-space */, 3200, /* DiagArray160 */ 466, 0)
DIAG_ENTRY(anonymous_129 /* concepts-ts-compat */, 3230, /* DiagArray161 */ 468, 0)
DIAG_ENTRY(anonymous_240 /* conditional-type-mismatch */, 3249, /* DiagArray162 */ 470, 0)
DIAG_ENTRY(UninitializedMaybe /* conditional-uninitialized */, 3275, /* DiagArray163 */ 472, 0)
DIAG_ENTRY(ConfigMacros /* config-macros */, 3301, /* DiagArray164 */ 474, 0)
DIAG_ENTRY(ConstantConversion /* constant-conversion */, 3315, /* DiagArray165 */ 476, /* DiagSubGroup165 */ 155)
DIAG_ENTRY(anonymous_71 /* constant-evaluated */, 3335, /* DiagArray166 */ 478, 0)
DIAG_ENTRY(anonymous_218 /* constant-logical-operand */, 3354, /* DiagArray167 */ 480, 0)
DIAG_ENTRY(anonymous_164 /* constexpr-not-const */, 3379, /* DiagArray168 */ 482, 0)
DIAG_ENTRY(Consumed /* consumed */, 3399, /* DiagArray169 */ 484, 0)
DIAG_ENTRY(Conversion /* conversion */, 3408, /* DiagArray170 */ 493, /* DiagSubGroup170 */ 158)
DIAG_ENTRY(anonymous_57 /* conversion-null */, 3419, 0, /* DiagSubGroup171 */ 174)
DIAG_ENTRY(Coroutine /* coroutine */, 3435, /* DiagArray172 */ 499, /* DiagSubGroup172 */ 176)
DIAG_ENTRY(CoroutineMissingUnhandledException /* coroutine-missing-unhandled-exception */, 3445, /* DiagArray173 */ 501, 0)
DIAG_ENTRY(CoveredSwitchDefault /* covered-switch-default */, 3483, /* DiagArray174 */ 503, 0)
DIAG_ENTRY(anonymous_55 /* cpp */, 3506, 0, /* DiagSubGroup175 */ 179)
DIAG_ENTRY(ObjCCStringFormat /* cstring-format-directive */, 3510, /* DiagArray176 */ 505, 0)
DIAG_ENTRY(CTADMaybeUnsupported /* ctad-maybe-unsupported */, 3535, /* DiagArray177 */ 507, 0)
DIAG_ENTRY(anonymous_3 /* ctor-dtor-privacy */, 3558, 0, 0)
DIAG_ENTRY(CrossTU /* ctu */, 3576, /* DiagArray179 */ 509, 0)
DIAG_ENTRY(CudaCompat /* cuda-compat */, 3580, /* DiagArray180 */ 511, 0)
DIAG_ENTRY(CustomAtomic /* custom-atomic-properties */, 3592, /* DiagArray181 */ 517, 0)
DIAG_ENTRY(anonymous_126 /* cxx-attribute-extension */, 3617, /* DiagArray182 */ 519, 0)
DIAG_ENTRY(Dangling /* dangling */, 3641, /* DiagArray183 */ 521, /* DiagSubGroup183 */ 181)
DIAG_ENTRY(DanglingElse /* dangling-else */, 3650, /* DiagArray184 */ 524, 0)
DIAG_ENTRY(DanglingField /* dangling-field */, 3664, /* DiagArray185 */ 526, 0)
DIAG_ENTRY(DanglingGsl /* dangling-gsl */, 3679, /* DiagArray186 */ 531, 0)
DIAG_ENTRY(DanglingInitializerList /* dangling-initializer-list */, 3692, /* DiagArray187 */ 534, 0)
DIAG_ENTRY(anonymous_82 /* darwin-sdk-settings */, 3718, /* DiagArray188 */ 536, 0)
DIAG_ENTRY(anonymous_111 /* date-time */, 3738, /* DiagArray189 */ 538, 0)
DIAG_ENTRY(DeallocInCategory /* dealloc-in-category */, 3748, /* DiagArray190 */ 540, 0)
DIAG_ENTRY(anonymous_79 /* debug-compression-unavailable */, 3768, /* DiagArray191 */ 542, 0)
DIAG_ENTRY(anonymous_254 /* declaration-after-statement */, 3798, /* DiagArray192 */ 544, 0)
DIAG_ENTRY(DefaultedFunctionDeleted /* defaulted-function-deleted */, 3826, /* DiagArray193 */ 546, 0)
DIAG_ENTRY(DelegatingCtorCycles /* delegating-ctor-cycles */, 3853, /* DiagArray194 */ 549, 0)
DIAG_ENTRY(DeleteAbstractNonVirtualDtor /* delete-abstract-non-virtual-dtor */, 3876, /* DiagArray195 */ 551, 0)
DIAG_ENTRY(DeleteIncomplete /* delete-incomplete */, 3909, /* DiagArray196 */ 553, 0)
DIAG_ENTRY(DeleteNonAbstractNonVirtualDtor /* delete-non-abstract-non-virtual-dtor */, 3927, /* DiagArray197 */ 556, 0)
DIAG_ENTRY(DeleteNonVirtualDtor /* delete-non-virtual-dtor */, 3964, 0, /* DiagSubGroup198 */ 186)
DIAG_ENTRY(anonymous_95 /* delimited-escape-sequence-extension */, 3988, /* DiagArray199 */ 558, 0)
DIAG_ENTRY(Deprecated /* deprecated */, 4024, /* DiagArray200 */ 560, /* DiagSubGroup200 */ 189)
DIAG_ENTRY(anonymous_231 /* deprecated-altivec-src-compat */, 4035, /* DiagArray201 */ 569, 0)
DIAG_ENTRY(DeprecatedAnonEnumEnumConversion /* deprecated-anon-enum-enum-conversion */, 4065, /* DiagArray202 */ 571, 0)
DIAG_ENTRY(DeprecatedArrayCompare /* deprecated-array-compare */, 4102, /* DiagArray203 */ 573, 0)
DIAG_ENTRY(DeprecatedAttributes /* deprecated-attributes */, 4127, /* DiagArray204 */ 575, 0)
DIAG_ENTRY(DeprecatedCommaSubscript /* deprecated-comma-subscript */, 4149, /* DiagArray205 */ 577, 0)
DIAG_ENTRY(DeprecatedCopy /* deprecated-copy */, 4176, /* DiagArray206 */ 579, /* DiagSubGroup206 */ 209)
DIAG_ENTRY(anonymous_4 /* deprecated-copy-dtor */, 4192, 0, /* DiagSubGroup207 */ 211)
DIAG_ENTRY(DeprecatedCopyWithDtor /* deprecated-copy-with-dtor */, 4213, /* DiagArray208 */ 581, /* DiagSubGroup208 */ 213)
DIAG_ENTRY(DeprecatedCopyWithUserProvidedCopy /* deprecated-copy-with-user-provided-copy */, 4239, /* DiagArray209 */ 583, 0)
DIAG_ENTRY(DeprecatedCopyWithUserProvidedDtor /* deprecated-copy-with-user-provided-dtor */, 4279, /* DiagArray210 */ 585, 0)
DIAG_ENTRY(DeprecatedCoroutine /* deprecated-coroutine */, 4319, /* DiagArray211 */ 587, /* DiagSubGroup211 */ 215)
DIAG_ENTRY(DeprecatedDeclarations /* deprecated-declarations */, 4340, /* DiagArray212 */ 589, 0)
DIAG_ENTRY(DeprecatedDynamicExceptionSpec /* deprecated-dynamic-exception-spec */, 4364, /* DiagArray213 */ 596, 0)
DIAG_ENTRY(DeprecatedEnumCompare /* deprecated-enum-compare */, 4398, /* DiagArray214 */ 598, 0)
DIAG_ENTRY(DeprecatedEnumCompareConditional /* deprecated-enum-compare-conditional */, 4422, /* DiagArray215 */ 600, 0)
DIAG_ENTRY(DeprecatedEnumEnumConversion /* deprecated-enum-enum-conversion */, 4458, /* DiagArray216 */ 602, 0)
DIAG_ENTRY(DeprecatedEnumFloatConversion /* deprecated-enum-float-conversion */, 4490, /* DiagArray217 */ 604, 0)
DIAG_ENTRY(DeprecatedExperimentalCoroutine /* deprecated-experimental-coroutine */, 4523, /* DiagArray218 */ 606, 0)
DIAG_ENTRY(DeprecatedImplementations /* deprecated-implementations */, 4557, /* DiagArray219 */ 608, 0)
DIAG_ENTRY(DeprecatedIncrementBool /* deprecated-increment-bool */, 4584, /* DiagArray220 */ 611, 0)
DIAG_ENTRY(DeprecatedObjCIsaUsage /* deprecated-objc-isa-usage */, 4610, /* DiagArray221 */ 613, 0)
DIAG_ENTRY(ObjCPointerIntrospect /* deprecated-objc-pointer-introspection */, 4636, /* DiagArray222 */ 616, /* DiagSubGroup222 */ 217)
DIAG_ENTRY(ObjCPointerIntrospectPerformSelector /* deprecated-objc-pointer-introspection-performSelector */, 4674, /* DiagArray223 */ 618, 0)
DIAG_ENTRY(DeprecatedPragma /* deprecated-pragma */, 4728, /* DiagArray224 */ 620, 0)
DIAG_ENTRY(DeprecatedRegister /* deprecated-register */, 4746, /* DiagArray225 */ 622, 0)
DIAG_ENTRY(DeprecatedThisCapture /* deprecated-this-capture */, 4766, /* DiagArray226 */ 624, 0)
DIAG_ENTRY(DeprecatedType /* deprecated-type */, 4790, /* DiagArray227 */ 626, 0)
DIAG_ENTRY(DeprecatedVolatile /* deprecated-volatile */, 4806, /* DiagArray228 */ 628, 0)
DIAG_ENTRY(DeprecatedWritableStr /* deprecated-writable-strings */, 4826, 0, /* DiagSubGroup229 */ 219)
DIAG_ENTRY(anonymous_257 /* direct-ivar-access */, 4854, /* DiagArray230 */ 635, 0)
DIAG_ENTRY(anonymous_103 /* disabled-macro-expansion */, 4873, /* DiagArray231 */ 637, 0)
DIAG_ENTRY(anonymous_6 /* disabled-optimization */, 4898, 0, 0)
DIAG_ENTRY(anonymous_7 /* discard-qual */, 4920, 0, 0)
DIAG_ENTRY(DistributedObjectModifiers /* distributed-object-modifiers */, 4933, /* DiagArray234 */ 639, 0)
DIAG_ENTRY(anonymous_8 /* div-by-zero */, 4962, 0, /* DiagSubGroup235 */ 221)
DIAG_ENTRY(DivZero /* division-by-zero */, 4974, /* DiagArray236 */ 642, 0)
DIAG_ENTRY(anonymous_174 /* dll-attribute-on-redeclaration */, 4991, /* DiagArray237 */ 644, 0)
DIAG_ENTRY(DllexportExplicitInstantiationDecl /* dllexport-explicit-instantiation-decl */, 5022, /* DiagArray238 */ 646, 0)
DIAG_ENTRY(anonymous_175 /* dllimport-static-field-def */, 5060, /* DiagArray239 */ 648, 0)
DIAG_ENTRY(Documentation /* documentation */, 5087, /* DiagArray240 */ 650, /* DiagSubGroup240 */ 223)
DIAG_ENTRY(DocumentationDeprecatedSync /* documentation-deprecated-sync */, 5101, /* DiagArray241 */ 670, 0)
DIAG_ENTRY(DocumentationHTML /* documentation-html */, 5131, /* DiagArray242 */ 672, 0)
DIAG_ENTRY(DocumentationPedantic /* documentation-pedantic */, 5150, /* DiagArray243 */ 677, /* DiagSubGroup243 */ 226)
DIAG_ENTRY(DocumentationUnknownCommand /* documentation-unknown-command */, 5173, /* DiagArray244 */ 679, 0)
DIAG_ENTRY(anonymous_90 /* dollar-in-identifier-extension */, 5203, /* DiagArray245 */ 682, 0)
DIAG_ENTRY(DoublePromotion /* double-promotion */, 5234, /* DiagArray246 */ 684, 0)
DIAG_ENTRY(DtorName /* dtor-name */, 5251, /* DiagArray247 */ 686, 0)
DIAG_ENTRY(anonymous_163 /* dtor-typedef */, 5261, /* DiagArray248 */ 690, 0)
DIAG_ENTRY(DuplicateDeclSpecifier /* duplicate-decl-specifier */, 5274, /* DiagArray249 */ 692, 0)
DIAG_ENTRY(anonymous_130 /* duplicate-enum */, 5299, /* DiagArray250 */ 697, 0)
DIAG_ENTRY(DuplicateArgDecl /* duplicate-method-arg */, 5314, /* DiagArray251 */ 699, 0)
DIAG_ENTRY(MethodDuplicate /* duplicate-method-match */, 5335, /* DiagArray252 */ 701, 0)
DIAG_ENTRY(anonymous_144 /* duplicate-protocol */, 5358, /* DiagArray253 */ 703, 0)
DIAG_ENTRY(DynamicClassMemaccess /* dynamic-class-memaccess */, 5377, /* DiagArray254 */ 705, 0)
DIAG_ENTRY(DynamicExceptionSpec /* dynamic-exception-spec */, 5401, /* DiagArray255 */ 707, /* DiagSubGroup255 */ 228)
DIAG_ENTRY(anonymous_31 /* effc++ */, 5424, 0, /* DiagSubGroup256 */ 230)
DIAG_ENTRY(anonymous_117 /* elaborated-enum-base */, 5431, /* DiagArray257 */ 709, 0)
DIAG_ENTRY(anonymous_118 /* elaborated-enum-class */, 5452, /* DiagArray258 */ 711, 0)
DIAG_ENTRY(anonymous_109 /* embedded-directive */, 5474, /* DiagArray259 */ 713, 0)
DIAG_ENTRY(EmptyBody /* empty-body */, 5493, /* DiagArray260 */ 715, 0)
DIAG_ENTRY(anonymous_122 /* empty-decomposition */, 5504, /* DiagArray261 */ 721, 0)
DIAG_ENTRY(EmptyInitStatement /* empty-init-stmt */, 5524, /* DiagArray262 */ 723, 0)
DIAG_ENTRY(anonymous_114 /* empty-translation-unit */, 5540, /* DiagArray263 */ 725, 0)
DIAG_ENTRY(anonymous_178 /* encode-type */, 5563, /* DiagArray264 */ 727, 0)
DIAG_ENTRY(anonymous_54 /* endif-labels */, 5575, 0, /* DiagSubGroup265 */ 232)
DIAG_ENTRY(EnumCompare /* enum-compare */, 5588, /* DiagArray266 */ 729, /* DiagSubGroup266 */ 234)
DIAG_ENTRY(EnumCompareConditional /* enum-compare-conditional */, 5601, /* DiagArray267 */ 731, /* DiagSubGroup267 */ 237)
DIAG_ENTRY(EnumCompareSwitch /* enum-compare-switch */, 5626, /* DiagArray268 */ 733, 0)
DIAG_ENTRY(EnumConversion /* enum-conversion */, 5646, /* DiagArray269 */ 735, /* DiagSubGroup269 */ 239)
DIAG_ENTRY(EnumEnumConversion /* enum-enum-conversion */, 5662, /* DiagArray270 */ 737, /* DiagSubGroup270 */ 243)
DIAG_ENTRY(EnumFloatConversion /* enum-float-conversion */, 5683, /* DiagArray271 */ 739, /* DiagSubGroup271 */ 245)
DIAG_ENTRY(EnumTooLarge /* enum-too-large */, 5705, /* DiagArray272 */ 741, 0)
DIAG_ENTRY(Exceptions /* exceptions */, 5720, /* DiagArray273 */ 744, 0)
DIAG_ENTRY(ExcessInitializers /* excess-initializers */, 5731, /* DiagArray274 */ 748, 0)
DIAG_ENTRY(ExitTimeDestructors /* exit-time-destructors */, 5751, /* DiagArray275 */ 753, 0)
DIAG_ENTRY(ExpansionToDefined /* expansion-to-defined */, 5773, /* DiagArray276 */ 755, 0)
DIAG_ENTRY(ExplicitInitializeCall /* explicit-initialize-call */, 5794, /* DiagArray277 */ 758, 0)
DIAG_ENTRY(anonymous_211 /* explicit-ownership-type */, 5819, /* DiagArray278 */ 761, 0)
DIAG_ENTRY(ExportUnnamed /* export-unnamed */, 5843, /* DiagArray279 */ 763, 0)
DIAG_ENTRY(anonymous_260 /* export-using-directive */, 5858, /* DiagArray280 */ 766, 0)
DIAG_ENTRY(ExternCCompat /* extern-c-compat */, 5881, /* DiagArray281 */ 768, 0)
DIAG_ENTRY(anonymous_206 /* extern-initializer */, 5897, /* DiagArray282 */ 770, 0)
DIAG_ENTRY(Extra /* extra */, 5916, /* DiagArray283 */ 772, /* DiagSubGroup283 */ 247)
DIAG_ENTRY(anonymous_219 /* extra-qualification */, 5922, /* DiagArray284 */ 774, 0)
DIAG_ENTRY(ExtraSemi /* extra-semi */, 5942, /* DiagArray285 */ 776, /* DiagSubGroup285 */ 262)
DIAG_ENTRY(ExtraSemiStmt /* extra-semi-stmt */, 5953, /* DiagArray286 */ 779, /* DiagSubGroup286 */ 265)
DIAG_ENTRY(ExtraTokens /* extra-tokens */, 5969, /* DiagArray287 */ 781, 0)
DIAG_ENTRY(FinalDtorNonFinalClass /* final-dtor-non-final-class */, 5982, /* DiagArray288 */ 784, 0)
DIAG_ENTRY(FinalMacro /* final-macro */, 6009, /* DiagArray289 */ 786, 0)
DIAG_ENTRY(anonymous_116 /* fixed-enum-extension */, 6021, /* DiagArray290 */ 788, 0)
DIAG_ENTRY(anonymous_70 /* fixed-point-overflow */, 6042, /* DiagArray291 */ 790, 0)
DIAG_ENTRY(FlagEnum /* flag-enum */, 6063, /* DiagArray292 */ 792, 0)
DIAG_ENTRY(FlexibleArrayExtensions /* flexible-array-extensions */, 6073, /* DiagArray293 */ 794, 0)
DIAG_ENTRY(FloatConversion /* float-conversion */, 6099, /* DiagArray294 */ 797, /* DiagSubGroup294 */ 267)
DIAG_ENTRY(anonymous_212 /* float-equal */, 6116, /* DiagArray295 */ 799, 0)
DIAG_ENTRY(FloatOverflowConversion /* float-overflow-conversion */, 6128, /* DiagArray296 */ 801, 0)
DIAG_ENTRY(FloatZeroConversion /* float-zero-conversion */, 6154, /* DiagArray297 */ 804, 0)
DIAG_ENTRY(ForLoopAnalysis /* for-loop-analysis */, 6176, /* DiagArray298 */ 806, 0)
DIAG_ENTRY(Format /* format */, 6194, /* DiagArray299 */ 809, /* DiagSubGroup299 */ 270)
DIAG_ENTRY(FormatExtraArgs /* format-extra-args */, 6201, /* DiagArray300 */ 835, 0)
DIAG_ENTRY(FormatInsufficientArgs /* format-insufficient-args */, 6219, /* DiagArray301 */ 837, 0)
DIAG_ENTRY(FormatInvalidSpecifier /* format-invalid-specifier */, 6244, /* DiagArray302 */ 839, 0)
DIAG_ENTRY(FormatNonStandard /* format-non-iso */, 6269, /* DiagArray303 */ 841, 0)
DIAG_ENTRY(FormatNonLiteral /* format-nonliteral */, 6284, /* DiagArray304 */ 845, 0)
DIAG_ENTRY(FormatPedantic /* format-pedantic */, 6302, /* DiagArray305 */ 847, 0)
DIAG_ENTRY(FormatSecurity /* format-security */, 6318, /* DiagArray306 */ 850, 0)
DIAG_ENTRY(FormatTypeConfusion /* format-type-confusion */, 6334, /* DiagArray307 */ 852, 0)
DIAG_ENTRY(FormatY2K /* format-y2k */, 6356, 0, 0)
DIAG_ENTRY(FormatZeroLength /* format-zero-length */, 6367, /* DiagArray309 */ 854, 0)
DIAG_ENTRY(Format2 /* format=2 */, 6386, 0, /* DiagSubGroup310 */ 278)
DIAG_ENTRY(FortifySource /* fortify-source */, 6395, /* DiagArray311 */ 856, 0)
DIAG_ENTRY(FourByteMultiChar /* four-char-constants */, 6410, /* DiagArray312 */ 862, 0)
DIAG_ENTRY(FrameAddress /* frame-address */, 6430, /* DiagArray313 */ 864, 0)
DIAG_ENTRY(BackendFrameLargerThan /* frame-larger-than */, 6444, /* DiagArray314 */ 866, 0)
DIAG_ENTRY(anonymous_67 /* frame-larger-than= */, 6462, 0, /* DiagSubGroup315 */ 282)
DIAG_ENTRY(FrameworkIncludePrivateFromPublic /* framework-include-private-from-public */, 6481, /* DiagArray316 */ 869, 0)
DIAG_ENTRY(FreeNonHeapObject /* free-nonheap-object */, 6519, /* DiagArray317 */ 871, 0)
DIAG_ENTRY(FunctionDefInObjCContainer /* function-def-in-objc-container */, 6539, /* DiagArray318 */ 873, 0)
DIAG_ENTRY(FunctionMultiVersioning /* function-multiversion */, 6570, /* DiagArray319 */ 875, /* DiagSubGroup319 */ 284)
DIAG_ENTRY(FUseLdPath /* fuse-ld-path */, 6592, /* DiagArray320 */ 879, 0)
DIAG_ENTRY(FutureAttrs /* future-attribute-extensions */, 6605, 0, /* DiagSubGroup321 */ 286)
DIAG_ENTRY(FutureCompat /* future-compat */, 6633, 0, 0)
DIAG_ENTRY(GccCompat /* gcc-compat */, 6647, /* DiagArray323 */ 881, 0)
DIAG_ENTRY(GlobalConstructors /* global-constructors */, 6658, /* DiagArray324 */ 892, 0)
DIAG_ENTRY(GlobalISel /* global-isel */, 6678, /* DiagArray325 */ 895, 0)
DIAG_ENTRY(GNU /* gnu */, 6690, 0, /* DiagSubGroup326 */ 290)
DIAG_ENTRY(GNUAlignofExpression /* gnu-alignof-expression */, 6694, /* DiagArray327 */ 898, 0)
DIAG_ENTRY(GNUAnonymousStruct /* gnu-anonymous-struct */, 6717, /* DiagArray328 */ 900, 0)
DIAG_ENTRY(anonymous_221 /* gnu-array-member-paren-init */, 6738, /* DiagArray329 */ 902, 0)
DIAG_ENTRY(GNUAutoType /* gnu-auto-type */, 6766, /* DiagArray330 */ 904, 0)
DIAG_ENTRY(GNUBinaryLiteral /* gnu-binary-literal */, 6780, /* DiagArray331 */ 906, 0)
DIAG_ENTRY(GNUCaseRange /* gnu-case-range */, 6799, /* DiagArray332 */ 908, 0)
DIAG_ENTRY(GNUComplexInteger /* gnu-complex-integer */, 6814, /* DiagArray333 */ 910, 0)
DIAG_ENTRY(GNUCompoundLiteralInitializer /* gnu-compound-literal-initializer */, 6834, /* DiagArray334 */ 912, 0)
DIAG_ENTRY(GNUConditionalOmittedOperand /* gnu-conditional-omitted-operand */, 6867, /* DiagArray335 */ 914, 0)
DIAG_ENTRY(GNUDesignator /* gnu-designator */, 6899, /* DiagArray336 */ 916, 0)
DIAG_ENTRY(GNUEmptyInitializer /* gnu-empty-initializer */, 6914, /* DiagArray337 */ 920, 0)
DIAG_ENTRY(GNUEmptyStruct /* gnu-empty-struct */, 6936, /* DiagArray338 */ 922, 0)
DIAG_ENTRY(GNUFlexibleArrayInitializer /* gnu-flexible-array-initializer */, 6953, /* DiagArray339 */ 926, 0)
DIAG_ENTRY(GNUFlexibleArrayUnionMember /* gnu-flexible-array-union-member */, 6984, /* DiagArray340 */ 928, 0)
DIAG_ENTRY(GNUFoldingConstant /* gnu-folding-constant */, 7016, /* DiagArray341 */ 930, 0)
DIAG_ENTRY(GNUImaginaryConstant /* gnu-imaginary-constant */, 7037, /* DiagArray342 */ 934, 0)
DIAG_ENTRY(GNUIncludeNext /* gnu-include-next */, 7060, /* DiagArray343 */ 936, 0)
DIAG_ENTRY(anonymous_179 /* gnu-inline-cpp-without-extern */, 7077, /* DiagArray344 */ 938, 0)
DIAG_ENTRY(GNULabelsAsValue /* gnu-label-as-value */, 7107, /* DiagArray345 */ 940, 0)
DIAG_ENTRY(GNURedeclaredEnum /* gnu-redeclared-enum */, 7126, /* DiagArray346 */ 943, 0)
DIAG_ENTRY(GNUStatementExpression /* gnu-statement-expression */, 7146, /* DiagArray347 */ 945, 0)
DIAG_ENTRY(GNUStaticFloatInit /* gnu-static-float-init */, 7171, /* DiagArray348 */ 947, 0)
DIAG_ENTRY(GNUStringLiteralOperatorTemplate /* gnu-string-literal-operator-template */, 7193, /* DiagArray349 */ 949, 0)
DIAG_ENTRY(GNUUnionCast /* gnu-union-cast */, 7230, /* DiagArray350 */ 951, 0)
DIAG_ENTRY(GNUVariableSizedTypeNotAtEnd /* gnu-variable-sized-type-not-at-end */, 7245, /* DiagArray351 */ 953, 0)
DIAG_ENTRY(GNUZeroLineDirective /* gnu-zero-line-directive */, 7280, /* DiagArray352 */ 955, 0)
DIAG_ENTRY(GNUZeroVariadicMacroArguments /* gnu-zero-variadic-macro-arguments */, 7304, /* DiagArray353 */ 957, 0)
DIAG_ENTRY(anonymous_237 /* gpu-maybe-wrong-side */, 7338, /* DiagArray354 */ 960, 0)
DIAG_ENTRY(anonymous_113 /* header-guard */, 7359, /* DiagArray355 */ 962, 0)
DIAG_ENTRY(HeaderHygiene /* header-hygiene */, 7372, /* DiagArray356 */ 964, 0)
DIAG_ENTRY(HIPOnly /* hip-only */, 7387, /* DiagArray357 */ 966, 0)
DIAG_ENTRY(anonymous_233 /* idiomatic-parentheses */, 7396, /* DiagArray358 */ 968, 0)
DIAG_ENTRY(IgnoredAttributes /* ignored-attributes */, 7418, /* DiagArray359 */ 970, 0)
DIAG_ENTRY(anonymous_182 /* ignored-availability-without-sdk-settings */, 7437, /* DiagArray360 */ 1050, 0)
DIAG_ENTRY(IgnoredOptimizationArgument /* ignored-optimization-argument */, 7479, /* DiagArray361 */ 1052, 0)
DIAG_ENTRY(IgnoredPragmaIntrinsic /* ignored-pragma-intrinsic */, 7509, /* DiagArray362 */ 1055, 0)
DIAG_ENTRY(IgnoredPragmaOptimize /* ignored-pragma-optimize */, 7534, /* DiagArray363 */ 1057, 0)
DIAG_ENTRY(IgnoredPragmas /* ignored-pragmas */, 7558, /* DiagArray364 */ 1059, /* DiagSubGroup364 */ 319)
DIAG_ENTRY(IgnoredQualifiers /* ignored-qualifiers */, 7574, /* DiagArray365 */ 1105, /* DiagSubGroup365 */ 322)
DIAG_ENTRY(IgnoredReferenceQualifiers /* ignored-reference-qualifiers */, 7593, /* DiagArray366 */ 1110, 0)
DIAG_ENTRY(Implicit /* implicit */, 7622, 0, /* DiagSubGroup367 */ 324)
DIAG_ENTRY(ImplicitAtomic /* implicit-atomic-properties */, 7631, /* DiagArray368 */ 1112, 0)
DIAG_ENTRY(ImplicitConstIntFloatConversion /* implicit-const-int-float-conversion */, 7658, /* DiagArray369 */ 1115, 0)
DIAG_ENTRY(ImplicitConversionFloatingPointToBool /* implicit-conversion-floating-point-to-bool */, 7694, /* DiagArray370 */ 1117, 0)
DIAG_ENTRY(anonymous_248 /* implicit-exception-spec-mismatch */, 7737, /* DiagArray371 */ 1119, 0)
DIAG_ENTRY(ImplicitFallthrough /* implicit-fallthrough */, 7770, /* DiagArray372 */ 1121, /* DiagSubGroup372 */ 327)
DIAG_ENTRY(ImplicitFallthroughPerFunction /* implicit-fallthrough-per-function */, 7791, /* DiagArray373 */ 1123, 0)
DIAG_ENTRY(ImplicitFixedPointConversion /* implicit-fixed-point-conversion */, 7825, /* DiagArray374 */ 1125, 0)
DIAG_ENTRY(ImplicitFloatConversion /* implicit-float-conversion */, 7857, /* DiagArray375 */ 1127, /* DiagSubGroup375 */ 329)
DIAG_ENTRY(ImplicitFunctionDeclare /* implicit-function-declaration */, 7883, /* DiagArray376 */ 1130, 0)
DIAG_ENTRY(ImplicitInt /* implicit-int */, 7913, /* DiagArray377 */ 1135, 0)
DIAG_ENTRY(ImplicitIntConversion /* implicit-int-conversion */, 7926, /* DiagArray378 */ 1137, /* DiagSubGroup378 */ 332)
DIAG_ENTRY(ImplicitIntFloatConversion /* implicit-int-float-conversion */, 7950, /* DiagArray379 */ 1140, /* DiagSubGroup379 */ 334)
DIAG_ENTRY(anonymous_155 /* implicit-retain-self */, 7980, /* DiagArray380 */ 1142, 0)
DIAG_ENTRY(ImplicitlyUnsignedLiteral /* implicitly-unsigned-literal */, 8001, /* DiagArray381 */ 1144, 0)
DIAG_ENTRY(anonymous_22 /* import */, 8029, 0, 0)
DIAG_ENTRY(anonymous_108 /* import-preprocessor-directive-pedantic */, 8036, /* DiagArray383 */ 1146, 0)
DIAG_ENTRY(anonymous_245 /* inaccessible-base */, 8075, /* DiagArray384 */ 1148, 0)
DIAG_ENTRY(anonymous_98 /* include-next-absolute-path */, 8093, /* DiagArray385 */ 1150, 0)
DIAG_ENTRY(anonymous_97 /* include-next-outside-header */, 8120, /* DiagArray386 */ 1152, 0)
DIAG_ENTRY(IncompatibleExceptionSpec /* incompatible-exception-spec */, 8148, /* DiagArray387 */ 1154, 0)
DIAG_ENTRY(IncompatibleFunctionPointerTypes /* incompatible-function-pointer-types */, 8176, /* DiagArray388 */ 1157, 0)
DIAG_ENTRY(anonymous_138 /* incompatible-library-redeclaration */, 8212, /* DiagArray389 */ 1159, 0)
DIAG_ENTRY(IncompatibleMSStruct /* incompatible-ms-struct */, 8247, /* DiagArray390 */ 1161, 0)
DIAG_ENTRY(IncompatiblePointerTypes /* incompatible-pointer-types */, 8270, /* DiagArray391 */ 1164, /* DiagSubGroup391 */ 336)
DIAG_ENTRY(IncompatiblePointerTypesDiscardsQualifiers /* incompatible-pointer-types-discards-qualifiers */, 8297, /* DiagArray392 */ 1166, 0)
DIAG_ENTRY(anonymous_145 /* incompatible-property-type */, 8344, /* DiagArray393 */ 1170, 0)
DIAG_ENTRY(anonymous_78 /* incompatible-sysroot */, 8371, /* DiagArray394 */ 1172, 0)
DIAG_ENTRY(IncompleteFrameworkModuleDeclaration /* incomplete-framework-module-declaration */, 8392, /* DiagArray395 */ 1174, 0)
DIAG_ENTRY(anonymous_147 /* incomplete-implementation */, 8432, /* DiagArray396 */ 1176, 0)
DIAG_ENTRY(IncompleteModule /* incomplete-module */, 8458, 0, /* DiagSubGroup397 */ 339)
DIAG_ENTRY(anonymous_137 /* incomplete-setjmp-declaration */, 8476, /* DiagArray398 */ 1178, 0)
DIAG_ENTRY(IncompleteUmbrella /* incomplete-umbrella */, 8506, /* DiagArray399 */ 1180, 0)
DIAG_ENTRY(MicrosoftInconsistentDllImport /* inconsistent-dllimport */, 8526, /* DiagArray400 */ 1184, 0)
DIAG_ENTRY(CXX11WarnInconsistentOverrideDestructor /* inconsistent-missing-destructor-override */, 8549, /* DiagArray401 */ 1187, 0)
DIAG_ENTRY(CXX11WarnInconsistentOverrideMethod /* inconsistent-missing-override */, 8590, /* DiagArray402 */ 1189, 0)
DIAG_ENTRY(IncrementBool /* increment-bool */, 8620, /* DiagArray403 */ 1191, /* DiagSubGroup403 */ 342)
DIAG_ENTRY(InfiniteRecursion /* infinite-recursion */, 8635, /* DiagArray404 */ 1193, 0)
DIAG_ENTRY(anonymous_23 /* init-self */, 8654, 0, 0)
DIAG_ENTRY(InitializerOverrides /* initializer-overrides */, 8664, /* DiagArray406 */ 1195, 0)
DIAG_ENTRY(anonymous_162 /* injected-class-name */, 8686, /* DiagArray407 */ 1198, 0)
DIAG_ENTRY(anonymous_24 /* inline */, 8706, 0, 0)
DIAG_ENTRY(BackendInlineAsm /* inline-asm */, 8713, /* DiagArray409 */ 1200, 0)
DIAG_ENTRY(InlineNamespaceReopenedNoninline /* inline-namespace-reopened-noninline */, 8724, /* DiagArray410 */ 1202, 0)
DIAG_ENTRY(anonymous_246 /* inline-new-delete */, 8760, /* DiagArray411 */ 1204, 0)
DIAG_ENTRY(anonymous_194 /* instantiation-after-specialization */, 8778, /* DiagArray412 */ 1206, 0)
DIAG_ENTRY(IntConversion /* int-conversion */, 8813, /* DiagArray413 */ 1208, 0)
DIAG_ENTRY(anonymous_59 /* int-conversions */, 8828, 0, /* DiagSubGroup414 */ 344)
DIAG_ENTRY(IntInBoolContext /* int-in-bool-context */, 8844, /* DiagArray415 */ 1211, 0)
DIAG_ENTRY(IntToPointerCast /* int-to-pointer-cast */, 8864, /* DiagArray416 */ 1214, /* DiagSubGroup416 */ 346)
DIAG_ENTRY(IntToVoidPointerCast /* int-to-void-pointer-cast */, 8884, /* DiagArray417 */ 1216, 0)
DIAG_ENTRY(anonymous_69 /* integer-overflow */, 8909, /* DiagArray418 */ 1218, 0)
DIAG_ENTRY(anonymous_133 /* interrupt-service-routine */, 8926, /* DiagArray419 */ 1220, 0)
DIAG_ENTRY(InvalidCommandLineArgument /* invalid-command-line-argument */, 8952, /* DiagArray420 */ 1222, /* DiagSubGroup420 */ 348)
DIAG_ENTRY(anonymous_165 /* invalid-constexpr */, 8982, /* DiagArray421 */ 1231, 0)
DIAG_ENTRY(ObjCInvalidIBOutletProperty /* invalid-iboutlet */, 9000, /* DiagArray422 */ 1233, 0)
DIAG_ENTRY(anonymous_176 /* invalid-initializer-from-system-header */, 9017, /* DiagArray423 */ 1236, 0)
DIAG_ENTRY(InvalidIOSDeploymentTarget /* invalid-ios-deployment-target */, 9056, /* DiagArray424 */ 1238, 0)
DIAG_ENTRY(anonymous_188 /* invalid-no-builtin-names */, 9086, /* DiagArray425 */ 1240, 0)
DIAG_ENTRY(InvalidNoreturn /* invalid-noreturn */, 9111, /* DiagArray426 */ 1242, 0)
DIAG_ENTRY(InvalidOffsetof /* invalid-offsetof */, 9128, /* DiagArray427 */ 1245, 0)
DIAG_ENTRY(InvalidOrNonExistentDirectory /* invalid-or-nonexistent-directory */, 9145, /* DiagArray428 */ 1248, 0)
DIAG_ENTRY(anonymous_192 /* invalid-partial-specialization */, 9178, /* DiagArray429 */ 1251, 0)
DIAG_ENTRY(anonymous_25 /* invalid-pch */, 9209, 0, 0)
DIAG_ENTRY(InvalidPPToken /* invalid-pp-token */, 9221, /* DiagArray431 */ 1253, 0)
DIAG_ENTRY(InvalidSourceEncoding /* invalid-source-encoding */, 9238, /* DiagArray432 */ 1256, 0)
DIAG_ENTRY(anonymous_110 /* invalid-token-paste */, 9262, /* DiagArray433 */ 1259, 0)
DIAG_ENTRY(anonymous_232 /* jump-seh-finally */, 9282, /* DiagArray434 */ 1261, 0)
DIAG_ENTRY(KeywordCompat /* keyword-compat */, 9299, /* DiagArray435 */ 1263, 0)
DIAG_ENTRY(KeywordAsMacro /* keyword-macro */, 9314, /* DiagArray436 */ 1265, 0)
DIAG_ENTRY(KNRPromotedParameter /* knr-promoted-parameter */, 9328, /* DiagArray437 */ 1267, 0)
DIAG_ENTRY(anonymous_91 /* language-extension-token */, 9351, /* DiagArray438 */ 1269, 0)
DIAG_ENTRY(LargeByValueCopy /* large-by-value-copy */, 9376, /* DiagArray439 */ 1271, 0)
DIAG_ENTRY(LibLTO /* liblto */, 9396, 0, 0)
DIAG_ENTRY(LinkerWarnings /* linker-warnings */, 9403, /* DiagArray441 */ 1274, 0)
DIAG_ENTRY(LiteralConversion /* literal-conversion */, 9419, /* DiagArray442 */ 1276, 0)
DIAG_ENTRY(LiteralRange /* literal-range */, 9438, /* DiagArray443 */ 1279, 0)
DIAG_ENTRY(LocalTypeTemplateArgs /* local-type-template-args */, 9452, /* DiagArray444 */ 1282, /* DiagSubGroup444 */ 350)
DIAG_ENTRY(LogicalNotParentheses /* logical-not-parentheses */, 9477, /* DiagArray445 */ 1284, 0)
DIAG_ENTRY(LogicalOpParentheses /* logical-op-parentheses */, 9501, /* DiagArray446 */ 1286, 0)
DIAG_ENTRY(LongLong /* long-long */, 9524, /* DiagArray447 */ 1288, /* DiagSubGroup447 */ 352)
DIAG_ENTRY(LoopAnalysis /* loop-analysis */, 9534, 0, /* DiagSubGroup448 */ 354)
DIAG_ENTRY(MacroRedefined /* macro-redefined */, 9548, /* DiagArray449 */ 1290, 0)
DIAG_ENTRY(Main /* main */, 9564, /* DiagArray450 */ 1292, 0)
DIAG_ENTRY(MainReturnType /* main-return-type */, 9569, /* DiagArray451 */ 1300, 0)
DIAG_ENTRY(MalformedWarningCheck /* malformed-warning-check */, 9586, /* DiagArray452 */ 1302, 0)
DIAG_ENTRY(anonymous_208 /* many-braces-around-scalar-init */, 9610, /* DiagArray453 */ 1304, 0)
DIAG_ENTRY(MaxTokens /* max-tokens */, 9641, /* DiagArray454 */ 1306, 0)
DIAG_ENTRY(MaxUnsignedZero /* max-unsigned-zero */, 9652, /* DiagArray455 */ 1309, 0)
DIAG_ENTRY(MemsetTransposedArgs /* memset-transposed-args */, 9670, /* DiagArray456 */ 1311, 0)
DIAG_ENTRY(anonymous_140 /* memsize-comparison */, 9693, /* DiagArray457 */ 1313, 0)
DIAG_ENTRY(MethodSignatures /* method-signatures */, 9712, /* DiagArray458 */ 1315, 0)
DIAG_ENTRY(Microsoft /* microsoft */, 9730, 0, /* DiagSubGroup459 */ 357)
DIAG_ENTRY(MicrosoftAbstract /* microsoft-abstract */, 9740, /* DiagArray460 */ 1318, 0)
DIAG_ENTRY(MicrosoftAnonTag /* microsoft-anon-tag */, 9759, /* DiagArray461 */ 1320, 0)
DIAG_ENTRY(MicrosoftCast /* microsoft-cast */, 9778, /* DiagArray462 */ 1323, 0)
DIAG_ENTRY(MicrosoftCharize /* microsoft-charize */, 9793, /* DiagArray463 */ 1326, 0)
DIAG_ENTRY(MicrosoftCommentPaste /* microsoft-comment-paste */, 9811, /* DiagArray464 */ 1328, 0)
DIAG_ENTRY(MicrosoftConstInit /* microsoft-const-init */, 9835, /* DiagArray465 */ 1330, 0)
DIAG_ENTRY(MicrosoftCppMacro /* microsoft-cpp-macro */, 9856, /* DiagArray466 */ 1332, 0)
DIAG_ENTRY(MicrosoftDefaultArgRedefinition /* microsoft-default-arg-redefinition */, 9876, /* DiagArray467 */ 1334, 0)
DIAG_ENTRY(MicrosoftDrectveSection /* microsoft-drectve-section */, 9911, /* DiagArray468 */ 1336, 0)
DIAG_ENTRY(MicrosoftEndOfFile /* microsoft-end-of-file */, 9937, /* DiagArray469 */ 1338, 0)
DIAG_ENTRY(MicrosoftEnumForwardReference /* microsoft-enum-forward-reference */, 9959, /* DiagArray470 */ 1340, 0)
DIAG_ENTRY(MicrosoftEnumValue /* microsoft-enum-value */, 9992, /* DiagArray471 */ 1342, 0)
DIAG_ENTRY(MicrosoftExceptionSpec /* microsoft-exception-spec */, 10013, /* DiagArray472 */ 1344, 0)
DIAG_ENTRY(anonymous_119 /* microsoft-exists */, 10038, /* DiagArray473 */ 1350, 0)
DIAG_ENTRY(MicrosoftExplicitConstructorCall /* microsoft-explicit-constructor-call */, 10055, /* DiagArray474 */ 1352, 0)
DIAG_ENTRY(MicrosoftExtraQualification /* microsoft-extra-qualification */, 10091, /* DiagArray475 */ 1354, 0)
DIAG_ENTRY(MicrosoftFixedEnum /* microsoft-fixed-enum */, 10121, /* DiagArray476 */ 1356, 0)
DIAG_ENTRY(MicrosoftFlexibleArray /* microsoft-flexible-array */, 10142, /* DiagArray477 */ 1358, 0)
DIAG_ENTRY(MicrosoftGoto /* microsoft-goto */, 10167, /* DiagArray478 */ 1361, 0)
DIAG_ENTRY(MicrosoftInaccessibleBase /* microsoft-inaccessible-base */, 10182, /* DiagArray479 */ 1363, 0)
DIAG_ENTRY(MicrosoftInclude /* microsoft-include */, 10210, /* DiagArray480 */ 1365, 0)
DIAG_ENTRY(MicrosoftMutableReference /* microsoft-mutable-reference */, 10228, /* DiagArray481 */ 1367, 0)
DIAG_ENTRY(MicrosoftPureDefinition /* microsoft-pure-definition */, 10256, /* DiagArray482 */ 1369, 0)
DIAG_ENTRY(MicrosoftRedeclareStatic /* microsoft-redeclare-static */, 10282, /* DiagArray483 */ 1371, 0)
DIAG_ENTRY(MicrosoftSealed /* microsoft-sealed */, 10309, /* DiagArray484 */ 1373, 0)
DIAG_ENTRY(MicrosoftStaticAssert /* microsoft-static-assert */, 10326, /* DiagArray485 */ 1375, 0)
DIAG_ENTRY(MicrosoftTemplate /* microsoft-template */, 10350, /* DiagArray486 */ 1377, /* DiagSubGroup486 */ 388)
DIAG_ENTRY(MicrosoftTemplateShadow /* microsoft-template-shadow */, 10369, /* DiagArray487 */ 1387, 0)
DIAG_ENTRY(MicrosoftUnionMemberReference /* microsoft-union-member-reference */, 10395, /* DiagArray488 */ 1389, 0)
DIAG_ENTRY(MicrosoftUnqualifiedFriend /* microsoft-unqualified-friend */, 10428, /* DiagArray489 */ 1391, 0)
DIAG_ENTRY(MicrosoftUsingDecl /* microsoft-using-decl */, 10457, /* DiagArray490 */ 1393, 0)
DIAG_ENTRY(MicrosoftVoidPseudoDtor /* microsoft-void-pseudo-dtor */, 10478, /* DiagArray491 */ 1395, 0)
DIAG_ENTRY(MisleadingIndentation /* misleading-indentation */, 10505, /* DiagArray492 */ 1397, 0)
DIAG_ENTRY(anonymous_229 /* mismatched-new-delete */, 10528, /* DiagArray493 */ 1399, 0)
DIAG_ENTRY(MismatchedParameterTypes /* mismatched-parameter-types */, 10550, /* DiagArray494 */ 1401, 0)
DIAG_ENTRY(MismatchedReturnTypes /* mismatched-return-types */, 10577, /* DiagArray495 */ 1403, 0)
DIAG_ENTRY(MismatchedTags /* mismatched-tags */, 10601, /* DiagArray496 */ 1405, 0)
DIAG_ENTRY(MissingBraces /* missing-braces */, 10617, /* DiagArray497 */ 1408, 0)
DIAG_ENTRY(anonymous_242 /* missing-constinit */, 10632, /* DiagArray498 */ 1410, 0)
DIAG_ENTRY(MissingDeclarations /* missing-declarations */, 10650, /* DiagArray499 */ 1412, 0)
DIAG_ENTRY(anonymous_161 /* missing-exception-spec */, 10671, /* DiagArray500 */ 1417, 0)
DIAG_ENTRY(MissingFieldInitializers /* missing-field-initializers */, 10694, /* DiagArray501 */ 1419, 0)
DIAG_ENTRY(anonymous_26 /* missing-format-attribute */, 10721, 0, 0)
DIAG_ENTRY(anonymous_27 /* missing-include-dirs */, 10746, 0, 0)
DIAG_ENTRY(MissingMethodReturnType /* missing-method-return-type */, 10767, /* DiagArray504 */ 1421, 0)
DIAG_ENTRY(MissingNoEscape /* missing-noescape */, 10794, /* DiagArray505 */ 1423, 0)
DIAG_ENTRY(MissingNoreturn /* missing-noreturn */, 10811, /* DiagArray506 */ 1425, 0)
DIAG_ENTRY(anonymous_180 /* missing-prototype-for-cc */, 10828, /* DiagArray507 */ 1428, 0)
DIAG_ENTRY(anonymous_196 /* missing-prototypes */, 10853, /* DiagArray508 */ 1430, 0)
DIAG_ENTRY(anonymous_120 /* missing-selector-name */, 10872, /* DiagArray509 */ 1432, 0)
DIAG_ENTRY(anonymous_77 /* missing-sysroot */, 10894, /* DiagArray510 */ 1434, 0)
DIAG_ENTRY(anonymous_198 /* missing-variable-declarations */, 10910, /* DiagArray511 */ 1436, 0)
DIAG_ENTRY(MisspelledAssumption /* misspelled-assumption */, 10940, /* DiagArray512 */ 1438, 0)
DIAG_ENTRY(ModuleBuild /* module-build */, 10962, /* DiagArray513 */ 1440, 0)
DIAG_ENTRY(ModuleConflict /* module-conflict */, 10975, /* DiagArray514 */ 1445, 0)
DIAG_ENTRY(anonymous_87 /* module-file-config-mismatch */, 10991, /* DiagArray515 */ 1448, 0)
DIAG_ENTRY(ModuleFileExtension /* module-file-extension */, 11019, /* DiagArray516 */ 1450, 0)
DIAG_ENTRY(ModuleImport /* module-import */, 11041, /* DiagArray517 */ 1452, 0)
DIAG_ENTRY(anonymous_258 /* module-import-in-extern-c */, 11055, /* DiagArray518 */ 1454, 0)
DIAG_ENTRY(ModuleLock /* module-lock */, 11081, /* DiagArray519 */ 1456, 0)
DIAG_ENTRY(anonymous_261 /* modules-ambiguous-internal-linkage */, 11093, /* DiagArray520 */ 1458, 0)
DIAG_ENTRY(anonymous_259 /* modules-import-nested-redundant */, 11128, /* DiagArray521 */ 1460, 0)
DIAG_ENTRY(Most /* most */, 11160, 0, /* DiagSubGroup522 */ 390)
DIAG_ENTRY(Move /* move */, 11165, 0, /* DiagSubGroup523 */ 427)
DIAG_ENTRY(anonymous_66 /* msvc-include */, 11170, 0, /* DiagSubGroup524 */ 432)
DIAG_ENTRY(anonymous_81 /* msvc-not-found */, 11183, /* DiagArray525 */ 1462, 0)
DIAG_ENTRY(MultiChar /* multichar */, 11198, /* DiagArray526 */ 1464, 0)
DIAG_ENTRY(anonymous_247 /* multiple-move-vbase */, 11208, /* DiagArray527 */ 1466, 0)
DIAG_ENTRY(anonymous_17 /* narrowing */, 11228, 0, /* DiagSubGroup528 */ 434)
DIAG_ENTRY(anonymous_244 /* nested-anon-types */, 11238, /* DiagArray529 */ 1468, 0)
DIAG_ENTRY(anonymous_28 /* nested-externs */, 11256, 0, 0)
DIAG_ENTRY(OperatorNewReturnsNull /* new-returns-null */, 11271, /* DiagArray531 */ 1470, 0)
DIAG_ENTRY(NewlineEOF /* newline-eof */, 11288, /* DiagArray532 */ 1472, 0)
DIAG_ENTRY(NoDeref /* noderef */, 11300, /* DiagArray533 */ 1475, 0)
DIAG_ENTRY(NoexceptType /* noexcept-type */, 11308, 0, /* DiagSubGroup534 */ 436)
DIAG_ENTRY(anonymous_143 /* non-c-typedef-for-linkage */, 11322, /* DiagArray535 */ 1479, 0)
DIAG_ENTRY(NonGCC /* non-gcc */, 11348, 0, /* DiagSubGroup536 */ 438)
DIAG_ENTRY(NonLiteralNullConversion /* non-literal-null-conversion */, 11356, /* DiagArray537 */ 1481, 0)
DIAG_ENTRY(NonModularIncludeInFrameworkModule /* non-modular-include-in-framework-module */, 11384, /* DiagArray538 */ 1483, 0)
DIAG_ENTRY(NonModularIncludeInModule /* non-modular-include-in-module */, 11424, /* DiagArray539 */ 1485, /* DiagSubGroup539 */ 442)
DIAG_ENTRY(NonPODVarargs /* non-pod-varargs */, 11454, /* DiagArray540 */ 1487, 0)
DIAG_ENTRY(anonymous_171 /* non-power-of-two-alignment */, 11470, /* DiagArray541 */ 1492, 0)
DIAG_ENTRY(NonVirtualDtor /* non-virtual-dtor */, 11497, /* DiagArray542 */ 1494, 0)
DIAG_ENTRY(NonNull /* nonnull */, 11514, /* DiagArray543 */ 1496, 0)
DIAG_ENTRY(anonymous_30 /* nonportable-cfstrings */, 11522, 0, 0)
DIAG_ENTRY(anonymous_99 /* nonportable-include-path */, 11544, /* DiagArray545 */ 1499, 0)
DIAG_ENTRY(anonymous_100 /* nonportable-system-include-path */, 11569, /* DiagArray546 */ 1501, 0)
DIAG_ENTRY(anonymous_253 /* nonportable-vector-initialization */, 11601, /* DiagArray547 */ 1503, 0)
DIAG_ENTRY(NonTrivialMemaccess /* nontrivial-memaccess */, 11635, /* DiagArray548 */ 1505, 0)
DIAG_ENTRY(NSConsumedMismatch /* nsconsumed-mismatch */, 11656, /* DiagArray549 */ 1507, 0)
DIAG_ENTRY(NSReturnsMismatch /* nsreturns-mismatch */, 11676, /* DiagArray550 */ 1509, 0)
DIAG_ENTRY(NullArithmetic /* null-arithmetic */, 11695, /* DiagArray551 */ 1511, 0)
DIAG_ENTRY(NullCharacter /* null-character */, 11711, /* DiagArray552 */ 1514, 0)
DIAG_ENTRY(NullConversion /* null-conversion */, 11726, /* DiagArray553 */ 1517, 0)
DIAG_ENTRY(NullDereference /* null-dereference */, 11742, /* DiagArray554 */ 1519, 0)
DIAG_ENTRY(NullPointerArithmetic /* null-pointer-arithmetic */, 11759, /* DiagArray555 */ 1522, 0)
DIAG_ENTRY(NullPointerSubtraction /* null-pointer-subtraction */, 11783, /* DiagArray556 */ 1525, 0)
DIAG_ENTRY(Nullability /* nullability */, 11808, /* DiagArray557 */ 1527, 0)
DIAG_ENTRY(NullabilityCompleteness /* nullability-completeness */, 11820, /* DiagArray558 */ 1533, /* DiagSubGroup558 */ 444)
DIAG_ENTRY(NullabilityCompletenessOnArrays /* nullability-completeness-on-arrays */, 11845, /* DiagArray559 */ 1535, 0)
DIAG_ENTRY(NullabilityDeclSpec /* nullability-declspec */, 11880, /* DiagArray560 */ 1537, 0)
DIAG_ENTRY(anonymous_115 /* nullability-extension */, 11901, /* DiagArray561 */ 1539, 0)
DIAG_ENTRY(NullabilityInferredOnNestedType /* nullability-inferred-on-nested-type */, 11923, /* DiagArray562 */ 1541, 0)
DIAG_ENTRY(NullableToNonNullConversion /* nullable-to-nonnull-conversion */, 11959, /* DiagArray563 */ 1543, 0)
DIAG_ENTRY(anonymous_152 /* objc-autosynthesis-property-ivar-name-match */, 11990, /* DiagArray564 */ 1545, 0)
DIAG_ENTRY(ObjCBoolConstantConversion /* objc-bool-constant-conversion */, 12034, /* DiagArray565 */ 1547, 0)
DIAG_ENTRY(ObjCBoxing /* objc-boxing */, 12064, /* DiagArray566 */ 1549, 0)
DIAG_ENTRY(anonymous_226 /* objc-circular-container */, 12076, /* DiagArray567 */ 1551, 0)
DIAG_ENTRY(ObjCCocoaAPI /* objc-cocoa-api */, 12100, 0, /* DiagSubGroup568 */ 446)
DIAG_ENTRY(ObjCDesignatedInit /* objc-designated-initializers */, 12115, /* DiagArray569 */ 1553, 0)
DIAG_ENTRY(anonymous_168 /* objc-dictionary-duplicate-keys */, 12144, /* DiagArray570 */ 1560, 0)
DIAG_ENTRY(ObjCFlexibleArray /* objc-flexible-array */, 12175, /* DiagArray571 */ 1562, 0)
DIAG_ENTRY(anonymous_204 /* objc-forward-class-redefinition */, 12195, /* DiagArray572 */ 1565, 0)
DIAG_ENTRY(anonymous_205 /* objc-interface-ivars */, 12227, /* DiagArray573 */ 1567, 0)
DIAG_ENTRY(ObjCLiteralComparison /* objc-literal-compare */, 12248, /* DiagArray574 */ 1569, /* DiagSubGroup574 */ 448)
DIAG_ENTRY(ObjCLiteralConversion /* objc-literal-conversion */, 12269, /* DiagArray575 */ 1571, 0)
DIAG_ENTRY(anonymous_107 /* objc-macro-redefinition */, 12293, /* DiagArray576 */ 1574, 0)
DIAG_ENTRY(anonymous_157 /* objc-messaging-id */, 12317, /* DiagArray577 */ 1576, 0)
DIAG_ENTRY(MethodAccess /* objc-method-access */, 12335, /* DiagArray578 */ 1578, 0)
DIAG_ENTRY(anonymous_153 /* objc-missing-property-synthesis */, 12354, /* DiagArray579 */ 1585, 0)
DIAG_ENTRY(ObjCMissingSuperCalls /* objc-missing-super-calls */, 12386, /* DiagArray580 */ 1587, 0)
DIAG_ENTRY(ObjCMultipleMethodNames /* objc-multiple-method-names */, 12411, /* DiagArray581 */ 1589, 0)
DIAG_ENTRY(ObjCRetainBlockProperty /* objc-noncopy-retain-block-property */, 12438, /* DiagArray582 */ 1591, 0)
DIAG_ENTRY(ObjCNonUnifiedException /* objc-nonunified-exceptions */, 12473, /* DiagArray583 */ 1593, 0)
DIAG_ENTRY(ObjCPropertyAssignOnObjectType /* objc-property-assign-on-object-type */, 12500, /* DiagArray584 */ 1595, 0)
DIAG_ENTRY(ObjCPropertyImpl /* objc-property-implementation */, 12536, /* DiagArray585 */ 1597, 0)
DIAG_ENTRY(anonymous_148 /* objc-property-implicit-mismatch */, 12565, /* DiagArray586 */ 1602, 0)
DIAG_ENTRY(anonymous_150 /* objc-property-matches-cocoa-ownership-rule */, 12597, /* DiagArray587 */ 1604, 0)
DIAG_ENTRY(ObjCPropertyNoAttribute /* objc-property-no-attribute */, 12640, /* DiagArray588 */ 1606, 0)
DIAG_ENTRY(ObjCNoPropertyAutoSynthesis /* objc-property-synthesis */, 12667, /* DiagArray589 */ 1609, 0)
DIAG_ENTRY(ObjCProtocolMethodImpl /* objc-protocol-method-implementation */, 12691, /* DiagArray590 */ 1613, 0)
DIAG_ENTRY(anonymous_151 /* objc-protocol-property-synthesis */, 12727, /* DiagArray591 */ 1615, 0)
DIAG_ENTRY(ObjCProtocolQualifiers /* objc-protocol-qualifiers */, 12760, /* DiagArray592 */ 1617, 0)
DIAG_ENTRY(ObjCReadonlyPropertyHasSetter /* objc-readonly-with-setter-property */, 12785, /* DiagArray593 */ 1619, 0)
DIAG_ENTRY(ObjCRedundantAPIUse /* objc-redundant-api-use */, 12820, 0, /* DiagSubGroup594 */ 450)
DIAG_ENTRY(ObjCRedundantLiteralUse /* objc-redundant-literal-use */, 12843, /* DiagArray595 */ 1621, 0)
DIAG_ENTRY(ObjCRootClass /* objc-root-class */, 12870, /* DiagArray596 */ 1623, 0)
DIAG_ENTRY(ObjCSignedCharBool /* objc-signed-char-bool */, 12886, 0, /* DiagSubGroup597 */ 452)
DIAG_ENTRY(ObjCSignedCharBoolImplicitFloatConversion /* objc-signed-char-bool-implicit-float-conversion */, 12908, /* DiagArray598 */ 1625, 0)
DIAG_ENTRY(ObjCSignedCharBoolImplicitIntConversion /* objc-signed-char-bool-implicit-int-conversion */, 12956, /* DiagArray599 */ 1627, 0)
DIAG_ENTRY(ObjCStringComparison /* objc-string-compare */, 13002, /* DiagArray600 */ 1629, 0)
DIAG_ENTRY(ObjCStringConcatenation /* objc-string-concatenation */, 13022, /* DiagArray601 */ 1631, 0)
DIAG_ENTRY(anonymous_227 /* objc-unsafe-perform-selector */, 13048, /* DiagArray602 */ 1633, 0)
DIAG_ENTRY(ODR /* odr */, 13077, /* DiagArray603 */ 1635, 0)
DIAG_ENTRY(OldStyleCast /* old-style-cast */, 13081, /* DiagArray604 */ 1654, 0)
DIAG_ENTRY(anonymous_32 /* old-style-definition */, 13096, 0, 0)
DIAG_ENTRY(OpenCLUnsupportedRGBA /* opencl-unsupported-rgba */, 13117, /* DiagArray606 */ 1656, 0)
DIAG_ENTRY(OpenMP /* openmp */, 13141, 0, /* DiagSubGroup607 */ 457)
DIAG_ENTRY(OpenMP51Ext /* openmp-51-extensions */, 13148, /* DiagArray608 */ 1658, 0)
DIAG_ENTRY(OpenMPClauses /* openmp-clauses */, 13169, /* DiagArray609 */ 1660, 0)
DIAG_ENTRY(OpenMPLoopForm /* openmp-loop-form */, 13184, /* DiagArray610 */ 1679, 0)
DIAG_ENTRY(OpenMPMapping /* openmp-mapping */, 13201, /* DiagArray611 */ 1682, 0)
DIAG_ENTRY(OpenMPTarget /* openmp-target */, 13216, /* DiagArray612 */ 1684, /* DiagSubGroup612 */ 464)
DIAG_ENTRY(OptionIgnored /* option-ignored */, 13230, /* DiagArray613 */ 1688, 0)
DIAG_ENTRY(OrderedCompareFunctionPointers /* ordered-compare-function-pointers */, 13245, /* DiagArray614 */ 1700, 0)
DIAG_ENTRY(OutOfLineDeclaration /* out-of-line-declaration */, 13279, /* DiagArray615 */ 1703, 0)
DIAG_ENTRY(anonymous_135 /* out-of-scope-function */, 13303, /* DiagArray616 */ 1705, 0)
DIAG_ENTRY(OveralignedType /* over-aligned */, 13325, /* DiagArray617 */ 1707, 0)
DIAG_ENTRY(anonymous_33 /* overflow */, 13338, 0, 0)
DIAG_ENTRY(OverlengthStrings /* overlength-strings */, 13347, /* DiagArray619 */ 1709, 0)
DIAG_ENTRY(OverloadedShiftOpParentheses /* overloaded-shift-op-parentheses */, 13366, /* DiagArray620 */ 1711, 0)
DIAG_ENTRY(OverloadedVirtual /* overloaded-virtual */, 13398, /* DiagArray621 */ 1713, 0)
DIAG_ENTRY(anonymous_29 /* override-init */, 13417, 0, /* DiagSubGroup622 */ 466)
DIAG_ENTRY(anonymous_84 /* override-module */, 13431, /* DiagArray623 */ 1715, 0)
DIAG_ENTRY(OverridingMethodMismatch /* overriding-method-mismatch */, 13447, /* DiagArray624 */ 1717, 0)
DIAG_ENTRY(anonymous_76 /* overriding-t-option */, 13474, /* DiagArray625 */ 1725, 0)
DIAG_ENTRY(Packed /* packed */, 13494, /* DiagArray626 */ 1727, 0)
DIAG_ENTRY(Padded /* padded */, 13501, /* DiagArray627 */ 1729, 0)
DIAG_ENTRY(Parentheses /* parentheses */, 13508, /* DiagArray628 */ 1733, /* DiagSubGroup628 */ 468)
DIAG_ENTRY(ParenthesesOnEquality /* parentheses-equality */, 13520, /* DiagArray629 */ 1737, 0)
DIAG_ENTRY(anonymous_5 /* partial-availability */, 13541, 0, /* DiagSubGroup630 */ 477)
DIAG_ENTRY(BackendOptimizationRemark /* pass */, 13562, /* DiagArray631 */ 1739, 0)
DIAG_ENTRY(BackendOptimizationRemarkAnalysis /* pass-analysis */, 13567, /* DiagArray632 */ 1741, 0)
DIAG_ENTRY(BackendOptimizationFailure /* pass-failed */, 13581, /* DiagArray633 */ 1745, 0)
DIAG_ENTRY(BackendOptimizationRemarkMissed /* pass-missed */, 13593, /* DiagArray634 */ 1747, 0)
DIAG_ENTRY(anonymous_264 /* pch-date-time */, 13605, /* DiagArray635 */ 1749, 0)
DIAG_ENTRY(Pedantic /* pedantic */, 13619, /* DiagArray636 */ 1751, /* DiagSubGroup636 */ 479)
DIAG_ENTRY(OpenCLCoreFeaturesDiagGroup /* pedantic-core-features */, 13628, /* DiagArray637 */ 1825, 0)
DIAG_ENTRY(PedanticMacros /* pedantic-macros */, 13651, 0, /* DiagSubGroup638 */ 536)
DIAG_ENTRY(PessimizingMove /* pessimizing-move */, 13667, /* DiagArray639 */ 1828, 0)
DIAG_ENTRY(PointerArith /* pointer-arith */, 13684, /* DiagArray640 */ 1831, 0)
DIAG_ENTRY(PointerBoolConversion /* pointer-bool-conversion */, 13698, /* DiagArray641 */ 1838, 0)
DIAG_ENTRY(anonymous_183 /* pointer-compare */, 13722, /* DiagArray642 */ 1841, 0)
DIAG_ENTRY(anonymous_225 /* pointer-integer-compare */, 13738, /* DiagArray643 */ 1843, 0)
DIAG_ENTRY(anonymous_234 /* pointer-sign */, 13762, /* DiagArray644 */ 1845, 0)
DIAG_ENTRY(PointerToEnumCast /* pointer-to-enum-cast */, 13775, /* DiagArray645 */ 1847, /* DiagSubGroup645 */ 542)
DIAG_ENTRY(PointerToIntCast /* pointer-to-int-cast */, 13796, /* DiagArray646 */ 1849, /* DiagSubGroup646 */ 544)
DIAG_ENTRY(anonymous_239 /* pointer-type-mismatch */, 13816, /* DiagArray647 */ 1851, 0)
DIAG_ENTRY(anonymous_75 /* poison-system-directories */, 13838, /* DiagArray648 */ 1853, 0)
DIAG_ENTRY(ObjCPotentiallyDirectSelector /* potentially-direct-selector */, 13864, /* DiagArray649 */ 1855, 0)
DIAG_ENTRY(PotentiallyEvaluatedExpression /* potentially-evaluated-expression */, 13892, /* DiagArray650 */ 1857, 0)
DIAG_ENTRY(PragmaClangAttribute /* pragma-clang-attribute */, 13925, /* DiagArray651 */ 1859, 0)
DIAG_ENTRY(anonymous_101 /* pragma-once-outside-header */, 13948, /* DiagArray652 */ 1861, 0)
DIAG_ENTRY(PragmaPack /* pragma-pack */, 13975, /* DiagArray653 */ 1863, /* DiagSubGroup653 */ 547)
DIAG_ENTRY(PragmaPackSuspiciousInclude /* pragma-pack-suspicious-include */, 13987, /* DiagArray654 */ 1866, 0)
DIAG_ENTRY(anonymous_102 /* pragma-system-header-outside-header */, 14018, /* DiagArray655 */ 1868, 0)
DIAG_ENTRY(Pragmas /* pragmas */, 14054, /* DiagArray656 */ 1870, /* DiagSubGroup656 */ 549)
DIAG_ENTRY(CXXPre14Compat /* pre-c++14-compat */, 14062, /* DiagArray657 */ 1872, 0)
DIAG_ENTRY(CXXPre14CompatPedantic /* pre-c++14-compat-pedantic */, 14079, 0, /* DiagSubGroup658 */ 554)
DIAG_ENTRY(CXXPre17Compat /* pre-c++17-compat */, 14105, /* DiagArray659 */ 1884, 0)
DIAG_ENTRY(CXXPre17CompatPedantic /* pre-c++17-compat-pedantic */, 14122, /* DiagArray660 */ 1902, /* DiagSubGroup660 */ 557)
DIAG_ENTRY(CXXPre20Compat /* pre-c++20-compat */, 14148, /* DiagArray661 */ 1905, 0)
DIAG_ENTRY(CXXPre20CompatPedantic /* pre-c++20-compat-pedantic */, 14165, /* DiagArray662 */ 1932, /* DiagSubGroup662 */ 559)
DIAG_ENTRY(CXXPre2bCompat /* pre-c++2b-compat */, 14191, /* DiagArray663 */ 1935, 0)
DIAG_ENTRY(CXXPre2bCompatPedantic /* pre-c++2b-compat-pedantic */, 14208, 0, /* DiagSubGroup664 */ 561)
DIAG_ENTRY(CPre2xCompat /* pre-c2x-compat */, 14234, /* DiagArray665 */ 1940, 0)
DIAG_ENTRY(CPre2xCompatPedantic /* pre-c2x-compat-pedantic */, 14249, 0, /* DiagSubGroup666 */ 563)
DIAG_ENTRY(OpenMPPre51Compat /* pre-openmp-51-compat */, 14273, /* DiagArray667 */ 1944, 0)
DIAG_ENTRY(anonymous_132 /* predefined-identifier-outside-function */, 14294, /* DiagArray668 */ 1946, 0)
DIAG_ENTRY(PrivateExtern /* private-extern */, 14333, /* DiagArray669 */ 1948, 0)
DIAG_ENTRY(anonymous_112 /* private-header */, 14348, /* DiagArray670 */ 1950, 0)
DIAG_ENTRY(PrivateModule /* private-module */, 14363, /* DiagArray671 */ 1952, 0)
DIAG_ENTRY(ProfileInstrMissing /* profile-instr-missing */, 14378, /* DiagArray672 */ 1957, 0)
DIAG_ENTRY(ProfileInstrOutOfDate /* profile-instr-out-of-date */, 14400, /* DiagArray673 */ 1959, 0)
DIAG_ENTRY(ProfileInstrUnprofiled /* profile-instr-unprofiled */, 14426, /* DiagArray674 */ 1961, 0)
DIAG_ENTRY(PropertyAccessDotSyntax /* property-access-dot-syntax */, 14451, /* DiagArray675 */ 1963, 0)
DIAG_ENTRY(PropertyAttr /* property-attribute-mismatch */, 14478, /* DiagArray676 */ 1965, 0)
DIAG_ENTRY(Protocol /* protocol */, 14506, /* DiagArray677 */ 1970, 0)
DIAG_ENTRY(anonymous_146 /* protocol-property-synthesis-ambiguity */, 14515, /* DiagArray678 */ 1972, 0)
DIAG_ENTRY(anonymous_88 /* psabi */, 14553, /* DiagArray679 */ 1974, 0)
DIAG_ENTRY(anonymous_210 /* qualified-void-return-type */, 14559, /* DiagArray680 */ 1976, 0)
DIAG_ENTRY(FrameworkHdrQuotedInclude /* quoted-include-in-framework-header */, 14586, /* DiagArray681 */ 1978, 0)
DIAG_ENTRY(RangeLoopAnalysis /* range-loop-analysis */, 14621, 0, /* DiagSubGroup682 */ 565)
DIAG_ENTRY(RangeLoopBindReference /* range-loop-bind-reference */, 14641, /* DiagArray683 */ 1980, 0)
DIAG_ENTRY(RangeLoopConstruct /* range-loop-construct */, 14667, /* DiagArray684 */ 1982, 0)
DIAG_ENTRY(anonymous_156 /* readonly-iboutlet-property */, 14688, /* DiagArray685 */ 1985, 0)
DIAG_ENTRY(ObjCReceiver /* receiver-expr */, 14715, /* DiagArray686 */ 1987, 0)
DIAG_ENTRY(ForwardClassReceiver /* receiver-forward-class */, 14729, /* DiagArray687 */ 1989, 0)
DIAG_ENTRY(RedeclaredClassMember /* redeclared-class-member */, 14752, /* DiagArray688 */ 1992, 0)
DIAG_ENTRY(anonymous_158 /* redundant-consteval-if */, 14776, /* DiagArray689 */ 1994, 0)
DIAG_ENTRY(anonymous_34 /* redundant-decls */, 14799, 0, 0)
DIAG_ENTRY(RedundantMove /* redundant-move */, 14815, /* DiagArray691 */ 1996, 0)
DIAG_ENTRY(anonymous_134 /* redundant-parens */, 14830, /* DiagArray692 */ 1998, 0)
DIAG_ENTRY(Register /* register */, 14847, /* DiagArray693 */ 2000, /* DiagSubGroup693 */ 568)
DIAG_ENTRY(ReinterpretBaseClass /* reinterpret-base-class */, 14856, /* DiagArray694 */ 2002, 0)
DIAG_ENTRY(RemarkBackendPlugin /* remark-backend-plugin */, 14879, /* DiagArray695 */ 2004, 0)
DIAG_ENTRY(Reorder /* reorder */, 14901, 0, /* DiagSubGroup696 */ 570)
DIAG_ENTRY(ReorderCtor /* reorder-ctor */, 14909, /* DiagArray697 */ 2006, 0)
DIAG_ENTRY(ReorderInitList /* reorder-init-list */, 14922, /* DiagArray698 */ 2009, 0)
DIAG_ENTRY(anonymous_189 /* requires-super-attribute */, 14940, /* DiagArray699 */ 2011, 0)
DIAG_ENTRY(ReservedIdAsMacroAlias /* reserved-id-macro */, 14965, 0, /* DiagSubGroup700 */ 573)
DIAG_ENTRY(ReservedIdentifier /* reserved-identifier */, 14983, /* DiagArray701 */ 2013, /* DiagSubGroup701 */ 575)
DIAG_ENTRY(ReservedIdAsMacro /* reserved-macro-identifier */, 15003, /* DiagArray702 */ 2015, 0)
DIAG_ENTRY(ReservedUserDefinedLiteral /* reserved-user-defined-literal */, 15029, /* DiagArray703 */ 2017, /* DiagSubGroup703 */ 577)
DIAG_ENTRY(RestrictExpansionMacro /* restrict-expansion */, 15059, /* DiagArray704 */ 2020, 0)
DIAG_ENTRY(anonymous_203 /* retained-language-linkage */, 15078, /* DiagArray705 */ 2022, 0)
DIAG_ENTRY(ReturnStackAddress /* return-stack-address */, 15104, /* DiagArray706 */ 2024, 0)
DIAG_ENTRY(ReturnStdMove /* return-std-move */, 15125, 0, 0)
DIAG_ENTRY(ReturnType /* return-type */, 15141, /* DiagArray708 */ 2028, /* DiagSubGroup708 */ 579)
DIAG_ENTRY(ReturnTypeCLinkage /* return-type-c-linkage */, 15153, /* DiagArray709 */ 2038, 0)
DIAG_ENTRY(anonymous_191 /* rewrite-not-bool */, 15175, /* DiagArray710 */ 2041, 0)
DIAG_ENTRY(RoundTripCC1Args /* round-trip-cc1-args */, 15192, /* DiagArray711 */ 2043, 0)
DIAG_ENTRY(RTTI /* rtti */, 15212, /* DiagArray712 */ 2045, 0)
DIAG_ENTRY(SanitizeAddressRemarks /* sanitize-address */, 15217, /* DiagArray713 */ 2048, 0)
DIAG_ENTRY(UsedSearchPath /* search-path-usage */, 15234, /* DiagArray714 */ 2051, 0)
DIAG_ENTRY(Section /* section */, 15252, /* DiagArray715 */ 2053, 0)
DIAG_ENTRY(Selector /* selector */, 15260, /* DiagArray716 */ 2057, /* DiagSubGroup716 */ 581)
DIAG_ENTRY(SelectorTypeMismatch /* selector-type-mismatch */, 15269, /* DiagArray717 */ 2059, 0)
DIAG_ENTRY(SelfAssignment /* self-assign */, 15292, /* DiagArray718 */ 2061, /* DiagSubGroup718 */ 583)
DIAG_ENTRY(SelfAssignmentField /* self-assign-field */, 15304, /* DiagArray719 */ 2063, 0)
DIAG_ENTRY(SelfAssignmentOverloaded /* self-assign-overloaded */, 15322, /* DiagArray720 */ 2065, 0)
DIAG_ENTRY(SelfMove /* self-move */, 15345, /* DiagArray721 */ 2067, 0)
DIAG_ENTRY(SemiBeforeMethodBody /* semicolon-before-method-body */, 15355, /* DiagArray722 */ 2069, 0)
DIAG_ENTRY(Sentinel /* sentinel */, 15384, /* DiagArray723 */ 2071, 0)
DIAG_ENTRY(anonymous_38 /* sequence-point */, 15393, 0, /* DiagSubGroup724 */ 586)
DIAG_ENTRY(SerializedDiagnostics /* serialized-diagnostics */, 15408, /* DiagArray725 */ 2074, 0)
DIAG_ENTRY(Shadow /* shadow */, 15431, /* DiagArray726 */ 2078, /* DiagSubGroup726 */ 588)
DIAG_ENTRY(ShadowAll /* shadow-all */, 15438, 0, /* DiagSubGroup727 */ 591)
DIAG_ENTRY(ShadowField /* shadow-field */, 15449, /* DiagArray728 */ 2080, 0)
DIAG_ENTRY(ShadowFieldInConstructor /* shadow-field-in-constructor */, 15462, /* DiagArray729 */ 2082, /* DiagSubGroup729 */ 596)
DIAG_ENTRY(ShadowFieldInConstructorModified /* shadow-field-in-constructor-modified */, 15490, /* DiagArray730 */ 2084, 0)
DIAG_ENTRY(ShadowIvar /* shadow-ivar */, 15527, /* DiagArray731 */ 2086, 0)
DIAG_ENTRY(ShadowUncapturedLocal /* shadow-uncaptured-local */, 15539, /* DiagArray732 */ 2088, 0)
DIAG_ENTRY(anonymous_214 /* shift-count-negative */, 15563, /* DiagArray733 */ 2090, 0)
DIAG_ENTRY(anonymous_215 /* shift-count-overflow */, 15584, /* DiagArray734 */ 2092, 0)
DIAG_ENTRY(anonymous_213 /* shift-negative-value */, 15605, /* DiagArray735 */ 2094, 0)
DIAG_ENTRY(ShiftOpParentheses /* shift-op-parentheses */, 15626, /* DiagArray736 */ 2096, 0)
DIAG_ENTRY(anonymous_216 /* shift-overflow */, 15647, /* DiagArray737 */ 2098, 0)
DIAG_ENTRY(anonymous_217 /* shift-sign-overflow */, 15662, /* DiagArray738 */ 2100, 0)
DIAG_ENTRY(Shorten64To32 /* shorten-64-to-32 */, 15682, /* DiagArray739 */ 2102, 0)
DIAG_ENTRY(SignCompare /* sign-compare */, 15699, /* DiagArray740 */ 2104, 0)
DIAG_ENTRY(SignConversion /* sign-conversion */, 15712, /* DiagArray741 */ 2106, 0)
DIAG_ENTRY(anonymous_35 /* sign-promo */, 15728, 0, 0)
DIAG_ENTRY(SignedEnumBitfield /* signed-enum-bitfield */, 15739, /* DiagArray743 */ 2110, 0)
DIAG_ENTRY(anonymous_256 /* signed-unsigned-wchar */, 15760, /* DiagArray744 */ 2112, 0)
DIAG_ENTRY(SizeofArrayArgument /* sizeof-array-argument */, 15782, /* DiagArray745 */ 2114, 0)
DIAG_ENTRY(SizeofArrayDecay /* sizeof-array-decay */, 15804, /* DiagArray746 */ 2116, 0)
DIAG_ENTRY(anonymous_185 /* sizeof-array-div */, 15823, /* DiagArray747 */ 2118, 0)
DIAG_ENTRY(anonymous_184 /* sizeof-pointer-div */, 15840, /* DiagArray748 */ 2120, 0)
DIAG_ENTRY(SizeofPointerMemaccess /* sizeof-pointer-memaccess */, 15859, /* DiagArray749 */ 2122, 0)
DIAG_ENTRY(anonymous_80 /* slash-u-filename */, 15884, /* DiagArray750 */ 2125, 0)
DIAG_ENTRY(anonymous_74 /* slh-asm-goto */, 15901, /* DiagArray751 */ 2127, 0)
DIAG_ENTRY(UninitializedSometimes /* sometimes-uninitialized */, 15914, /* DiagArray752 */ 2129, 0)
DIAG_ENTRY(BackendSourceMgr /* source-mgr */, 15938, /* DiagArray753 */ 2131, 0)
DIAG_ENTRY(SourceUsesOpenMP /* source-uses-openmp */, 15949, /* DiagArray754 */ 2133, 0)
DIAG_ENTRY(SpirCompat /* spir-compat */, 15968, /* DiagArray755 */ 2142, 0)
DIAG_ENTRY(anonymous_68 /* spirv-compat */, 15980, 0, /* DiagSubGroup756 */ 598)
DIAG_ENTRY(anonymous_72 /* stack-exhausted */, 15993, /* DiagArray757 */ 2144, 0)
DIAG_ENTRY(anonymous_73 /* stack-protector */, 16009, /* DiagArray758 */ 2146, 0)
DIAG_ENTRY(StaticFloatInit /* static-float-init */, 16025, /* DiagArray759 */ 2148, /* DiagSubGroup759 */ 600)
DIAG_ENTRY(StaticInInline /* static-in-inline */, 16043, /* DiagArray760 */ 2150, 0)
DIAG_ENTRY(anonymous_127 /* static-inline-explicit-instantiation */, 16060, /* DiagArray761 */ 2153, 0)
DIAG_ENTRY(StaticLocalInInline /* static-local-in-inline */, 16097, /* DiagArray762 */ 2155, 0)
DIAG_ENTRY(UninitializedStaticSelfInit /* static-self-init */, 16120, /* DiagArray763 */ 2157, 0)
DIAG_ENTRY(anonymous_83 /* stdlibcxx-not-found */, 16137, /* DiagArray764 */ 2159, 0)
DIAG_ENTRY(anonymous_42 /* strict-aliasing */, 16157, 0, 0)
DIAG_ENTRY(anonymous_39 /* strict-aliasing=0 */, 16173, 0, 0)
DIAG_ENTRY(anonymous_40 /* strict-aliasing=1 */, 16191, 0, 0)
DIAG_ENTRY(anonymous_41 /* strict-aliasing=2 */, 16209, 0, 0)
DIAG_ENTRY(anonymous_49 /* strict-overflow */, 16227, 0, 0)
DIAG_ENTRY(anonymous_43 /* strict-overflow=0 */, 16243, 0, 0)
DIAG_ENTRY(anonymous_44 /* strict-overflow=1 */, 16261, 0, 0)
DIAG_ENTRY(anonymous_45 /* strict-overflow=2 */, 16279, 0, 0)
DIAG_ENTRY(anonymous_46 /* strict-overflow=3 */, 16297, 0, 0)
DIAG_ENTRY(anonymous_47 /* strict-overflow=4 */, 16315, 0, 0)
DIAG_ENTRY(anonymous_48 /* strict-overflow=5 */, 16333, 0, 0)
DIAG_ENTRY(ObjCStrictPotentiallyDirectSelector /* strict-potentially-direct-selector */, 16351, /* DiagArray776 */ 2161, /* DiagSubGroup776 */ 602)
DIAG_ENTRY(anonymous_197 /* strict-prototypes */, 16386, /* DiagArray777 */ 2163, 0)
DIAG_ENTRY(StrictSelector /* strict-selector-match */, 16404, /* DiagArray778 */ 2165, 0)
DIAG_ENTRY(StringCompare /* string-compare */, 16426, /* DiagArray779 */ 2167, 0)
DIAG_ENTRY(StringConcatation /* string-concatenation */, 16441, /* DiagArray780 */ 2169, 0)
DIAG_ENTRY(StringConversion /* string-conversion */, 16462, /* DiagArray781 */ 2171, 0)
DIAG_ENTRY(StringPlusChar /* string-plus-char */, 16480, /* DiagArray782 */ 2173, 0)
DIAG_ENTRY(StringPlusInt /* string-plus-int */, 16497, /* DiagArray783 */ 2175, 0)
DIAG_ENTRY(anonymous_139 /* strlcpy-strlcat-size */, 16513, /* DiagArray784 */ 2177, 0)
DIAG_ENTRY(StrncatSize /* strncat-size */, 16534, /* DiagArray785 */ 2179, 0)
DIAG_ENTRY(CXX11WarnSuggestOverrideDestructor /* suggest-destructor-override */, 16547, /* DiagArray786 */ 2183, 0)
DIAG_ENTRY(CXX11WarnSuggestOverride /* suggest-override */, 16575, /* DiagArray787 */ 2185, 0)
DIAG_ENTRY(SuperSubClassMismatch /* super-class-method-mismatch */, 16592, /* DiagArray788 */ 2187, 0)
DIAG_ENTRY(SuspiciousBzero /* suspicious-bzero */, 16620, /* DiagArray789 */ 2189, 0)
DIAG_ENTRY(SuspiciousMemaccess /* suspicious-memaccess */, 16637, 0, /* DiagSubGroup790 */ 604)
DIAG_ENTRY(SwiftNameAttribute /* swift-name-attribute */, 16658, /* DiagArray791 */ 2191, 0)
DIAG_ENTRY(Switch /* switch */, 16679, /* DiagArray792 */ 2205, 0)
DIAG_ENTRY(SwitchBool /* switch-bool */, 16686, /* DiagArray793 */ 2209, 0)
DIAG_ENTRY(anonymous_36 /* switch-default */, 16698, 0, 0)
DIAG_ENTRY(SwitchEnum /* switch-enum */, 16713, /* DiagArray795 */ 2211, 0)
DIAG_ENTRY(anonymous_255 /* sync-fetch-and-nand-semantics-changed */, 16725, /* DiagArray796 */ 2213, 0)
DIAG_ENTRY(anonymous_37 /* synth */, 16763, 0, 0)
DIAG_ENTRY(TargetClonesMixedSpecifiers /* target-clones-mixed-specifiers */, 16769, /* DiagArray798 */ 2215, 0)
DIAG_ENTRY(TautologicalBitwiseCompare /* tautological-bitwise-compare */, 16800, /* DiagArray799 */ 2217, 0)
DIAG_ENTRY(TautologicalCompare /* tautological-compare */, 16829, /* DiagArray800 */ 2220, /* DiagSubGroup800 */ 610)
DIAG_ENTRY(TautologicalConstantCompare /* tautological-constant-compare */, 16850, /* DiagArray801 */ 2223, /* DiagSubGroup801 */ 617)
DIAG_ENTRY(TautologicalInRangeCompare /* tautological-constant-in-range-compare */, 16880, 0, /* DiagSubGroup802 */ 619)
DIAG_ENTRY(TautologicalOutOfRangeCompare /* tautological-constant-out-of-range-compare */, 16919, /* DiagArray803 */ 2227, 0)
DIAG_ENTRY(TautologicalObjCBoolCompare /* tautological-objc-bool-compare */, 16962, /* DiagArray804 */ 2229, 0)
DIAG_ENTRY(TautologicalOverlapCompare /* tautological-overlap-compare */, 16993, /* DiagArray805 */ 2231, 0)
DIAG_ENTRY(TautologicalPointerCompare /* tautological-pointer-compare */, 17022, /* DiagArray806 */ 2233, 0)
DIAG_ENTRY(TautologicalTypeLimitCompare /* tautological-type-limit-compare */, 17051, /* DiagArray807 */ 2236, 0)
DIAG_ENTRY(TautologicalUndefinedCompare /* tautological-undefined-compare */, 17083, /* DiagArray808 */ 2238, 0)
DIAG_ENTRY(TautologicalUnsignedCharZeroCompare /* tautological-unsigned-char-zero-compare */, 17114, /* DiagArray809 */ 2241, 0)
DIAG_ENTRY(TautologicalUnsignedEnumZeroCompare /* tautological-unsigned-enum-zero-compare */, 17154, /* DiagArray810 */ 2243, 0)
DIAG_ENTRY(TautologicalUnsignedZeroCompare /* tautological-unsigned-zero-compare */, 17194, /* DiagArray811 */ 2245, 0)
DIAG_ENTRY(TautologicalValueRangeCompare /* tautological-value-range-compare */, 17229, /* DiagArray812 */ 2247, 0)
DIAG_ENTRY(anonymous_263 /* tcb-enforcement */, 17262, /* DiagArray813 */ 2249, 0)
DIAG_ENTRY(anonymous_220 /* tentative-definition-incomplete-type */, 17278, /* DiagArray814 */ 2251, 0)
DIAG_ENTRY(ThreadSafety /* thread-safety */, 17315, 0, /* DiagSubGroup815 */ 622)
DIAG_ENTRY(ThreadSafetyAnalysis /* thread-safety-analysis */, 17329, /* DiagArray816 */ 2253, 0)
DIAG_ENTRY(ThreadSafetyAttributes /* thread-safety-attributes */, 17352, /* DiagArray817 */ 2272, 0)
DIAG_ENTRY(ThreadSafetyBeta /* thread-safety-beta */, 17377, /* DiagArray818 */ 2279, 0)
DIAG_ENTRY(ThreadSafetyNegative /* thread-safety-negative */, 17396, /* DiagArray819 */ 2281, 0)
DIAG_ENTRY(ThreadSafetyPrecise /* thread-safety-precise */, 17419, /* DiagArray820 */ 2283, 0)
DIAG_ENTRY(ThreadSafetyReference /* thread-safety-reference */, 17441, /* DiagArray821 */ 2287, 0)
DIAG_ENTRY(ThreadSafetyVerbose /* thread-safety-verbose */, 17465, /* DiagArray822 */ 2290, 0)
DIAG_ENTRY(Trigraphs /* trigraphs */, 17487, /* DiagArray823 */ 2292, 0)
DIAG_ENTRY(TypeLimits /* type-limits */, 17497, 0, /* DiagSubGroup824 */ 627)
DIAG_ENTRY(TypeSafety /* type-safety */, 17509, /* DiagArray825 */ 2297, 0)
DIAG_ENTRY(anonymous_202 /* typedef-redefinition */, 17521, /* DiagArray826 */ 2301, 0)
DIAG_ENTRY(anonymous_195 /* typename-missing */, 17542, /* DiagArray827 */ 2303, 0)
DIAG_ENTRY(anonymous_85 /* unable-to-open-stats-file */, 17559, /* DiagArray828 */ 2305, 0)
DIAG_ENTRY(UnavailableDeclarations /* unavailable-declarations */, 17585, /* DiagArray829 */ 2307, 0)
DIAG_ENTRY(UndeclaredSelector /* undeclared-selector */, 17610, /* DiagArray830 */ 2309, 0)
DIAG_ENTRY(anonymous_105 /* undef */, 17630, /* DiagArray831 */ 2312, 0)
DIAG_ENTRY(anonymous_106 /* undef-prefix */, 17636, /* DiagArray832 */ 2314, 0)
DIAG_ENTRY(UndefinedBoolConversion /* undefined-bool-conversion */, 17649, /* DiagArray833 */ 2316, 0)
DIAG_ENTRY(UndefinedFuncTemplate /* undefined-func-template */, 17675, /* DiagArray834 */ 2319, 0)
DIAG_ENTRY(anonymous_201 /* undefined-inline */, 17699, /* DiagArray835 */ 2321, 0)
DIAG_ENTRY(anonymous_199 /* undefined-internal */, 17716, /* DiagArray836 */ 2323, 0)
DIAG_ENTRY(anonymous_200 /* undefined-internal-type */, 17735, /* DiagArray837 */ 2325, 0)
DIAG_ENTRY(UndefinedReinterpretCast /* undefined-reinterpret-cast */, 17759, /* DiagArray838 */ 2327, 0)
DIAG_ENTRY(UndefinedVarTemplate /* undefined-var-template */, 17786, /* DiagArray839 */ 2330, 0)
DIAG_ENTRY(UnderalignedExceptionObject /* underaligned-exception-object */, 17809, /* DiagArray840 */ 2332, 0)
DIAG_ENTRY(UnevaluatedExpression /* unevaluated-expression */, 17839, /* DiagArray841 */ 2334, /* DiagSubGroup841 */ 632)
DIAG_ENTRY(UnguardedAvailability /* unguarded-availability */, 17862, /* DiagArray842 */ 2336, /* DiagSubGroup842 */ 634)
DIAG_ENTRY(UnguardedAvailabilityNew /* unguarded-availability-new */, 17885, /* DiagArray843 */ 2338, 0)
DIAG_ENTRY(Unicode /* unicode */, 17912, /* DiagArray844 */ 2340, 0)
DIAG_ENTRY(anonymous_93 /* unicode-homoglyph */, 17920, /* DiagArray845 */ 2348, 0)
DIAG_ENTRY(anonymous_92 /* unicode-whitespace */, 17938, /* DiagArray846 */ 2350, 0)
DIAG_ENTRY(anonymous_94 /* unicode-zero-width */, 17957, /* DiagArray847 */ 2352, 0)
DIAG_ENTRY(Uninitialized /* uninitialized */, 17976, /* DiagArray848 */ 2354, /* DiagSubGroup848 */ 636)
DIAG_ENTRY(UninitializedConstReference /* uninitialized-const-reference */, 17990, /* DiagArray849 */ 2362, 0)
DIAG_ENTRY(UnknownArgument /* unknown-argument */, 18020, /* DiagArray850 */ 2364, 0)
DIAG_ENTRY(UnknownAssumption /* unknown-assumption */, 18037, /* DiagArray851 */ 2367, 0)
DIAG_ENTRY(UnknownAttributes /* unknown-attributes */, 18056, /* DiagArray852 */ 2369, 0)
DIAG_ENTRY(CudaUnknownVersion /* unknown-cuda-version */, 18075, /* DiagArray853 */ 2371, 0)
DIAG_ENTRY(anonymous_96 /* unknown-escape-sequence */, 18096, /* DiagArray854 */ 2374, 0)
DIAG_ENTRY(UnknownPragmas /* unknown-pragmas */, 18120, /* DiagArray855 */ 2376, 0)
DIAG_ENTRY(UnknownSanitizers /* unknown-sanitizers */, 18136, /* DiagArray856 */ 2397, 0)
DIAG_ENTRY(UnknownWarningOption /* unknown-warning-option */, 18155, /* DiagArray857 */ 2399, 0)
DIAG_ENTRY(UnnamedTypeTemplateArgs /* unnamed-type-template-args */, 18178, /* DiagArray858 */ 2403, /* DiagSubGroup858 */ 640)
DIAG_ENTRY(UnneededInternalDecl /* unneeded-internal-declaration */, 18205, /* DiagArray859 */ 2405, 0)
DIAG_ENTRY(UnneededMemberFunction /* unneeded-member-function */, 18235, /* DiagArray860 */ 2408, 0)
DIAG_ENTRY(UnreachableCode /* unreachable-code */, 18260, /* DiagArray861 */ 2410, /* DiagSubGroup861 */ 642)
DIAG_ENTRY(UnreachableCodeAggressive /* unreachable-code-aggressive */, 18277, 0, /* DiagSubGroup862 */ 645)
DIAG_ENTRY(UnreachableCodeBreak /* unreachable-code-break */, 18305, /* DiagArray863 */ 2412, 0)
DIAG_ENTRY(UnreachableCodeFallthrough /* unreachable-code-fallthrough */, 18328, /* DiagArray864 */ 2414, 0)
DIAG_ENTRY(UnreachableCodeLoopIncrement /* unreachable-code-loop-increment */, 18357, /* DiagArray865 */ 2416, 0)
DIAG_ENTRY(UnreachableCodeReturn /* unreachable-code-return */, 18389, /* DiagArray866 */ 2418, 0)
DIAG_ENTRY(Unsequenced /* unsequenced */, 18413, /* DiagArray867 */ 2420, 0)
DIAG_ENTRY(UnsupportedAbs /* unsupported-abs */, 18425, /* DiagArray868 */ 2423, 0)
DIAG_ENTRY(anonymous_181 /* unsupported-availability-guard */, 18441, /* DiagArray869 */ 2426, 0)
DIAG_ENTRY(UnsupportedCB /* unsupported-cb */, 18472, /* DiagArray870 */ 2428, 0)
DIAG_ENTRY(anonymous_177 /* unsupported-dll-base-class-template */, 18487, /* DiagArray871 */ 2430, 0)
DIAG_ENTRY(UnsupportedFPOpt /* unsupported-floating-point-opt */, 18523, /* DiagArray872 */ 2432, 0)
DIAG_ENTRY(UnsupportedFriend /* unsupported-friend */, 18554, /* DiagArray873 */ 2435, 0)
DIAG_ENTRY(UnsupportedGPOpt /* unsupported-gpopt */, 18573, /* DiagArray874 */ 2438, 0)
DIAG_ENTRY(UnsupportedNan /* unsupported-nan */, 18591, /* DiagArray875 */ 2440, 0)
DIAG_ENTRY(UnsupportedTargetOpt /* unsupported-target-opt */, 18607, /* DiagArray876 */ 2443, 0)
DIAG_ENTRY(anonymous_187 /* unsupported-visibility */, 18630, /* DiagArray877 */ 2446, 0)
DIAG_ENTRY(anonymous_193 /* unusable-partial-specialization */, 18653, /* DiagArray878 */ 2448, 0)
DIAG_ENTRY(Unused /* unused */, 18685, 0, /* DiagSubGroup879 */ 649)
DIAG_ENTRY(UnusedArgument /* unused-argument */, 18692, 0, 0)
DIAG_ENTRY(UnusedButSetParameter /* unused-but-set-parameter */, 18708, /* DiagArray881 */ 2450, 0)
DIAG_ENTRY(UnusedButSetVariable /* unused-but-set-variable */, 18733, /* DiagArray882 */ 2452, 0)
DIAG_ENTRY(UnusedCommandLineArgument /* unused-command-line-argument */, 18757, /* DiagArray883 */ 2454, 0)
DIAG_ENTRY(UnusedComparison /* unused-comparison */, 18786, /* DiagArray884 */ 2465, 0)
DIAG_ENTRY(UnusedConstVariable /* unused-const-variable */, 18804, /* DiagArray885 */ 2467, 0)
DIAG_ENTRY(UnusedExceptionParameter /* unused-exception-parameter */, 18826, /* DiagArray886 */ 2469, 0)
DIAG_ENTRY(UnusedFunction /* unused-function */, 18853, /* DiagArray887 */ 2471, /* DiagSubGroup887 */ 660)
DIAG_ENTRY(UnusedGetterReturnValue /* unused-getter-return-value */, 18869, /* DiagArray888 */ 2473, 0)
DIAG_ENTRY(UnusedLabel /* unused-label */, 18896, /* DiagArray889 */ 2475, 0)
DIAG_ENTRY(UnusedLambdaCapture /* unused-lambda-capture */, 18909, /* DiagArray890 */ 2477, 0)
DIAG_ENTRY(UnusedLocalTypedef /* unused-local-typedef */, 18931, /* DiagArray891 */ 2479, 0)
DIAG_ENTRY(anonymous_61 /* unused-local-typedefs */, 18952, 0, /* DiagSubGroup892 */ 662)
DIAG_ENTRY(anonymous_104 /* unused-macros */, 18974, /* DiagArray893 */ 2481, 0)
DIAG_ENTRY(UnusedMemberFunction /* unused-member-function */, 18988, /* DiagArray894 */ 2483, /* DiagSubGroup894 */ 664)
DIAG_ENTRY(UnusedParameter /* unused-parameter */, 19011, /* DiagArray895 */ 2485, 0)
DIAG_ENTRY(UnusedPrivateField /* unused-private-field */, 19028, /* DiagArray896 */ 2487, 0)
DIAG_ENTRY(UnusedPropertyIvar /* unused-property-ivar */, 19049, /* DiagArray897 */ 2489, 0)
DIAG_ENTRY(UnusedResult /* unused-result */, 19070, /* DiagArray898 */ 2491, 0)
DIAG_ENTRY(UnusedTemplate /* unused-template */, 19084, /* DiagArray899 */ 2494, /* DiagSubGroup899 */ 666)
DIAG_ENTRY(UnusedValue /* unused-value */, 19100, /* DiagArray900 */ 2496, /* DiagSubGroup900 */ 668)
DIAG_ENTRY(UnusedVariable /* unused-variable */, 19113, /* DiagArray901 */ 2504, /* DiagSubGroup901 */ 672)
DIAG_ENTRY(anonymous_241 /* unused-volatile-lvalue */, 19129, /* DiagArray902 */ 2506, 0)
DIAG_ENTRY(UsedButMarkedUnused /* used-but-marked-unused */, 19152, /* DiagArray903 */ 2508, 0)
DIAG_ENTRY(UserDefinedLiterals /* user-defined-literals */, 19175, /* DiagArray904 */ 2510, 0)
DIAG_ENTRY(UserDefinedWarnings /* user-defined-warnings */, 19197, /* DiagArray905 */ 2512, 0)
DIAG_ENTRY(Varargs /* varargs */, 19219, /* DiagArray906 */ 2514, 0)
DIAG_ENTRY(VariadicMacros /* variadic-macros */, 19227, /* DiagArray907 */ 2518, 0)
DIAG_ENTRY(anonymous_167 /* vec-elem-size */, 19243, /* DiagArray908 */ 2522, 0)
DIAG_ENTRY(VectorConversion /* vector-conversion */, 19257, /* DiagArray909 */ 2524, 0)
DIAG_ENTRY(anonymous_60 /* vector-conversions */, 19275, 0, /* DiagSubGroup910 */ 674)
DIAG_ENTRY(VexingParse /* vexing-parse */, 19294, /* DiagArray911 */ 2526, 0)
DIAG_ENTRY(Visibility /* visibility */, 19307, /* DiagArray912 */ 2530, 0)
DIAG_ENTRY(VLA /* vla */, 19318, /* DiagArray913 */ 2533, /* DiagSubGroup913 */ 676)
DIAG_ENTRY(VLAExtension /* vla-extension */, 19322, /* DiagArray914 */ 2535, 0)
DIAG_ENTRY(VoidPointerToEnumCast /* void-pointer-to-enum-cast */, 19336, /* DiagArray915 */ 2537, 0)
DIAG_ENTRY(VoidPointerToIntCast /* void-pointer-to-int-cast */, 19362, /* DiagArray916 */ 2539, /* DiagSubGroup916 */ 678)
DIAG_ENTRY(anonymous_222 /* void-ptr-dereference */, 19387, /* DiagArray917 */ 2541, 0)
DIAG_ENTRY(VolatileRegisterVar /* volatile-register-var */, 19408, 0, 0)
DIAG_ENTRY(WebAssemblyExceptionSpec /* wasm-exception-spec */, 19430, /* DiagArray919 */ 2543, 0)
DIAG_ENTRY(anonymous_160 /* weak-template-vtables */, 19450, /* DiagArray920 */ 2545, 0)
DIAG_ENTRY(anonymous_159 /* weak-vtables */, 19472, /* DiagArray921 */ 2547, 0)
DIAG_ENTRY(WritableStrings /* writable-strings */, 19485, /* DiagArray922 */ 2549, /* DiagSubGroup922 */ 680)
DIAG_ENTRY(GCCWriteStrings /* write-strings */, 19502, 0, /* DiagSubGroup923 */ 682)
DIAG_ENTRY(XorUsedAsPow /* xor-used-as-pow */, 19516, /* DiagArray924 */ 2551, 0)
DIAG_ENTRY(anonymous_262 /* zero-as-null-pointer-constant */, 19532, /* DiagArray925 */ 2555, 0)
DIAG_ENTRY(ZeroLengthArray /* zero-length-array */, 19562, /* DiagArray926 */ 2557, 0)
#endif // DIAG_ENTRY


#ifdef GET_CATEGORY_TABLE
CATEGORY("", DiagCat_None)
CATEGORY("Lexical or Preprocessor Issue", DiagCat_Lexical_or_Preprocessor_Issue)
CATEGORY("Semantic Issue", DiagCat_Semantic_Issue)
CATEGORY("Lambda Issue", DiagCat_Lambda_Issue)
CATEGORY("Parse Issue", DiagCat_Parse_Issue)
CATEGORY("ARC Semantic Issue", DiagCat_ARC_Semantic_Issue)
CATEGORY("ARC and @properties", DiagCat_ARC_and__properties)
CATEGORY("ARC Casting Rules", DiagCat_ARC_Casting_Rules)
CATEGORY("ARC Parse Issue", DiagCat_ARC_Parse_Issue)
CATEGORY("ARC Weak References", DiagCat_ARC_Weak_References)
CATEGORY("ARC Restrictions", DiagCat_ARC_Restrictions)
CATEGORY("OpenMP Issue", DiagCat_OpenMP_Issue)
CATEGORY("Inline Assembly Issue", DiagCat_Inline_Assembly_Issue)
CATEGORY("AST Deserialization Issue", DiagCat_AST_Deserialization_Issue)
CATEGORY("Modules Issue", DiagCat_Modules_Issue)
CATEGORY("Coroutines Issue", DiagCat_Coroutines_Issue)
CATEGORY("Concepts Issue", DiagCat_Concepts_Issue)
CATEGORY("Dependency Directive Source Minimization Issue", DiagCat_Dependency_Directive_Source_Minimization_Issue)
CATEGORY("Backend Issue", DiagCat_Backend_Issue)
CATEGORY("SourceMgr Reported Issue", DiagCat_SourceMgr_Reported_Issue)
CATEGORY("Related Result Type Issue", DiagCat_Related_Result_Type_Issue)
CATEGORY("AST Serialization Issue", DiagCat_AST_Serialization_Issue)
CATEGORY("Nullability Issue", DiagCat_Nullability_Issue)
CATEGORY("Generics Issue", DiagCat_Generics_Issue)
CATEGORY("User-Defined Issue", DiagCat_User_Defined_Issue)
CATEGORY("Refactoring Invocation Issue", DiagCat_Refactoring_Invocation_Issue)
CATEGORY("VTable ABI Issue", DiagCat_VTable_ABI_Issue)
CATEGORY("Value Conversion Issue", DiagCat_Value_Conversion_Issue)
CATEGORY("Documentation Issue", DiagCat_Documentation_Issue)
CATEGORY("ARC Retain Cycle", DiagCat_ARC_Retain_Cycle)
CATEGORY("Deprecations", DiagCat_Deprecations)
CATEGORY("Format String Issue", DiagCat_Format_String_Issue)
CATEGORY("Cocoa API Issue", DiagCat_Cocoa_API_Issue)
CATEGORY("#pragma message Directive", DiagCat__pragma_message_Directive)
CATEGORY("Instrumentation Issue", DiagCat_Instrumentation_Issue)
CATEGORY("Unused Entity Issue", DiagCat_Unused_Entity_Issue)
#endif // GET_CATEGORY_TABLE

