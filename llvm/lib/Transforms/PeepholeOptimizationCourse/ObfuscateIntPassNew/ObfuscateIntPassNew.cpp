#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateIntPassNew.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/ObfuscateIntPassFunctions.h"

#include "llvm/Pass.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

PreservedAnalyses ObfuscateIntPassNew::run(Function& F, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** OBFUSC INT8 ADD NEW **********\n";
    errs() << "********** Function: " << F.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();

    for (BasicBlock& BB : F.getBasicBlockList()) {
        for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
            auto* binary_operator = dyn_cast<BinaryOperator>(I);

            if (!binary_operator || binary_operator->getOpcode() != Instruction::Add) {
                continue;
            }

            if (!(binary_operator->getType()->isIntegerTy() && binary_operator->getType()->getIntegerBitWidth() == 8)) {
                continue;
            }

            Instruction* replacement = PassInstruction(binary_operator);

            ReplaceInstWithInst(BB.getInstList(), I, replacement);
            changed = PreservedAnalyses::none();
        }
    }

    return changed;
}