#include "mainwindow.hpp"

#include "widgets/functionoptimizerwidget.hpp"

#include <QStatusBar>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    m_optimizerWidget = new FunctionOptimizerWidget;

    setCentralWidget(m_optimizerWidget);
    setContentsMargins(5, 5, 5, 5);

    connect(
        m_optimizerWidget,
        &FunctionOptimizerWidget::statusChanged,
        this,
        &MainWindow::indicateSolverStatus
        );
}

void MainWindow::indicateSolverStatus(QString status)
{
    statusBar()->showMessage(status);
}
