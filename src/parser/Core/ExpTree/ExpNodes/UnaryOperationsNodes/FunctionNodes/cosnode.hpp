#ifndef COSNODE_HPP
#define COSNODE_HPP

#include "../unaryoperationnode.hpp"

class CosNode : public UnaryOperationNode
{
public:
    explicit CosNode(ExpNode *operand);
    virtual double evaluate(const Values &values) const;

};

#endif // COSNODE_HPP
