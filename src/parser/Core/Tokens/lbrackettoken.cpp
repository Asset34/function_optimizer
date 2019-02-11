#include "lbrackettoken.hpp"

LBracketToken::LBracketToken(const QString &str)
    :Token(str)
{
}

void LBracketToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
