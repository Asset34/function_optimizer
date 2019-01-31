#include "numberleaf.hpp"

NumberLeaf::NumberLeaf(double value)
    :m_value(value)
{
}

double NumberLeaf::evaluate(const Values &values) const
{
    return m_value;
}
