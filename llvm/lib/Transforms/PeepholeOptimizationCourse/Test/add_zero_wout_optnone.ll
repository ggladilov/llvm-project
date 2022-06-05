; ModuleID = 'i8sum.cpp'
source_filename = "i8sum.cpp"
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
  %add = add i8 %b, %a
  ret i8 %add
}

; Function Attrs: norecurse uwtable
define dso_local noundef i32 @main(i32 noundef %argc, ptr nocapture noundef readonly %argv) local_unnamed_addr #1 personality ptr @__gxx_personality_v0 {
entry:
  %__endptr.i.i189 = alloca ptr, align 8
  %__dnew.i.i165 = alloca i64, align 8
  %__endptr.i.i141 = alloca ptr, align 8
  %__dnew.i.i117 = alloca i64, align 8
  %__endptr.i.i93 = alloca ptr, align 8
  %__dnew.i.i69 = alloca i64, align 8
  %__endptr.i.i = alloca ptr, align 8
  %__dnew.i.i = alloca i64, align 8
  %ref.tmp = alloca %"class.std::__cxx11::basic_string", align 8
  %ref.tmp6 = alloca %"class.std::__cxx11::basic_string", align 8
  %ref.tmp18 = alloca %"class.std::__cxx11::basic_string", align 8
  %ref.tmp30 = alloca %"class.std::__cxx11::basic_string", align 8
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
  %call5.i10.i63 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %ref.tmp, ptr noundef nonnull align 8 dereferenceable(8) %__dnew.i.i, i64 noundef 0)
          to label %call5.i10.i.noexc unwind label %lpad

call5.i10.i.noexc:                                ; preds = %if.then4.i.i
  store ptr %call5.i10.i63, ptr %ref.tmp, align 8, !tbaa !13
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

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit: ; preds = %if.end6.i.i, %if.then.i.i.i.i, %if.end.i.i.i.i.i
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
  %call.i.i64 = call noundef i64 @strtol(ptr noundef %7, ptr noundef nonnull %__endptr.i.i, i32 noundef 10)
  %9 = load ptr, ptr %__endptr.i.i, align 8, !tbaa !5
  %cmp.i.i = icmp eq ptr %9, %7
  br i1 %cmp.i.i, label %if.then.i.i65, label %if.else.i.i

if.then.i.i65:                                    ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont1.i.i unwind label %lpad.i.i

invoke.cont1.i.i:                                 ; preds = %if.then.i.i65
  unreachable

lpad.i.i:                                         ; preds = %if.then7.i.i, %if.then.i.i65
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
  %cmp.i.i.i213 = icmp eq ptr %12, %1
  br i1 %cmp.i.i.i213, label %ehcleanup, label %if.then.i.i214

if.else.i.i:                                      ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit
  %13 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp3.i.i66 = icmp eq i32 %13, 34
  %14 = add i64 %call.i.i64, -2147483648
  %15 = icmp ult i64 %14, -4294967296
  %or.cond.i.i = or i1 %15, %cmp3.i.i66
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

_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit: ; preds = %if.else9.i.i, %if.then.i26.i.i
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i) #10
  %16 = load ptr, ptr %ref.tmp, align 8, !tbaa !13
  %cmp.i.i.i67 = icmp eq ptr %16, %1
  br i1 %cmp.i.i.i67, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit, label %if.then.i.i68

if.then.i.i68:                                    ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit
  call void @_ZdlPv(ptr noundef %16) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit: ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit, %if.then.i.i68
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp) #10
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %ref.tmp6) #10
  %arrayidx7 = getelementptr inbounds ptr, ptr %argv, i64 2
  %17 = load ptr, ptr %arrayidx7, align 8, !tbaa !5
  %18 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp6, i64 0, i32 2
  store ptr %18, ptr %ref.tmp6, align 8, !tbaa !9
  %tobool.not.i70 = icmp eq ptr %17, null
  br i1 %tobool.not.i70, label %cond.end.i76, label %cond.true.i73

cond.true.i73:                                    ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit
  %call.i.i71 = call i64 @strlen(ptr noundef nonnull dereferenceable(1) %17) #10
  %add.ptr.i72 = getelementptr inbounds i8, ptr %17, i64 %call.i.i71
  br label %cond.end.i76

