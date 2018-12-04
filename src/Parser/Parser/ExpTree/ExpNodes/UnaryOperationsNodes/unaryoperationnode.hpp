#ifndef UNARYOPERATIONNODE_HPP
#define UNARYOPERATIONNODE_HPP

#include "../expnode.hpp"

class UnaryOperationNode : public ExpNode
{
public:
    UnaryOperationNode(ExpNode *operand);

    virtual ~UnaryOperationNode();

protected:
    ExpNode *m_operand;
};

#endif // UNARYOPERATIONNODE_HPP
