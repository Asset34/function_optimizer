#include "absnode.hpp"

#include <QtGlobal>

AbsNode::AbsNode(ExpNode *operand)
    :UnaryOperationNode(operand)
{
}

double AbsNode::evaluate(const Values &values) const
{
    return qAbs(m_operand->evaluate(values));
}
