#ifndef VALUES_HPP
#define VALUES_HPP

#include <QString>
#include <QMap>

class Values
{
public:
    double getValue(const QString &name) const;
    void assign(const QString &name, double value);

private:
    QMap<QString, double> m_variables;
};

#endif // VALUES_HPP
