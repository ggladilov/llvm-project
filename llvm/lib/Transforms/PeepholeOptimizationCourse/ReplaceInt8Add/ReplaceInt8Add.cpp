#include "llvm/Transforms/PeepholeOptimizationCourse/Functions.h"
#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {

struct ReplaceInt8Add : public FunctionPass {
    static char ID;
    ReplaceInt8Add() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE ADD **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool replaced = false;

        for (auto ii = inst_begin(function), ie = inst_end(function); ii !=ie;) {
			auto instruction = &*ii;
			++ii;
			
			if (!isBinaryAddInt8(instruction)) {
                continue;
            }
			
			ReplaceInt8Instruction(instruction);
			replaced = true;
		}
        return replaced;
    }

};

}  // namespace

char ReplaceInt8Add::ID = 0;
static RegisterPass<ReplaceInt8Add> X(
    "replace-add",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Replace Add", /* Help string */
    false                                                      /* Changes the CFG */,
    false                                                      /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new ReplaceInt8Add());
    }
);
