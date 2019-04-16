//===-- ARCMT.h - ARC Migration Rewriter ------------------------*- C++ -*-===//
//
//                     The LLVM Compiler Infrastructure
//
// This file is distributed under the University of Illinois Open Source
// License. See LICENSE.TXT for details.
//
//===----------------------------------------------------------------------===//
#ifndef LLVM_CLANG_EG_ACTIONS_H
#define LLVM_CLANG_EG_ACTIONS_H

#include "clang/ARCMigrate/FileRemapper.h"
#include "clang/Frontend/FrontendAction.h"
#include <memory>

namespace clang {

namespace clang_eg {
     
//class EGDatabase;

class EGAction : public WrapperFrontendAction 
{
protected:
    bool BeginInvocation(CompilerInstance &CI) override;

    std::unique_ptr<ASTConsumer> CreateASTConsumer(CompilerInstance &CI, StringRef InFile) override;
    
    virtual void EndSourceFileAction();
public:
    EGAction( CompilerInstance &CI, std::unique_ptr<FrontendAction> WrappedAction );
    
private:
    //std::shared_ptr< EGDatabase > m_pEGDatabase;
};
    
    
} // end namespace clang_eg

}  // end namespace clang

#endif