#ifndef FUNCTIONOPTIMIZERWIDGET_HPP
#define FUNCTIONOPTIMIZERWIDGET_HPP

#include <QWidget>

class QVBoxLayout;
class QPushButton;
class FunctionInputBox;
class OptimizationAlgorithmWidget;
class OptimizationResultWidget;

class FunctionOptimizerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FunctionOptimizerWidget(QWidget *parent = nullptr);

public slots:
    void optimize();

private:
    QVBoxLayout *m_layout;

    QPushButton *m_optimizeButton;

    FunctionInputBox *m_functionInputBox;
    OptimizationAlgorithmWidget *m_algorithmWidget;
    OptimizationResultWidget *m_resultWidget;

signals:
    void statusChanged(QString status);

};

#endif // FUNCTIONOPTIMIZERWIDGET_HPP
