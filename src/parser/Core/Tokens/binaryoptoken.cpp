#include "binaryoptoken.hpp"

BinaryOpToken::BinaryOpToken(const QString &str)
    :Token(str)
{
}

void BinaryOpToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
