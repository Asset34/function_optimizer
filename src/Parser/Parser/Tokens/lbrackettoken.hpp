#ifndef LBRACKETTOKEN_HPP
#define LBRACKETTOKEN_HPP

#include "../tokenvisitor.hpp"

class LBracketToken : public Token
{
public:
    LBracketToken(const QString &str);

    virtual ~LBracketToken();
    virtual void accept(TokenVisitor &visitor);
};

#endif // LBRACKETTOKEN_HPP
