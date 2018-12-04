#include "lbrackettoken.hpp"

LBracketToken::LBracketToken(const QString &str)
    :Token(str)
{
}

LBracketToken::~LBracketToken()
{
}

void LBracketToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
