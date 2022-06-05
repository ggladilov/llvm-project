; ModuleID = '<stdin>'
source_filename = "test.cpp"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

%"class.std::__cxx11::basic_string" = type { %"struct.std::__cxx11::basic_string<char>::_Alloc_hider", i64, %union.anon }
%"struct.std::__cxx11::basic_string<char>::_Alloc_hider" = type { ptr }
%union.anon = type { i64, [8 x i8] }

@.str = private unnamed_addr constant [5 x i8] c"stoi\00", align 1
@.str.1 = private unnamed_addr constant [42 x i8] c"basic_string::_M_construct null not valid\00", align 1

; Function Attrs: mustprogress nofree norecurse nosync nounwind readnone willreturn uwtable
define dso_local noundef signext i8 @_Z16sum_to_obfuscateaa(i8 noundef signext %a, i8 noundef signext %b) local_unnamed_addr #0 {
entry:
  %0 = xor i8 %b, %a
  %1 = mul i8 2, %0
  %2 = and i8 %b, %a
  %3 = add i8 %2, %1
  %4 = add i8 %3, 23
  %5 = mul i8 39, %4
  %6 = mul i8 %5, -105
  %add = add i8 %6, 111
  ret i8 %add
}

; Function Attrs: norecurse uwtable
define dso_local noundef i32 @main(i32 noundef %argc, ptr nocapture noundef readonly %argv) local_unnamed_addr #1 personality ptr @__gxx_personality_v0 {
entry:
  %__endptr.i.i59 = alloca ptr, align 8
  %__dnew.i.i35 = alloca i64, align 8
  %__endptr.i.i = alloca ptr, align 8
  %__dnew.i.i = alloca i64, align 8
  %ref.tmp = alloca %"class.std::__cxx11::basic_string", align 8
  %ref.tmp6 = alloca %"class.std::__cxx11::basic_string", align 8
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %ref.tmp) #10
  %arrayidx = getelementptr inbounds ptr, ptr %argv, i64 1
  %0 = load ptr, ptr %arrayidx, align 8, !tbaa !5
  %1 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp, i64 0, i32 2
  store ptr %1, ptr %ref.tmp, align 8, !tbaa !9
  %tobool.not.i = icmp eq ptr %0, null
  br i1 %tobool.not.i, label %cond.end.i, label %cond.true.i

cond.true.i:                                      ; preds = %entry
  %call.i.i = call i64 @strlen(ptr noundef nonnull dereferenceable(1) %0) #10
  %add.ptr.i = getelementptr inbounds i8, ptr %0, i64 %call.i.i
  br label %cond.end.i

cond.end.i:                                       ; preds = %cond.true.i, %entry
  %cond.i = phi ptr [ %add.ptr.i, %cond.true.i ], [ inttoptr (i64 1 to ptr), %entry ]
  br i1 %tobool.not.i, label %if.then.i.i, label %if.end.i.i

if.then.i.i:                                      ; preds = %cond.end.i
  invoke void @_ZSt19__throw_logic_errorPKc(ptr noundef nonnull @.str.1) #11
          to label %.noexc unwind label %lpad

.noexc:                                           ; preds = %if.then.i.i
  unreachable

if.end.i.i:                                       ; preds = %cond.end.i
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__dnew.i.i) #10
  %sub.ptr.lhs.cast.i.i.i.i = ptrtoint ptr %cond.i to i64
  %sub.ptr.rhs.cast.i.i.i.i = ptrtoint ptr %0 to i64
  %sub.ptr.sub.i.i.i.i = sub i64 %sub.ptr.lhs.cast.i.i.i.i, %sub.ptr.rhs.cast.i.i.i.i
  store i64 %sub.ptr.sub.i.i.i.i, ptr %__dnew.i.i, align 8, !tbaa !11
  %cmp3.i.i = icmp ugt i64 %sub.ptr.sub.i.i.i.i, 15
  br i1 %cmp3.i.i, label %if.then4.i.i, label %if.end6.i.i

if.then4.i.i:                                     ; preds = %if.end.i.i
  %call5.i10.i29 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %ref.tmp, ptr noundef nonnull align 8 dereferenceable(8) %__dnew.i.i, i64 noundef 0)
          to label %call5.i10.i.noexc unwind label %lpad

