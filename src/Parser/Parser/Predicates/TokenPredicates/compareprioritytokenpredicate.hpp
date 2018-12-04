#ifndef COMPAREPRIORITYTOKENPREDICATE_HPP
#define COMPAREPRIORITYTOKENPREDICATE_HPP

#include "tokencomparepredicate.hpp"
#include "../../emptytokenvisitor.hpp"
#include "../../Tokens/binaryoptoken.hpp"
#include "../../Tokens/lbrackettoken.hpp"
#include "../../Tokens/rbrackettoken.hpp"
#include "../../Tokens/unaryoptoken.hpp"
#include "../../tables.hpp"

class ComparePriorityTokenPredicate : public TokenComparePredicate
{
public:
    virtual ~ComparePriorityTokenPredicate();
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
