add_llvm_library(
    LLVMReplaceInt8Add
        MODULE ReplaceInt8Add.cpp
        PLUGIN_TOOL opt
) 