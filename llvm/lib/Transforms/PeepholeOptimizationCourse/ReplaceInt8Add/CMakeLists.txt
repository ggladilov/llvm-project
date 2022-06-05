add_llvm_library(
    LLVMReplaceInt8Add
        MODULE ReplaceInt8Sum.cpp
        PLUGIN_TOOL opt
)
