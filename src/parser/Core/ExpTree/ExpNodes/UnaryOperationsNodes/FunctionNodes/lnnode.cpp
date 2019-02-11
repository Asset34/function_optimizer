#include "lnnode.hpp"

#include <QtMath>

LnNode::LnNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

double LnNode::evaluate(const Values &values) const
{
    return qLn(m_operand->evaluate(values));
}
