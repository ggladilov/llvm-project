add_llvm_component_library(
    LLVMObfuscateI8AddFunctions
    ObfuscateI8AddFunctions.cpp
	
	ADDITIONAL_HEADER_DIRS
    ${LLVM_MAIN_INCLUDE_DIR}/llvm/Transforms/PeepholeOptimizationCourse
	
	LINK_COMPONENTS
    Core
)