call5.i10.i.noexc:                                ; preds = %if.then4.i.i
  store ptr %call5.i10.i29, ptr %ref.tmp, align 8, !tbaa !13
  %2 = load i64, ptr %__dnew.i.i, align 8, !tbaa !11
  store i64 %2, ptr %1, align 8, !tbaa !15
  br label %if.end6.i.i

if.end6.i.i:                                      ; preds = %call5.i10.i.noexc, %if.end.i.i
  %3 = load ptr, ptr %ref.tmp, align 8, !tbaa !13
  switch i64 %sub.ptr.sub.i.i.i.i, label %if.end.i.i.i.i.i [
    i64 1, label %if.then.i.i.i.i
    i64 0, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit
  ]

if.then.i.i.i.i:                                  ; preds = %if.end6.i.i
  %4 = load i8, ptr %0, align 1, !tbaa !15
  store i8 %4, ptr %3, align 1, !tbaa !15
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit

if.end.i.i.i.i.i:                                 ; preds = %if.end6.i.i
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %3, ptr nonnull align 1 %0, i64 %sub.ptr.sub.i.i.i.i, i1 false) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit: ; preds = %if.end.i.i.i.i.i, %if.then.i.i.i.i, %if.end6.i.i
  %5 = load i64, ptr %__dnew.i.i, align 8, !tbaa !11
  %_M_string_length.i.i.i.i = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp, i64 0, i32 1
  store i64 %5, ptr %_M_string_length.i.i.i.i, align 8, !tbaa !16
  %6 = load ptr, ptr %ref.tmp, align 8, !tbaa !13
  %arrayidx.i.i.i = getelementptr inbounds i8, ptr %6, i64 %5
  store i8 0, ptr %arrayidx.i.i.i, align 1, !tbaa !15
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__dnew.i.i) #10
  %7 = load ptr, ptr %ref.tmp, align 8, !tbaa !13
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__endptr.i.i) #10
  %call.i.i.i = call ptr @__errno_location() #12
  %8 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  store i32 0, ptr %call.i.i.i, align 4, !tbaa !17
  %call.i.i30 = call noundef i64 @strtol(ptr noundef %7, ptr noundef nonnull %__endptr.i.i, i32 noundef 10)
  %9 = load ptr, ptr %__endptr.i.i, align 8, !tbaa !5
  %cmp.i.i = icmp eq ptr %9, %7
  br i1 %cmp.i.i, label %if.then.i.i31, label %if.else.i.i

if.then.i.i31:                                    ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont1.i.i unwind label %lpad.i.i

invoke.cont1.i.i:                                 ; preds = %if.then.i.i31
  unreachable

lpad.i.i:                                         ; preds = %if.then7.i.i, %if.then.i.i31
  %10 = landingpad { ptr, i32 }
          cleanup
  %11 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp.i.i.i = icmp eq i32 %11, 0
  br i1 %cmp.i.i.i, label %if.then.i.i.i, label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i

if.then.i.i.i:                                    ; preds = %lpad.i.i
  store i32 %8, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i

_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i: ; preds = %if.then.i.i.i, %lpad.i.i
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i) #10
  %12 = load ptr, ptr %ref.tmp, align 8, !tbaa !13
  %cmp.i.i.i83 = icmp eq ptr %12, %1
  br i1 %cmp.i.i.i83, label %ehcleanup, label %if.then.i.i84

if.else.i.i:                                      ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit
  %13 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp3.i.i32 = icmp eq i32 %13, 34
  %14 = add i64 %call.i.i30, -2147483648
  %15 = icmp ult i64 %14, -4294967296
  %or.cond.i.i = or i1 %15, %cmp3.i.i32
  br i1 %or.cond.i.i, label %if.then7.i.i, label %if.else9.i.i

if.then7.i.i:                                     ; preds = %if.else.i.i
  invoke void @_ZSt20__throw_out_of_rangePKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont8.i.i unwind label %lpad.i.i

invoke.cont8.i.i:                                 ; preds = %if.then7.i.i
  unreachable

