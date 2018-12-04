#include "rbrackettoken.hpp"

RBracketToken::RBracketToken(const QString &str)
    :Token(str)
{
}

RBracketToken::~RBracketToken()
{
}

void RBracketToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