cond.end.i76:                                     ; preds = %cond.true.i73, %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit
  %cond.i74 = phi ptr [ %add.ptr.i72, %cond.true.i73 ], [ inttoptr (i64 1 to ptr), %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit ]
  br i1 %tobool.not.i70, label %if.then.i.i77, label %if.end.i.i82

if.then.i.i77:                                    ; preds = %cond.end.i76
  invoke void @_ZSt19__throw_logic_errorPKc(ptr noundef nonnull @.str.1) #11
          to label %.noexc89 unwind label %lpad9

.noexc89:                                         ; preds = %if.then.i.i77
  unreachable

if.end.i.i82:                                     ; preds = %cond.end.i76
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__dnew.i.i69) #10
  %sub.ptr.lhs.cast.i.i.i.i78 = ptrtoint ptr %cond.i74 to i64
  %sub.ptr.rhs.cast.i.i.i.i79 = ptrtoint ptr %17 to i64
  %sub.ptr.sub.i.i.i.i80 = sub i64 %sub.ptr.lhs.cast.i.i.i.i78, %sub.ptr.rhs.cast.i.i.i.i79
  store i64 %sub.ptr.sub.i.i.i.i80, ptr %__dnew.i.i69, align 8, !tbaa !11
  %cmp3.i.i81 = icmp ugt i64 %sub.ptr.sub.i.i.i.i80, 15
  br i1 %cmp3.i.i81, label %if.then4.i.i83, label %if.end6.i.i84

if.then4.i.i83:                                   ; preds = %if.end.i.i82
  %call5.i10.i91 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %ref.tmp6, ptr noundef nonnull align 8 dereferenceable(8) %__dnew.i.i69, i64 noundef 0)
          to label %call5.i10.i.noexc90 unwind label %lpad9

call5.i10.i.noexc90:                              ; preds = %if.then4.i.i83
  store ptr %call5.i10.i91, ptr %ref.tmp6, align 8, !tbaa !13
  %19 = load i64, ptr %__dnew.i.i69, align 8, !tbaa !11
  store i64 %19, ptr %18, align 8, !tbaa !15
  br label %if.end6.i.i84

if.end6.i.i84:                                    ; preds = %call5.i10.i.noexc90, %if.end.i.i82
  %20 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  switch i64 %sub.ptr.sub.i.i.i.i80, label %if.end.i.i.i.i.i86 [
    i64 1, label %if.then.i.i.i.i85
    i64 0, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit92
  ]

if.then.i.i.i.i85:                                ; preds = %if.end6.i.i84
  %21 = load i8, ptr %17, align 1, !tbaa !15
  store i8 %21, ptr %20, align 1, !tbaa !15
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit92

if.end.i.i.i.i.i86:                               ; preds = %if.end6.i.i84
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %20, ptr nonnull align 1 %17, i64 %sub.ptr.sub.i.i.i.i80, i1 false) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit92

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit92: ; preds = %if.end6.i.i84, %if.then.i.i.i.i85, %if.end.i.i.i.i.i86
  %22 = load i64, ptr %__dnew.i.i69, align 8, !tbaa !11
  %_M_string_length.i.i.i.i87 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp6, i64 0, i32 1
  store i64 %22, ptr %_M_string_length.i.i.i.i87, align 8, !tbaa !16
  %23 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  %arrayidx.i.i.i88 = getelementptr inbounds i8, ptr %23, i64 %22
  store i8 0, ptr %arrayidx.i.i.i88, align 1, !tbaa !15
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__dnew.i.i69) #10
  %24 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__endptr.i.i93) #10
  %25 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  store i32 0, ptr %call.i.i.i, align 4, !tbaa !17
  %call.i.i95 = call noundef i64 @strtol(ptr noundef %24, ptr noundef nonnull %__endptr.i.i93, i32 noundef 10)
  %26 = load ptr, ptr %__endptr.i.i93, align 8, !tbaa !5
  %cmp.i.i96 = icmp eq ptr %26, %24
  br i1 %cmp.i.i96, label %if.then.i.i97, label %if.else.i.i105

if.then.i.i97:                                    ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit92
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont1.i.i98 unwind label %lpad.i.i100

invoke.cont1.i.i98:                               ; preds = %if.then.i.i97
  unreachable

lpad.i.i100:                                      ; preds = %if.then7.i.i106, %if.then.i.i97
  %27 = landingpad { ptr, i32 }
          cleanup
  %28 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp.i.i.i99 = icmp eq i32 %28, 0
  br i1 %cmp.i.i.i99, label %if.then.i.i.i101, label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i102