if.else9.i.i:                                     ; preds = %if.else.i.i
  %cmp.i25.i.i = icmp eq i32 %13, 0
  br i1 %cmp.i25.i.i, label %if.then.i26.i.i, label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit

if.then.i26.i.i:                                  ; preds = %if.else9.i.i
  store i32 %8, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit

_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit: ; preds = %if.then.i26.i.i, %if.else9.i.i
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i) #10
  %16 = load ptr, ptr %ref.tmp, align 8, !tbaa !13
  %cmp.i.i.i33 = icmp eq ptr %16, %1
  br i1 %cmp.i.i.i33, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit, label %if.then.i.i34

if.then.i.i34:                                    ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit
  call void @_ZdlPv(ptr noundef %16) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit: ; preds = %if.then.i.i34, %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp) #10
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %ref.tmp6) #10
  %arrayidx7 = getelementptr inbounds ptr, ptr %argv, i64 2
  %17 = load ptr, ptr %arrayidx7, align 8, !tbaa !5
  %18 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp6, i64 0, i32 2
  store ptr %18, ptr %ref.tmp6, align 8, !tbaa !9
  %tobool.not.i36 = icmp eq ptr %17, null
  br i1 %tobool.not.i36, label %cond.end.i42, label %cond.true.i39

cond.true.i39:                                    ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit
  %call.i.i37 = call i64 @strlen(ptr noundef nonnull dereferenceable(1) %17) #10
  %add.ptr.i38 = getelementptr inbounds i8, ptr %17, i64 %call.i.i37
  br label %cond.end.i42

cond.end.i42:                                     ; preds = %cond.true.i39, %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit
  %cond.i40 = phi ptr [ %add.ptr.i38, %cond.true.i39 ], [ inttoptr (i64 1 to ptr), %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit ]
  br i1 %tobool.not.i36, label %if.then.i.i43, label %if.end.i.i48

if.then.i.i43:                                    ; preds = %cond.end.i42
  invoke void @_ZSt19__throw_logic_errorPKc(ptr noundef nonnull @.str.1) #11
          to label %.noexc55 unwind label %lpad9

.noexc55:                                         ; preds = %if.then.i.i43
  unreachable

if.end.i.i48:                                     ; preds = %cond.end.i42
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__dnew.i.i35) #10
  %sub.ptr.lhs.cast.i.i.i.i44 = ptrtoint ptr %cond.i40 to i64
  %sub.ptr.rhs.cast.i.i.i.i45 = ptrtoint ptr %17 to i64
  %sub.ptr.sub.i.i.i.i46 = sub i64 %sub.ptr.lhs.cast.i.i.i.i44, %sub.ptr.rhs.cast.i.i.i.i45
  store i64 %sub.ptr.sub.i.i.i.i46, ptr %__dnew.i.i35, align 8, !tbaa !11
  %cmp3.i.i47 = icmp ugt i64 %sub.ptr.sub.i.i.i.i46, 15
  br i1 %cmp3.i.i47, label %if.then4.i.i49, label %if.end6.i.i50

if.then4.i.i49:                                   ; preds = %if.end.i.i48
  %call5.i10.i57 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %ref.tmp6, ptr noundef nonnull align 8 dereferenceable(8) %__dnew.i.i35, i64 noundef 0)
          to label %call5.i10.i.noexc56 unwind label %lpad9

call5.i10.i.noexc56:                              ; preds = %if.then4.i.i49
  store ptr %call5.i10.i57, ptr %ref.tmp6, align 8, !tbaa !13
  %19 = load i64, ptr %__dnew.i.i35, align 8, !tbaa !11
  store i64 %19, ptr %18, align 8, !tbaa !15
  br label %if.end6.i.i50

if.end6.i.i50:                                    ; preds = %call5.i10.i.noexc56, %if.end.i.i48
  %20 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  switch i64 %sub.ptr.sub.i.i.i.i46, label %if.end.i.i.i.i.i52 [
    i64 1, label %if.then.i.i.i.i51
    i64 0, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit58
  ]

if.then.i.i.i.i51:                                ; preds = %if.end6.i.i50
  %21 = load i8, ptr %17, align 1, !tbaa !15
  store i8 %21, ptr %20, align 1, !tbaa !15
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit58

