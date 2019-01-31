#ifndef POWERNODE_HPP
#define POWERNODE_HPP

#include "binaryoperationnode.hpp"

class PowerNode : public BinaryOperationNode
{
public:
    PowerNode(ExpNode *operand1, ExpNode *operand2);
    virtual double evaluate(const Values &values) const;

};

#endif // POWERNODE_HPP
