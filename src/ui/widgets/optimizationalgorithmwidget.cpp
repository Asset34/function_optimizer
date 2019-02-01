#include "optimizationalgorithmwidget.hpp"

OptimizationAlgorithmWidget::OptimizationAlgorithmWidget(QWidget *parent)
    : AlgorithmWidget(parent)
{
}

OptimizationResult OptimizationAlgorithmWidget::execute(const Function &function)
{
    Algorithm &algorithm = getCurrentAlgorithm();
    OptimizationAlgorithm &optimizationAlgorithm = static_cast<OptimizationAlgorithm&>(algorithm);

    return optimizationAlgorithm.execute(function);
}
