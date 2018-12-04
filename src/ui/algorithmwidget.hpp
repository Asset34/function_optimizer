#ifndef ALGORITHMWIDGET_HPP
#define ALGORITHMWIDGET_HPP

#include <QWidget>

#include <algorithms/optimizealgorithm.hpp>
#include <Parser/Functions/function.hpp>

class QHBoxLayout;
class QFormLayout;
class QSpinBox;
class QLabel;

class AlgorithmWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmWidget(QWidget *parent = nullptr);
    virtual ~AlgorithmWidget();

public slots:
    void optimize(const Function *func);

private:
    QHBoxLayout *m_mainLayout;
    QFormLayout *m_inputLayout;
    QFormLayout *m_resultLayout;

    QSpinBox *m_maxIterationsSpinBox;
    QSpinBox *m_sizeSpinBox;

    QLabel *m_valueLabel;
    QLabel *m_iterationsLabel;

    OptimizeAlgorithm *m_algorithm;

};

#endif // ALGORITHMWIDGET_HPP
