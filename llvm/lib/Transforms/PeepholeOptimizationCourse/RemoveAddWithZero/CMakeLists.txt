add_llvm_library(
    LLVMRemoveAddWithZero
        MODULE RemoveAddWithZero.cpp
        PLUGIN_TOOL opt
)
