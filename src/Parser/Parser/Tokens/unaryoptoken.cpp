#include "unaryoptoken.hpp"

UnaryOpToken::UnaryOpToken(const QString &str)
    :Token(str)
{
}

UnaryOpToken::~UnaryOpToken()
{
}

void UnaryOpToken::accept(TokenVisitor &visitor)
{
    visitor.visit(this);
}
