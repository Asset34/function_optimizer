#include "exponentnode.hpp"

ExponentNode::ExponentNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

ExponentNode::~ExponentNode()
{
}

double ExponentNode::evaluate(const Values &values) const
{
    return qExp(m_operand->evaluate(values));
}
