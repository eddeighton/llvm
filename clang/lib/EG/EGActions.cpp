

#include "clang/EG/EGActions.h"
#include "clang/EG/EGDatabase.h"

#include "clang/Frontend/CompilerInstance.h"
#include "clang/Frontend/ASTConsumers.h"
#include "clang/Frontend/MultiplexConsumer.h"
#include "clang/AST/AST.h"
#include "clang/AST/ASTConsumer.h"
#include "clang/AST/ASTContext.h"
#include "clang/AST/PrettyPrinter.h"
#include "clang/AST/RecordLayout.h"
#include "clang/AST/RecursiveASTVisitor.h"
#include "clang/Sema/Sema.h"
#include "clang/Sema/Lookup.h"
#include "clang/Sema/SemaDiagnostic.h"


using namespace clang;
using namespace clang_eg;

EGAction::EGAction( CompilerInstance &CI, std::unique_ptr<FrontendAction> WrappedAction )
    :   WrapperFrontendAction( std::move( WrappedAction ) )
{
    //const FrontendOptions &FEOpts = CI.getFrontendOpts();
    //llvm::outs() <<
    //    "EGDatabase: "      << FEOpts.EGDatabase        << "\n" <<
    //    "EGAnalysisPath: "  << FEOpts.EGAnalysisPath    << "\n" <<
    //    "EGAnalysisID: "    << FEOpts.EGAnalysisID      << "\n" <<
    //    "EGCXXFile: "       << FEOpts.EGCXXFile         << "\n";
}

std::unique_ptr<ASTConsumer> EGAction::CreateASTConsumer(CompilerInstance &CI, StringRef InFile)
{
    //const FrontendOptions &FEOpts = CI.getFrontendOpts();
    
    //interesting thing to do...
    //PPConditionalDirectiveRecord *
    // PPRec = new PPConditionalDirectiveRecord(CompInst->getSourceManager());
    //CI.getPreprocessor().addPPCallbacks(std::unique_ptr<PPCallbacks>(PPRec));
  
    std::vector< std::unique_ptr< ASTConsumer> > Consumers;
  
    Consumers.push_back( WrapperFrontendAction::CreateASTConsumer( CI, InFile ) );
  
    //if( !FEOpts.EGCXXFile.empty() )
    //{
    //    llvm::outs() << "creating cxx output file: " << FEOpts.EGCXXFile << "\n";
    //    if (std::unique_ptr<raw_ostream> OS =
    //          CI.createOutputFile( FEOpts.EGCXXFile, false, false, InFile, ".cpp", false, false ) )
    //    {
    //        Consumers.push_back( 
    //            llvm::make_unique< EGASTPrinter >( std::move( OS ) ) );
    //    }
    //}
    
    return llvm::make_unique< MultiplexConsumer >( std::move( Consumers ) );
}

bool EGAction::BeginInvocation( CompilerInstance& CI ) 
{
    //if( !CI.getFrontendOpts().EGDatabase.empty() )
    //{
    //    if( CI.getFrontendOpts().EGAnalysisPath.empty() )
    //    {
    //        m_pEGDatabase = std::make_shared< EGDatabaseImpl >( 
    //            CI.getFrontendOpts().EGDatabase );
    //    }
    //    else
    //    {
    //        m_pEGDatabase = std::make_shared< EGDatabaseImpl >( 
    //            CI.getFrontendOpts().EGDatabase,
    //            CI.getFrontendOpts().EGAnalysisPath,
    //            CI.getFrontendOpts().EGAnalysisID );
    //    }
    //        
    //    CI.m_pEGDatabase = m_pEGDatabase;
    //}
    
    return true;
}

//This is only called if the compilation was successful
void EGAction::EndSourceFileAction()
{
    WrapperFrontendAction::EndSourceFileAction();
    
    //if( m_pEGDatabase )
    //{
    //    m_pEGDatabase->runAnalysis();
    //    m_pEGDatabase.reset();
    //}
}