#ifndef UNARYMINUSNODE_HPP
#define UNARYMINUSNODE_HPP

#include "unaryoperationnode.hpp"

class UnaryMinusNode : public UnaryOperationNode
{
public:
    explicit UnaryMinusNode(ExpNode *operand);
    virtual double evaluate(const Values &values) const;

};

#endif // UNARYMINUSNODE_HPP
