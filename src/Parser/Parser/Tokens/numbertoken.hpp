#ifndef NUMBERTOKEN_HPP
#define NUMBERTOKEN_HPP

#include "../tokenvisitor.hpp"

class NumberToken : public Token
{
public:
    NumberToken(const QString &str);

    virtual ~NumberToken();
    virtual void accept(TokenVisitor &visitor);
};

#endif // NUMBERTOKEN_HPP
