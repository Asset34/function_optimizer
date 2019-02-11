#include "exponentnode.hpp"

#include <QtMath>
ExponentNode::ExponentNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

double ExponentNode::evaluate(const Values &values) const
{
    return qExp(m_operand->evaluate(values));
}