if.then.i.i.i101:                                 ; preds = %lpad.i.i100
  store i32 %25, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i102

_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i102: ; preds = %if.then.i.i.i101, %lpad.i.i100
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i93) #10
  %29 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  %cmp.i.i.i216 = icmp eq ptr %29, %18
  br i1 %cmp.i.i.i216, label %ehcleanup15, label %if.then.i.i217

if.else.i.i105:                                   ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit92
  %30 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp3.i.i103 = icmp eq i32 %30, 34
  %31 = add i64 %call.i.i95, -2147483648
  %32 = icmp ult i64 %31, -4294967296
  %or.cond.i.i104 = or i1 %32, %cmp3.i.i103
  br i1 %or.cond.i.i104, label %if.then7.i.i106, label %if.else9.i.i108

if.then7.i.i106:                                  ; preds = %if.else.i.i105
  invoke void @_ZSt20__throw_out_of_rangePKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont8.i.i107 unwind label %lpad.i.i100

invoke.cont8.i.i107:                              ; preds = %if.then7.i.i106
  unreachable

if.else9.i.i108:                                  ; preds = %if.else.i.i105
  %cmp.i25.i.i109 = icmp eq i32 %30, 0
  br i1 %cmp.i25.i.i109, label %if.then.i26.i.i110, label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit113

if.then.i26.i.i110:                               ; preds = %if.else9.i.i108
  store i32 %25, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit113

_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit113: ; preds = %if.else9.i.i108, %if.then.i26.i.i110
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i93) #10
  %33 = load ptr, ptr %ref.tmp6, align 8, !tbaa !13
  %cmp.i.i.i114 = icmp eq ptr %33, %18
  br i1 %cmp.i.i.i114, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit116, label %if.then.i.i115

if.then.i.i115:                                   ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit113
  call void @_ZdlPv(ptr noundef %33) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit116

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit116: ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit113, %if.then.i.i115
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp6) #10
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %ref.tmp18) #10
  %arrayidx19 = getelementptr inbounds ptr, ptr %argv, i64 3
  %34 = load ptr, ptr %arrayidx19, align 8, !tbaa !5
  %35 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp18, i64 0, i32 2
  store ptr %35, ptr %ref.tmp18, align 8, !tbaa !9
  %tobool.not.i118 = icmp eq ptr %34, null
  br i1 %tobool.not.i118, label %cond.end.i124, label %cond.true.i121

cond.true.i121:                                   ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit116
  %call.i.i119 = call i64 @strlen(ptr noundef nonnull dereferenceable(1) %34) #10
  %add.ptr.i120 = getelementptr inbounds i8, ptr %34, i64 %call.i.i119
  br label %cond.end.i124

cond.end.i124:                                    ; preds = %cond.true.i121, %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit116
  %cond.i122 = phi ptr [ %add.ptr.i120, %cond.true.i121 ], [ inttoptr (i64 1 to ptr), %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit116 ]
  br i1 %tobool.not.i118, label %if.then.i.i125, label %if.end.i.i130

if.then.i.i125:                                   ; preds = %cond.end.i124
  invoke void @_ZSt19__throw_logic_errorPKc(ptr noundef nonnull @.str.1) #11
          to label %.noexc137 unwind label %lpad21

.noexc137:                                        ; preds = %if.then.i.i125
  unreachable

if.end.i.i130:                                    ; preds = %cond.end.i124
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__dnew.i.i117) #10
  %sub.ptr.lhs.cast.i.i.i.i126 = ptrtoint ptr %cond.i122 to i64
  %sub.ptr.rhs.cast.i.i.i.i127 = ptrtoint ptr %34 to i64
  %sub.ptr.sub.i.i.i.i128 = sub i64 %sub.ptr.lhs.cast.i.i.i.i126, %sub.ptr.rhs.cast.i.i.i.i127
  store i64 %sub.ptr.sub.i.i.i.i128, ptr %__dnew.i.i117, align 8, !tbaa !11
  %cmp3.i.i129 = icmp ugt i64 %sub.ptr.sub.i.i.i.i128, 15
  br i1 %cmp3.i.i129, label %if.then4.i.i131, label %if.end6.i.i132

if.then4.i.i131:                                  ; preds = %if.end.i.i130
  %call5.i10.i139 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %ref.tmp18, ptr noundef nonnull align 8 dereferenceable(8) %__dnew.i.i117, i64 noundef 0)
          to label %call5.i10.i.noexc138 unwind label %lpad21

