add_llvm_component_library(
    LLVMObfuscateI8AddNewPassManager
    ObfuscateI8AddNewPassManager.cpp
	
	ADDITIONAL_HEADER_DIRS
    ${LLVM_MAIN_INCLUDE_DIR}/llvm/Transforms/PeepholeOptimizationCourse
	
	LINK_COMPONENTS
	ObfuscateI8AddFunctions
	Core
	Support
)
