#include "astcreator.hpp"

#include <Core/Tokens/numbertoken.hpp>
#include <Core/Tokens/variabletoken.hpp>
#include <Core/Tokens/functionnametoken.hpp>
#include <Core/Tokens/lbrackettoken.hpp>
#include <Core/Tokens/rbrackettoken.hpp>
#include <Core/Tokens/funcseparatortoken.hpp>
#include <Core/Tokens/unaryoptoken.hpp>
#include <Core/Tokens/binaryoptoken.hpp>

#include <Core/ExpTree/ExpNodes/ExpLeafes/numberleaf.hpp>
#include <Core/ExpTree/ExpNodes/ExpLeafes/variableleaf.hpp>
#include <Core/tables.hpp>

ExpNode *AstCreator::create(const QList<Token *> tokens)
{
    // Reset handler
    reset();

    // Handle tokens
    QListIterator<Token*> it(tokens);
    while (it.hasNext()) {
        it.next()->accept(*this);
    }

    return m_expTree.pop();
}

const QList<QString> &AstCreator::getVariablesList() const
{
    return m_variables;
}

AstCreator::~AstCreator()
{
}

void AstCreator::visit(NumberToken *t)
{
    double number = t->getValue().toDouble();
    m_expTree.push(new NumberLeaf(number));
}

void AstCreator::visit(VariableToken *t)
{
    QString variable = t->getValue();

    if (!m_variables.contains(variable)) {
        m_variables.append(variable);
    }

    m_expTree.push(new VariableLeaf(variable));
}

void AstCreator::visit(FunctionNameToken *t)
{
    QString funcName = t->getValue();

    // Get number of nessessary arguments
    int n = Tables::functionArgNumberTable[funcName];

    // Pop arguments
    QVector<ExpNode*> arguments;
    for (int i = 0; i < n; i++) {
        arguments.append(m_expTree.pop());
    }

    m_expTree.push(Tables::functionNodesTable[funcName](arguments));
}

void AstCreator::visit(UnaryOpToken *t)
{
    // Get operation
    QChar op = t->getValue()[0];

    // Get operand
    ExpNode *operand = m_expTree.top();

    // Get ast-node of the operation
    ExpNode *operation = Tables::unaryOpNodesTable[op](operand);

    if (operation) {
        m_expTree.pop();
        m_expTree.push(operation);
    }
}

void AstCreator::visit(BinaryOpToken *t)
{
    // Get operation
    QChar op = t->getValue()[0];

    // Get operands
    ExpNode *operand2 = m_expTree.pop();
    ExpNode *operand1 = m_expTree.pop();

    m_expTree.push(Tables::binaryOpNodesTable[op](operand1, operand2));
}

void AstCreator::reset()
{
    m_expTree.clear();
    m_variables.clear();
}
