#include "values.hpp"

double Values::getValue(const QString &name) const
{
    return m_variables[name];
}

void Values::assign(const QString &name, double value)
{
    m_variables.insert(name, value);
}
