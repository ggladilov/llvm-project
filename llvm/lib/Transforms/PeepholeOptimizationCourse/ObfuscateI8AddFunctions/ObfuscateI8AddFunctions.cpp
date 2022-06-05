#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateI8AddFunctions.h"

namespace llvm {
	
bool isAddI8(Instruction const* instruction) {
    return isBinaryAdd(instruction) && isI8Instruction(instruction);
}

void doObfuscateI8Add(Instruction* instruction) {
	auto const& a = instruction->getOperand(0);
    auto const& b = instruction->getOperand(1);
	auto const& I8Type = a->getType();
	
	IRBuilder<> Builder(instruction);
	auto mul4 =  Builder.CreateXor(a,b);
	auto inc2 = Builder.CreateAnd(a, b);
	auto inc3 = Builder.CreateMul(ConstantInt::get(I8Type, 2), mul4);
	auto mul3 = Builder.CreateAdd(inc2, inc3);
	auto mul2 = Builder.CreateMul(ConstantInt::get(I8Type, 39), mul3);
	auto mul1 = Builder.CreateAdd(mul2, ConstantInt::get(I8Type, 23));
	auto inc1 = Builder.CreateMul(mul1, ConstantInt::get(I8Type, 151));
	Instruction *newInst = BinaryOperator::CreateAdd(inc1, ConstantInt::get(I8Type, 111));
	ReplaceInstWithInst(instruction, newInst);
}

}