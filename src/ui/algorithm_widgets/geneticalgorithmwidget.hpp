#ifndef GENETICALGORITHMWIDGET_HPP
#define GENETICALGORITHMWIDGET_HPP

#include "algorithmwidget.hpp"

class QHBoxLayout;
class QVBoxLayout;
class QFormLayout;
class QFrame;
class QLabel;
class QCheckBox;
class QSpinBox;
class QDoubleSpinBox;
class QLineEdit;
class IntervalListBox;

class GeneticAlgorithmWidget : public AlgorithmWidget
{
    Q_OBJECT

public:
    explicit GeneticAlgorithmWidget(QWidget *parent = nullptr);
    virtual ~GeneticAlgorithmWidget() override;

    virtual bool optimize(const Function &func) override;

private:
    QHBoxLayout *m_mainLayout;
    QVBoxLayout *m_leftLayout;

    // Input widgets

    QFormLayout *m_inputLayout;

    QSpinBox *m_iterationsSpinBox;

    IntervalListBox *m_genIntervalListBox;

    QLineEdit *m_crossoverFactorLineEdit;
    QLineEdit *m_mutationChanceLineEdit;
    QLineEdit *m_mutationMaxLineEdit;

    QFrame *m_separator;

    // Output widgets

    QFormLayout *m_outputLayout;

    QLabel *m_resultVectorLabel;
    QLabel *m_resultIterationsLabel;

};

#endif // GENETICALGORITHMWIDGET_HPP
