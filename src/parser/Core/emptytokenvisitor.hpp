#ifndef EMPTYTOKENVISITOR_HPP
#define EMPTYTOKENVISITOR_HPP

#include "tokenvisitor.hpp"

class EmptyTokenVisitor : public TokenVisitor
{
public:
    virtual void visit(NumberToken        *t);
    virtual void visit(VariableToken      *t);
    virtual void visit(FunctionNameToken  *t);
    virtual void visit(LBracketToken      *t);
    virtual void visit(RBracketToken      *t);
    virtual void visit(FuncSeparatorToken *t);
    virtual void visit(UnaryOpToken       *t);
    virtual void visit(BinaryOpToken      *t);

};

#endif // EMPTYTOKENVISITOR_HPP
