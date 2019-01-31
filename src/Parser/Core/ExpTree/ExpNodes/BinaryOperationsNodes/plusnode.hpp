#ifndef PLUSNODE_HPP
#define PLUSNODE_HPP

#include "binaryoperationnode.hpp"

class PlusNode : public BinaryOperationNode
{
public:
    PlusNode(ExpNode *operand1, ExpNode *operand2);
    virtual double evaluate(const Values &values) const;

};

#endif // PLUSNODE_HPP
