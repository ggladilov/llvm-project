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
define dso_local noundef signext i8 @_Z16sum_to_obfuscateaaaa(i8 noundef signext %0, i8 noundef signext %1, i8 noundef signext %2, i8 noundef signext %3) local_unnamed_addr #0 {
  %5 = xor i8 %1, %0
  %6 = mul i8 2, %5
  %7 = and i8 %1, %0
  %8 = add i8 %7, %6
  %9 = mul i8 39, %8
  %10 = add i8 %9, 23
  %11 = mul i8 %10, -105
  %12 = add i8 %11, 111
  %13 = xor i8 %12, %2
  %14 = mul i8 2, %13
  %15 = and i8 %12, %2
  %16 = add i8 %15, %14
  %17 = mul i8 39, %16
  %18 = add i8 %17, 23
  %19 = mul i8 %18, -105
  %20 = add i8 %19, 111
  %21 = xor i8 %20, %3
  %22 = mul i8 2, %21
  %23 = and i8 %20, %3
  %24 = add i8 %23, %22
  %25 = mul i8 39, %24
  %26 = add i8 %25, 23
  %27 = mul i8 %26, -105
  %28 = add i8 %27, 111
  ret i8 %28
}

; Function Attrs: norecurse uwtable
define dso_local noundef i32 @main(i32 noundef %0, ptr nocapture noundef readonly %1) local_unnamed_addr #1 personality ptr @__gxx_personality_v0 {
  %3 = alloca ptr, align 8
  %4 = alloca i64, align 8
  %5 = alloca ptr, align 8
  %6 = alloca i64, align 8
  %7 = alloca ptr, align 8
  %8 = alloca i64, align 8
  %9 = alloca ptr, align 8
  %10 = alloca i64, align 8
  %11 = alloca %"class.std::__cxx11::basic_string", align 8
  %12 = alloca %"class.std::__cxx11::basic_string", align 8
  %13 = alloca %"class.std::__cxx11::basic_string", align 8
  %14 = alloca %"class.std::__cxx11::basic_string", align 8
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %11) #10
  %15 = getelementptr inbounds ptr, ptr %1, i64 1
  %16 = load ptr, ptr %15, align 8, !tbaa !5
  %17 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %11, i64 0, i32 2
  store ptr %17, ptr %11, align 8, !tbaa !9
  %18 = icmp eq ptr %16, null
  br i1 %18, label %22, label %19

19:                                               ; preds = %2
  %20 = call i64 @strlen(ptr noundef nonnull dereferenceable(1) %16) #10
  %21 = getelementptr inbounds i8, ptr %16, i64 %20
  br label %22

22:                                               ; preds = %19, %2
  %23 = phi ptr [ %21, %19 ], [ inttoptr (i64 -1 to ptr), %2 ]
  br i1 %18, label %24, label %26

24:                                               ; preds = %22
  invoke void @_ZSt19__throw_logic_errorPKc(ptr noundef nonnull @.str.1) #11
          to label %25 unwind label %269

25:                                               ; preds = %24
  unreachable

26:                                               ; preds = %22
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %10) #10
  %27 = ptrtoint ptr %23 to i64
  %28 = ptrtoint ptr %16 to i64
  %29 = sub i64 %27, %28
  store i64 %29, ptr %10, align 8, !tbaa !11
  %30 = icmp ugt i64 %29, 15
  br i1 %30, label %31, label %35

31:                                               ; preds = %26
  %32 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %11, ptr noundef nonnull align 8 dereferenceable(8) %10, i64 noundef 0)
          to label %33 unwind label %269

33:                                               ; preds = %31
  store ptr %32, ptr %11, align 8, !tbaa !13
  %34 = load i64, ptr %10, align 8, !tbaa !11
  store i64 %34, ptr %17, align 8, !tbaa !15
  br label %35

35:                                               ; preds = %33, %26
  %36 = load ptr, ptr %11, align 8, !tbaa !13
  switch i64 %29, label %39 [
    i64 1, label %37
    i64 0, label %40
  ]

