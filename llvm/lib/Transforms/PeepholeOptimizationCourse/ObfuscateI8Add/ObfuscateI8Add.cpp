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

namespace {

struct ObfuscateI8Add : public FunctionPass {
    static char ID;
    ObfuscateI8Add() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** OBFUSCATE INT8 ADD **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool changed = false;
        for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
            auto instruction = &*ii;
            ++ii;

            if (!isAddWithI8(instruction)) {
                continue;
            }
				
			//errs() << "I8 check complite\n";
			doObfuscateI8Add(instruction);

            changed = true;
		}
        return changed;
    }

private:
    bool isAddWithI8(Instruction const* instruction) const {
        return isBinaryAdd(instruction) && withI8(instruction);
    }

    bool isBinaryAdd(Instruction const* instruction) const {
        return instruction->getOpcode() == Instruction::Add &&
               instruction->getNumOperands() == 2;
    }

    bool withI8(Instruction const* instruction) const {
		auto const& operands = instruction->operands();
        return std::any_of(operands.begin(), operands.end(),
                           [this](auto const& operand) { return isI8(operand); });
    }
	bool isI8(Value const* operand) const {
        return (operand->getType()->isIntegerTy()) && (operand->getType()->getIntegerBitWidth() == 8);
    }
	
	void doObfuscateI8Add(Instruction* instruction) const {
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
};

}  // namespace

char ObfuscateI8Add::ID = 0;
static RegisterPass<ObfuscateI8Add> X(
    "obfuscate-i8-add",                                            								   /* Command line argument */
    "Peephole Optimization Course Pass: Obfuscate int8 add (after compiling with -O1 flag)",       /* Help string */
    false                                                      								   /* Changes the CFG */,
    false                                                     								   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new ObfuscateI8Add());
    }
);
