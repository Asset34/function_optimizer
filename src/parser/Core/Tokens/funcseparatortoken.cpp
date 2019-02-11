#include "funcseparatortoken.hpp"

FuncSeparatorToken::FuncSeparatorToken(const QString &str)
    :Token(str)
{
}

void FuncSeparatorToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
