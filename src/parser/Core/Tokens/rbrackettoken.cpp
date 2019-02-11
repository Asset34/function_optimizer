#include "rbrackettoken.hpp"

RBracketToken::RBracketToken(const QString &str)
    :Token(str)
{
}

void RBracketToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
