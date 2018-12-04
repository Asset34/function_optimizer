#include "numbertoken.hpp"

NumberToken::NumberToken(const QString &str)
    :Token(str)
{
}

NumberToken::~NumberToken()
{
}

void NumberToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
