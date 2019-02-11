#include "lognode.hpp"

#include <QtMath>

LogNode::LogNode(ExpNode *operand1, ExpNode *operand2)
    : BinaryOperationNode(operand1, operand2)
{
}

double LogNode::evaluate(const Values &values) const
{
    return qLn(m_operand1->evaluate(values))/qLn(m_operand2->evaluate(values));
}
