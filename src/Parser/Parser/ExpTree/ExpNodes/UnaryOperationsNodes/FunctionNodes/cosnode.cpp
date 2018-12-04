#include "cosnode.hpp"

CosNode::CosNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

CosNode::~CosNode()
{
}

double CosNode::evaluate(const Values &values) const
{
    return qCos(m_operand->evaluate(values));
}
