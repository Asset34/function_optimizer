#ifndef UNARYOPTOKEN_HPP
#define UNARYOPTOKEN_HPP

#include "../tokenvisitor.hpp"

class UnaryOpToken : public Token
{
public:
    explicit UnaryOpToken(const QString &str);
    virtual void accept(TokenVisitor &visitor);

};

#endif // UNARYOPTOKEN_HPP
