#ifndef BINARYOPTOKEN_HPP
#define BINARYOPTOKEN_HPP

#include "../tokenvisitor.hpp"

class BinaryOpToken : public Token
{
public:
    explicit BinaryOpToken(const QString &str);
    virtual void accept(TokenVisitor &visitor);

};

#endif // BINARYOPTOKEN_HPP
