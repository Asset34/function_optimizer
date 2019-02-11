#ifndef CTGNODE_HPP
#define CTGNODE_HPP

#include "../unaryoperationnode.hpp"

class CtgNode : public UnaryOperationNode
{
public:
    explicit CtgNode(ExpNode *operand);
    virtual double evaluate(const Values &values) const;

};

#endif // CTGNODE_HPP
