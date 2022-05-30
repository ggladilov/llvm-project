#include "llvm/Transforms/PeepholeOptimizationCourse/ReplaceInt8AddNewPassManager.h"

#include "llvm/Pass.h"

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

PreservedAnalyses ReplaceInt8AddNewPassManager::run(Function& F, FunctionAnalysisManager& analysisManager) {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** REPLACE INT8 ADD **********\n";
    errs() << "********** Function: " << F.getName() << '\n';

    PreservedAnalyses changed = PreservedAnalyses::all();

    for (BasicBlock& BB : F.getBasicBlockList()) {
        for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
            auto* binOp = dyn_cast<BinaryOperator>(I);

            // Check op is binary
            if (!binOp) {
                continue;
            }

            // Check op is add
            if (binOp->getOpcode() != Instruction::Add) {
                continue;
            }

            // Check precision is i8
            if (!(binOp->getType()->isIntegerTy() && binOp->getType()->getIntegerBitWidth() == 8)) {
                continue;
            }

            IRBuilder<> B(binOp);
            auto const& lhs = binOp->getOperand(0);
            auto const& rhs = binOp->getOperand(1);
            auto const& i8 = binOp->getType();

            Instruction* replacement = BinaryOperator::CreateAdd(
                B.CreateMul(
                    B.CreateMul(
                        ConstantInt::get(i8, 39),
                        B.CreateAdd(
                            B.CreateAnd(lhs, rhs),
                            B.CreateAdd(
                                B.CreateMul(
                                    ConstantInt::get(i8, 2),
                                    B.CreateXor(lhs, rhs)
                                ),
                                ConstantInt::get(i8, 23)
                            )
                        )
                    ),
                    ConstantInt::get(i8, 151)
                ),
                ConstantInt::get(i8, 111)
            );

            ReplaceInstWithInst(BB.getInstList(), I, replacement);
            changed = PreservedAnalyses::none();
        }
    }

    return changed;
}
