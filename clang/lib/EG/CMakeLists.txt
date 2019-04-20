set(LLVM_LINK_COMPONENTS
  Support
  )
  
find_library( EG_PLUGIN_LIB_DEBUG eg_clang_plugind.lib  )
find_library( EG_PLUGIN_LIB_RELEASE eg_clang_plugin.lib  )
    
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

target_link_libraries( clangEG LINK_PRIVATE debug ${EG_PLUGIN_LIB_DEBUG} optimized ${EG_PLUGIN_LIB_RELEASE} )