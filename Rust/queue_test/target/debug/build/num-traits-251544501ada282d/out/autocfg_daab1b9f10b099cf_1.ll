; ModuleID = 'autocfg_daab1b9f10b099cf_1.6b376e584f1fa6ff-cgu.0'
source_filename = "autocfg_daab1b9f10b099cf_1.6b376e584f1fa6ff-cgu.0"
target datalayout = "e-m:e-p270:32:32-p271:32:32-p272:64:64-i64:64-i128:128-f80:128-n8:16:32:64-S128"
target triple = "x86_64-unknown-linux-gnu"

@alloc_f93507f8ba4b5780b14b2c2584609be0 = private unnamed_addr constant <{ [8 x i8] }> <{ [8 x i8] c"\00\00\00\00\00\00\F0?" }>, align 8
@alloc_ef0a1f828f3393ef691f2705e817091c = private unnamed_addr constant <{ [8 x i8] }> <{ [8 x i8] c"\00\00\00\00\00\00\00@" }>, align 8

; core::f64::<impl f64>::total_cmp
; Function Attrs: inlinehint nonlazybind uwtable
define hidden i8 @"_ZN4core3f6421_$LT$impl$u20$f64$GT$9total_cmp17h28d564b232a3e79bE"(ptr align 8 %self, ptr align 8 %other) unnamed_addr #0 !dbg !17 {
start:
  %other.dbg.spill6 = alloca [8 x i8], align 8
  %self.dbg.spill5 = alloca [8 x i8], align 8
  %self.dbg.spill4 = alloca [8 x i8], align 8
  %self.dbg.spill2 = alloca [8 x i8], align 8
  %other.dbg.spill = alloca [8 x i8], align 8
  %self.dbg.spill = alloca [8 x i8], align 8
  %right = alloca [8 x i8], align 8
  %left = alloca [8 x i8], align 8
  store ptr %self, ptr %self.dbg.spill, align 8
    #dbg_declare(ptr %self.dbg.spill, !26, !DIExpression(), !34)
  store ptr %other, ptr %other.dbg.spill, align 8
    #dbg_declare(ptr %other.dbg.spill, !27, !DIExpression(), !35)
    #dbg_declare(ptr %left, !28, !DIExpression(), !36)
    #dbg_declare(ptr %right, !31, !DIExpression(), !37)
  %self1 = load double, ptr %self, align 8, !dbg !38
  store double %self1, ptr %self.dbg.spill2, align 8, !dbg !38
    #dbg_declare(ptr %self.dbg.spill2, !39, !DIExpression(), !45)
  %_4 = bitcast double %self1 to i64, !dbg !47
  store i64 %_4, ptr %left, align 8, !dbg !38
  %self3 = load double, ptr %other, align 8, !dbg !48
  store double %self3, ptr %self.dbg.spill4, align 8, !dbg !48
    #dbg_declare(ptr %self.dbg.spill4, !39, !DIExpression(), !49)
  %_7 = bitcast double %self3 to i64, !dbg !51
  store i64 %_7, ptr %right, align 8, !dbg !48
  %_13 = load i64, ptr %left, align 8, !dbg !52
  %_12 = ashr i64 %_13, 63, !dbg !53
  %_10 = lshr i64 %_12, 1, !dbg !54
  %0 = load i64, ptr %left, align 8, !dbg !55
  %1 = xor i64 %0, %_10, !dbg !55
  store i64 %1, ptr %left, align 8, !dbg !55
  %_18 = load i64, ptr %right, align 8, !dbg !56
  %_17 = ashr i64 %_18, 63, !dbg !57
  %_15 = lshr i64 %_17, 1, !dbg !58
  %2 = load i64, ptr %right, align 8, !dbg !59
  %3 = xor i64 %2, %_15, !dbg !59
  store i64 %3, ptr %right, align 8, !dbg !59
  store ptr %left, ptr %self.dbg.spill5, align 8, !dbg !60
    #dbg_declare(ptr %self.dbg.spill5, !61, !DIExpression(), !71)
  store ptr %right, ptr %other.dbg.spill6, align 8, !dbg !73
    #dbg_declare(ptr %other.dbg.spill6, !70, !DIExpression(), !74)
  %_21 = load i64, ptr %left, align 8, !dbg !75
  %_22 = load i64, ptr %right, align 8, !dbg !76
  %4 = icmp sgt i64 %_21, %_22, !dbg !77
  %5 = zext i1 %4 to i8, !dbg !77
  %6 = icmp slt i64 %_21, %_22, !dbg !77
  %7 = zext i1 %6 to i8, !dbg !77
  %_0 = sub nsw i8 %5, %7, !dbg !77
  ret i8 %_0, !dbg !78
}