37:                                               ; preds = %35
  %38 = load i8, ptr %16, align 1, !tbaa !15
  store i8 %38, ptr %36, align 1, !tbaa !15
  br label %40

39:                                               ; preds = %35
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %36, ptr nonnull align 1 %16, i64 %29, i1 false) #10
  br label %40

40:                                               ; preds = %39, %37, %35
  %41 = load i64, ptr %10, align 8, !tbaa !11
  %42 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %11, i64 0, i32 1
  store i64 %41, ptr %42, align 8, !tbaa !16
  %43 = load ptr, ptr %11, align 8, !tbaa !13
  %44 = getelementptr inbounds i8, ptr %43, i64 %41
  store i8 0, ptr %44, align 1, !tbaa !15
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %10) #10
  %45 = load ptr, ptr %11, align 8, !tbaa !13
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %9) #10
  %46 = call ptr @__errno_location() #12
  %47 = load i32, ptr %46, align 4, !tbaa !17
  store i32 0, ptr %46, align 4, !tbaa !17
  %48 = call noundef i64 @strtol(ptr noundef %45, ptr noundef nonnull %9, i32 noundef 10)
  %49 = load ptr, ptr %9, align 8, !tbaa !5
  %50 = icmp eq ptr %49, %45
  br i1 %50, label %51, label %61

51:                                               ; preds = %40
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %52 unwind label %53

52:                                               ; preds = %51
  unreachable

53:                                               ; preds = %67, %51
  %54 = landingpad { ptr, i32 }
          cleanup
  %55 = load i32, ptr %46, align 4, !tbaa !17
  %56 = icmp eq i32 %55, 0
  br i1 %56, label %57, label %58

57:                                               ; preds = %53
  store i32 %47, ptr %46, align 4, !tbaa !17
  br label %58

58:                                               ; preds = %57, %53
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %9) #10
  %59 = load ptr, ptr %11, align 8, !tbaa !13
  %60 = icmp eq ptr %59, %17
  br i1 %60, label %272, label %271

61:                                               ; preds = %40
  %62 = load i32, ptr %46, align 4, !tbaa !17
  %63 = icmp eq i32 %62, 34
  %64 = add i64 %48, -2147483648
  %65 = icmp ult i64 %64, -4294967296
  %66 = or i1 %65, %63
  br i1 %66, label %67, label %69

67:                                               ; preds = %61
  invoke void @_ZSt20__throw_out_of_rangePKc(ptr noundef nonnull @.str) #11
          to label %68 unwind label %53

68:                                               ; preds = %67
  unreachable

69:                                               ; preds = %61
  %70 = icmp eq i32 %62, 0
  br i1 %70, label %71, label %72

71:                                               ; preds = %69
  store i32 %47, ptr %46, align 4, !tbaa !17
  br label %72

72:                                               ; preds = %71, %69
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %9) #10
  %73 = load ptr, ptr %11, align 8, !tbaa !13
  %74 = icmp eq ptr %73, %17
  br i1 %74, label %76, label %75

75:                                               ; preds = %72
  call void @_ZdlPv(ptr noundef %73) #10
  br label %76

76:                                               ; preds = %75, %72
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %11) #10
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %12) #10
  %77 = getelementptr inbounds ptr, ptr %1, i64 2
  %78 = load ptr, ptr %77, align 8, !tbaa !5
  %79 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %12, i64 0, i32 2
  store ptr %79, ptr %12, align 8, !tbaa !9
  %80 = icmp eq ptr %78, null
  br i1 %80, label %84, label %81

81:                                               ; preds = %76
  %82 = call i64 @strlen(ptr noundef nonnull dereferenceable(1) %78) #10
  %83 = getelementptr inbounds i8, ptr %78, i64 %82
  br label %84

