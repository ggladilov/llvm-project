#include "llvm/Transforms/PeepholeOptimizationCourse/Obfuscate8BytesNewPassManager.h"

#include "llvm/Pass.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/InstrTypes.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Support/Debug.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#define DEBUG_TYPE "obfuscate"

using namespace llvm;
namespace {

	bool isAddWithI8(Instruction const* instruction) {
		bool is8Bit = operand->getType()->isIntegerTy() && (operand->getType()->getIntegerBitWidth() == 8);
		bool isBinaryAdd = (instruction->getOpcode() == Instruction::Add) && (instruction->getNumOperands() == 2);
		return is8Bit && isBinaryAdd;
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


	struct Obfuscate8Bytes : public FunctionPass {
    static char ID;
    Obfuscate8Bytes() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** Obfuscate 8Bytes Add **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool changed = false;
        for (auto basicBlock = function.begin(), basicBlockEnd = function.end(); basicBlock != basicBlockEnd; ++basicBlock) {
            for (auto instruction = basicBlock->begin(), ie = basicBlock->end(); instruction != ie; ++instruction) {
                auto binaryOperator = dyn_cast<BinaryOperator>(instruction);
                
				if (!isAddWithI8(instruction))
					continue;
				
				doObfuscateI8Add(instruction);

                LLVM_DEBUG(dbgs() << *binaryOperator << " -> " << *obfuscated << '\n');
                changed = true;
            }
        }

        return changed;
    }
};

}  // namespace

char Obfuscate8Bytes::ID = 0;
static RegisterPass<Obfuscate8Bytes> X(
    "obfuscate-8bytes-add",                                    /* Command line argument */
    "Add Obfescate 8 bytes ", /* Help string */
    false                                                  /* Changes the CFG */,
    false                                                  /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new Obfuscate8Bytes());
    }
);
