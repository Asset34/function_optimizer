#include "variableleaf.hpp"

VariableLeaf::VariableLeaf(const QString name)
    :m_name(name)
{
}

VariableLeaf::~VariableLeaf()
{
}

double VariableLeaf::evaluate(const Values &values) const
{
    return values.getValue(m_name);
}
