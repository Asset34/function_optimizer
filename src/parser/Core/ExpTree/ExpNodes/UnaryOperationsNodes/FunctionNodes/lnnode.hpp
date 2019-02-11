#ifndef LNNODE_HPP
#define LNNODE_HPP

#include "../unaryoperationnode.hpp"

class LnNode : public UnaryOperationNode
{
public:
    explicit LnNode(ExpNode *operand);
    virtual double evaluate(const Values &values) const;

};

#endif // LNNODE_HPP
