#include "numbertoken.hpp"

NumberToken::NumberToken(const QString &str)
    :Token(str)
{
}

void NumberToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
