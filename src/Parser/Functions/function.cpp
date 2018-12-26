#include "function.hpp"

#include <QDebug>

Function::Function()
    :m_exp(""), m_expTree(nullptr)
{
}

Function::Function(const QString &exp, ExpNode *expTree, QVector<QString> variables)
    :m_exp(exp), m_expTree(expTree), m_variables(variables)
{
}

Function::~Function()
{
    delete m_expTree;
}

double Function::operator()(const Vector &vec) const
{
    if (vec.getSize() != m_variables.size()) {
        throw std::invalid_argument("Incorrect number of the arguments");
    }

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
