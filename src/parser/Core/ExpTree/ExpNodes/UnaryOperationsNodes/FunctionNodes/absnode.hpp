#ifndef ABSNODE_HPP
#define ABSNODE_HPP

#include "../unaryoperationnode.hpp"

class AbsNode : public UnaryOperationNode
{
public:
    explicit AbsNode(ExpNode *operand);
    virtual double evaluate(const Values &values) const;

};

#endif // ABSNODE_HPP
