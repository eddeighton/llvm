set(LLVM_LINK_COMPONENTS
  Support
  )
  
find_path( EG_API_DIR NAMES clang_plugin/clang_plugin.hpp )
include_directories( ${EG_API_DIR} )

add_clang_library(clangEG
  EGDatabase.cpp

  LINK_LIBS
  clangAST
  clangAnalysis
  clangBasic
  clangEdit
  clangFrontend
  clangLex
  clangRewrite
  clangSema
  clangSerialization
  clangStaticAnalyzerCheckers
  clangStaticAnalyzerCore
  )
