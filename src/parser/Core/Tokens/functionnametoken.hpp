#ifndef FUNCTIONNAMETOKEN_HPP
#define FUNCTIONNAMETOKEN_HPP

#include "../tokenvisitor.hpp"

class FunctionNameToken : public Token
{
public:
    explicit FunctionNameToken(const QString &str);
    virtual void accept(TokenVisitor &visitor);

};

#endif // FUNCTIONNAMETOKEN_HPP
