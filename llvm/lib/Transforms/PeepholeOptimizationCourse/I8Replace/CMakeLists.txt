add_llvm_library(
    LLVMReplaceInt8Add
        MODULE I8Replace.cpp
        PLUGIN_TOOL opt
)