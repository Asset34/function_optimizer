#include "variabletoken.hpp"

VariableToken::VariableToken(const QString &str)
    :Token(str)
{
}

void VariableToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
