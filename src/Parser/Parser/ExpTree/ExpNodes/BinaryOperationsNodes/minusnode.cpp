#include "minusnode.hpp"

MinusNode::MinusNode(ExpNode *operand1, ExpNode *operand2)
    : BinaryOperationNode(operand1, operand2)
{
}

MinusNode::~MinusNode()
{
}

double MinusNode::evaluate(const Values &values) const
{
    return m_operand1->evaluate(values) - m_operand2->evaluate(values);
}
