#include "numberleaf.hpp"

NumberLeaf::NumberLeaf(double value)
    :m_value(value)
{
}

NumberLeaf::~NumberLeaf()
{
}

double NumberLeaf::evaluate(const Values &values) const
{
    return m_value;
}
