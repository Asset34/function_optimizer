#ifndef COSNODE_HPP
#define COSNODE_HPP

#include "../unaryoperationnode.hpp"

#include <QtMath>

class CosNode : public UnaryOperationNode
{
public:
    CosNode(ExpNode *operand);

    virtual ~CosNode();
    virtual double evaluate(const Values &values) const;
};

#endif // COSNODE_HPP
