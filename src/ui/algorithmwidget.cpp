#include "algorithmwidget.hpp"

#include <QHBoxLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QLabel>

#include <algorithms/geneticalgorithm.hpp>

AlgorithmWidget::AlgorithmWidget(QWidget *parent)
    : QWidget(parent)
{
    // Create spin boxes

    m_maxIterationsSpinBox = new QSpinBox;
    m_maxIterationsSpinBox->setRange(0, 1e9);
    m_maxIterationsSpinBox->setValue(1e9);

    m_sizeSpinBox = new QSpinBox;
    m_sizeSpinBox->setRange(0, 1e9);
    m_sizeSpinBox->setValue(5);

    // Create input layout
    m_inputLayout = new QFormLayout;
    m_inputLayout->setContentsMargins(0, 0, 0, 0);
    m_inputLayout->addRow("Max iterations:", m_maxIterationsSpinBox);
    m_inputLayout->addRow("Size:"          , m_sizeSpinBox);

    // Create labels
    m_valueLabel = new QLabel;
    m_iterationsLabel = new QLabel;

    // Create result layout
    m_resultLayout = new QFormLayout;
    m_resultLayout->setContentsMargins(0, 0, 0, 0);
    m_resultLayout->addRow("Value:"     , m_valueLabel);
    m_resultLayout->addRow("Iterations:", m_iterationsLabel);

    // Create main layout
    m_mainLayout = new QHBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_inputLayout);
    m_mainLayout->addLayout(m_resultLayout);

    // Create algorithm
    m_algorithm = new GeneticAlgorithm;

    // Create widget
    setLayout(m_mainLayout);
}

AlgorithmWidget::~AlgorithmWidget()
{
    delete m_algorithm;
}

void AlgorithmWidget::optimize(const Function *func)
{
    // Set parameters
    OptimizeAlgorithm::Parameters p;
    p.maxIterations = m_maxIterationsSpinBox->value();
    p.size = m_sizeSpinBox->value();

    // Run
    OptimizeAlgorithm::Result result = m_algorithm->run(func, p);

    // Set results
    QString valueStr = QString::number(result.value);
    QString iterationsStr = QString::number(result.iterations);
    m_valueLabel->setText(valueStr);
    m_iterationsLabel->setText(iterationsStr);
}
