#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateI8AddFunctions.h"
#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/InstIterator.h"
#include "llvm/IR/LegacyPassManager.h"

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

            if (!isAddI8(instruction)) {
                continue;
            }
				
			//errs() << "I8 check complite\n";
			doObfuscateI8Add(instruction);

            changed = true;
		}
        return changed;
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
