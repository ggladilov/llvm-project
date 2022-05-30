#include "llvm/Pass.h"

#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/LegacyPassManager.h"

#include "llvm/Support/raw_ostream.h"

#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"

using namespace llvm;

namespace {

struct ReplaceInt8Add : public FunctionPass {
    static char ID;
    ReplaceInt8Add() : FunctionPass(ID) {}

    bool runOnFunction(Function& F) override {
        errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
        errs() << "********** REPLACE INT8 ADD **********\n";
        errs() << "********** Function: " << F.getName() << '\n';

        bool changed = false;

        for (BasicBlock& BB : F.getBasicBlockList()) {
            for (auto I = BB.begin(), IE = BB.end(); I != IE; ++I) {
                auto *binOp = dyn_cast<BinaryOperator>(I);

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

                Instruction *replacement = BinaryOperator::CreateAdd(
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
                changed = true;
            }
        }

        return changed;
    }
};

}  // namespace

char ReplaceInt8Add::ID = 0;
static RegisterPass<ReplaceInt8Add> X(
    "replace-int8-add",                                    /* Command line argument */
    "Peephole Optimization Course Pass: Replace Int8 Add", /* Help string */
    false                                                   /* Changes the CFG */,
    false                                                   /* This is not the Analysis Pass */
);

static RegisterStandardPasses Y(
    PassManagerBuilder::EP_EarlyAsPossible,
    [](const PassManagerBuilder &Builder, legacy::PassManagerBase &PM) {
        PM.add(new ReplaceInt8Add());
    }
);
