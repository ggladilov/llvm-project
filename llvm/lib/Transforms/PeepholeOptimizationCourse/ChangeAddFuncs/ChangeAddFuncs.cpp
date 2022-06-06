#include "llvm/Transforms/PeepholeOptimizationCourse/ChangeAddFuncs.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* GetNewInstruction(BinaryOperator* bin_op) {
                
		auto const& lhs = bin_op->getOperand(0);
		auto const& rhs = bin_op->getOperand(1);
		auto const& type = lhs->getType();

		IRBuilder<> builder(bin_op);

		auto logAnd = builder.CreateAnd(lhs, rhs);
		auto Xor =  builder.CreateXor(lhs, rhs);
		auto mul2 = builder.CreateMul(ConstantInt::get(type, 2), Xor);
		auto add = builder.CreateAdd(logAnd, mul2);
		auto mul39 = builder.CreateMul(ConstantInt::get(type, 39), add);
		auto add23 = builder.CreateAdd(mul39, ConstantInt::get(type, 23));
		auto mul151 = builder.CreateMul(add23, ConstantInt::get(type, 151));
		Instruction *new_instruction = BinaryOperator::CreateAdd(mul151, ConstantInt::get(type, 111));

    return new_instruction;
}

}