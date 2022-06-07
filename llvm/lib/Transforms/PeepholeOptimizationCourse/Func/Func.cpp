#include "llvm/Transforms/PeepholeOptimizationCourse/Func.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* ReplaceInt8Instruction(BinaryOperator* binOp) {
                IRBuilder<> B(binOp);
                auto const& lhs = binOp->getOperand(0);
                auto const& rhs = binOp->getOperand(1);
                auto const& i8 = binOp->getType();

                auto mul4 = Builder.CreateXor(lhs, rhs);
                auto inc2 = Builder.CreateAnd(lhs, rhs);
	            auto inc3 = Builder.CreateMul(ConstantInt::get(i8, 2), mul4);
	            auto mul3 = Builder.CreateAdd(inc2, inc3);
	            auto mul2 = Builder.CreateMul(ConstantInt::get(i8, 39), mul3);
	            auto mul1 = Builder.CreateAdd(mul2, ConstantInt::get(i8, 23));
	            auto inc1 = Builder.CreateMul(mul1, ConstantInt::get(i8, 151));

                Instruction *replacement = BinaryOperator::CreateAdd(inc1, ConstantInt::get(i8, 111));

                return replacement;
}

}