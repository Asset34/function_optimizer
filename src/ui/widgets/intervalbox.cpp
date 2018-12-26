#include "intervalbox.hpp"

#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>

#include <QDoubleValidator>

IntervalBox::IntervalBox(const QString &name, double left, double right, QWidget *parent)
    : QWidget(parent)
{
    // Create labels
    m_nameLabel = new QLabel(name);
    m_separatorLabel = new QLabel(" - ");

    // Create validator
    QDoubleValidator *validator = new QDoubleValidator(-1e9, 1e9, 10, this);

    // Create line editors
    m_leftLineEdit = new QLineEdit(QString::number(left));
    m_leftLineEdit->setValidator(validator);
    m_rightLineEdit = new QLineEdit(QString::number(right));
    m_rightLineEdit->setValidator(validator);

    // Create layout
    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_nameLabel);
    m_layout->addWidget(m_leftLineEdit);
    m_layout->addWidget(m_separatorLabel);
    m_layout->addWidget(m_rightLineEdit);

    // Create widget
    setLayout(m_layout);
}

Interval IntervalBox::getInternal() const
{
    double left = m_leftLineEdit->text().toDouble();
    double right = m_rightLineEdit->text().toDouble();

    return Interval(left, right);
}
