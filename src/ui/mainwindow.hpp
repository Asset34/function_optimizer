#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <Parser/Parser/mathparser.hpp>

class QVBoxLayout;
class QHBoxLayout;
class QLabel;
class QLineEdit;
class QPushButton;

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

    MathParser *m_parser;

private slots:
    void evaluate();
    void optimize();

};

#endif // MAINWINDOW_HPP
