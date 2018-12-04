#ifndef SQRTNODE_HPP
#define SQRTNODE_HPP

#include "../unaryoperationnode.hpp"

#include <QtMath>

class SqrtNode : public UnaryOperationNode
{
public:
    SqrtNode(ExpNode *operand);

    virtual ~SqrtNode();
    virtual double evaluate(const Values &values) const;
};

#endif // SQRTNODE_HPP
