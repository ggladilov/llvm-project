#include "llvm/Transforms/PeepholeOptimizationCourse/RemoveInt8Addfuncs.h"
#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"

using namespace llvm;

namespace {

struct RemoveInt8Add : public FunctionPass {
    static char ID;
    RemoveInt8Add() : FunctionPass(ID) {}

    bool runOnFunction(Function& function) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REMOVE INT 8 SUM **********\n";
        errs() << "********** Function: " << function.getName() << '\n';

        bool changed = false;
        for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
            auto instruction = &*ii;
            ++ii;

            if (!IsItI8Add(instruction)) {
                continue;
            }
            replaceInst(instruction);
            changed = true;
        }

        return changed;
    }

};

}  // namespace

char RemoveInt8Add::ID = 0;
static RegisterPass<RemoveInt8Add> X(
    "replace-8int-add",                                    /* Command line argument */
    "Peephole Optimization Course Pass: replace 8int add", /* Help string */
    false                                                      /* Changes the CFG */,
    false                                                      /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new RemoveInt8Add());
    }
);