#include "sqrtnode.hpp"

SqrtNode::SqrtNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

SqrtNode::~SqrtNode()
{
}

double SqrtNode::evaluate(const Values &values) const
{
    return qSqrt(m_operand->evaluate(values));
}
