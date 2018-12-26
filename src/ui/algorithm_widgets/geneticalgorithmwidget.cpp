#include "geneticalgorithmwidget.hpp"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QFrame>
#include <QLabel>
#include <QCheckBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLineEdit>

#include <QDoubleValidator>

#include <ui/widgets/intervallistbox.hpp>

#include <algorithms/geneticalgorithm.hpp>

GeneticAlgorithmWidget::GeneticAlgorithmWidget(QWidget *parent)
    : AlgorithmWidget(parent)
{
    // Create validators
    QDoubleValidator *generalValidator = new QDoubleValidator(0.0, 1e9, 10, this);
    QDoubleValidator *chanceValidator = new QDoubleValidator(0.0, 1.0, 10, this);

    // Create input iterations spin box
    m_iterationsSpinBox = new QSpinBox;
    m_iterationsSpinBox->setRange(0, 1e9);
    m_iterationsSpinBox->setValue(100);

    // Create input interval list box
    m_genIntervalListBox = new IntervalListBox;

    // Create input line edits
    m_crossoverFactorLineEdit = new QLineEdit("0.2");
    m_crossoverFactorLineEdit->setValidator(chanceValidator);

    m_mutationChanceLineEdit = new QLineEdit("0.05");
    m_mutationChanceLineEdit->setValidator(chanceValidator);

    m_mutationMaxLineEdit = new QLineEdit("100");
    m_mutationMaxLineEdit->setValidator(generalValidator);

    // Create input layout
    m_inputLayout = new QFormLayout;
    m_inputLayout->setContentsMargins(0, 0, 0, 0);
    m_inputLayout->addRow("Iterations:"      , m_iterationsSpinBox);
    m_inputLayout->addRow("Search space:"    , m_genIntervalListBox);
    m_inputLayout->addRow("Crossover factor:", m_crossoverFactorLineEdit);
    m_inputLayout->addRow("Mutation chance:" , m_mutationChanceLineEdit);
    m_inputLayout->addRow("Mutation max"     , m_mutationMaxLineEdit);

    // Create output labels
    m_resultVectorLabel = new QLabel;
    m_resultIterationsLabel = new QLabel;

    // Create output layout
    m_outputLayout = new QFormLayout;
    m_outputLayout->setContentsMargins(0, 0, 0, 0);
    m_outputLayout->addRow("Result:"    , m_resultVectorLabel);
    m_outputLayout->addRow("Iterations:", m_resultIterationsLabel);

    // Create separator
    m_separator = new QFrame;
    m_separator->setFrameShape(QFrame::Shape::HLine);

    // Create left layout
    m_leftLayout = new QVBoxLayout;
    m_leftLayout->setContentsMargins(0, 0, 0, 0);
    m_leftLayout->addLayout(m_inputLayout);
    m_leftLayout->addWidget(m_separator);
    m_leftLayout->addLayout(m_outputLayout);

    // Create main layout
    m_mainLayout = new QHBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_leftLayout);

    // Creare algorithm
    m_algorithm = new GeneticAlgorithm;

    // Create widget
    setLayout(m_mainLayout);
}

GeneticAlgorithmWidget::~GeneticAlgorithmWidget()
{
    delete m_algorithm;
}

bool GeneticAlgorithmWidget::optimize(const Function &func)
{
    // TODO

    return true;
}
