#ifndef SINNODE_HPP
#define SINNODE_HPP

#include "../unaryoperationnode.hpp"

#include <QtMath>

class SinNode : public UnaryOperationNode
{
public:
    SinNode(ExpNode *operand);

    virtual ~SinNode();
    virtual double evaluate(const Values &values) const;
};

#endif // SINNODE_HPP
