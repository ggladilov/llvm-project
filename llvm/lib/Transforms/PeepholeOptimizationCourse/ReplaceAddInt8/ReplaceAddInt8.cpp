#include "llvm/Transforms/PeepholeOptimizationCourse/ReplaceAddInt8Functions.h"
#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {

struct ReplaceAddInt8 : public FunctionPass {
    static char ID;
    ReplaceAddInt8() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE ADD INT 8 **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool changed = false;

        for (auto ii = inst_begin(function), ie = inst_end(function); ii !=ie;) {
			auto instruction = &*ii;
			++ii;

			if (!isAddInt8(instruction)) continue;

			ReplaceAddInt8Instruction(instruction);
			changed = true;
		}
        return changed;
    }

};

}  // namespace

char ReplaceAddInt8::ID = 0;
static RegisterPass<ReplaceAddInt8> X(
    "replace-add-int8",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Replace Add Int 8", /* Help string */
    false                                                      /* Changes the CFG */,
    false                                                      /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new ReplaceAddInt8());
    }
); 
