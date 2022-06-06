#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateIntPassFunctions.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/IR/InstrTypes.h"

namespace llvm {

Instruction* PassInstruction(BinaryOperator* binary_operator) {
  
		auto const& lhs = binary_operator->getOperand(0);
		auto const& rhs = binary_operator->getOperand(1);
		auto const& type = lhs->getType();

		IRBuilder<> builder(binary_operator);

		auto logAnd = builder.CreateAnd(lhs, rhs);
		auto Xor =  builder.CreateXor(lhs, rhs);
		auto mul2 = builder.CreateMul(ConstantInt::get(type, 2), Xor);
		auto add = builder.CreateAdd(logAnd, mul2);
		auto mul39 = builder.CreateMul(ConstantInt::get(type, 39), add);
		auto add23 = builder.CreateAdd(mul39, ConstantInt::get(type, 23));
		auto mul151 = builder.CreateMul(add23, ConstantInt::get(type, 151));
		Instruction *replacement = BinaryOperator::CreateAdd(mul151, ConstantInt::get(type, 111));

    return replacement;
}

}
