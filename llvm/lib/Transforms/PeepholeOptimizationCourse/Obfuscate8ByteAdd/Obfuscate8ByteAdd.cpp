#include "llvm/IR/Constants.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LegacyPassManager.h"
#include "llvm/Pass.h"
#include "llvm/Support/raw_ostream.h"
#include "llvm/Transforms/IPO/PassManagerBuilder.h"
#include "llvm/Transforms/Utils/BasicBlockUtils.h"
#include "llvm/Transforms/PeepholeOptimizationCourse/Obfuscate8ByteFunc.h"

using namespace llvm;

namespace {

struct Obfuscate8ByteAdd : public FunctionPass {
  static char ID;
  Obfuscate8ByteAdd() : FunctionPass(ID) {}

  bool runOnFunction(Function& func) override {
    errs() << "********** PEEPHOLE OPTIMIZATION COURSE **********\n";
    errs() << "********** OBFUSCATE 8BYTE ADD **********\n";
    errs() << "********** Function: " << func.getName() << '\n';

    bool changed = false;

    for (BasicBlock& bb : func.getBasicBlockList()) {
      for (auto i = bb.begin(), ie = bb.end(); i != ie; ++i) {
        auto* binaryOperator = dyn_cast<BinaryOperator>(i);

        //////////////////////////////////////////
        if (binaryOperator != nullptr) {
          const auto instruction = binaryOperator->getOpcode();
          if (instruction == Instruction::Add) {
            const auto instruction_type = binaryOperator->getType();
            if (instruction_type->isIntegerTy() &&
                instruction_type->getIntegerBitWidth() == 8U) {
              Instruction* AddOpIns = OperFunc(binaryOperator);

              ReplaceInstWithInst(bb.getInstList(), i, AddOpIns);
              changed = true;
            }
          }
        }
      }
    }

    return changed;
  }
};

}  // namespace

char Obfuscate8ByteAdd::ID = 0;
static RegisterPass<Obfuscate8ByteAdd> X(
    "obfuscate-8byte-add",  //  Command line argument
    "Peephole Optimization Course Pass: Obfuscate 8Byte Add",  //  Help string
    false,  //  Changes the CFG
    false   //  This is not the Analysis Pass
);

static RegisterStandardPasses Y(PassManagerBuilder::EP_EarlyAsPossible,
                                [](const PassManagerBuilder& Builder,
                                   legacy::PassManagerBase& PM) {
                                  PM.add(new Obfuscate8ByteAdd());
                                });
