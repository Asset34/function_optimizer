#ifndef TGNODE_HPP
#define TGNODE_HPP

#include "../unaryoperationnode.hpp"

#include <QtMath>

class TgNode : public UnaryOperationNode
{
public:
    TgNode(ExpNode *operand);

    virtual ~TgNode();
    virtual double evaluate(const Values &values) const;
};

#endif // TGNODE_HPP
