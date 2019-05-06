

#include "clang/EG/EGDatabase.h"

#include "clang_plugin/clang_plugin.hpp"

#include "clang/AST/Type.h"

namespace clang {

namespace clang_eg {
    
void eg_initialise( ASTContext* pASTContext, Sema* pSema )
{
    eg::initialise( pASTContext, pSema );
}

void eg_initialiseMode_Interface( const char* strDatabasePath )
{
    eg::initialiseMode_Interface( strDatabasePath );
}

void eg_initialiseMode_Operations( const char* strDatabasePath, 
    const char* strTranslationUnitDatabasePath, unsigned uiTranslationUnitID )
{
    eg::initialiseMode_Operations( strDatabasePath, strTranslationUnitDatabasePath, uiTranslationUnitID );
}
    
void eg_initialiseMode_Implementation()
{
    eg::initialiseMode_Implementation();
}

void eg_runFinalAnalysis()
{
    eg::runFinalAnalysis();
}

const char* eg_getTypePathString()
{
    return eg::getTypePathString();
}
const char* eg_getInvocationString()
{
    return eg::getInvocationString();
}
const char* eg_getVariantString()
{
    return eg::getVariantString();
}
const char* eg_getInvokeString()
{
    return eg::getInvokeString();
}
const char* eg_getResultTypeTrait()
{
    return eg::getResultTypeTrait();
}
    
bool eg_isEGEnabled()
{
    return eg::isEGEnabled();
}

bool eg_isEGType( const QualType& type )
{
    return eg::isEGType( type );
}

bool eg_isPossibleEGType( const QualType& type )
{
    return eg::isPossibleEGType( type );
}

bool eg_isPossibleEGTypeIdentifier( const Token& token )
{
    return eg::isPossibleEGTypeIdentifier( token );
}

int eg_isPossibleEGTypeIdentifierDecl( const Token& token, bool bIsTypePathParsing )
{
    return eg::isPossibleEGTypeIdentifierDecl( token, bIsTypePathParsing );
}

bool eg_getInvocationOperationType( const SourceLocation& loc, const QualType& typePathType, bool bHasArguments, QualType& operationType )
{
    return eg::getInvocationOperationType( loc, typePathType, bHasArguments, operationType );
}

bool eg_getInvocationResultType( const SourceLocation& loc, const QualType& baseType, QualType& resultType )
{
    return eg::getInvocationResultType( loc, baseType, resultType );
}

}//clang_eg
}//clang

 