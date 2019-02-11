#include "unaryoperationnode.hpp"

UnaryOperationNode::UnaryOperationNode(ExpNode *operand)
    :m_operand(operand)
{
}

UnaryOperationNode::~UnaryOperationNode()
{
    delete m_operand;
}
