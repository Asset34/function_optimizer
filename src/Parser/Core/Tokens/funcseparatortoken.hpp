#ifndef FUNCSEPARATORTOKEN_HPP
#define FUNCSEPARATORTOKEN_HPP

#include "../tokenvisitor.hpp"

class FuncSeparatorToken : public Token
{
public:
    explicit FuncSeparatorToken(const QString &str);
    virtual void accept(TokenVisitor &visitor);

};

#endif // FUNCSEPARATORTOKEN_HPP
