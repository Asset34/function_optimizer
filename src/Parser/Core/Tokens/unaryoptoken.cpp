#include "unaryoptoken.hpp"

UnaryOpToken::UnaryOpToken(const QString &str)
    :Token(str)
{
}

void UnaryOpToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
