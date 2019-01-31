#ifndef RPNCONVERTER_HPP
#define RPNCONVERTER_HPP

#include <Core/emptytokenvisitor.hpp>

#include <Core/Predicates/TokenPredicates/compareprioritytokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/functionnametokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/lbrackettokenpredicate.hpp>

#include <QStack>
#include <QList>

class NumberToken;
class VariableToken;
class FunctionNameToken;
class LBracketToken;
class RBracketToken;
class FuncSeparatorToken;
class UnaryOpToken;
class BinaryOpToken;

class RpnConverter : public EmptyTokenVisitor
{
public:
    virtual ~RpnConverter();

    QList<Token*> convert(const QList<Token*> &tokens);

    virtual void visit(NumberToken        *t);
    virtual void visit(VariableToken      *t);
    virtual void visit(FunctionNameToken  *t);
    virtual void visit(LBracketToken      *t);
    virtual void visit(RBracketToken      *t);
    virtual void visit(FuncSeparatorToken *t);
    virtual void visit(UnaryOpToken       *t);
    virtual void visit(BinaryOpToken      *t);

private:
    void reset();
    void popRemainOperators();

    /* UsedPredicates */
    FunctionNameTokenPredicate    m_functionNamePr;
    LBracketTokenPredicate        m_lbracketPr;
    ComparePriorityTokenPredicate m_comparePriorityPr;

    /* Containers */
    QStack<Token*> m_operators;
    QList<Token*>  m_resultTokens;
};

#endif // RPNCONVERTER_HPP
