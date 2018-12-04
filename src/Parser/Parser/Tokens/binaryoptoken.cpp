#include "binaryoptoken.hpp"

BinaryOpToken::BinaryOpToken(const QString &str)
    :Token(str)
{
}

BinaryOpToken::~BinaryOpToken()
{
}

void BinaryOpToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
