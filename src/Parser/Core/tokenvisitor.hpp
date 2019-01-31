#ifndef TOKENVISITOR_HPP
#define TOKENVISITOR_HPP

#include "Tokens/token.hpp"

class NumberToken;
class VariableToken;
class FunctionNameToken;
class LBracketToken;
class RBracketToken;
class FuncSeparatorToken;
class UnaryOpToken;
class BinaryOpToken;

class TokenVisitor
{
public:
    virtual ~TokenVisitor() = default;

    virtual void visit(NumberToken        *t) = 0;
    virtual void visit(VariableToken      *t) = 0;
    virtual void visit(FunctionNameToken  *t) = 0;
    virtual void visit(LBracketToken      *t) = 0;
    virtual void visit(RBracketToken      *t) = 0;
    virtual void visit(FuncSeparatorToken *t) = 0;
    virtual void visit(UnaryOpToken       *t) = 0;
    virtual void visit(BinaryOpToken      *t) = 0;

};

#endif // TOKENVISITOR_HPP
