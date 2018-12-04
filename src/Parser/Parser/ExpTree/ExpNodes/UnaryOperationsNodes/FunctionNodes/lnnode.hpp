#ifndef LNNODE_HPP
#define LNNODE_HPP

#include "../unaryoperationnode.hpp"

#include <QtMath>

class LnNode : public UnaryOperationNode
{
public:
    LnNode(ExpNode *operand);

    virtual ~LnNode();
    virtual double evaluate(const Values &values) const;
};

#endif // LNNODE_HPP
