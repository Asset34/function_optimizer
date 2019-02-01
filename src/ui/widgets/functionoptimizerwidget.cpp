#include "functionoptimizerwidget.hpp"

#include <QVBoxLayout>
#include <QPushButton>

#include <ui/boxes/functioninputbox.hpp>

#include "optimizationalgorithmwidget.hpp"
#include "optimizationresultwidget.hpp"

FunctionOptimizerWidget::FunctionOptimizerWidget(QWidget *parent)
    : QWidget(parent)
{
    m_functionInputBox = new FunctionInputBox;
    m_algorithmWidget = new OptimizationAlgorithmWidget;
    m_resultWidget = new OptimizationResultWidget;

    m_optimizeButton = new QPushButton("Optimize");

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_functionInputBox);
    m_layout->addWidget(m_algorithmWidget);
    m_layout->addWidget(m_resultWidget);
    m_layout->addWidget(m_optimizeButton);

    setLayout(m_layout);
}

void FunctionOptimizerWidget::optimize()
{
    emit statusChanged("Solving...");

    Function function = m_functionInputBox->parseExpression();
    OptimizationResult result = m_algorithmWidget->execute(function);
    m_resultWidget->setResult(result);

    emit statusChanged("Success");
}
