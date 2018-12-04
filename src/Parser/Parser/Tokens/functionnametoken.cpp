#include "functionnametoken.hpp"

FunctionNameToken::FunctionNameToken(const QString &str)
    :Token(str)
{
}

FunctionNameToken::~FunctionNameToken()
{
}

void FunctionNameToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
