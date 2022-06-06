#include "llvm/Transforms/PeepholeOptimizationCourse/Obfuscate8ByteAddNewPassManager.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/Obfuscate8ByteFunc.h"

#include "llvm/IR/Constants.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

PreservedAnalyses Obfuscate8ByteAddNewPassManager::run(
    Function& func, FunctionAnalysisManager& analysisManager) {
  errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
  errs() << "********** OBFUSCATE 8BYTE ADD **********\n";
  errs() << "********** Function: " << func.getName() << '\n';

  PreservedAnalyses changed = PreservedAnalyses::all();

  for (BasicBlock& bb : func.getBasicBlockList()) {
    for (auto i = bb.begin(), ie = bb.end(); i != ie; ++i) {
      auto* binaryOperator = dyn_cast<BinaryOperator>(i);

      if (binaryOperator != nullptr) {
        const auto instruction = binaryOperator->getOpcode();
        if (instruction == Instruction::Add) {
          const auto instruction_type = binaryOperator->getType();
          if (instruction_type->isIntegerTy() &&
              instruction_type->getIntegerBitWidth() == 8U) {
            Instruction* AddOpIns = OperFunc(binaryOperator);
            ReplaceInstWithInst(bb.getInstList(), i, AddOpIns);

            changed = PreservedAnalyses::none();
          }
        }
      }
    }
  }

  return changed;
}
