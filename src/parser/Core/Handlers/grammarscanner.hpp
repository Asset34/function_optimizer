#ifndef GRAMMARSCANNER_HPP
#define GRAMMARSCANNER_HPP

#include "../tables.hpp"

#include <Core/Tokens/token.hpp>
#include <Core/Predicates/TokenPredicates/tokencomparepredicate.hpp>
#include <Core/Predicates/TokenPredicates/disjunctiontokenpredicate.hpp>

#include <stdexcept>

#include <QString>
#include <QStack>

class NumberToken;
class VariableToken;
class FunctionNameToken;
class LBracketToken;
class RBracketToken;
class FuncSeparatorToken;
class UnaryOpToken;
class BinaryOpToken;

class GrammarScanner : public EmptyTokenVisitor
{
public:
    GrammarScanner();

    void Scann(QList<Token*> tokens);

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
    void throwException(Token *lastToken);
    void compareBracketCounters();
    void functionEnter(FunctionNameToken *t);
    void functionArgLeave();
    void functionLeave();

    /* Edges */
    DisjunctionTokenPredicate m_edgesMathExp;
    DisjunctionTokenPredicate m_edgesVariable;
    DisjunctionTokenPredicate m_edgesNumber;
    DisjunctionTokenPredicate m_edgesBinaryOp;
    DisjunctionTokenPredicate m_edgesUnaryOp;
    DisjunctionTokenPredicate m_edgesLbracket;
    DisjunctionTokenPredicate m_edgesRbacket;
    DisjunctionTokenPredicate m_edgesFuncSeparator;
    DisjunctionTokenPredicate m_edgesFunctionName;

    /* Current edge */
    TokenPredicate *m_edgesCurrent;

    /* Current functions */
    QStack<QString> m_functions;

    /* Counters */
    QStack<int> m_argumentsCounters;
    QStack<int> m_maxArguments;
    QStack<int> m_bracketValues;

    int m_bracketCounter;
};

#endif // GRAMMARSCANNER_HPP
