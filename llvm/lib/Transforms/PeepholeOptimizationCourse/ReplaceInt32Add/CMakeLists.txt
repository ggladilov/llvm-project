add_llvm_library(
    LLVMReplaceInt32Add
        MODULE ReplaceInt32Add.cpp
        PLUGIN_TOOL opt
)
