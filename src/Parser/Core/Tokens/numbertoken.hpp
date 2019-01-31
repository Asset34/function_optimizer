#ifndef NUMBERTOKEN_HPP
#define NUMBERTOKEN_HPP

#include "../tokenvisitor.hpp"

class NumberToken : public Token
{
public:
    explicit NumberToken(const QString &str);
    virtual void accept(TokenVisitor &visitor);

};

#endif // NUMBERTOKEN_HPP