if.end.i.i.i.i.i52:                               ; preds = %if.end6.i.i50
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %20, ptr nonnull align 1 %17, i64 %sub.ptr.sub.i.i.i.i46, i1 false) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit58

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit58: ; preds = %if.end.i.i.i.i.i52, %if.then.i.i.i.i51, %if.end6.i.i50
  %22 = load i64, ptr %__dnew.i.i35, align 8, !tbaa !11
  %_M_string_length.i.i.i.i53 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp6, i64 0, i32 1
  store i64 %22, ptr %_M_string_length.i.i.i.i53, align 8, !tbaa !16
  %23 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  %arrayidx.i.i.i54 = getelementptr inbounds i8, ptr %23, i64 %22
  store i8 0, ptr %arrayidx.i.i.i54, align 1, !tbaa !15
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__dnew.i.i35) #10
  %24 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__endptr.i.i59) #10
  %25 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  store i32 0, ptr %call.i.i.i, align 4, !tbaa !17
  %call.i.i61 = call noundef i64 @strtol(ptr noundef %24, ptr noundef nonnull %__endptr.i.i59, i32 noundef 10)
  %26 = load ptr, ptr %__endptr.i.i59, align 8, !tbaa !5
  %cmp.i.i62 = icmp eq ptr %26, %24
  br i1 %cmp.i.i62, label %if.then.i.i63, label %if.else.i.i71

if.then.i.i63:                                    ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit58
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont1.i.i64 unwind label %lpad.i.i66

invoke.cont1.i.i64:                               ; preds = %if.then.i.i63
  unreachable

lpad.i.i66:                                       ; preds = %if.then7.i.i72, %if.then.i.i63
  %27 = landingpad { ptr, i32 }
          cleanup
  %28 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp.i.i.i65 = icmp eq i32 %28, 0
  br i1 %cmp.i.i.i65, label %if.then.i.i.i67, label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i68

if.then.i.i.i67:                                  ; preds = %lpad.i.i66
  store i32 %25, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i68

_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i68: ; preds = %if.then.i.i.i67, %lpad.i.i66
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i59) #10
  %29 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  %cmp.i.i.i86 = icmp eq ptr %29, %18
  br i1 %cmp.i.i.i86, label %ehcleanup15, label %if.then.i.i87

if.else.i.i71:                                    ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit58
  %30 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp3.i.i69 = icmp eq i32 %30, 34
  %31 = add i64 %call.i.i61, -2147483648
  %32 = icmp ult i64 %31, -4294967296
  %or.cond.i.i70 = or i1 %32, %cmp3.i.i69
  br i1 %or.cond.i.i70, label %if.then7.i.i72, label %if.else9.i.i74

if.then7.i.i72:                                   ; preds = %if.else.i.i71
  invoke void @_ZSt20__throw_out_of_rangePKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont8.i.i73 unwind label %lpad.i.i66

invoke.cont8.i.i73:                               ; preds = %if.then7.i.i72
  unreachable

if.else9.i.i74:                                   ; preds = %if.else.i.i71
  %cmp.i25.i.i75 = icmp eq i32 %30, 0
  br i1 %cmp.i25.i.i75, label %if.then.i26.i.i76, label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit79

if.then.i26.i.i76:                                ; preds = %if.else9.i.i74
  store i32 %25, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit79

_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit79: ; preds = %if.then.i26.i.i76, %if.else9.i.i74
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i59) #10
  %33 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  %cmp.i.i.i80 = icmp eq ptr %33, %18
  br i1 %cmp.i.i.i80, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit82, label %if.then.i.i81

if.then.i.i81:                                    ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit79
  call void @_ZdlPv(ptr noundef %33) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit82

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit82: ; preds = %if.then.i.i81, %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit79
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp6) #10
  %conv = trunc i64 %call.i.i30 to i32
  %conv18 = trunc i64 %call.i.i61 to i32
  %add.i = add i32 %conv18, %conv
  %sext = shl i32 %add.i, 24
  %conv20 = ashr exact i32 %sext, 24
  ret i32 %conv20

lpad:                                             ; preds = %if.then4.i.i, %if.then.i.i
  %34 = landingpad { ptr, i32 }
          cleanup
  br label %ehcleanup

