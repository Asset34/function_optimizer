#ifndef FUNCTIONNAMETOKEN_HPP
#define FUNCTIONNAMETOKEN_HPP

#include "../tokenvisitor.hpp"

class FunctionNameToken : public Token
{
public:
    FunctionNameToken(const QString &str);

    virtual ~FunctionNameToken();
    virtual void accept(TokenVisitor &visitor);
};

#endif // FUNCTIONNAMETOKEN_HPP
