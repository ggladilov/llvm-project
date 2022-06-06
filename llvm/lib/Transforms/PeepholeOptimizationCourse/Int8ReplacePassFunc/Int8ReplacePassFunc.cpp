#include "llvm/Transforms/PeepholeOptimizationCourse/Int8ReplacePassFunc.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* ReplacePass(BinaryOperator* bin_op) {
    IRBuilder<> B(bin_op);
    auto const& lhs = bin_op->getOperand(0);
    auto const& rhs = bin_op->getOperand(1);
    auto const& i8 = bin_op->getType();

    const auto IntConst2 = ConstantInt::get(i8, 2);
    const auto IntConst23 = ConstantInt::get(i8, 23);
    const auto IntConst39 = ConstantInt::get(i8, 39);
    const auto IntConst151 = ConstantInt::get(i8, 151);
    const auto IntConst111 = ConstantInt::get(i8, 111);

    const auto And1 = B.CreateAnd(lhs, rhs);
    const auto Xor1 = B.CreateXor(lhs, rhs);
    const auto Mul1 = B.CreateMul(IntConst2, Xor1);
    const auto Add1 = B.CreateAdd(And1, Mul1);
    const auto Mul2 = B.CreateMul(IntConst39, Add1);
    const auto Add2 = B.CreateAdd(Mul2, IntConst23);
    const auto Mul3 = B.CreateMul(Add2, IntConst151);

    return BinaryOperator::CreateAdd(Mul3, IntConst111);
}

}
