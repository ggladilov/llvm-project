#include "llvm/Transforms/PeepholeOptimizationCourse/Obfuscate8BytesNewPassManager.h"

#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"


#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

bool isBinaryAdd(Instruction const* instruction) {
    return instruction->getOpcode() == Instruction::Add && instruction->getNumOperands() == 2;
}

bool isI8(Value const* operand) {
    return (operand->getType()->isIntegerTy()) && (operand->getType()->getIntegerBitWidth() == 8);
}

bool withI8(Instruction const* instruction) {
	auto const& operands = instruction->operands();
    return std::any_of(operands.begin(), operands.end(),
                       [](auto const& operand) { return isI8(operand); });
}

bool isAddWithI8(Instruction const* instruction) {
	return isBinaryAdd(instruction) && withI8(instruction);
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


PreservedAnalyses ObfuscateI8AddNewPassManager::run(Function& function, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** OBFUSCATE 8 BYTES ADD WITH NEW PASS MANAGER **********\n";
    errs() << "********** Function: " << function.getName() << '\n';

    auto changed = PreservedAnalyses::all();
	
    for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
        auto instruction = &*ii;
        ++ii;
        if (!isAddWithI8(instruction)) {
                continue;
        }
		doObfuscateI8Add(instruction);
        changed = PreservedAnalyses::none();
	}
	
    return changed;
}