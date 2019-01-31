#ifndef EXPONENTNODE_HPP
#define EXPONENTNODE_HPP

#include "../unaryoperationnode.hpp"

class ExponentNode : public UnaryOperationNode
{
public:
    explicit ExponentNode(ExpNode *operand);
    virtual double evaluate(const Values &values) const;

};

#endif // EXPONENTNODE_HPP
