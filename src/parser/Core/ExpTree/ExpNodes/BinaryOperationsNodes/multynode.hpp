#ifndef MULTYNODE_HPP
#define MULTYNODE_HPP

#include "binaryoperationnode.hpp"

class MultyNode : public BinaryOperationNode
{
public:
    MultyNode(ExpNode *operand1, ExpNode *operand2);
    virtual double evaluate(const Values &values) const;

};

#endif // MULTYNODE_HPP
