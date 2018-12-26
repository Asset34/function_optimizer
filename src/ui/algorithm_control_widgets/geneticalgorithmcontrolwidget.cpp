#include "geneticalgorithmcontrolwidget.hpp"

#include <QFormLayout>
#include <QSpinBox>
#include <QLineEdit>

#include <QDoubleValidator>

GeneticAlgorithmControlWidget::GeneticAlgorithmControlWidget(QWidget *parent)
    :  AlgorithmControlWidget(parent)
{
    // Create validators
    QDoubleValidator *validator1 = new QDoubleValidator(0.0, 1.0, 10, this);
    QDoubleValidator *validator2 = new QDoubleValidator(0.0, 1e9, 10, this);
    QDoubleValidator *validator3 = new QDoubleValidator(-1e9, 1e9, 10, this);

    // Create iterations spin box
    m_iterationsSpinBox = new QSpinBox;
    m_iterationsSpinBox->setRange(0, 1e9);
    m_iterationsSpinBox->setValue(10);

    // Create size spin box
    m_sizeSpinBox = new QSpinBox;
    m_sizeSpinBox->setRange(1, 1e9);
    m_sizeSpinBox->setValue(2);

    // Create line editors

    m_initMinLineEdit = new QLineEdit("-10000.0");
    m_initMinLineEdit->setValidator(validator3);


    m_initMaxLineEdit = new QLineEdit("10000.0");
    m_initMaxLineEdit->setValidator(validator3);

    m_crossoverFactorLineEdit = new QLineEdit("0.2");
    m_crossoverFactorLineEdit->setValidator(validator1);

    m_mutationMaxLineEdit = new QLineEdit("100");
    m_mutationMaxLineEdit->setValidator(validator2);

    m_mutationProbabilityLineEdit = new QLineEdit("0.05");
    m_mutationProbabilityLineEdit->setValidator(validator1);

    // Create layout
    m_layout = new QFormLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addRow("Iterations:"                , m_iterationsSpinBox);
    m_layout->addRow("Size:"                , m_sizeSpinBox);
    m_layout->addRow("Min:"                 , m_initMinLineEdit);
    m_layout->addRow("Max:"                 , m_initMaxLineEdit);
    m_layout->addRow("Crossover factor:"    , m_crossoverFactorLineEdit);
    m_layout->addRow("Max mutation:"        , m_mutationMaxLineEdit);
    m_layout->addRow("Mutation probability:", m_mutationProbabilityLineEdit);

    // Create widget
    setLayout(m_layout);
}

OptimizeAlgorithm::Parameters GeneticAlgorithmControlWidget::getParameters() const
{
    OptimizeAlgorithm::Parameters p;
    p.maxIterations = m_iterationsSpinBox->value();
    p.populationSize = m_sizeSpinBox->value();
    p.initMin = m_initMinLineEdit->text().toDouble();
    p.initMax = m_initMaxLineEdit->text().toDouble();
    p.crossoverFactor = m_crossoverFactorLineEdit->text().toDouble();
    p.mutationMax = m_mutationMaxLineEdit->text().toDouble();
    p.pmut = m_mutationProbabilityLineEdit->text().toDouble();

    return p;
}
