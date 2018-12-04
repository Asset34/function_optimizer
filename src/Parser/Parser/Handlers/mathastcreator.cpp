#include "mathastcreator.hpp"

ExpNode *MathASTCreator::create(const QList<Token *> tokens)
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

const QList<QString> &MathASTCreator::getVariablesList() const
{
    return m_variables;
}

MathASTCreator::~MathASTCreator()
{
}

void MathASTCreator::visit(NumberToken *t)
{
    double number = t->getValue().toDouble();
    m_expTree.push(new NumberLeaf(number));
}

void MathASTCreator::visit(VariableToken *t)
{
    QString variable = t->getValue();

    if (!m_variables.contains(variable)) {
        m_variables.append(variable);
    }

    m_expTree.push(new VariableLeaf(variable));
}

void MathASTCreator::visit(FunctionNameToken *t)
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

void MathASTCreator::visit(UnaryOpToken *t)
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

void MathASTCreator::visit(BinaryOpToken *t)
{
    // Get operation
    QChar op = t->getValue()[0];

    // Get operands
    ExpNode *operand2 = m_expTree.pop();
    ExpNode *operand1 = m_expTree.pop();

    m_expTree.push(Tables::binaryOpNodesTable[op](operand1, operand2));
}

void MathASTCreator::reset()
{
    m_expTree.clear();
    m_variables.clear();
}
