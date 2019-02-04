#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include <Core/ExpTree/ExpNodes/expnode.hpp>
#include <Utility/vector.hpp>

#include <QString>
#include <QVector>

#include <memory>

class Function
{
public:
    Function(
        const QString &exp,
        std::unique_ptr<ExpNode> expTree,
        const QVector<QString> &variables
        );

    double operator()(const std::vector<double> &vec) const;
    double operator()(const Vector &vec) const;

    int getSize() const;
    const QVector<QString> &getVariables() const;
    const QString &getExp() const;

private:
    QString m_exp;
    std::unique_ptr<ExpNode> m_expTree;
    QVector<QString> m_variables;

};

#endif // FUNCTION_HPP
