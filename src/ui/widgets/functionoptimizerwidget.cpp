#include "functionoptimizerwidget.hpp"

#include <QVBoxLayout>
#include <QPushButton>

#include <ui/boxes/functioninputbox.hpp>

#include <algorithms/geneticalgorithm.hpp>

#include "optimizationalgorithmwidget.hpp"
#include "optimizationresultwidget.hpp"

FunctionOptimizerWidget::FunctionOptimizerWidget(QWidget *parent)
    : QWidget(parent)
{
    m_functionInputBox = new FunctionInputBox;
    m_functionInputBox->addExpression("x^2 + y^2 + 10"); // (0, 0)
    m_functionInputBox->addExpression("(x - 5)^2 + (y + 3)^2 - 5"); // (5, -3)
    m_functionInputBox->addExpression("2*x^2 + 3*exp(-x)"); // (0.469150)
    m_functionInputBox->addExpression("2*x^2 - exp(x)"); // (0.357403)
    m_functionInputBox->addExpression("(10*x^3 + 3*x^2 + x + 5)^2"); // (-0.859902)
    m_functionInputBox->addExpression("3*x^2 + 12/x^3 - 5"); // (1.430969)
    m_functionInputBox->addExpression("x1^2 + 3*x2^2 + 2*x1*x2"); // (0.2558, -0.1163)
    m_functionInputBox->addExpression("100*(x2 - x1^2)^2 + (1 - x1)^2"); // (-0.3413, 0.13172)
    m_functionInputBox->addExpression("-12*x2 + 4*x1^2 + 4*x2^2 - 4*x1*x2"); // (0.5, 1)
    m_functionInputBox->addExpression("(x1 - 2)^4 + (x1 - 2*x2)^2"); // (3.13, 3)
    m_functionInputBox->addExpression("4*(x1 - 5)^2 + (x2 - 6)^2"); // (5, 9)
    m_functionInputBox->addExpression("2x1^3 + 4*x1*x2^3 - 10*x1*x2 + x2^2"); // (-2.938, 4.4479)
//    m_functionInputBox->addExpression(""); // (, )

    m_resultWidget = new OptimizationResultWidget;

    m_algorithmWidget = new OptimizationAlgorithmWidget;
    m_algorithmWidget->addAlgorithm(std::unique_ptr<OptimizationAlgorithm>(new GeneticAlgorithm));

    m_optimizeButton = new QPushButton("Optimize");

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_functionInputBox);
    m_layout->addWidget(m_algorithmWidget);
    m_layout->addWidget(m_resultWidget);
    m_layout->addWidget(m_optimizeButton);

    setLayout(m_layout);

    connect(
        m_optimizeButton,
        &QPushButton::clicked,
        this,
        &FunctionOptimizerWidget::optimize
        );
}

void FunctionOptimizerWidget::optimize()
{
    emit statusChanged("Solving...");

    Function function = m_functionInputBox->parseExpression();
    OptimizationResult result = m_algorithmWidget->execute(function);
    m_resultWidget->setResult(result);

    emit statusChanged("Success");
}
