#ifndef SQRTNODE_HPP
#define SQRTNODE_HPP

#include "../unaryoperationnode.hpp"

class SqrtNode : public UnaryOperationNode
{
public:
    explicit SqrtNode(ExpNode *operand);
    virtual double evaluate(const Values &values) const;

};

#endif // SQRTNODE_HPP
