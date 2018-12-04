#ifndef MATHRPNCONVERTER_HPP
#define MATHRPNCONVERTER_HPP

#include "../emptytokenvisitor.hpp"
#include "../Predicates/TokenPredicates/compareprioritytokenpredicate.hpp"
#include "../Predicates/TokenPredicates/functionnametokenpredicate.hpp"
#include "../Predicates/TokenPredicates/lbrackettokenpredicate.hpp"
#include "../Tokens/binaryoptoken.hpp"
#include "../Tokens/funcseparatortoken.hpp"
#include "../Tokens/functionnametoken.hpp"
#include "../Tokens/lbrackettoken.hpp"
#include "../Tokens/numbertoken.hpp"
#include "../Tokens/rbrackettoken.hpp"
#include "../Tokens/unaryoptoken.hpp"
#include "../Tokens/variabletoken.hpp"
#include "../../utils.hpp"

#include <QStack>
#include <QList>

class MathRPNConverter : public EmptyTokenVisitor
{
public:
    QList<Token*> convert(const QList<Token*> &tokens);

    virtual ~MathRPNConverter();
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

#endif // MATHRPNCONVERTER_HPP