84:                                               ; preds = %81, %76
  %85 = phi ptr [ %83, %81 ], [ inttoptr (i64 -1 to ptr), %76 ]
  br i1 %80, label %86, label %88

86:                                               ; preds = %84
  invoke void @_ZSt19__throw_logic_errorPKc(ptr noundef nonnull @.str.1) #11
          to label %87 unwind label %274

87:                                               ; preds = %86
  unreachable

88:                                               ; preds = %84
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %8) #10
  %89 = ptrtoint ptr %85 to i64
  %90 = ptrtoint ptr %78 to i64
  %91 = sub i64 %89, %90
  store i64 %91, ptr %8, align 8, !tbaa !11
  %92 = icmp ugt i64 %91, 15
  br i1 %92, label %93, label %97

93:                                               ; preds = %88
  %94 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %12, ptr noundef nonnull align 8 dereferenceable(8) %8, i64 noundef 0)
          to label %95 unwind label %274

95:                                               ; preds = %93
  store ptr %94, ptr %12, align 8, !tbaa !13
  %96 = load i64, ptr %8, align 8, !tbaa !11
  store i64 %96, ptr %79, align 8, !tbaa !15
  br label %97

97:                                               ; preds = %95, %88
  %98 = load ptr, ptr %12, align 8, !tbaa !13
  switch i64 %91, label %101 [
    i64 1, label %99
    i64 0, label %102
  ]

99:                                               ; preds = %97
  %100 = load i8, ptr %78, align 1, !tbaa !15
  store i8 %100, ptr %98, align 1, !tbaa !15
  br label %102

101:                                              ; preds = %97
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %98, ptr nonnull align 1 %78, i64 %91, i1 false) #10
  br label %102

102:                                              ; preds = %101, %99, %97
  %103 = load i64, ptr %8, align 8, !tbaa !11
  %104 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %12, i64 0, i32 1
  store i64 %103, ptr %104, align 8, !tbaa !16
  %105 = load ptr, ptr %12, align 8, !tbaa !13
  %106 = getelementptr inbounds i8, ptr %105, i64 %103
  store i8 0, ptr %106, align 1, !tbaa !15
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %8) #10
  %107 = load ptr, ptr %12, align 8, !tbaa !13
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %7) #10
  %108 = load i32, ptr %46, align 4, !tbaa !17
  store i32 0, ptr %46, align 4, !tbaa !17
  %109 = call noundef i64 @strtol(ptr noundef %107, ptr noundef nonnull %7, i32 noundef 10)
  %110 = load ptr, ptr %7, align 8, !tbaa !5
  %111 = icmp eq ptr %110, %107
  br i1 %111, label %112, label %122

112:                                              ; preds = %102
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %113 unwind label %114

113:                                              ; preds = %112
  unreachable

114:                                              ; preds = %128, %112
  %115 = landingpad { ptr, i32 }
          cleanup
  %116 = load i32, ptr %46, align 4, !tbaa !17
  %117 = icmp eq i32 %116, 0
  br i1 %117, label %118, label %119

118:                                              ; preds = %114
  store i32 %108, ptr %46, align 4, !tbaa !17
  br label %119

119:                                              ; preds = %118, %114
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %7) #10
  %120 = load ptr, ptr %12, align 8, !tbaa !13
  %121 = icmp eq ptr %120, %79
  br i1 %121, label %277, label %276

122:                                              ; preds = %102
  %123 = load i32, ptr %46, align 4, !tbaa !17
  %124 = icmp eq i32 %123, 34
  %125 = add i64 %109, -2147483648
  %126 = icmp ult i64 %125, -4294967296
  %127 = or i1 %126, %124
  br i1 %127, label %128, label %130

128:                                              ; preds = %122
  invoke void @_ZSt20__throw_out_of_rangePKc(ptr noundef nonnull @.str) #11
          to label %129 unwind label %114

129:                                              ; preds = %128
  unreachable

130:                                              ; preds = %122
  %131 = icmp eq i32 %123, 0
  br i1 %131, label %132, label %133

