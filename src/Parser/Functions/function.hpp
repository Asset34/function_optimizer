#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "../Parser/ExpTree/ExpNodes/expnode.hpp"
#include "../Entities/vector.hpp"

#include <stdexcept>

#include <QString>
#include <QVector>

class Function
{
public:
    Function();
    Function(const QString &exp, ExpNode *expTree, QVector<QString> variables);
    virtual ~Function();

    virtual double operator()(const Vector &vec) const;
    virtual double operator()(const std::vector<double> &vec) const;

    int getSize() const;
    const QVector<QString> &getVariables() const;
    const QString &getExp() const;

private:
    QString m_exp;
    ExpNode *m_expTree;
    QVector<QString> m_variables;
};

#endif // FUNCTION_HPP
