#ifndef LOGNODE_HPP
#define LOGNODE_HPP

#include "../binaryoperationnode.hpp"

class LogNode : public BinaryOperationNode
{
public:
    LogNode(ExpNode *operand1, ExpNode *operand2);
    virtual double evaluate(const Values &values) const;

};

#endif // PLUSNODE_HPP
