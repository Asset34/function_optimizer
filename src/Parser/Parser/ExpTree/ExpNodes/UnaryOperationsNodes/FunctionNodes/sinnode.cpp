#include "sinnode.hpp"

SinNode::SinNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

SinNode::~SinNode()
{
}

double SinNode::evaluate(const Values &values) const
{
    return qSin(m_operand->evaluate(values));
}
