#ifndef ALGORITHMVISUALIZER_HPP
#define ALGORITHMVISUALIZER_HPP

#include <QWidget>

#include <algorithms/optimizationalgorithm.hpp>

class QVBoxLayout;
class FunctionDrawer;
class IterationWidget;

class AlgorithmVisualizer : public QWidget
{
    Q_OBJECT

public:
    explicit AlgorithmVisualizer(QWidget *parent = nullptr);

    void setFunction(Function &f, double min, double max);
    void setAlgorithmData(const OptimizationData &data);

public slots:
    void setIterationData(int it);

private:
    QVBoxLayout *m_layout;

    FunctionDrawer *m_functionDrawer;
    IterationWidget *m_iterationWidget;

    Function m_function;
    OptimizationData m_data;

};

#endif // ALGORITHMVISUALIZER_HPP
