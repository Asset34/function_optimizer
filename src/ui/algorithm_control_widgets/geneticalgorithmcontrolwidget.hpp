#ifndef GENETICALGORITHMCONTROLWIDGET_HPP
#define GENETICALGORITHMCONTROLWIDGET_HPP

#include "algorithmcontrolwidget.hpp"

class QFormLayout;
class QSpinBox;
class QLineEdit;

class GeneticAlgorithmControlWidget : public AlgorithmControlWidget
{
public:
    explicit GeneticAlgorithmControlWidget(QWidget *parent = nullptr);

    virtual OptimizeAlgorithm::Parameters getParameters() const override;

private:
    QFormLayout *m_layout;

    QSpinBox *m_iterationsSpinBox;
    QSpinBox *m_sizeSpinBox;

    QLineEdit *m_initMinLineEdit;
    QLineEdit *m_initMaxLineEdit;
    QLineEdit *m_crossoverFactorLineEdit;
    QLineEdit *m_mutationMaxLineEdit;
    QLineEdit *m_mutationProbabilityLineEdit;

};

#endif // GENETICALGORITHMCONTROLWIDGET_HPP