call5.i10.i.noexc138:                             ; preds = %if.then4.i.i131
  store ptr %call5.i10.i139, ptr %ref.tmp18, align 8, !tbaa !13
  %36 = load i64, ptr %__dnew.i.i117, align 8, !tbaa !11
  store i64 %36, ptr %35, align 8, !tbaa !15
  br label %if.end6.i.i132

if.end6.i.i132:                                   ; preds = %call5.i10.i.noexc138, %if.end.i.i130
  %37 = load ptr, ptr %ref.tmp18, align 8, !tbaa !13
  switch i64 %sub.ptr.sub.i.i.i.i128, label %if.end.i.i.i.i.i134 [
    i64 1, label %if.then.i.i.i.i133
    i64 0, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit140
  ]

if.then.i.i.i.i133:                               ; preds = %if.end6.i.i132
  %38 = load i8, ptr %34, align 1, !tbaa !15
  store i8 %38, ptr %37, align 1, !tbaa !15
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit140

if.end.i.i.i.i.i134:                              ; preds = %if.end6.i.i132
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %37, ptr nonnull align 1 %34, i64 %sub.ptr.sub.i.i.i.i128, i1 false) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit140

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit140: ; preds = %if.end6.i.i132, %if.then.i.i.i.i133, %if.end.i.i.i.i.i134
  %39 = load i64, ptr %__dnew.i.i117, align 8, !tbaa !11
  %_M_string_length.i.i.i.i135 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp18, i64 0, i32 1
  store i64 %39, ptr %_M_string_length.i.i.i.i135, align 8, !tbaa !16
  %40 = load ptr, ptr %ref.tmp18, align 8, !tbaa !13
  %arrayidx.i.i.i136 = getelementptr inbounds i8, ptr %40, i64 %39
  store i8 0, ptr %arrayidx.i.i.i136, align 1, !tbaa !15
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__dnew.i.i117) #10
  %41 = load ptr, ptr %ref.tmp18, align 8, !tbaa !13
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__endptr.i.i141) #10
  %42 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  store i32 0, ptr %call.i.i.i, align 4, !tbaa !17
  %call.i.i143 = call noundef i64 @strtol(ptr noundef %41, ptr noundef nonnull %__endptr.i.i141, i32 noundef 10)
  %43 = load ptr, ptr %__endptr.i.i141, align 8, !tbaa !5
  %cmp.i.i144 = icmp eq ptr %43, %41
  br i1 %cmp.i.i144, label %if.then.i.i145, label %if.else.i.i153

if.then.i.i145:                                   ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit140
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont1.i.i146 unwind label %lpad.i.i148

invoke.cont1.i.i146:                              ; preds = %if.then.i.i145
  unreachable

lpad.i.i148:                                      ; preds = %if.then7.i.i154, %if.then.i.i145
  %44 = landingpad { ptr, i32 }
          cleanup
  %45 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp.i.i.i147 = icmp eq i32 %45, 0
  br i1 %cmp.i.i.i147, label %if.then.i.i.i149, label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i150

if.then.i.i.i149:                                 ; preds = %lpad.i.i148
  store i32 %42, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i150

_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i150: ; preds = %if.then.i.i.i149, %lpad.i.i148
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i141) #10
  %46 = load ptr, ptr %ref.tmp18, align 8, !tbaa !13
  %cmp.i.i.i219 = icmp eq ptr %46, %35
  br i1 %cmp.i.i.i219, label %ehcleanup27, label %if.then.i.i220

if.else.i.i153:                                   ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit140
  %47 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp3.i.i151 = icmp eq i32 %47, 34
  %48 = add i64 %call.i.i143, -2147483648
  %49 = icmp ult i64 %48, -4294967296
  %or.cond.i.i152 = or i1 %49, %cmp3.i.i151
  br i1 %or.cond.i.i152, label %if.then7.i.i154, label %if.else9.i.i156

if.then7.i.i154:                                  ; preds = %if.else.i.i153
  invoke void @_ZSt20__throw_out_of_rangePKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont8.i.i155 unwind label %lpad.i.i148

invoke.cont8.i.i155:                              ; preds = %if.then7.i.i154
  unreachable

if.else9.i.i156:                                  ; preds = %if.else.i.i153
  %cmp.i25.i.i157 = icmp eq i32 %47, 0
  br i1 %cmp.i25.i.i157, label %if.then.i26.i.i158, label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit161

