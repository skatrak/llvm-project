; NOTE: Assertions have been autogenerated by utils/update_test_checks.py
; RUN: opt -S -passes=instcombine -instcombine-infinite-loop-threshold=2 < %s | FileCheck %s

; This used to require 10 instcombine iterations to fully optimize.
; The number of iterations grew linearly with the number of DSEd stores,
; resulting in overall quadratic runtime.

%struct.S3 = type { i64 }

@csmith_sink_ = dso_local global i64 0, align 1
@g_302_7 = internal constant i32 0, align 1
@g_313_0 = internal global i16 0, align 1
@g_313_1 = internal global i32 0, align 1
@g_313_2 = internal global i32 0, align 1
@g_313_3 = internal global i32 0, align 1
@g_313_4 = internal global i16 0, align 1
@g_313_5 = internal global i16 0, align 1
@g_313_6 = internal global i16 0, align 1
@g_316 = internal global %struct.S3 zeroinitializer, align 1
@g_316_1_0 = internal global i16 0, align 1

define i16 @main() {
; CHECK-LABEL: @main(
; CHECK-NEXT:  entry:
; CHECK-NEXT:    store i64 0, ptr @csmith_sink_, align 1
; CHECK-NEXT:    ret i16 0
;
entry:
  store i64 0, ptr @csmith_sink_, align 1
  %0 = load i16, ptr @g_313_0, align 1
  %conv2 = sext i16 %0 to i64
  store i64 %conv2, ptr @csmith_sink_, align 1
  %1 = load i32, ptr @g_313_1, align 1
  %conv3 = zext i32 %1 to i64
  store i64 %conv3, ptr @csmith_sink_, align 1
  %2 = load i32, ptr @g_313_2, align 1
  %conv4 = sext i32 %2 to i64
  store i64 %conv4, ptr @csmith_sink_, align 1
  %3 = load i32, ptr @g_313_3, align 1
  %conv5 = zext i32 %3 to i64
  store i64 %conv5, ptr @csmith_sink_, align 1
  %4 = load i16, ptr @g_313_4, align 1
  %conv6 = sext i16 %4 to i64
  store i64 %conv6, ptr @csmith_sink_, align 1
  %5 = load i16, ptr @g_313_5, align 1
  %conv7 = sext i16 %5 to i64
  store i64 %conv7, ptr @csmith_sink_, align 1
  %6 = load i16, ptr @g_313_6, align 1
  %conv8 = sext i16 %6 to i64
  store i64 %conv8, ptr @csmith_sink_, align 1
  %7 = load i64, ptr @g_316, align 1
  store i64 %7, ptr @csmith_sink_, align 1
  %8 = load i16, ptr @g_316_1_0, align 1
  %conv9 = sext i16 %8 to i64
  store i64 %conv9, ptr @csmith_sink_, align 1
  store i64 0, ptr @csmith_sink_, align 1
  ret i16 0
}