132:                                              ; preds = %130
  store i32 %108, ptr %46, align 4, !tbaa !17
  br label %133

133:                                              ; preds = %132, %130
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %7) #10
  %134 = load ptr, ptr %12, align 8, !tbaa !13
  %135 = icmp eq ptr %134, %79
  br i1 %135, label %137, label %136

136:                                              ; preds = %133
  call void @_ZdlPv(ptr noundef %134) #10
  br label %137

137:                                              ; preds = %136, %133
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %12) #10
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %13) #10
  %138 = getelementptr inbounds ptr, ptr %1, i64 3
  %139 = load ptr, ptr %138, align 8, !tbaa !5
  %140 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %13, i64 0, i32 2
  store ptr %140, ptr %13, align 8, !tbaa !9
  %141 = icmp eq ptr %139, null
  br i1 %141, label %145, label %142

142:                                              ; preds = %137
  %143 = call i64 @strlen(ptr noundef nonnull dereferenceable(1) %139) #10
  %144 = getelementptr inbounds i8, ptr %139, i64 %143
  br label %145

145:                                              ; preds = %142, %137
  %146 = phi ptr [ %144, %142 ], [ inttoptr (i64 -1 to ptr), %137 ]
  br i1 %141, label %147, label %149

147:                                              ; preds = %145
  invoke void @_ZSt19__throw_logic_errorPKc(ptr noundef nonnull @.str.1) #11
          to label %148 unwind label %279

148:                                              ; preds = %147
  unreachable

149:                                              ; preds = %145
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %6) #10
  %150 = ptrtoint ptr %146 to i64
  %151 = ptrtoint ptr %139 to i64
  %152 = sub i64 %150, %151
  store i64 %152, ptr %6, align 8, !tbaa !11
  %153 = icmp ugt i64 %152, 15
  br i1 %153, label %154, label %158

154:                                              ; preds = %149
  %155 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %13, ptr noundef nonnull align 8 dereferenceable(8) %6, i64 noundef 0)
          to label %156 unwind label %279

156:                                              ; preds = %154
  store ptr %155, ptr %13, align 8, !tbaa !13
  %157 = load i64, ptr %6, align 8, !tbaa !11
  store i64 %157, ptr %140, align 8, !tbaa !15
  br label %158

158:                                              ; preds = %156, %149
  %159 = load ptr, ptr %13, align 8, !tbaa !13
  switch i64 %152, label %162 [
    i64 1, label %160
    i64 0, label %163
  ]

160:                                              ; preds = %158
  %161 = load i8, ptr %139, align 1, !tbaa !15
  store i8 %161, ptr %159, align 1, !tbaa !15
  br label %163

162:                                              ; preds = %158
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %159, ptr nonnull align 1 %139, i64 %152, i1 false) #10
  br label %163

163:                                              ; preds = %162, %160, %158
  %164 = load i64, ptr %6, align 8, !tbaa !11
  %165 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %13, i64 0, i32 1
  store i64 %164, ptr %165, align 8, !tbaa !16
  %166 = load ptr, ptr %13, align 8, !tbaa !13
  %167 = getelementptr inbounds i8, ptr %166, i64 %164
  store i8 0, ptr %167, align 1, !tbaa !15
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %6) #10
  %168 = load ptr, ptr %13, align 8, !tbaa !13
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %5) #10
  %169 = load i32, ptr %46, align 4, !tbaa !17
  store i32 0, ptr %46, align 4, !tbaa !17
  %170 = call noundef i64 @strtol(ptr noundef %168, ptr noundef nonnull %5, i32 noundef 10)
  %171 = load ptr, ptr %5, align 8, !tbaa !5
  %172 = icmp eq ptr %171, %168
  br i1 %172, label %173, label %183

173:                                              ; preds = %163
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %174 unwind label %175

174:                                              ; preds = %173
  unreachable

