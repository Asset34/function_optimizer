#ifndef VARIABLELEAF_HPP
#define VARIABLELEAF_HPP

#include "../expnode.hpp"

#include <QString>

class VariableLeaf : public ExpNode
{
public:
    VariableLeaf(const QString name);

    virtual ~VariableLeaf();
    virtual double evaluate(const Values &values) const;

private:
    QString m_name;
};

#endif // VARIABLELEAF_HPP
