#include "tgnode.hpp"

TgNode::TgNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

TgNode::~TgNode()
{
}

double TgNode::evaluate(const Values &values) const
{
    return qTan(m_operand->evaluate(values));
}
