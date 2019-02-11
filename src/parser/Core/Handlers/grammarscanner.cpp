#include "grammarscanner.hpp"

#include <Core/Tokens/numbertoken.hpp>
#include <Core/Tokens/variabletoken.hpp>
#include <Core/Tokens/functionnametoken.hpp>
#include <Core/Tokens/lbrackettoken.hpp>
#include <Core/Tokens/rbrackettoken.hpp>
#include <Core/Tokens/funcseparatortoken.hpp>
#include <Core/Tokens/unaryoptoken.hpp>
#include <Core/Tokens/binaryoptoken.hpp>

#include <Core/Predicates/TokenPredicates/tokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/binaryoptokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/funcseparatortokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/functionnametokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/lbrackettokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/rbrackettokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/numbertokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/unaryoptokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/variabletokenpredicate.hpp>
#include <Core/Predicates/TokenPredicates/disjunctiontokenpredicate.hpp>

#include <Core/tables.hpp>

GrammarScanner::GrammarScanner()
{
    /* Build edges of FSM */

    // MathExp
    m_edgesMathExp.add(new VariableTokenPredicate());
    m_edgesMathExp.add(new NumberTokenPredicate());
    m_edgesMathExp.add(new FunctionNameTokenPredicate());
    m_edgesMathExp.add(new LBracketTokenPredicate());
    m_edgesMathExp.add(new UnaryOpTokenPredicate());

    // Variable
    m_edgesVariable.add(new BinaryOpTokenPredicate());
    m_edgesVariable.add(new RBracketTokenPredicate());
    m_edgesVariable.add(new FuncSeparatorTokenPredicate());

    // UnaryOp
    m_edgesUnaryOp.add(new VariableTokenPredicate());
    m_edgesUnaryOp.add(new NumberTokenPredicate());
    m_edgesUnaryOp.add(new FunctionNameTokenPredicate());
    m_edgesUnaryOp.add(new LBracketTokenPredicate());

    // RBracket
    m_edgesRbacket.add(new BinaryOpTokenPredicate());
    m_edgesRbacket.add(new RBracketTokenPredicate());
    m_edgesRbacket.add(new FuncSeparatorTokenPredicate());

    // Number
    m_edgesNumber.add(new BinaryOpTokenPredicate());
    m_edgesNumber.add(new RBracketTokenPredicate());
    m_edgesNumber.add(new FuncSeparatorTokenPredicate());

    // BinaryOp
    m_edgesBinaryOp.add(new VariableTokenPredicate());
    m_edgesBinaryOp.add(new NumberTokenPredicate());
    m_edgesBinaryOp.add(new FunctionNameTokenPredicate());
    m_edgesBinaryOp.add(new LBracketTokenPredicate());
    m_edgesBinaryOp.add(new UnaryOpTokenPredicate());

    // LBracket
    m_edgesLbracket.add(new VariableTokenPredicate());
    m_edgesLbracket.add(new NumberTokenPredicate());
    m_edgesLbracket.add(new FunctionNameTokenPredicate());
    m_edgesLbracket.add(new LBracketTokenPredicate());
    m_edgesLbracket.add(new UnaryOpTokenPredicate());

    // FuncSeparator
    m_edgesFuncSeparator.add(new VariableTokenPredicate());
    m_edgesFuncSeparator.add(new NumberTokenPredicate());
    m_edgesFuncSeparator.add(new FunctionNameTokenPredicate());
    m_edgesFuncSeparator.add(new LBracketTokenPredicate());
    m_edgesFuncSeparator.add(new UnaryOpTokenPredicate());

    // FunctionName
    m_edgesFunctionName.add(new LBracketTokenPredicate());

    /* Set start edges */
    m_edgesCurrent = &m_edgesMathExp;
}

void GrammarScanner::Scann(QList<Token*> tokens)
{
    // Reset handler
    reset();

    // Handle tokens
    QListIterator<Token*> it(tokens);
    while (it.hasNext()) {
        it.next()->accept(*this);
    }

    compareBracketCounters();
}

void GrammarScanner::visit(NumberToken *t)
{
    if (m_edgesCurrent->execute(*t)) {
        m_edgesCurrent = &m_edgesNumber;
    }
    else {
        throwException(t);
    }
}

void GrammarScanner::visit(VariableToken *t)
{
    if (m_edgesCurrent->execute(*t)) {
        m_edgesCurrent = &m_edgesVariable;
    }
    else {
        throwException(t);
    }
}

void GrammarScanner::visit(FunctionNameToken *t)
{
    if (m_edgesCurrent->execute(*t)) {
        m_edgesCurrent = &m_edgesFunctionName;
    }
    else {
        throwException(t);
    }
}

void GrammarScanner::visit(LBracketToken *t)
{
    if (m_edgesCurrent->execute(*t)) {
        m_edgesCurrent = &m_edgesLbracket;
    }
    else {
        throwException(t);
    }
}

void GrammarScanner::visit(RBracketToken *t)
{
    if (m_edgesCurrent->execute(*t)) {
        m_edgesCurrent = &m_edgesRbacket;
    }
    else {
        throwException(t);
    }
}

void GrammarScanner::visit(FuncSeparatorToken *t)
{
    if (m_edgesCurrent->execute(*t)) {
        m_edgesCurrent = &m_edgesFuncSeparator;
    }
    else {
        throwException(t);
    }
}

void GrammarScanner::visit(UnaryOpToken *t)
{
    if (m_edgesCurrent->execute(*t)) {
        m_edgesCurrent = &m_edgesUnaryOp;
    }
    else {
        throwException(t);
    }
}

void GrammarScanner::visit(BinaryOpToken *t)
{
    if (m_edgesCurrent->execute(*t)) {
        m_edgesCurrent = &m_edgesBinaryOp;
    }
    else {
        throwException(t);
    }
}

void GrammarScanner::reset()
{
    // Reset function stack
    m_functions.clear();

    // Reset counters
    m_argumentsCounters.clear();
    m_maxArguments.clear();;
    m_bracketValues.clear();
    m_bracketCounter = 0;

    // Reset start edge
    m_edgesCurrent = &m_edgesMathExp;
}

void GrammarScanner::throwException(Token *lastToken)
{
    throw std::logic_error("Invalid expression (Last token: "  +
                           lastToken->getValue().toStdString() +
                           " )");
}

void GrammarScanner::compareBracketCounters()
{
    if (m_bracketCounter < 0) {
        throw std::logic_error("Missing /'(/'");
    }
    else if (m_bracketCounter > 0) {
        throw std::logic_error("Missing /'(/'");
    }
}

void GrammarScanner::functionEnter(FunctionNameToken *t)
{
    m_functions.push(t->getValue());
    m_argumentsCounters.push(0);
    m_maxArguments.push(Tables::functionArgNumberTable[t->getValue()]);
    m_bracketValues.push(m_bracketCounter);
}

void GrammarScanner::functionArgLeave()
{
    m_argumentsCounters.top() += 1;
}

void GrammarScanner::functionLeave()
{
    int args1 = m_maxArguments.pop();
    int args2 = m_argumentsCounters.pop() + 1;

    QString funcName(m_functions.pop());

    m_bracketValues.pop();

    if (args2 < args1) {
        throw std::logic_error("Too few arguments in /'" + funcName.toStdString() + "/'");
    }
    else if (args2 > args1) {
        throw std::logic_error("Too many arguments in /'" + funcName.toStdString() + "/'");
    }
}
