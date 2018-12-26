#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <parser/Parser/mathparser.hpp>

#include <algorithms/optimizealgorithm.hpp>

class QVBoxLayout;
class QFormLayout;
class QLineEdit;
class QPushButton;
class QComboBox;
class InputFunctionBox;
class AlgorithmWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QVBoxLayout *m_mainLayout;
    QFormLayout *m_toplayout;

    InputFunctionBox *m_inputFunctionBox;

    QComboBox *m_algorithmComboBox;

    QPushButton *m_optimizeButton;

    AlgorithmWidget *m_algorithmWidget;

private slots:
    void optimize();

};

#endif // MAINWINDOW_HPP
