#include "functionoptimizerwidget.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFrame>

#include <ui/boxes/functioninputbox.hpp>

#include <algorithms/genetic_algorithm/geneticalgorithm.hpp>
#include <algorithms/particleswarm.hpp>

#include "optimizationalgorithmwidget.hpp"
#include "optimizationresultwidget.hpp"
#include "algorithmvisualizer.hpp"

FunctionOptimizerWidget::FunctionOptimizerWidget(QWidget *parent)
    : QWidget(parent)
{
    m_functionInputBox = new FunctionInputBox;
    m_functionInputBox->setFixedWidth(200);
    m_functionInputBox->addExpression("2*x^2 + 3*exp(-x)");                                                 // (0.469150)
    m_functionInputBox->addExpression("2*x^2 - exp(x)");                                                    // (0.357403)
    m_functionInputBox->addExpression("(10*x^3 + 3*x^2 + x + 5)^2");                                        // (-0.859902)
    m_functionInputBox->addExpression("3*x^2 + 12/x^3 - 5");                                                // (1.430969)
    m_functionInputBox->addExpression("x1^2 + 3*x2^2 + 2*x1*x2");                                           // (0 ; 0)
    m_functionInputBox->addExpression("100*(x2 - x1^2)^2 + (1 - x1)^2");                                    // (1 ; 1)
    m_functionInputBox->addExpression("-12*x2 + 4*x1^2 + 4*x2^2 - 4*x1*x2");                                // (1 ; 2)
    m_functionInputBox->addExpression("(x1 - 2)^4 + (x1 - 2*x2)^2");                                        // (2 ; 1)
    m_functionInputBox->addExpression("4*(x1 - 5)^2 + (x2 - 6)^2");                                         // (5 ; 6)
    m_functionInputBox->addExpression("8*x1^2 + 4*x1*x2 + 5*x2^2");                                         // (0 ; 0)
    m_functionInputBox->addExpression("(x1 - 1)^2 + (x2 - 3)^2 + 4*(x3 + 5)^2");                            // (1 ; 3 ; -5)
    m_functionInputBox->addExpression("(x2 - x1^2)^2 + (1 - x1)^2");                                        // (1 ; 1)
    m_functionInputBox->addExpression("100*(x2 - x1^2)^2 + 100*(1 - x1)^2");                                // (1 ; 1)
    m_functionInputBox->addExpression("3*(x1 - 4)^2 + 5*(x2 + 3)^2 + 7*(2*x3 + 1)^2");                      // (4 ; -3 ; -0.5)
    m_functionInputBox->addExpression("x1^3 + x2^2 - 3*x1 - 2*x2 + 2");                                     // (1 ; 1)
    m_functionInputBox->addExpression("4*x1^2 + 3*x2^2 - 4*x1*x2^2 + x1");                                  // (-0.125, 0)
    m_functionInputBox->addExpression("0.1*(12 + x1^2 + (1 + x2^2)/x1^2 + (x1^2*x2^2 + 100)/(x1^4*x2^4))"); // (+-1.743, +-2.036)
    m_functionInputBox->addExpression("(x1 - 1)^2 + (x2 - 3)^2 + 4*(x3 + 5)^2");                            // (1, 3, -5)
    m_functionInputBox->addExpression("3*(x1 - 4)^2 + 5*(x2 + 3)^2 + 7*(2*x3 + 1)^2");                      // (4, -3, -0.5)

    m_algorithmWidget = new OptimizationAlgorithmWidget;
    m_algorithmWidget->addAlgorithm(std::unique_ptr<OptimizationAlgorithm>(new GeneticAlgorithm));
    m_algorithmWidget->addAlgorithm(std::unique_ptr<OptimizationAlgorithm>(new ParticleSwarm));
    m_algorithmWidget->setFixedWidth(200);

    m_resultWidget = new OptimizationResultWidget;
    m_resultWidget->setFixedWidth(200);

    m_separator = new QFrame;
    m_separator->setFrameShape(QFrame::HLine);
    m_separator->setFrameShadow(QFrame::Raised);
    m_separator->setFixedWidth(200);

    m_optimizeButton = new QPushButton("Optimize");
    m_optimizeButton->setFixedWidth(200);

    m_algorithmLayout = new QVBoxLayout;
    m_algorithmLayout->setContentsMargins(0, 0, 0, 0);
    m_algorithmLayout->addWidget(m_functionInputBox);
    m_algorithmLayout->addWidget(m_algorithmWidget);
    m_algorithmLayout->addWidget(m_separator);
    m_algorithmLayout->addWidget(m_resultWidget);
    m_algorithmLayout->addWidget(m_optimizeButton);

    m_algorithmVisualizer = new AlgorithmVisualizer;
    m_algorithmVisualizer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_mainLayout = new QHBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_algorithmLayout);
    m_mainLayout->addWidget(m_algorithmVisualizer);

    setLayout(m_mainLayout);

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

    Function f = m_functionInputBox->parseExpression();
    OptimizationResult result = m_algorithmWidget->execute(f);
    m_resultWidget->setResult(result);

    m_algorithmVisualizer->clear();
    if (f.getSize() == 2) {
        m_algorithmVisualizer->setFunction(f, result.leftBound, result.rightBound);
        m_algorithmVisualizer->setAlgorithmData(result.data);
    }

    emit statusChanged("Success");
}