if.then.i26.i.i158:                               ; preds = %if.else9.i.i156
  store i32 %42, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit161

_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit161: ; preds = %if.else9.i.i156, %if.then.i26.i.i158
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i141) #10
  %50 = load ptr, ptr %ref.tmp18, align 8, !tbaa !13
  %cmp.i.i.i162 = icmp eq ptr %50, %35
  br i1 %cmp.i.i.i162, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit164, label %if.then.i.i163

if.then.i.i163:                                   ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit161
  call void @_ZdlPv(ptr noundef %50) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit164

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit164: ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit161, %if.then.i.i163
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp18) #10
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %ref.tmp30) #10
  %arrayidx31 = getelementptr inbounds ptr, ptr %argv, i64 4
  %51 = load ptr, ptr %arrayidx31, align 8, !tbaa !5
  %52 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp30, i64 0, i32 2
  store ptr %52, ptr %ref.tmp30, align 8, !tbaa !9
  %tobool.not.i166 = icmp eq ptr %51, null
  br i1 %tobool.not.i166, label %cond.end.i172, label %cond.true.i169

cond.true.i169:                                   ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit164
  %call.i.i167 = call i64 @strlen(ptr noundef nonnull dereferenceable(1) %51) #10
  %add.ptr.i168 = getelementptr inbounds i8, ptr %51, i64 %call.i.i167
  br label %cond.end.i172

cond.end.i172:                                    ; preds = %cond.true.i169, %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit164
  %cond.i170 = phi ptr [ %add.ptr.i168, %cond.true.i169 ], [ inttoptr (i64 1 to ptr), %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit164 ]
  br i1 %tobool.not.i166, label %if.then.i.i173, label %if.end.i.i178

if.then.i.i173:                                   ; preds = %cond.end.i172
  invoke void @_ZSt19__throw_logic_errorPKc(ptr noundef nonnull @.str.1) #11
          to label %.noexc185 unwind label %lpad33

.noexc185:                                        ; preds = %if.then.i.i173
  unreachable

if.end.i.i178:                                    ; preds = %cond.end.i172
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__dnew.i.i165) #10
  %sub.ptr.lhs.cast.i.i.i.i174 = ptrtoint ptr %cond.i170 to i64
  %sub.ptr.rhs.cast.i.i.i.i175 = ptrtoint ptr %51 to i64
  %sub.ptr.sub.i.i.i.i176 = sub i64 %sub.ptr.lhs.cast.i.i.i.i174, %sub.ptr.rhs.cast.i.i.i.i175
  store i64 %sub.ptr.sub.i.i.i.i176, ptr %__dnew.i.i165, align 8, !tbaa !11
  %cmp3.i.i177 = icmp ugt i64 %sub.ptr.sub.i.i.i.i176, 15
  br i1 %cmp3.i.i177, label %if.then4.i.i179, label %if.end6.i.i180

if.then4.i.i179:                                  ; preds = %if.end.i.i178
  %call5.i10.i187 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %ref.tmp30, ptr noundef nonnull align 8 dereferenceable(8) %__dnew.i.i165, i64 noundef 0)
          to label %call5.i10.i.noexc186 unwind label %lpad33

call5.i10.i.noexc186:                             ; preds = %if.then4.i.i179
  store ptr %call5.i10.i187, ptr %ref.tmp30, align 8, !tbaa !13
  %53 = load i64, ptr %__dnew.i.i165, align 8, !tbaa !11
  store i64 %53, ptr %52, align 8, !tbaa !15
  br label %if.end6.i.i180

if.end6.i.i180:                                   ; preds = %call5.i10.i.noexc186, %if.end.i.i178
  %54 = load ptr, ptr %ref.tmp30, align 8, !tbaa !13
  switch i64 %sub.ptr.sub.i.i.i.i176, label %if.end.i.i.i.i.i182 [
    i64 1, label %if.then.i.i.i.i181
    i64 0, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit188
  ]

if.then.i.i.i.i181:                               ; preds = %if.end6.i.i180
  %55 = load i8, ptr %51, align 1, !tbaa !15
  store i8 %55, ptr %54, align 1, !tbaa !15
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit188

