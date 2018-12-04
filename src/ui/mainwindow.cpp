#include "mainwindow.hpp"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include <Parser/Functions/function.hpp>

#include "algorithmwidget.hpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // Create function label
    m_functionLabel = new QLineEdit;

    // Create buttons
    m_evaluateButton = new QPushButton("Evaluate");
    m_optimizeButton = new QPushButton("Optimize");

    // Create control layout
    m_controlLayout = new QVBoxLayout;
    m_controlLayout->setContentsMargins(0, 0, 0, 0);
    m_controlLayout->addWidget(m_evaluateButton);
    m_controlLayout->addWidget(m_optimizeButton);

    // Create algorithm widget
    m_algorithmWidget = new AlgorithmWidget;

    // Create main layout
    m_mainLayout = new QVBoxLayout;
    m_mainLayout->setContentsMargins(0, 0, 0, 0);
    m_mainLayout->addWidget(m_functionLabel);
    m_mainLayout->addWidget(m_algorithmWidget);
    m_mainLayout->addLayout(m_controlLayout);

    // Create parser
    m_parser = new MathParser;

    // Create widget
    QWidget *centralWidget = new QWidget;
    centralWidget->setLayout(m_mainLayout);
    setCentralWidget(centralWidget);
    setContentsMargins(5, 5, 5, 5);

    // Create connections
    connect(m_evaluateButton, &QPushButton::clicked, this, &MainWindow::evaluate);
    connect(m_optimizeButton, &QPushButton::clicked, this, &MainWindow::optimize);
}

void MainWindow::evaluate()
{
//    QString funcStr = m_functionLabel->text();
//    Function *func = m_parser->parse(funcStr);


//    delete func;
}

void MainWindow::optimize()
{
    // TODO
}
