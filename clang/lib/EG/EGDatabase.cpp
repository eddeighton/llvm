

#include "clang/EG/EGDatabase.h"

#include "database/database.hpp"


namespace clang {

namespace clang_eg {

const char* getTypePathString()
{
    return "__eg_type_path";
}
const char* getInvocationString()
{
    return "__eg_invocation";
}
const char* getVariantString()
{
    return "__eg_variant";
}
const char* getInvokeString()
{
    return "invoke";
}


    
bool isTypePathsEnabled()
{
    return eg::isLanguageOptionEnabled( eg::EG_LANGUAGE_TYPE_PATHS );
}

bool isEGType( QualType type )
{
    return false;
}

bool isPossibleEGType( QualType type )
{
    if( !type.isNull() )
    {
        if( type->isDependentType() )
        {
            
        }
        else
        {
            
        }
    }
    return isEGType( type );
}
bool isPossibleEGTypeIdentifier( const IdentifierInfo &II )
{
    return false;
}

}//clang_eg
}//clang

 