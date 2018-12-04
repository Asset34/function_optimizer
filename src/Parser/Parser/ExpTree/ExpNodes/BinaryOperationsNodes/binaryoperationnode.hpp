#ifndef BINARYOPERATIONNODE_HPP
#define BINARYOPERATIONNODE_HPP

#include "../expnode.hpp"

class BinaryOperationNode : public ExpNode
{
public:
    BinaryOperationNode(ExpNode *operand1, ExpNode *operand2);

    virtual ~BinaryOperationNode();

protected:
    ExpNode *m_operand1;
    ExpNode *m_operand2;
};

#endif // BINARYOPERATIONNODE_HPP
