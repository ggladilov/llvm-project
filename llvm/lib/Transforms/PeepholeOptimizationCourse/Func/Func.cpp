#include "llvm/Transforms/PeepholeOptimizationCourse/Func.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* SwapInt8Instruction(BinaryOperator* binOp) {
    IRBuilder<> B(binOp);

    auto const& lhs = binOp->getOperand(0);
    auto const& rhs = binOp->getOperand(1);
    auto const& i8 = binOp->getType();

    const auto AndOp1 = B.CreateAnd(lhs, rhs);
    const auto XorOp1 = B.CreateXor(lhs, rhs);
    const auto MulOp1 = B.CreateMul(ConstantInt::get(i8, 2), XorOp1);
    const auto AddOp1 = B.CreateAdd(AndOp1, MulOp1);
    const auto MulOp2 = B.CreateMul(ConstantInt::get(i8, 39), AddOp1);
    const auto AddOp2 = B.CreateAdd(MulOp2, ConstantInt::get(i8, 23));
    const auto MulOp3 = B.CreateMul(AddOp2, ConstantInt::get(i8, 151));
    Instruction *replacement = BinaryOperator::CreateAdd(MulOp3, ConstantInt::get(i8, 111));
    
    return replacement;
}

}
