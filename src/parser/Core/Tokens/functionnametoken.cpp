#include "functionnametoken.hpp"

FunctionNameToken::FunctionNameToken(const QString &str)
    :Token(str)
{
}

void FunctionNameToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
