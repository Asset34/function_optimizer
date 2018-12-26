#include "mainwindow.hpp"

#include <QVBoxLayout>
#include <QFormLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>

#include <Parser/Functions/function.hpp>

#include <ui/widgets/inputfunctionbox.hpp>
#include <ui/algorithm_widgets/geneticalgorithmwidget.hpp>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create widgets
    m_inputFunctionBox = new InputFunctionBox;
    m_algorithmWidget = new GeneticAlgorithmWidget;

    // Create algorithm combo box
    m_algorithmComboBox = new QComboBox;
    m_algorithmComboBox->addItem("Genetic algorithm");

    // Create top layout
    m_toplayout = new QFormLayout;
    m_toplayout->setContentsMargins(0, 0, 0, 0);
    m_toplayout->addRow("Function:" , m_inputFunctionBox);
    m_toplayout->addRow("Algorithm:", m_algorithmComboBox);

    // Create optimize buton
    m_optimizeButton = new QPushButton("Optimize");

    // Create main layout
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addLayout(m_toplayout);
    m_mainLayout->addWidget(m_algorithmWidget);
    m_mainLayout->addWidget(m_optimizeButton);

    // Create window
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(m_mainLayout);
    setCentralWidget(centralWidget);
    setContentsMargins(5, 5, 5, 5);

    // Create connections
    connect(m_optimizeButton, &QPushButton::clicked, this, &MainWindow::optimize);
}

void MainWindow::optimize()
{
    // TODO
}