175:                                              ; preds = %189, %173
  %176 = landingpad { ptr, i32 }
          cleanup
  %177 = load i32, ptr %46, align 4, !tbaa !17
  %178 = icmp eq i32 %177, 0
  br i1 %178, label %179, label %180

179:                                              ; preds = %175
  store i32 %169, ptr %46, align 4, !tbaa !17
  br label %180

180:                                              ; preds = %179, %175
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %5) #10
  %181 = load ptr, ptr %13, align 8, !tbaa !13
  %182 = icmp eq ptr %181, %140
  br i1 %182, label %282, label %281

183:                                              ; preds = %163
  %184 = load i32, ptr %46, align 4, !tbaa !17
  %185 = icmp eq i32 %184, 34
  %186 = add i64 %170, -2147483648
  %187 = icmp ult i64 %186, -4294967296
  %188 = or i1 %187, %185
  br i1 %188, label %189, label %191

189:                                              ; preds = %183
  invoke void @_ZSt20__throw_out_of_rangePKc(ptr noundef nonnull @.str) #11
          to label %190 unwind label %175

190:                                              ; preds = %189
  unreachable

191:                                              ; preds = %183
  %192 = icmp eq i32 %184, 0
  br i1 %192, label %193, label %194

193:                                              ; preds = %191
  store i32 %169, ptr %46, align 4, !tbaa !17
  br label %194

194:                                              ; preds = %193, %191
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %5) #10
  %195 = load ptr, ptr %13, align 8, !tbaa !13
  %196 = icmp eq ptr %195, %140
  br i1 %196, label %198, label %197

197:                                              ; preds = %194
  call void @_ZdlPv(ptr noundef %195) #10
  br label %198

198:                                              ; preds = %197, %194
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %13) #10
  call void @llvm.lifetime.start.p0(i64 32, ptr nonnull %14) #10
  %199 = getelementptr inbounds ptr, ptr %1, i64 4
  %200 = load ptr, ptr %199, align 8, !tbaa !5
  %201 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %14, i64 0, i32 2
  store ptr %201, ptr %14, align 8, !tbaa !9
  %202 = icmp eq ptr %200, null
  br i1 %202, label %206, label %203

203:                                              ; preds = %198
  %204 = call i64 @strlen(ptr noundef nonnull dereferenceable(1) %200) #10
  %205 = getelementptr inbounds i8, ptr %200, i64 %204
  br label %206

206:                                              ; preds = %203, %198
  %207 = phi ptr [ %205, %203 ], [ inttoptr (i64 -1 to ptr), %198 ]
  br i1 %202, label %208, label %210

208:                                              ; preds = %206
  invoke void @_ZSt19__throw_logic_errorPKc(ptr noundef nonnull @.str.1) #11
          to label %209 unwind label %284

209:                                              ; preds = %208
  unreachable

210:                                              ; preds = %206
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %4) #10
  %211 = ptrtoint ptr %207 to i64
  %212 = ptrtoint ptr %200 to i64
  %213 = sub i64 %211, %212
  store i64 %213, ptr %4, align 8, !tbaa !11
  %214 = icmp ugt i64 %213, 15
  br i1 %214, label %215, label %219

215:                                              ; preds = %210
  %216 = invoke noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32) %14, ptr noundef nonnull align 8 dereferenceable(8) %4, i64 noundef 0)
          to label %217 unwind label %284

217:                                              ; preds = %215
  store ptr %216, ptr %14, align 8, !tbaa !13
  %218 = load i64, ptr %4, align 8, !tbaa !11
  store i64 %218, ptr %201, align 8, !tbaa !15
  br label %219

219:                                              ; preds = %217, %210
  %220 = load ptr, ptr %14, align 8, !tbaa !13
  switch i64 %213, label %223 [
    i64 1, label %221
    i64 0, label %224
  ]

221:                                              ; preds = %219
  %222 = load i8, ptr %200, align 1, !tbaa !15
  store i8 %222, ptr %220, align 1, !tbaa !15
  br label %224

