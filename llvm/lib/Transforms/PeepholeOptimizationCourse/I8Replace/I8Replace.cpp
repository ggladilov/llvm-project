#include "llvm/Transforms/PeepholeOptimizationCourse/I8ReplaceFunc.h"
#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {

struct I8Replace : public FunctionPass {
    static char ID;
    I8Replace() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REMOVE INT 8 SUM **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool changed = false;
        for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
            auto instruction = &*ii;
            ++ii;

            if (!I8Add(instruction)) {
                continue;
            }
            replaceInstruction(instruction);
            changed = true;
        }

        return changed;
    }

};

}  // namespace

char I8Replace::ID = 0;
static RegisterPass<I8Replace> X(
    "replace-8int-add",                                    /* Command line argument */
    "Peephole Optimization Course Pass: replace 8int add", /* Help string */
    false                                                      /* Changes the CFG */,
    false                                                      /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new I8Replace());
    }
);