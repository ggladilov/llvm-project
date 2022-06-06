#include "llvm/Transforms/PeepholeOptimizationCourse/ChangeAddNewPassManager.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/ChangeAddFuncs.h"

#include "llvm/Pass.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

PreservedAnalyses ChangeAddNewPassManager::run(Function& F, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** CHANGE INT8 ADD NEW PASS MANAGER **********\n";
    errs() << "********** Function: " << F.getName() << '\n';

    PreservedAnalyses inst_changed = PreservedAnalyses::all();

    for (BasicBlock& BB : F.getBasicBlockList()) {
        for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
            auto* binOp = dyn_cast<BinaryOperator>(I);

                if (checkForInt8Op(binOp)) {
                    continue;
                }

                Instruction* new_instruction = changeAddNewInstruction(binOp);
                ReplaceInstWithInst(BB.getInstList(), I, new_instruction);
                inst_changed = PreservedAnalyses::none();
        }
    }

    return inst_changed;
}