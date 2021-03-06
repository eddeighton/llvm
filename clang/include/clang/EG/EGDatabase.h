

#ifndef LLVM_CLANG_EG_DATABASE_API
#define LLVM_CLANG_EG_DATABASE_API

namespace clang 
{
    class ASTContext;
    class Sema;
    class QualType;
    class Token;
    class SourceLocation;

    namespace clang_eg 
    {
		void eg_load_plugin( const char* strPluginPath );

        void eg_initialise( ASTContext* pASTContext, Sema* pSema );
        void eg_initialiseMode_Interface( const char* strDatabasePath );
        void eg_initialiseMode_Operations( const char* strDatabasePath, 
            const char* strTranslationUnitDatabasePath, unsigned uiTranslationUnitID );
        void eg_initialiseMode_Implementation();
        void eg_runFinalAnalysis();

        const char* eg_getTypePathString();
        const char* eg_getInvocationString();
        const char* eg_getVariantString();
        const char* eg_getInvokeString();
        const char* eg_getResultTypeTrait();

        bool eg_isEGEnabled();
        bool eg_isEGType( const QualType& type );
        bool eg_isPossibleEGType( const QualType& type );
        bool eg_isPossibleEGTypeIdentifier( const Token& token );
        int eg_isPossibleEGTypeIdentifierDecl( const Token& token, bool bIsTypePathParsing );
        bool eg_getInvocationOperationType( const SourceLocation& loc, const QualType& typePathType, bool bHasArguments, QualType& operationType );
        bool eg_getInvocationResultType( const SourceLocation& loc, const QualType& baseType, QualType& resultType );

    }
}

#endif //LLVM_CLANG_EG_DATABASE_API

