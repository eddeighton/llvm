set(LLVM_LINK_COMPONENTS
  support
  )

add_clang_library(clangMove
  ClangMove.cpp
  HelperDeclRefGraph.cpp

  LINK_LIBS
  clangAnalysis
  clangAST
  clangASTMatchers
  clangBasic
  clangFormat
  clangFrontend
  clangLex
  clangSerialization
  clangTooling
  clangToolingCore
  clangEG
  )

add_subdirectory(tool)
