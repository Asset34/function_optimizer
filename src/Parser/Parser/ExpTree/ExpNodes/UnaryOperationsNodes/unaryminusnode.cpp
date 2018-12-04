#include "unaryminusnode.hpp"

UnaryMinusNode::UnaryMinusNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

UnaryMinusNode::~UnaryMinusNode()
{
}

double UnaryMinusNode::evaluate(const Values &values) const
{
    return -m_operand->evaluate(values);
}
