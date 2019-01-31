#ifndef LBRACKETTOKEN_HPP
#define LBRACKETTOKEN_HPP

#include "../tokenvisitor.hpp"

class LBracketToken : public Token
{
public:
    explicit LBracketToken(const QString &str);
    virtual void accept(TokenVisitor &visitor);

};

#endif // LBRACKETTOKEN_HPP
