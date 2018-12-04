#ifndef CTGNODE_HPP
#define CTGNODE_HPP

#include "../unaryoperationnode.hpp"

#include <QtMath>

class CtgNode : public UnaryOperationNode
{
public:
    CtgNode(ExpNode *operand);

    virtual ~CtgNode();
    virtual double evaluate(const Values &values) const;
};

#endif // CTGNODE_HPP
