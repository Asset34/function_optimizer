#include "sqrtnode.hpp"

#include <QtMath>

SqrtNode::SqrtNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

double SqrtNode::evaluate(const Values &values) const
{
    return qSqrt(m_operand->evaluate(values));
}
