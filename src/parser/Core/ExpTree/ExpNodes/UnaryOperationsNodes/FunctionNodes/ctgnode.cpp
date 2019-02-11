#include "Ctgnode.hpp"

#include <QtMath>

CtgNode::CtgNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

double CtgNode::evaluate(const Values &values) const
{
    return qAtan(m_operand->evaluate(values));
}
