#ifndef MINUSNODE_HPP
#define MINUSNODE_HPP

#include "binaryoperationnode.hpp"

class MinusNode : public BinaryOperationNode
{
public:
    MinusNode(ExpNode *operand1, ExpNode *operand2);
    virtual double evaluate(const Values &values) const;

};

#endif // MINUSNODE_HPP