if.end.i.i.i.i.i182:                              ; preds = %if.end6.i.i180
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %54, ptr nonnull align 1 %51, i64 %sub.ptr.sub.i.i.i.i176, i1 false) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit188

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit188: ; preds = %if.end6.i.i180, %if.then.i.i.i.i181, %if.end.i.i.i.i.i182
  %56 = load i64, ptr %__dnew.i.i165, align 8, !tbaa !11
  %_M_string_length.i.i.i.i183 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %ref.tmp30, i64 0, i32 1
  store i64 %56, ptr %_M_string_length.i.i.i.i183, align 8, !tbaa !16
  %57 = load ptr, ptr %ref.tmp30, align 8, !tbaa !13
  %arrayidx.i.i.i184 = getelementptr inbounds i8, ptr %57, i64 %56
  store i8 0, ptr %arrayidx.i.i.i184, align 1, !tbaa !15
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__dnew.i.i165) #10
  %58 = load ptr, ptr %ref.tmp30, align 8, !tbaa !13
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %__endptr.i.i189) #10
  %59 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  store i32 0, ptr %call.i.i.i, align 4, !tbaa !17
  %call.i.i191 = call noundef i64 @strtol(ptr noundef %58, ptr noundef nonnull %__endptr.i.i189, i32 noundef 10)
  %60 = load ptr, ptr %__endptr.i.i189, align 8, !tbaa !5
  %cmp.i.i192 = icmp eq ptr %60, %58
  br i1 %cmp.i.i192, label %if.then.i.i193, label %if.else.i.i201

if.then.i.i193:                                   ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit188
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont1.i.i194 unwind label %lpad.i.i196

invoke.cont1.i.i194:                              ; preds = %if.then.i.i193
  unreachable

lpad.i.i196:                                      ; preds = %if.then7.i.i202, %if.then.i.i193
  %61 = landingpad { ptr, i32 }
          cleanup
  %62 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp.i.i.i195 = icmp eq i32 %62, 0
  br i1 %cmp.i.i.i195, label %if.then.i.i.i197, label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i198

if.then.i.i.i197:                                 ; preds = %lpad.i.i196
  store i32 %59, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i198

_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i198: ; preds = %if.then.i.i.i197, %lpad.i.i196
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i189) #10
  %63 = load ptr, ptr %ref.tmp30, align 8, !tbaa !13
  %cmp.i.i.i222 = icmp eq ptr %63, %52
  br i1 %cmp.i.i.i222, label %ehcleanup39, label %if.then.i.i223

if.else.i.i201:                                   ; preds = %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEEC2EPKcRKS3_.exit188
  %64 = load i32, ptr %call.i.i.i, align 4, !tbaa !17
  %cmp3.i.i199 = icmp eq i32 %64, 34
  %65 = add i64 %call.i.i191, -2147483648
  %66 = icmp ult i64 %65, -4294967296
  %or.cond.i.i200 = or i1 %66, %cmp3.i.i199
  br i1 %or.cond.i.i200, label %if.then7.i.i202, label %if.else9.i.i204

if.then7.i.i202:                                  ; preds = %if.else.i.i201
  invoke void @_ZSt20__throw_out_of_rangePKc(ptr noundef nonnull @.str) #11
          to label %invoke.cont8.i.i203 unwind label %lpad.i.i196

invoke.cont8.i.i203:                              ; preds = %if.then7.i.i202
  unreachable

if.else9.i.i204:                                  ; preds = %if.else.i.i201
  %cmp.i25.i.i205 = icmp eq i32 %64, 0
  br i1 %cmp.i25.i.i205, label %if.then.i26.i.i206, label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit209

if.then.i26.i.i206:                               ; preds = %if.else9.i.i204
  store i32 %59, ptr %call.i.i.i, align 4, !tbaa !17
  br label %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit209

_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit209: ; preds = %if.else9.i.i204, %if.then.i26.i.i206
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %__endptr.i.i189) #10
  %67 = load ptr, ptr %ref.tmp30, align 8, !tbaa !13
  %cmp.i.i.i210 = icmp eq ptr %67, %52
  br i1 %cmp.i.i.i210, label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit212, label %if.then.i.i211

if.then.i.i211:                                   ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit209
  call void @_ZdlPv(ptr noundef %67) #10
  br label %_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit212

