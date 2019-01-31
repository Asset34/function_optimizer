#include "cosnode.hpp"

#include <QtMath>

CosNode::CosNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

double CosNode::evaluate(const Values &values) const
{
    return qCos(m_operand->evaluate(values));
}
