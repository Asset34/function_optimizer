#ifndef OPTIMIZATIONALGORITHMWIDGET_HPP
#define OPTIMIZATIONALGORITHMWIDGET_HPP

#include <algorithms/optimizationalgorithm.hpp>
#include <parameterized_algorithm_qt/widgets/algorithmwidget.hpp>

class OptimizationAlgorithmWidget : public AlgorithmWidget
{
    Q_OBJECT

public:
    explicit OptimizationAlgorithmWidget(QWidget *parent = nullptr);

    OptimizationResult execute(const Function &function);

};

#endif // OPTIMIZATIONALGORITHMWIDGET_HPP
