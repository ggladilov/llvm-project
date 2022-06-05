#include "llvm/Transforms/PeepholeOptimizationCourse/CheckAndObfuscate.h"

using namespace llvm;

namespace {

    struct Obfuscate8ByteAddition : public FunctionPass {
        static char ID;
        Obfuscate8ByteAddition() : FunctionPass(ID) {}

        bool runOnFunction(Function& function) override {
            errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
            errs() << "********** OBFUSCATE 8BYTE ADDITION **********\n";
            errs() << "********** Function: " << function.getName() << '\n';
            
            bool changed = false;
            for (auto ii = inst_begin(function), ie = inst_end(function); ii != ie;) {
                auto instruction = &*ii;
                ++ii;

                if (!is8ByteAddition(instruction)) {
                    continue;
                }

                ReplaceInstWithInst(instruction, obfuscate8ByteAddition(instruction));
                changed = true;
            }

            return changed;
        }
    };

}  // namespace

char Obfuscate8ByteAddition::ID = 0;
static RegisterPass<Obfuscate8ByteAddition> X(
    "obfuscate-8byte-addition",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Obfuscate 8Byte Addition", /* Help string */
    false                                                          /* Changes the CFG */,
    false                                                          /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new Obfuscate8ByteAddition());
    }
);