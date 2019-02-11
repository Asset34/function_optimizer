#include "sinnode.hpp"

#include <QtMath>

SinNode::SinNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

double SinNode::evaluate(const Values &values) const
{
    return qSin(m_operand->evaluate(values));
}
