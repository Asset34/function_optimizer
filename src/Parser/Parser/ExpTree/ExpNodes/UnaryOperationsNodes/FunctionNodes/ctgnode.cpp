#include "Ctgnode.hpp"

CtgNode::CtgNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

CtgNode::~CtgNode()
{
}

double CtgNode::evaluate(const Values &values) const
{
    return qAtan(m_operand->evaluate(values));
}
