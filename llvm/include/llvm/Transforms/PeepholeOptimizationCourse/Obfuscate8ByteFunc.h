#ifndef LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_LIB_H
#define LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_LIB_H

#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/Instruction.h"

namespace llvm {

inline Instruction* OperFunc(BinaryOperator* binaryOperator) {
  IRBuilder<> builder(binaryOperator);
  auto const& first = binaryOperator->getOperand(0);
  auto const& second = binaryOperator->getOperand(1);
  auto const& i8Type = binaryOperator->getType();

  const auto IntConst2 = ConstantInt::get(i8Type, 2);
  const auto IntConst23 = ConstantInt::get(i8Type, 23);
  const auto IntConst39 = ConstantInt::get(i8Type, 39);
  const auto IntConst151 = ConstantInt::get(i8Type, 151);
  const auto IntConst111 = ConstantInt::get(i8Type, 111);

  const auto XorOperator = builder.CreateXor(first, second);
  const auto MulOperator1 = builder.CreateMul(IntConst2, XorOperator);
  const auto AddOperator1 = builder.CreateAdd(MulOperator1, IntConst23);
  const auto AndOperator = builder.CreateAnd(first, second);
  const auto AddOperator2 = builder.CreateAdd(AndOperator, AddOperator1);
  const auto MulOperator2 = builder.CreateMul(IntConst39, AddOperator2);
  const auto MulOperator3 = builder.CreateMul(MulOperator2, IntConst151);

  return BinaryOperator::CreateAdd(MulOperator3, IntConst111);
}

}  // namespace llvm

#endif  // LLVM_TRANSFORMS_PEEPHOLE_OBFUSCATE_LIB_H
