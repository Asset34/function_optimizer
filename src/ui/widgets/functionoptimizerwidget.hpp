#ifndef FUNCTIONOPTIMIZERWIDGET_HPP
#define FUNCTIONOPTIMIZERWIDGET_HPP

#include <QWidget>

class QHBoxLayout;
class QVBoxLayout;
class QPushButton;
class QFrame;
class FunctionInputBox;
class OptimizationAlgorithmWidget;
class OptimizationResultWidget;
class AlgorithmVisualizer;

class FunctionOptimizerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionOptimizerWidget(QWidget *parent = nullptr);

public slots:
    void optimize();

private:
    QHBoxLayout *m_mainLayout;
    QVBoxLayout *m_algorithmLayout;

    QPushButton *m_optimizeButton;

    QFrame *m_separator;

    FunctionInputBox *m_functionInputBox;
    OptimizationAlgorithmWidget *m_algorithmWidget;
    OptimizationResultWidget *m_resultWidget;
    AlgorithmVisualizer *m_algorithmVisualizer;

signals:
    void statusChanged(QString status);

};

#endif // FUNCTIONOPTIMIZERWIDGET_HPP
