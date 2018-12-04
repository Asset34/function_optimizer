#ifndef ABSNODE_HPP
#define ABSNODE_HPP

#include "../unaryoperationnode.hpp"

#include <QtGlobal>

class AbsNode : public UnaryOperationNode
{
public:
    AbsNode(ExpNode *operand);

    virtual ~AbsNode();
    virtual double evaluate(const Values &values) const;
};

#endif // ABSNODE_HPP
