#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/IR/IRBuilder.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

namespace {

struct ReplaceAdd : public FunctionPass {
    static char ID;
    ReplaceAdd() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE ADD **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool changed = false;

        for (auto ii = inst_begin(function), ie = inst_end(function); ii !=ie;) {
			auto instruction = &*ii;
			++ii;
			
			if (!isBinaryAddInt8(instruction)) {
                continue;
				
            }
			
			auto const& lhs = instruction->getOperand(0);
			auto const& rhs = instruction->getOperand(1);
			auto const& type = lhs->getType();
			
			IRBuilder<> builder(instruction);
			
			Instruction* new_instruction = BinaryOperator::CreateAdd( builder.CreateMul(builder.CreateAdd(
                builder.CreateMul( ConstantInt::get(type, 39), builder.CreateAdd(
                    builder.CreateAnd(lhs, rhs), builder.CreateMul(
                        ConstantInt::get(type, 2), builder.CreateXor(lhs, rhs)))),
                            ConstantInt::get(type, 23)), ConstantInt::get(type, 151)),
								ConstantInt::get(type, 111));
			
			ReplaceInstWithInst(instruction, new_instruction);
			changed = true;
		}
        return changed;
    }
	
private:
	
    bool isBinaryAddInt8(Instruction const* instruction) const {
        return instruction->getOpcode() == Instruction::Add &&
               instruction->getNumOperands() == 2 && instruction->getType()->isIntegerTy() 
			   && instruction->getType()->getIntegerBitWidth() == 8;
    }

};

}  // namespace

char ReplaceAdd::ID = 0;
static RegisterPass<ReplaceAdd> X(
    "replace-add",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Replace Add", /* Help string */
    false                                                      /* Changes the CFG */,
    false                                                      /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new ReplaceAdd());
    }
);