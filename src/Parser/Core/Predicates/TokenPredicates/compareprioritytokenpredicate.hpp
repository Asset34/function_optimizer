#ifndef COMPAREPRIORITYTOKENPREDICATE_HPP
#define COMPAREPRIORITYTOKENPREDICATE_HPP

#include "tokencomparepredicate.hpp"

class LBracketToken;
class RBracketToken;
class UnaryOpToken;
class BinaryOpToken;

class ComparePriorityTokenPredicate : public TokenComparePredicate
{
public:
    virtual bool execute(Token &t1, Token &t2);

    virtual void visit(LBracketToken      *t);
    virtual void visit(RBracketToken      *t);
    virtual void visit(UnaryOpToken       *t);
    virtual void visit(BinaryOpToken      *t);

private:
    void setPriority(int priority);

    int m_value;

};

#endif // COMPAREPRIORITYTOKENPREDICATE_HPP
