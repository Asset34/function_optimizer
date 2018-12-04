#include "powernode.hpp"

PowerNode::PowerNode(ExpNode *operand1, ExpNode *operand2)
    : BinaryOperationNode(operand1, operand2)
{
}

PowerNode::~PowerNode()
{
}

double PowerNode::evaluate(const Values &values) const
{
    return qPow(m_operand1->evaluate(values), m_operand2->evaluate(values));
}
