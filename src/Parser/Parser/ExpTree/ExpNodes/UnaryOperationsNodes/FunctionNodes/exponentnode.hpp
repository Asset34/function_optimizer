#ifndef EXPONENTNODE_HPP
#define EXPONENTNODE_HPP

#include "../unaryoperationnode.hpp"

#include <QtMath>

class ExponentNode : public UnaryOperationNode
{
public:
    ExponentNode(ExpNode *operand);

    virtual ~ExponentNode();
    virtual double evaluate(const Values &values) const;
};

#endif // EXPONENTNODE_HPP
