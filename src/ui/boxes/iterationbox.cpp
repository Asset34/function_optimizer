#include "iterationbox.hpp"

#include <QHBoxLayout>
#include <QSpinBox>
#include <QLabel>

IterationBox::IterationBox(int current, int max, QWidget *parent)
    : QWidget(parent),
      m_current(current),
      m_max(max)
{
    m_curIterationSpinBox = new QSpinBox;
    m_curIterationSpinBox->setValue(current);
    m_curIterationSpinBox->setRange(1, max);
//    m_curIterationLineEdit->setAlignment(Qt::AlignCenter);
//    m_curIterationLineEdit->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    m_separator = new QLabel("/");
    m_maxIterationLabel = new QLabel(QString::number(m_max));

    m_layout = new QHBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addStretch();
    m_layout->addWidget(m_curIterationSpinBox);
    m_layout->addWidget(m_separator);
    m_layout->addWidget(m_maxIterationLabel);
    m_layout->addStretch();

    setLayout(m_layout);

    connect(
        m_curIterationSpinBox,
        static_cast<void (QSpinBox::*)(int)>(&QSpinBox::valueChanged),
        this,
        &IterationBox::currentIterationChanged
        );
}

int IterationBox::getCurrent() const
{
    return m_current;
}

int IterationBox::getMax() const
{
    return m_max;
}

void IterationBox::setCurrent(int it)
{
    if (it > 0 && it <= m_max) {
        m_current = it;
        m_curIterationSpinBox->setValue(m_current);

        emit currentIterationChanged(it);
    }
}

void IterationBox::setMax(int max)
{
    m_max = max;
    m_maxIterationLabel->setText(QString::number(m_max));

    emit maxIterationChanged(max);
}

void IterationBox::first()
{
    setCurrent(1);
}

void IterationBox::last()
{
    setCurrent(m_max);
}

void IterationBox::next()
{
    if (m_current < m_max) {
        setCurrent(m_current + 1);
    }
}

void IterationBox::prev()
{
    if (m_current > 0) {
        setCurrent(m_current - 1);
    }
}
