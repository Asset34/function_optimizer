#ifndef MATHGRAMMARSCANNER_HPP
#define MATHGRAMMARSCANNER_HPP

#include "../Tokens/binaryoptoken.hpp"
#include "../Tokens/funcseparatortoken.hpp"
#include "../Tokens/functionnametoken.hpp"
#include "../Tokens/lbrackettoken.hpp"
#include "../Tokens/numbertoken.hpp"
#include "../Tokens/rbrackettoken.hpp"
#include "../Tokens/unaryoptoken.hpp"
#include "../Tokens/variabletoken.hpp"
#include "../Predicates/TokenPredicates/tokenpredicate.hpp"
#include "../Predicates/TokenPredicates/binaryoptokenpredicate.hpp"
#include "../Predicates/TokenPredicates/funcseparatortokenpredicate.hpp"
#include "../Predicates/TokenPredicates/functionnametokenpredicate.hpp"
#include "../Predicates/TokenPredicates/lbrackettokenpredicate.hpp"
#include "../Predicates/TokenPredicates/rbrackettokenpredicate.hpp"
#include "../Predicates/TokenPredicates/numbertokenpredicate.hpp"
#include "../Predicates/TokenPredicates/unaryoptokenpredicate.hpp"
#include "../Predicates/TokenPredicates/variabletokenpredicate.hpp"
#include "../Predicates/TokenPredicates/disjunctiontokenpredicate.hpp"
#include "../tables.hpp"

#include <stdexcept>

#include <QString>
#include <QStack>

class MathGrammarScanner : public EmptyTokenVisitor
{
public:
    MathGrammarScanner();
    virtual ~MathGrammarScanner();

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

#endif // MATHGRAMMARSCANNER_HPP
