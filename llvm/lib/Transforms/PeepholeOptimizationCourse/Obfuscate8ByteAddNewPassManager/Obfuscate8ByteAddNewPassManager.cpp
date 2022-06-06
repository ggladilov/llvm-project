#include "llvm/Transforms/PeepholeOptimizationCourse/Obfuscate8ByteAddNewPassManager.h"

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
            IRBuilder<> builder(binaryOperator);
            auto const& first = binaryOperator->getOperand(0);
            auto const& second = binaryOperator->getOperand(1);
            auto const& i8Type = binaryOperator->getType();

            const auto IntConst2 = ConstantInt::get(i8Type, 2);
            const auto IntConst23 = ConstantInt::get(i8Type, 23);
            const auto IntConst39 = ConstantInt::get(i8Type, 39);
            const auto IntConst151 = ConstantInt::get(i8Type, 151);
            const auto IntConst111 = ConstantInt::get(i8Type, 111);

            const auto XorOperator = builder.CreateXor(first, second);
            const auto MulOperator1 = builder.CreateMul(IntConst2, XorOperator);
            const auto AddOperator1 =
                builder.CreateAdd(MulOperator1, IntConst23);
            const auto AndOperator = builder.CreateAnd(first, second);
            const auto AddOperator2 =
                builder.CreateAdd(AndOperator, AddOperator1);
            const auto MulOperator2 =
                builder.CreateMul(IntConst39, AddOperator2);
            const auto MulOperator3 =
                builder.CreateMul(MulOperator2, IntConst151);

            Instruction* replacement =
                BinaryOperator::CreateAdd(MulOperator3, IntConst111);

            ReplaceInstWithInst(bb.getInstList(), i, replacement);
            changed = PreservedAnalyses::none();
          }
        }
      }
    }
  }

  return changed;
}