223:                                              ; preds = %219
  call void @llvm.memcpy.p0.p0.i64(ptr align 1 %220, ptr nonnull align 1 %200, i64 %213, i1 false) #10
  br label %224

224:                                              ; preds = %223, %221, %219
  %225 = load i64, ptr %4, align 8, !tbaa !11
  %226 = getelementptr inbounds %"class.std::__cxx11::basic_string", ptr %14, i64 0, i32 1
  store i64 %225, ptr %226, align 8, !tbaa !16
  %227 = load ptr, ptr %14, align 8, !tbaa !13
  %228 = getelementptr inbounds i8, ptr %227, i64 %225
  store i8 0, ptr %228, align 1, !tbaa !15
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %4) #10
  %229 = load ptr, ptr %14, align 8, !tbaa !13
  call void @llvm.lifetime.start.p0(i64 8, ptr nonnull %3) #10
  %230 = load i32, ptr %46, align 4, !tbaa !17
  store i32 0, ptr %46, align 4, !tbaa !17
  %231 = call noundef i64 @strtol(ptr noundef %229, ptr noundef nonnull %3, i32 noundef 10)
  %232 = load ptr, ptr %3, align 8, !tbaa !5
  %233 = icmp eq ptr %232, %229
  br i1 %233, label %234, label %244

234:                                              ; preds = %224
  invoke void @_ZSt24__throw_invalid_argumentPKc(ptr noundef nonnull @.str) #11
          to label %235 unwind label %236

235:                                              ; preds = %234
  unreachable

236:                                              ; preds = %250, %234
  %237 = landingpad { ptr, i32 }
          cleanup
  %238 = load i32, ptr %46, align 4, !tbaa !17
  %239 = icmp eq i32 %238, 0
  br i1 %239, label %240, label %241

240:                                              ; preds = %236
  store i32 %230, ptr %46, align 4, !tbaa !17
  br label %241

241:                                              ; preds = %240, %236
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %3) #10
  %242 = load ptr, ptr %14, align 8, !tbaa !13
  %243 = icmp eq ptr %242, %201
  br i1 %243, label %287, label %286

244:                                              ; preds = %224
  %245 = load i32, ptr %46, align 4, !tbaa !17
  %246 = icmp eq i32 %245, 34
  %247 = add i64 %231, -2147483648
  %248 = icmp ult i64 %247, -4294967296
  %249 = or i1 %248, %246
  br i1 %249, label %250, label %252

250:                                              ; preds = %244
  invoke void @_ZSt20__throw_out_of_rangePKc(ptr noundef nonnull @.str) #11
          to label %251 unwind label %236

251:                                              ; preds = %250
  unreachable

252:                                              ; preds = %244
  %253 = icmp eq i32 %245, 0
  br i1 %253, label %254, label %255

254:                                              ; preds = %252
  store i32 %230, ptr %46, align 4, !tbaa !17
  br label %255

255:                                              ; preds = %254, %252
  call void @llvm.lifetime.end.p0(i64 8, ptr nonnull %3) #10
  %256 = load ptr, ptr %14, align 8, !tbaa !13
  %257 = icmp eq ptr %256, %201
  br i1 %257, label %259, label %258

258:                                              ; preds = %255
  call void @_ZdlPv(ptr noundef %256) #10
  br label %259

259:                                              ; preds = %258, %255
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %14) #10
  %260 = trunc i64 %48 to i32
  %261 = trunc i64 %109 to i32
  %262 = trunc i64 %170 to i32
  %263 = trunc i64 %231 to i32
  %264 = add i32 %261, %260
  %265 = add i32 %264, %262
  %266 = add i32 %265, %263
  %267 = shl i32 %266, 24
  %268 = ashr exact i32 %267, 24
  ret i32 %268

269:                                              ; preds = %31, %24
  %270 = landingpad { ptr, i32 }
          cleanup
  br label %272

271:                                              ; preds = %58
  call void @_ZdlPv(ptr noundef %59) #10
  br label %272

