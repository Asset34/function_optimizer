#ifndef RBRACKETTOKEN_HPP
#define RBRACKETTOKEN_HPP

#include "../tokenvisitor.hpp"

class RBracketToken : public Token
{
public:
    explicit RBracketToken(const QString &str);
    virtual void accept(TokenVisitor &visitor);

};

#endif // LBRACKETTOKEN_HPP
