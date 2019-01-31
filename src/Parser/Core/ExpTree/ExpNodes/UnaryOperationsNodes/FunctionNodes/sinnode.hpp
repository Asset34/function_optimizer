#ifndef SINNODE_HPP
#define SINNODE_HPP

#include "../unaryoperationnode.hpp"

class SinNode : public UnaryOperationNode
{
public:
    explicit SinNode(ExpNode *operand);
    virtual double evaluate(const Values &values) const;

};

#endif // SINNODE_HPP
