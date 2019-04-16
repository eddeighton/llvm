

#ifndef LLVM_CLANG_EG_DATABASE
#define LLVM_CLANG_EG_DATABASE

#include "clang/AST/Type.h"

namespace clang {

namespace clang_eg {

/*
class EGDatabase
{
public:
    virtual ~EGDatabase();
    //virtual void setASTContext( ASTContext* pASTContext ) = 0;
    //virtual void setSema( Sema* pSema ) = 0;
    //virtual bool isEGType( QualType type ) = 0;
    //virtual bool isEGTraversalType( QualType type ) = 0;
    //virtual QualType getInvocationResultType( QualType contextType, QualType typePath, QualType operationType ) = 0;
    //virtual QualType invokeOperationType( QualType traversal, bool bHasParameters ) = 0;
    //
    //virtual void runAnalysis() = 0;
};
*/


const char* getTypePathString();
const char* getInvocationString();
const char* getVariantString();
const char* getInvokeString();

bool isTypePathsEnabled();
bool isEGType( QualType type );
bool isPossibleEGType( QualType type );
bool isPossibleEGTypeIdentifier( const IdentifierInfo &II );


}
}

#endif //LLVM_CLANG_EG_DATABASE

