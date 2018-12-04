#include "lnnode.hpp"

LnNode::LnNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

LnNode::~LnNode()
{
}

double LnNode::evaluate(const Values &values) const
{
    return qLn(m_operand->evaluate(values));
}
