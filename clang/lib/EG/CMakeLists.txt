set(LLVM_LINK_COMPONENTS
  Support
  )
  
  
find_library( EG_DATABASE_LIB_DEBUG egdatabased.lib  )
find_library( EG_DATABASE_LIB_RELEASE egdatabase.lib  )
    
find_path( EG_DATABASE_API NAMES egdb_export.hpp )
include_directories( ${EG_DATABASE_API} )

add_clang_library(clangEG
  EGActions.cpp
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

target_link_libraries( clangEG LINK_PRIVATE debug ${EG_DATABASE_LIB_DEBUG} optimized ${EG_DATABASE_LIB_RELEASE} )