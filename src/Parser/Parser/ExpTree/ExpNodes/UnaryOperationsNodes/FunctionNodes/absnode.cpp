#include "absnode.hpp"

AbsNode::AbsNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

AbsNode::~AbsNode()
{
}

double AbsNode::evaluate(const Values &values) const
{
    return qAbs(m_operand->evaluate(values));
}