272:                                              ; preds = %271, %269, %58
  %273 = phi { ptr, i32 } [ %270, %269 ], [ %54, %58 ], [ %54, %271 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %11) #10
  br label %289

274:                                              ; preds = %93, %86
  %275 = landingpad { ptr, i32 }
          cleanup
  br label %277

276:                                              ; preds = %119
  call void @_ZdlPv(ptr noundef %120) #10
  br label %277

277:                                              ; preds = %276, %274, %119
  %278 = phi { ptr, i32 } [ %275, %274 ], [ %115, %119 ], [ %115, %276 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %12) #10
  br label %289

279:                                              ; preds = %154, %147
  %280 = landingpad { ptr, i32 }
          cleanup
  br label %282

281:                                              ; preds = %180
  call void @_ZdlPv(ptr noundef %181) #10
  br label %282

282:                                              ; preds = %281, %279, %180
  %283 = phi { ptr, i32 } [ %280, %279 ], [ %176, %180 ], [ %176, %281 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %13) #10
  br label %289

284:                                              ; preds = %215, %208
  %285 = landingpad { ptr, i32 }
          cleanup
  br label %287

286:                                              ; preds = %241
  call void @_ZdlPv(ptr noundef %242) #10
  br label %287

287:                                              ; preds = %286, %284, %241
  %288 = phi { ptr, i32 } [ %285, %284 ], [ %237, %241 ], [ %237, %286 ]
  call void @llvm.lifetime.end.p0(i64 32, ptr nonnull %14) #10
  br label %289

289:                                              ; preds = %287, %282, %277, %272
  %290 = phi { ptr, i32 } [ %273, %272 ], [ %278, %277 ], [ %288, %287 ], [ %283, %282 ]
  resume { ptr, i32 } %290
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

; Function Attrs: noreturn
declare void @_ZSt19__throw_logic_errorPKc(ptr noundef) local_unnamed_addr #4

declare noundef ptr @_ZNSt7__cxx1112basic_stringIcSt11char_traitsIcESaIcEE9_M_createERmm(ptr noundef nonnull align 8 dereferenceable(32), ptr noundef nonnull align 8 dereferenceable(8), i64 noundef) local_unnamed_addr #7

; Function Attrs: argmemonly nofree nounwind willreturn
declare void @llvm.memcpy.p0.p0.i64(ptr noalias nocapture writeonly, ptr noalias nocapture readonly, i64, i1 immarg) #8

; Function Attrs: argmemonly mustprogress nofree nounwind readonly willreturn
declare i64 @strlen(ptr nocapture noundef) local_unnamed_addr #9

attributes #0 = { mustprogress nofree norecurse nosync nounwind readnone willreturn uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #1 = { norecurse uwtable "frame-pointer"="none" "min-legal-vector-width"="0" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #2 = { argmemonly nocallback nofree nosync nounwind willreturn }
attributes #3 = { mustprogress nofree nounwind willreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #4 = { noreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #5 = { mustprogress nofree nosync nounwind readnone willreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #6 = { nobuiltin nounwind "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #7 = { "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #8 = { argmemonly nofree nounwind willreturn }
attributes #9 = { argmemonly mustprogress nofree nounwind readonly willreturn "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="x86-64" "target-features"="+cx8,+fxsr,+mmx,+sse,+sse2,+x87" "tune-cpu"="generic" }
attributes #10 = { nounwind }
attributes #11 = { noreturn }
attributes #12 = { nounwind readnone willreturn }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}

!0 = !{i32 1, !"wchar_size", i32 4}
!1 = !{i32 7, !"PIC Level", i32 2}
!2 = !{i32 7, !"PIE Level", i32 2}
!3 = !{i32 7, !"uwtable", i32 2}
!4 = !{!"clang version 15.0.0 (https://github.com/ggladilov/llvm-project.git ca3d962548b9699d69157d102e071607d27ba126)"}
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