; autocfg_daab1b9f10b099cf_1::probe
; Function Attrs: nonlazybind uwtable
define void @_ZN26autocfg_daab1b9f10b099cf_15probe17h4700febbae0870f2E() unnamed_addr #1 !dbg !79 {
start:
; call core::f64::<impl f64>::total_cmp
  %_1 = call i8 @"_ZN4core3f6421_$LT$impl$u20$f64$GT$9total_cmp17h28d564b232a3e79bE"(ptr align 8 @alloc_f93507f8ba4b5780b14b2c2584609be0, ptr align 8 @alloc_ef0a1f828f3393ef691f2705e817091c), !dbg !84
  ret void, !dbg !85
}

attributes #0 = { inlinehint nonlazybind uwtable "probe-stack"="inline-asm" "target-cpu"="x86-64" }
attributes #1 = { nonlazybind uwtable "probe-stack"="inline-asm" "target-cpu"="x86-64" }

!llvm.module.flags = !{!0, !1, !2, !3}
!llvm.ident = !{!4}
!llvm.dbg.cu = !{!5}

!0 = !{i32 8, !"PIC Level", i32 2}
!1 = !{i32 2, !"RtLibUseGOT", i32 1}
!2 = !{i32 2, !"Dwarf Version", i32 4}
!3 = !{i32 2, !"Debug Info Version", i32 3}
!4 = !{!"rustc version 1.83.0 (90b35a623 2024-11-26)"}
!5 = distinct !DICompileUnit(language: DW_LANG_Rust, file: !6, producer: "clang LLVM (rustc version 1.83.0 (90b35a623 2024-11-26))", isOptimized: false, runtimeVersion: 0, emissionKind: FullDebug, enums: !7, splitDebugInlining: false, nameTableKind: None)
!6 = !DIFile(filename: "autocfg_daab1b9f10b099cf_1/@/autocfg_daab1b9f10b099cf_1.6b376e584f1fa6ff-cgu.0", directory: "/home/lendell/.cargo/registry/src/index.crates.io-6f17d22bba15001f/num-traits-0.2.19")
!7 = !{!8}
!8 = !DICompositeType(tag: DW_TAG_enumeration_type, name: "Ordering", scope: !10, file: !9, baseType: !12, size: 8, align: 8, flags: DIFlagEnumClass, elements: !13)
!9 = !DIFile(filename: "<unknown>", directory: "")
!10 = !DINamespace(name: "cmp", scope: !11)
!11 = !DINamespace(name: "core", scope: null)
!12 = !DIBasicType(name: "i8", size: 8, encoding: DW_ATE_signed)
!13 = !{!14, !15, !16}
!14 = !DIEnumerator(name: "Less", value: -1)
!15 = !DIEnumerator(name: "Equal", value: 0)
!16 = !DIEnumerator(name: "Greater", value: 1)
!17 = distinct !DISubprogram(name: "total_cmp", linkageName: "_ZN4core3f6421_$LT$impl$u20$f64$GT$9total_cmp17h28d564b232a3e79bE", scope: !19, file: !18, line: 1350, type: !21, scopeLine: 1350, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !5, templateParams: !33, retainedNodes: !25)
!18 = !DIFile(filename: "/home/lendell/.rustup/toolchains/stable-x86_64-unknown-linux-gnu/lib/rustlib/src/rust/library/core/src/num/f64.rs", directory: "", checksumkind: CSK_MD5, checksum: "30540f064ec89394f47e43c129237c59")
!19 = !DINamespace(name: "{impl#0}", scope: !20)
!20 = !DINamespace(name: "f64", scope: !11)
!21 = !DISubroutineType(types: !22)
!22 = !{!8, !23, !23}
!23 = !DIDerivedType(tag: DW_TAG_pointer_type, name: "&f64", baseType: !24, size: 64, align: 64, dwarfAddressSpace: 0)
!24 = !DIBasicType(name: "f64", size: 64, encoding: DW_ATE_float)
!25 = !{!26, !27, !28, !31}
!26 = !DILocalVariable(name: "self", arg: 1, scope: !17, file: !18, line: 1350, type: !23)
!27 = !DILocalVariable(name: "other", arg: 2, scope: !17, file: !18, line: 1350, type: !23)
!28 = !DILocalVariable(name: "left", scope: !29, file: !18, line: 1351, type: !30, align: 8)
!29 = distinct !DILexicalBlock(scope: !17, file: !18, line: 1351, column: 9)
!30 = !DIBasicType(name: "i64", size: 64, encoding: DW_ATE_signed)
!31 = !DILocalVariable(name: "right", scope: !32, file: !18, line: 1352, type: !30, align: 8)
!32 = distinct !DILexicalBlock(scope: !29, file: !18, line: 1352, column: 9)
!33 = !{}
!34 = !DILocation(line: 1350, column: 22, scope: !17)
!35 = !DILocation(line: 1350, column: 29, scope: !17)
!36 = !DILocation(line: 1351, column: 13, scope: !29)
!37 = !DILocation(line: 1352, column: 13, scope: !32)
!38 = !DILocation(line: 1351, column: 24, scope: !17)
!39 = !DILocalVariable(name: "self", arg: 1, scope: !40, file: !18, line: 1093, type: !24)
!40 = distinct !DISubprogram(name: "to_bits", linkageName: "_ZN4core3f6421_$LT$impl$u20$f64$GT$7to_bits17h5f754e455bc1cc7cE", scope: !19, file: !18, line: 1093, type: !41, scopeLine: 1093, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !5, templateParams: !33, retainedNodes: !44)
!41 = !DISubroutineType(types: !42)
!42 = !{!43, !24}
!43 = !DIBasicType(name: "u64", size: 64, encoding: DW_ATE_unsigned)
!44 = !{!39}
!45 = !DILocation(line: 1093, column: 26, scope: !40, inlinedAt: !46)
!46 = !DILocation(line: 1351, column: 29, scope: !17)
!47 = !DILocation(line: 1095, column: 18, scope: !40, inlinedAt: !46)
!48 = !DILocation(line: 1352, column: 25, scope: !29)
!49 = !DILocation(line: 1093, column: 26, scope: !40, inlinedAt: !50)
!50 = !DILocation(line: 1352, column: 31, scope: !29)
!51 = !DILocation(line: 1095, column: 18, scope: !40, inlinedAt: !50)
!52 = !DILocation(line: 1376, column: 20, scope: !32)
!53 = !DILocation(line: 1376, column: 19, scope: !32)
!54 = !DILocation(line: 1376, column: 17, scope: !32)
!55 = !DILocation(line: 1376, column: 9, scope: !32)
!56 = !DILocation(line: 1377, column: 21, scope: !32)
!57 = !DILocation(line: 1377, column: 20, scope: !32)
!58 = !DILocation(line: 1377, column: 18, scope: !32)
!59 = !DILocation(line: 1377, column: 9, scope: !32)
!60 = !DILocation(line: 1379, column: 9, scope: !32)
!61 = !DILocalVariable(name: "self", arg: 1, scope: !62, file: !63, line: 1732, type: !68)
!62 = distinct !DISubprogram(name: "cmp", linkageName: "_ZN4core3cmp5impls48_$LT$impl$u20$core..cmp..Ord$u20$for$u20$i64$GT$3cmp17hf2f734e18ee81392E", scope: !64, file: !63, line: 1732, type: !66, scopeLine: 1732, flags: DIFlagPrototyped, spFlags: DISPFlagLocalToUnit | DISPFlagDefinition, unit: !5, templateParams: !33, retainedNodes: !69)
!63 = !DIFile(filename: "/home/lendell/.rustup/toolchains/stable-x86_64-unknown-linux-gnu/lib/rustlib/src/rust/library/core/src/cmp.rs", directory: "", checksumkind: CSK_MD5, checksum: "6501442f117b91b93b0d294fef0784c8")
!64 = !DINamespace(name: "{impl#79}", scope: !65)
!65 = !DINamespace(name: "impls", scope: !10)
!66 = !DISubroutineType(types: !67)
!67 = !{!8, !68, !68}
!68 = !DIDerivedType(tag: DW_TAG_pointer_type, name: "&i64", baseType: !30, size: 64, align: 64, dwarfAddressSpace: 0)
!69 = !{!61, !70}
!70 = !DILocalVariable(name: "other", arg: 2, scope: !62, file: !63, line: 1732, type: !68)
!71 = !DILocation(line: 1732, column: 24, scope: !62, inlinedAt: !72)
!72 = !DILocation(line: 1379, column: 14, scope: !32)
!73 = !DILocation(line: 1379, column: 18, scope: !32)
!74 = !DILocation(line: 1732, column: 31, scope: !62, inlinedAt: !72)
!75 = !DILocation(line: 1733, column: 58, scope: !62, inlinedAt: !72)
!76 = !DILocation(line: 1733, column: 65, scope: !62, inlinedAt: !72)
!77 = !DILocation(line: 1733, column: 21, scope: !62, inlinedAt: !72)
!78 = !DILocation(line: 1380, column: 6, scope: !17)
!79 = distinct !DISubprogram(name: "probe", linkageName: "_ZN26autocfg_daab1b9f10b099cf_15probe17h4700febbae0870f2E", scope: !81, file: !80, line: 1, type: !82, scopeLine: 1, flags: DIFlagPrototyped, spFlags: DISPFlagDefinition, unit: !5, templateParams: !33)
!80 = !DIFile(filename: "<anon>", directory: "", checksumkind: CSK_MD5, checksum: "ca821b87a81998bc0a84ab6029e9650c")
!81 = !DINamespace(name: "autocfg_daab1b9f10b099cf_1", scope: null)
!82 = !DISubroutineType(types: !83)
!83 = !{null}
!84 = !DILocation(line: 1, column: 26, scope: !79)
!85 = !DILocation(line: 1, column: 50, scope: !86)
!86 = !DILexicalBlockFile(scope: !79, file: !80, discriminator: 0)
