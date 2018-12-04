#ifndef UNARYOPTOKEN_HPP
#define UNARYOPTOKEN_HPP

#include "../tokenvisitor.hpp"

class UnaryOpToken : public Token
{
public:
    UnaryOpToken(const QString &str);

    virtual ~UnaryOpToken();
    virtual void accept(TokenVisitor &visitor);
};

#endif // UNARYOPTOKEN_HPP
