#include "llvm/Transforms/PeepholeOptimizationCourse/AddInt8Func.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/IR/InstrTypes.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

namespace llvm {

Instruction* GetNewInstruction(BinaryOperator* bin_op) {

    IRBuilder<> B(bin_op);

    auto const& lhs = bin_op->getOperand(0);
    auto const& rhs = bin_op->getOperand(1);
    auto const& i8 = bin_op->getType();

    const auto And = B.CreateAnd(lhs, rhs);
    const auto Xor = B.CreateXor(lhs, rhs);
    const auto Mul1 = B.CreateMul(ConstantInt::get(i8, 2), Xor);
    const auto Add1 = B.CreateAdd(And, Mul1);
    const auto Mul2 = B.CreateMul(ConstantInt::get(i8, 39), Add1);
    const auto Add2 = B.CreateAdd(Mul2, ConstantInt::get(i8, 23));
    const auto Mul3 = B.CreateMul(Add2, ConstantInt::get(i8, 151));
    Instruction *new_inst = BinaryOperator::CreateAdd(Mul3, ConstantInt::get(i8, 111));
    
    return new_inst;
}

}