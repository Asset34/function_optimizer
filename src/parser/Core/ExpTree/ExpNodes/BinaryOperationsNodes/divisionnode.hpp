#ifndef DIVISIONNODE_HPP
#define DIVISIONNODE_HPP

#include "binaryoperationnode.hpp"

class DivisionNode : public BinaryOperationNode
{
public:
    DivisionNode(ExpNode *operand1, ExpNode *operand2);
    virtual double evaluate(const Values &values) const;

};

#endif // DIVISIONNODE_HPP
