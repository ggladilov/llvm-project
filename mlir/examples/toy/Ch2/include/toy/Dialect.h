//===- Dialect.h - Dialect definition for the Toy IR ----------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//
//
// This file implements the IR Dialect for the Toy language.
// See docs/Tutorials/Toy/Ch-2.md for more information.
//
//===----------------------------------------------------------------------===//

#ifndef MLIR_TUTORIAL_TOY_DIALECT_H_
#define MLIR_TUTORIAL_TOY_DIALECT_H_

#include "mlir/IR/Dialect.h"
#include "mlir/IR/FunctionInterfaces.h"
#include "mlir/IR/Location.h"
#include "mlir/IR/OpImplementation.h"
#include "mlir/IR/OperationSupport.h"
#include "mlir/IR/SymbolTable.h"
#include "mlir/Interfaces/CallInterfaces.h"
#include "mlir/Interfaces/SideEffectInterfaces.h"

/// Include the auto-generated header file containing the declaration of the toy
/// dialect.
#include "toy/Dialect.h.inc"
#include "llvm/Support/Compiler.h"

/// Include the auto-generated header file containing the declarations of the
/// toy operations.
#define GET_OP_CLASSES
#include "toy/Ops.h.inc"

template <uint64_t bits>
class TestOpBuilderHelper;

template <>
class TestOpBuilderHelper<0> {
public:
  ::mlir::toy::TestOp build(::mlir::OpBuilder &odsBuilder);

  // only required arguments / results need to be tracked
  static constexpr auto RESULT_TYPE_BIT = size_t{1 << 0};
  static constexpr auto REQUIRED_OPERAND_1_BIT = size_t{1 << 1};
  static constexpr auto REQUIRED_OPERAND_3_BIT = size_t{1 << 2};
  static constexpr auto REQUIRED_ATTRIBUTE_5_BIT = size_t{1 << 3};
  static constexpr auto ALL_BITS = RESULT_TYPE_BIT | REQUIRED_OPERAND_1_BIT |
                                   REQUIRED_OPERAND_3_BIT |
                                   REQUIRED_ATTRIBUTE_5_BIT;

protected:
  TestOpBuilderHelper(::mlir::Location location)
      : state(location, ::mlir::toy::TestOp::getOperationName()) {
    auto opName = mlir::RegisteredOperationName::lookup(
        ::mlir::toy::TestOp::getOperationName(), location.getContext());
    if (LLVM_UNLIKELY(!opName)) {
      llvm::report_fatal_error(
          "Building op `" + ::mlir::toy::TestOp::getOperationName() +
          "` but it isn't registered in this MLIRContext: the dialect may not "
          "be loaded or this operation isn't registered by the dialect. See "
          "also https://mlir.llvm.org/getting_started/Faq/"
          "#registered-loaded-dependent-whats-up-with-dialects-management");
    }
  }

  //   ::mlir::Type resultType;
  //   ::mlir::Value optionalOperand0;
  //   ::mlir::Value requiredOperand1;
  //   ::mlir::Value optionalOperand2;
  //   ::mlir::Value requiredOperand3;
  //   ::mlir::IntegerAttr optionalAttribute4;
  //   ::mlir::IntegerAttr requiredAttribute5;
  ::mlir::OperationState state;
};

using TestOpBuilder = TestOpBuilderHelper<TestOpBuilderHelper<0>::ALL_BITS>;

template <uint64_t N>
class TestOpBuilderHelper : public TestOpBuilderHelper<N - 1> {
  using Base = TestOpBuilderHelper<0>;

public:
  TestOpBuilderHelper(::mlir::Location location)
      : TestOpBuilderHelper<N - 1>(location) {}

  // required arguments clear corresponding bit

  TestOpBuilderHelper<N & ~Base::RESULT_TYPE_BIT> &
  setResultType(::mlir::Type resultType) {
    this->state.addTypes(resultType);
    return *this;
  }

  // optional arguments return itself as-is

  auto &setOptionalOperand0(::mlir::Value value) {
    this->state.addOperands(value);
    return *this;
  }

  TestOpBuilderHelper<N & ~Base::REQUIRED_OPERAND_1_BIT> &
  setRequiredOperand1(::mlir::Value value) {
    this->state.addOperands(value);
    return *this;
  }

  auto &setOptionalOperand2(::mlir::Value value) {
    this->state.addOperands(value);
    return *this;
  }

  TestOpBuilderHelper<N & ~Base::REQUIRED_OPERAND_3_BIT> &
  setRequiredOperand3(::mlir::Value value) {
    this->state.addOperands(value);
    return *this;
  }

  auto &setOptionalAttribute4(::mlir::IntegerAttr value) {
    this->state.addOperands(value);
    return *this;
  }

  TestOpBuilderHelper<N & ~Base::REQUIRED_ATTRIBUTE_5_BIT> &
  setRequiredAttribute5(::mlir::IntegerAttr value) {
    this->state.addAttribute(
        ::mlir::toy::TestOp::getRequiredAttribute5AttrName(
            ::mlir::OperationName(::mlir::toy::TestOp::getOperationName(),
                                  this->state.getContext())),
        value);
    return *this;
  }

  ::mlir::toy::TestOp build(::mlir::OpBuilder &) {
    if constexpr (N & Base::REQUIRED_OPERAND_1_BIT) {
      static_assert(false,
                    "an attempt to build TestOp with no requiredOperand1 set");
    } else if constexpr (N & Base::REQUIRED_OPERAND_3_BIT) {
      static_assert(false,
                    "an attempt to build TestOp with no requiredOperand3 set");
    } else if constexpr (N & Base::REQUIRED_ATTRIBUTE_5_BIT) {
      static_assert(
          false, "an attempt to build TestOp with no requiredAttribute5 set");
    } else {
      static_assert(false, "unexpected error");
    }
  }
};

#endif // MLIR_TUTORIAL_TOY_DIALECT_H_