if.then.i.i84:                                    ; preds = %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i
  call void @_ZdlPv(ptr noundef %12) #10
  br label %ehcleanup

ehcleanup:                                        ; preds = %if.then.i.i84, %lpad, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i
  %.pn = phi { ptr, i32 } [ %34, %lpad ], [ %10, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i ], [ %10, %if.then.i.i84 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp) #10
  br label %ehcleanup22

lpad9:                                            ; preds = %if.then4.i.i49, %if.then.i.i43
  %35 = landingpad { ptr, i32 }
          cleanup
  br label %ehcleanup15

if.then.i.i87:                                    ; preds = %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i68
  call void @_ZdlPv(ptr noundef %29) #10
  br label %ehcleanup15

ehcleanup15:                                      ; preds = %if.then.i.i87, %lpad9, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i68
  %.pn26 = phi { ptr, i32 } [ %35, %lpad9 ], [ %27, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i68 ], [ %27, %if.then.i.i87 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp6) #10
  br label %ehcleanup22

ehcleanup22:                                      ; preds = %ehcleanup15, %ehcleanup
  %.pn26.pn = phi { ptr, i32 } [ %.pn26, %ehcleanup15 ], [ %.pn, %ehcleanup ]
  resume { ptr, i32 } %.pn26.pn
}

; Function Attrs: argmemonly nocallback nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #2

declare i32 @__gxx_personality_v0(...)

; Function Attrs: argmemonly nocallback nofree nosync nounwind willreturn
declare void @llvm.lifetime.end.p0(i64 immarg, ptr nocapture) #2

; Function Attrs: mustprogress nofree nounwind willreturn
declare i64 @strtol(ptr noundef readonly, ptr nocapture noundef, i32 noundef) local_unnamed_addr #3

; Function Attrs: noreturn
declare void @_ZSt24__throw_invalid_argumentPKc(ptr noundef) local_unnamed_addr #4

; Function Attrs: mustprogress nofree nosync nounwind readnone willreturn
declare ptr @__errno_location() local_unnamed_addr #5

; Function Attrs: noreturn
declare void @_ZSt20__throw_out_of_rangePKc(ptr noundef) local_unnamed_addr #4

; Function Attrs: nobuiltin nounwind
declare void @_ZdlPv(ptr noundef) local_unnamed_addr #6

; Function Attrs: argmemonly mustprogress nofree nounwind readonly willreturn
declare i64 @strlen(ptr nocapture noundef) local_unnamed_addr #7

; Function Attrs: noreturn
declare void @_ZSt19__throw_logic_errorPKc(ptr noundef) local_unnamed_addr #4

declare noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32), ptr noundef nonnull align 8 dereferenceable(8), i64 noundef) local_unnamed_addr #8

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #9

attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone willreturn uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { norecurse uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly nocallback nofree nosync nounwind willreturn }
attributes #3 = { mustprogress nofree nounwind willreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { noreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { mustprogress nofree nosync nounwind readnone willreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #6 = { nobuiltin nounwind "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #7 = { argmemonly mustprogress nofree nounwind readonly willreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #8 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #9 = { argmemonly nofree nounwind willreturn }
attributes #10 = { nounwind }
attributes #11 = { noreturn }
attributes #12 = { nounwind readnone willreturn }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"clang version 15.0.0 (https://github.com/George-Amberson/llvm-project.git 54878fddeffd04679cb74d4e2d59df65303c44f8)"}
!5 = !{!6, !6, i64 0}
!6 = !{!"any pointer", !7, i64 0}
!7 = !{!"omnipotent char", !8, i64 0}
!8 = !{!"Simple C++ TBAA"}
!9 = !{!10, !6, i64 0}
!10 = !{!"_ZTSNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE12_Alloc_hiderE", !6, i64 0}
!11 = !{!12, !12, i64 0}
!12 = !{!"long", !7, i64 0}
!13 = !{!14, !6, i64 0}
!14 = !{!"_ZTSNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEE", !10, i64 0, !12, i64 8, !7, i64 16}
!15 = !{!7, !7, i64 0}
!16 = !{!14, !12, i64 8}
!17 = !{!18, !18, i64 0}
!18 = !{!"int", !7, i64 0}
