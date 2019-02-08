#include "iterationwidget.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

#include <ui/boxes/iterationbox.hpp>

IterationWidget::IterationWidget(int current, int max, QWidget *parent)
    : QWidget(parent)
{
    m_iterationBox = new IterationBox(current, max);

    m_nextButton = new QPushButton("Next");
    m_nextButton->setFixedWidth(50);
    m_nextButton->setFixedHeight(20);
    m_nextButton->setFont(QFont("Times", 8));

    m_prevButton = new QPushButton("Prev");
    m_prevButton->setFixedWidth(50);
    m_prevButton->setFixedHeight(20);
    m_prevButton->setFont(QFont("Times", 8));

    m_buttonsLayout = new QHBoxLayout;
    m_buttonsLayout->setContentsMargins(0, 0, 0, 0);
    m_buttonsLayout->addStretch();
    m_buttonsLayout->addWidget(m_prevButton);
    m_buttonsLayout->addWidget(m_nextButton);
    m_buttonsLayout->addStretch();

    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addStretch();
    m_mainLayout->addWidget(m_iterationBox);
    m_mainLayout->addLayout(m_buttonsLayout);
    m_mainLayout->addStretch();

    setLayout(m_mainLayout);

    connect(
        m_iterationBox,
        &IterationBox::currentIterationChanged,
        this,
        &IterationWidget::currentIterationChanged
        );
    connect(
        m_iterationBox,
        &IterationBox::maxIterationChanged,
        this,
        &IterationWidget::maxIterationChanged
        );
    connect(m_nextButton, &QPushButton::clicked, this, &IterationWidget::next);
    connect(m_prevButton, &QPushButton::clicked, this, &IterationWidget::prev);
}

int IterationWidget::getCurrent() const
{
    return m_iterationBox->getCurrent();
}

int IterationWidget::getMax() const
{
    return m_iterationBox->getMax();
}

void IterationWidget::setCurrent(int it)
{
    m_iterationBox->setCurrent(it);
}

void IterationWidget::setMax(int max)
{
    m_iterationBox->setMax(max);
}

void IterationWidget::next()
{
    m_iterationBox->next();
}

void IterationWidget::prev()
{
    m_iterationBox->prev();
}
