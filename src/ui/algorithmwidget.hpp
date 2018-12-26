#ifndef ALGORITHMWIDGET_HPP
#define ALGORITHMWIDGET_HPP

#include <QWidget>

#include <algorithms/optimizealgorithm.hpp>
#include <Parser/Functions/function.hpp>

class QVBoxLayout;
class QFormLayout;
class QComboBox;
class QSpinBox;
class QLabel;
class QFrame;

#include "algorithm_control_widgets/algorithmcontrolwidget.hpp"

class AlgorithmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmWidget(QWidget *parent = nullptr);
    virtual ~AlgorithmWidget();

public slots:
    void optimize(const Function &func);

private:
    void resetAlgorithm();
    void resetAlgorithmControlWidget();

    QVBoxLayout *m_mainLayout;
    QFormLayout *m_resultLayout;

    QComboBox *m_algorithmComboBox;

    QLabel *m_valueLabel;
    QLabel *m_iterationsLabel;

    QFrame *m_separator;

    AlgorithmControlWidget *m_algorithmControlWidget;

    OptimizeAlgorithm *m_algorithm;

private slots:
    void setAlgorithmControlWidget();

};

#endif // ALGORITHMWIDGET_HPP
