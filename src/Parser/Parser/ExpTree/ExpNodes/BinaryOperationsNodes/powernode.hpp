#ifndef POWERNODE_HPP
#define POWERNODE_HPP

#include "binaryoperationnode.hpp"

#include <QtMath>

class PowerNode : public BinaryOperationNode
{
public:
    PowerNode(ExpNode *operand1, ExpNode *operand2);

    virtual ~PowerNode();
    virtual double evaluate(const Values &values) const;
};

#endif // POWERNODE_HPP