_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEED2Ev.exit212: ; preds = %_ZNSt7__cxx114stoiERKNS_12basic_stringIcSt11char_traitsIcESaIcEEEPmi.exit209, %if.then.i.i211
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp30) #10
  %conv = trunc i64 %call.i.i64 to i32
  %conv42 = trunc i64 %call.i.i95 to i32
  %add.i = add i32 %conv42, %conv
  %sext = shl i32 %add.i, 24
  %conv44 = ashr exact i32 %sext, 24
  ret i32 %conv44

lpad:                                             ; preds = %if.then4.i.i, %if.then.i.i
  %68 = landingpad { ptr, i32 }
          cleanup
  br label %ehcleanup

if.then.i.i214:                                   ; preds = %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i
  call void @_ZdlPv(ptr noundef %12) #10
  br label %ehcleanup

ehcleanup:                                        ; preds = %if.then.i.i214, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i, %lpad
  %.pn = phi { ptr, i32 } [ %68, %lpad ], [ %10, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i ], [ %10, %if.then.i.i214 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp) #10
  br label %ehcleanup48

lpad9:                                            ; preds = %if.then4.i.i83, %if.then.i.i77
  %69 = landingpad { ptr, i32 }
          cleanup
  br label %ehcleanup15

if.then.i.i217:                                   ; preds = %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i102
  call void @_ZdlPv(ptr noundef %29) #10
  br label %ehcleanup15

ehcleanup15:                                      ; preds = %if.then.i.i217, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i102, %lpad9
  %.pn54 = phi { ptr, i32 } [ %69, %lpad9 ], [ %27, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i102 ], [ %27, %if.then.i.i217 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp6) #10
  br label %ehcleanup48

lpad21:                                           ; preds = %if.then4.i.i131, %if.then.i.i125
  %70 = landingpad { ptr, i32 }
          cleanup
  br label %ehcleanup27

if.then.i.i220:                                   ; preds = %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i150
  call void @_ZdlPv(ptr noundef %46) #10
  br label %ehcleanup27

ehcleanup27:                                      ; preds = %if.then.i.i220, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i150, %lpad21
  %.pn56 = phi { ptr, i32 } [ %70, %lpad21 ], [ %44, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i150 ], [ %44, %if.then.i.i220 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp18) #10
  br label %ehcleanup48

lpad33:                                           ; preds = %if.then4.i.i179, %if.then.i.i173
  %71 = landingpad { ptr, i32 }
          cleanup
  br label %ehcleanup39

if.then.i.i223:                                   ; preds = %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i198
  call void @_ZdlPv(ptr noundef %63) #10
  br label %ehcleanup39

ehcleanup39:                                      ; preds = %if.then.i.i223, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i198, %lpad33
  %.pn58 = phi { ptr, i32 } [ %71, %lpad33 ], [ %61, %_ZZN9__gnu_cxx6__stoaIlicJiEEET0_PFT_PKT1_PPS3_DpT2_EPKcS5_PmS9_EN11_Save_errnoD2Ev.exit.i.i198 ], [ %61, %if.then.i.i223 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %ref.tmp30) #10
  br label %ehcleanup48

ehcleanup48:                                      ; preds = %ehcleanup15, %ehcleanup39, %ehcleanup27, %ehcleanup
  %.pn58.pn.pn.pn = phi { ptr, i32 } [ %.pn, %ehcleanup ], [ %.pn54, %ehcleanup15 ], [ %.pn58, %ehcleanup39 ], [ %.pn56, %ehcleanup27 ]
  resume { ptr, i32 } %.pn58.pn.pn.pn
}

; Function Attrs: argmemonly mustprogress nocallback nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0(i64 immarg, ptr nocapture) #2

declare i32 @__gxx_personality_v0(...)

; Function Attrs: argmemonly mustprogress nocallback nofree nosync nounwind willreturn
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

; Function Attrs: argmemonly mustprogress nofree nounwind willreturn
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #9

attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone willreturn uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { norecurse uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly mustprogress nocallback nofree nosync nounwind willreturn }
attributes #3 = { mustprogress nofree nounwind willreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { noreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { mustprogress nofree nosync nounwind readnone willreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #6 = { nobuiltin nounwind "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #7 = { argmemonly mustprogress nofree nounwind readonly willreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #8 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #9 = { argmemonly mustprogress nofree nounwind willreturn }
attributes #10 = { nounwind }
attributes #11 = { noreturn }
attributes #12 = { nounwind readnone willreturn }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"clang version 15.0.0 (https://github.com/llvm/llvm-project 216f546c846ca69005de193f4d1eea78e0efb2c2)"}
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
