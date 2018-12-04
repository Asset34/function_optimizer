#ifndef UNARYMINUSNODE_HPP
#define UNARYMINUSNODE_HPP

#include "unaryoperationnode.hpp"

class UnaryMinusNode : public UnaryOperationNode
{
public:
    UnaryMinusNode(ExpNode *operand);

    virtual ~UnaryMinusNode();
    virtual double evaluate(const Values &values) const;
};

#endif // UNARYMINUSNODE_HPP
