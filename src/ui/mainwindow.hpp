#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <QString>

class FunctionOptimizerWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);

private:
    FunctionOptimizerWidget *m_optimizerWidget;

private slots:
    void indicateSolverStatus(QString status);

};

#endif // MAINWINDOW_HPP
