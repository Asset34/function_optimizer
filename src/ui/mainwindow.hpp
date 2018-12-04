#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <Parser/Parser/mathparser.hpp>

class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QLineEdit;
class QPushButton;
class AlgorithmWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QVBoxLayout *m_mainLayout;
    QVBoxLayout *m_controlLayout;

    QLineEdit *m_functionLabel;

    QPushButton *m_evaluateButton;
    QPushButton *m_optimizeButton;

    AlgorithmWidget *m_algorithmWidget;

    MathParser *m_parser;

private slots:
    void evaluate();
    void optimize();

};

#endif // MAINWINDOW_HPP
