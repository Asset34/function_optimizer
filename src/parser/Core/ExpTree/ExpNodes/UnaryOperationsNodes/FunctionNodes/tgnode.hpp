#ifndef TGNODE_HPP
#define TGNODE_HPP

#include "../unaryoperationnode.hpp"

class TgNode : public UnaryOperationNode
{
public:
    explicit TgNode(ExpNode *operand);
    virtual double evaluate(const Values &values) const;

};

#endif // TGNODE_HPP
