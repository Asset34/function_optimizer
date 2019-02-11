#include "rpnconverter.hpp"

#include <Core/Tokens/numbertoken.hpp>
#include <Core/Tokens/variabletoken.hpp>
#include <Core/Tokens/functionnametoken.hpp>
#include <Core/Tokens/lbrackettoken.hpp>
#include <Core/Tokens/rbrackettoken.hpp>
#include <Core/Tokens/funcseparatortoken.hpp>
#include <Core/Tokens/unaryoptoken.hpp>
#include <Core/Tokens/binaryoptoken.hpp>

#include <Utility/utils.hpp>

RpnConverter::~RpnConverter()
{
    reset();
}

QList<Token*> RpnConverter::convert(const QList<Token*> &tokens)
{
    // Reset handler
    reset();

    // Handle tokens
    QListIterator<Token*> it(tokens);
    while (it.hasNext()) {
        it.next()->accept(*this);
    }

    // Pop the rest of the operators in stack
    popRemainOperators();

    return m_resultTokens;
}

void RpnConverter::visit(NumberToken *t)
{
    m_resultTokens.append(t);
}

void RpnConverter::visit(VariableToken *t)
{
    m_resultTokens.append(t);
}

void RpnConverter::visit(LBracketToken *t)
{
    m_operators.push(t);
}

void RpnConverter::visit(FunctionNameToken *t)
{
    m_operators.push(t);
}

void RpnConverter::visit(RBracketToken *t)
{
    // Get operators of subexpression
    QList<Token*> subExpOperators = Utils::moveUntil(m_operators, m_lbracketPr);

    // Add operators to the result(RPN) list
    m_resultTokens.append(subExpOperators);


    // Delete and remove left bracket token
    delete m_operators.top();
    m_operators.pop();

    // Function check
    if (!m_operators.empty() &&
        Utils::check(m_operators, m_functionNamePr)) {
        m_resultTokens.append(m_operators.pop());
    }

    // Delete right bracket token
    delete t;
}

void RpnConverter::visit(FuncSeparatorToken *t)
{
    // Get operators of subexpression
    QList<Token*> subExpOperators = Utils::moveUntil(m_operators, m_lbracketPr);

    // Add operators to the result(RPN) list
    m_resultTokens.append(subExpOperators);

    // Delete token
    delete t;
}

void RpnConverter::visit(UnaryOpToken *t)
{
    m_operators.push(t);
}

void RpnConverter::visit(BinaryOpToken *t)
{
    // Get operators with lower or equal priority
    QList<Token*> lowOperators = Utils::moveWhile(*t, m_operators, m_comparePriorityPr);

    // Add operators to the result(RPN) list
    m_resultTokens.append(lowOperators);

    m_operators.push(t);
}

void RpnConverter::reset()
{
    // Clear containers
    m_operators.clear();
    m_resultTokens.clear();
}

void RpnConverter::popRemainOperators()
{
    while (!m_operators.empty()) {
        m_resultTokens.append(m_operators.pop());
    }
}
