#include "llvm/Transforms/PeepholeOptimizationCourse/Functions.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* ReplaceInstruction(BinaryOperator* binOp) {
    IRBuilder<> B(binOp);

    auto const& lhs = binOp->getOperand(0);
    auto const& rhs = binOp->getOperand(1);
    auto const& i8 = binOp->getType();

    const auto And = B.CreateAnd(lhs, rhs);
    const auto Xor = B.CreateXor(lhs, rhs);
    const auto Mul1 = B.CreateMul(ConstantInt::get(i8, 2), Xor);
    const auto Add1 = B.CreateAdd(And, Mul1);
    const auto Mul2 = B.CreateMul(ConstantInt::get(i8, 39), Add1);
    const auto Add2 = B.CreateAdd(Mul2, ConstantInt::get(i8, 23));
    const auto Mul3 = B.CreateMul(Add2, ConstantInt::get(i8, 151));
    Instruction *replacement = BinaryOperator::CreateAdd(Mul3, ConstantInt::get(i8, 111));
    
    return replacement;
}

}
