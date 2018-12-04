#include "funcseparatortoken.hpp"

FuncSeparatorToken::FuncSeparatorToken(const QString &str)
    :Token(str)
{
}

FuncSeparatorToken::~FuncSeparatorToken()
{
}

void FuncSeparatorToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
