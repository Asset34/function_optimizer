#include "optimizationresultwidget.hpp"

#include <QFormLayout>
#include <QLabel>

OptimizationResultWidget::OptimizationResultWidget(QWidget *parent)
    : QWidget(parent)
{
    m_iterationsLabel = new QLabel;
    m_argumentLabel = new QLabel;
    m_valueLabel = new QLabel;

    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Iterations:", m_iterationsLabel);
    m_layout->addRow("Argument:", m_argumentLabel);
    m_layout->addRow("Value:", m_valueLabel);

    setLayout(m_layout);
}

void OptimizationResultWidget::setResult(const OptimizationResult &result)
{
    m_iterationsLabel->setText(QString::number(result.iterations));
    m_argumentLabel->setText(QString::fromStdString(result.argument.toString()));
    m_valueLabel->setText(QString::number(result.value));
}
