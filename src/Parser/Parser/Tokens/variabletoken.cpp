#include "variabletoken.hpp"

VariableToken::VariableToken(const QString &str)
    :Token(str)
{
}

VariableToken::~VariableToken()
{
}

void VariableToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
