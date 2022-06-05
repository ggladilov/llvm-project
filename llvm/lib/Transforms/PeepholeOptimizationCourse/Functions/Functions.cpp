#include "llvm/Transforms/PeepholeOptimizationCourse/Functions.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"

namespace llvm {

void ReplaceInt8Instruction(Instruction* instruction) {		
		auto const& lhs = instruction->getOperand(0);
		auto const& rhs = instruction->getOperand(1);
		auto const& type = lhs->getType();
		
		IRBuilder<> builder(instruction);

		auto logAnd = builder.CreateAnd(lhs, rhs);
		auto Xor =  builder.CreateXor(lhs, rhs);
		auto mul2 = builder.CreateMul(ConstantInt::get(type, 2), Xor);
		auto add = builder.CreateAdd(logAnd, mul2);
		auto mul39 = builder.CreateMul(ConstantInt::get(type, 39), add);
		auto add23 = builder.CreateAdd(mul39, ConstantInt::get(type, 23));
		auto mul151 = builder.CreateMul(add23, ConstantInt::get(type, 151));
		Instruction *new_instruction = BinaryOperator::CreateAdd(mul151, ConstantInt::get(type, 111));
		
		ReplaceInstWithInst(instruction, new_instruction);
}

bool isBinaryAddInt8(Instruction const* instruction) {
	return instruction->getOpcode() == Instruction::Add &&
		   instruction->getNumOperands() == 2 && instruction->getType()->isIntegerTy() 
		   && instruction->getType()->getIntegerBitWidth() == 8;
}

}
