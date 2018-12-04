#ifndef BINARYOPTOKEN_HPP
#define BINARYOPTOKEN_HPP

#include "../tokenvisitor.hpp"

class BinaryOpToken : public Token
{
public:
    BinaryOpToken(const QString &str);

    virtual ~BinaryOpToken();
    virtual void accept(TokenVisitor &visitor);
};

#endif // BINARYOPTOKEN_HPP
