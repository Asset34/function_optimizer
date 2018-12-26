#include "algorithmwidget.hpp"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QSpinBox>
#include <QLabel>
#include <QFrame>

#include <algorithms/geneticalgorithm.hpp>

#include "algorithm_control_widgets/algorithmcontrolwidget.hpp"
#include "algorithm_control_widgets/geneticalgorithmcontrolwidget.hpp"

#include <QDebug>

AlgorithmWidget::AlgorithmWidget(QWidget *parent)
    : QWidget(parent),
      m_algorithmControlWidget(new GeneticAlgorithmControlWidget)
{
    // Create algorithm combo box
    m_algorithmComboBox = new QComboBox;
    m_algorithmComboBox->addItem(QString::fromStdString(GeneticAlgorithm().getName()));

    // Create separator
    m_separator = new QFrame;
    m_separator->setFrameShape(QFrame::Shape::HLine);

    // Create labels
    m_valueLabel = new QLabel;
    m_iterationsLabel = new QLabel;

    // Create result layout
    m_resultLayout = new QFormLayout;
    m_resultLayout->setContentsMargins(0, 0, 0, 0);
    m_resultLayout->addRow("Value:"     , m_valueLabel);
    m_resultLayout->addRow("Iterations:", m_iterationsLabel);

    // Create main layout
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addWidget(m_algorithmComboBox);
    m_mainLayout->addWidget(m_separator);
    m_mainLayout->addWidget(m_algorithmControlWidget);
    m_mainLayout->addWidget(m_separator);
    m_mainLayout->addLayout(m_resultLayout);

    // Create algorithm
    m_algorithm = new GeneticAlgorithm;

    // Create widget
    setLayout(m_mainLayout);

    // Create connections
    connect(
        m_algorithmComboBox,
        static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
        this,
        &AlgorithmWidget::setAlgorithmControlWidget
        );
}

AlgorithmWidget::~AlgorithmWidget()
{
    delete m_algorithm;
}

void AlgorithmWidget::optimize(const Function &func)
{
    resetAlgorithm();

    OptimizeAlgorithm::Parameters p = m_algorithmControlWidget->getParameters();
    OptimizeAlgorithm::Result result = m_algorithm->run(func, p);

    // Convert results
    QString valueStr;
    valueStr.append("(");
    for (double value : result.values) {
        valueStr.append(QString::number(value) + ", ");
    }
    valueStr.append(")");
    QString iterationsStr = QString::number(result.iterations);

    // Set results
    m_valueLabel->setText(valueStr);
    m_iterationsLabel->setText(iterationsStr);

    qDebug() << "*** RESULT *** : " << valueStr;
}

void AlgorithmWidget::resetAlgorithm()
{
    delete m_algorithm;

    // Set algorithm
    int row = m_algorithmComboBox->currentIndex();
    switch (row) {
        case 0:
            m_algorithm = new GeneticAlgorithm;
        break;
    }
}

void AlgorithmWidget::resetAlgorithmControlWidget()
{
    m_mainLayout->removeWidget(m_algorithmControlWidget);
    delete m_algorithmControlWidget;

    int row = m_algorithmComboBox->currentIndex();
    switch (row) {
        case 0:
            m_algorithmControlWidget = new GeneticAlgorithmControlWidget;
        default:
            m_algorithmControlWidget = nullptr;
        break;
    }

    m_mainLayout->insertWidget(1, m_algorithmControlWidget);
}

void AlgorithmWidget::setAlgorithmControlWidget()
{
    resetAlgorithmControlWidget();
}
