#ifndef VARIABLETOKEN_HPP
#define VARIABLETOKEN_HPP

#include "../tokenvisitor.hpp"

class VariableToken : public Token
{
public:
    explicit VariableToken(const QString &str);
    virtual void accept(TokenVisitor &visitor);

};

#endif // VARIABLETOKEN_HPP
