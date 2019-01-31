#include "tgnode.hpp"

#include <QtMath>

TgNode::TgNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

double TgNode::evaluate(const Values &values) const
{
    return qTan(m_operand->evaluate(values));
}
