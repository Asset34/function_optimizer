#include "binaryoperationnode.hpp"

BinaryOperationNode::BinaryOperationNode(ExpNode *operand1, ExpNode *operand2)
    :m_operand1(operand1), m_operand2(operand2)
{
}

BinaryOperationNode::~BinaryOperationNode()
{
    delete m_operand1;
    delete m_operand2;
}
