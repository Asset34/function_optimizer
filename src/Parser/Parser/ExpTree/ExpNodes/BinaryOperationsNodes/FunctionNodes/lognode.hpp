#ifndef LOGNODE_HPP
#define LOGNODE_HPP

#include "../binaryoperationnode.hpp"

#include <QtMath>

class LogNode : public BinaryOperationNode
{
public:
    LogNode(ExpNode *operand1, ExpNode *operand2);

    virtual ~LogNode();
    virtual double evaluate(const Values &values) const;
};

#endif // PLUSNODE_HPP
