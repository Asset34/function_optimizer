#include "function.hpp"

Function::Function(
        const QString &exp,
        std::unique_ptr<ExpNode> expTree,
        const QVector<QString> &variables
        )
    :m_exp(exp), m_expTree(std::move(expTree)), m_variables(variables)
{
}

Function::Function(Function &&other)
    : m_exp(other.m_exp),
      m_expTree(std::move(other.m_expTree)),
      m_variables(other.m_variables)
{
    other.m_exp.clear();
    other.m_variables.clear();
}

Function &Function::operator=(Function &&other)
{
    m_exp = other.m_exp;
    other.m_exp.clear();

    m_expTree = std::move(other.m_expTree);

    m_variables = other.m_variables;
    other.m_variables.clear();
}

double Function::operator()(const std::vector<double> &vec) const
{
    return this->operator()(Vector(vec));
}

double Function::operator()(const Vector &vec) const
{
    Values values;

    for (int i = 0; i < vec.getSize(); i++) {
        values.assign(m_variables[i], vec[i]);
    }

    return m_expTree->evaluate(values);
}

int Function::getSize() const
{
    return m_variables.size();
}

const QVector<QString> &Function::getVariables() const
{
    return m_variables;
}

const QString &Function::getExp() const
{
    return m_exp;
}
