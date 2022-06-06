add_llvm_library(
    LLVMReplaceInt8Add
        MODULE PassForI8Add.cpp
        PLUGIN_TOOL opt
)