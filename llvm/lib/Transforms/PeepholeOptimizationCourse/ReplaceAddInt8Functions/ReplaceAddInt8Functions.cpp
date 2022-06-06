
#include "llvm/Transforms/PeepholeOptimizationCourse/ReplaceAddInt8Functions.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"

namespace llvm {

void ReplaceAddInt8Instruction(Instruction* instruction) {		
		auto const& leftarg = instruction->getOperand(0);
		auto const& rightarg = instruction->getOperand(1);
		auto const& type = leftarg->getType();

		IRBuilder<> builder(instruction);
		
		//a + b -> (39 * ((a $\bigoplus$ b) + 2 * (a $\bigwedge$ b)) + 23) * 151 + 111, where
               //$\bigoplus$ is logical AND
               //$\bigwedge$ is XOR
               
		auto logAnd = builder.CreateAnd(leftarg, rightarg);
		auto Xor =  builder.CreateXor(leftarg, rightarg);
		
		auto innerbrackets = builder.CreateAdd(logAnd, builder.CreateMul(ConstantInt::get(type, 2), Xor));
		auto externbrackets = builder.CreateAdd(builder.CreateMul(ConstantInt::get(type, 39), innerbrackets), ConstantInt::get(type, 23));
		auto mul151 = builder.CreateMul(ConstantInt::get(type, 151), externbrackets);
		Instruction *new_instruction = BinaryOperator::CreateAdd(mul151, ConstantInt::get(type, 111));

		ReplaceInstWithInst(instruction, new_instruction);
}

bool isAddInt8(Instruction const* instruction) {
 if(instruction->getOpcode() == Instruction::Add && instruction->getType()->getIntegerBitWidth() == 8 &&
		   instruction->getNumOperands() == 2 && instruction->getType()->isIntegerTy() ) return true ;
		   return false;
}

}
