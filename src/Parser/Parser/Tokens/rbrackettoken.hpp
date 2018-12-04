#ifndef RBRACKETTOKEN_HPP
#define RBRACKETTOKEN_HPP

#include "../tokenvisitor.hpp"

class RBracketToken : public Token
{
public:
    RBracketToken(const QString &str);

    virtual ~RBracketToken();
    virtual void accept(TokenVisitor &visitor);
};

#endif // LBRACKETTOKEN_HPP
