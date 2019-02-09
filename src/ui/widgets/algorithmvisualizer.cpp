#include "algorithmvisualizer.hpp"

#include <QVBoxLayout>

#include <ui/widgets/functiondrawer.hpp>
#include <ui/widgets/iterationwidget.hpp>

AlgorithmVisualizer::AlgorithmVisualizer(QWidget *parent)
    : QWidget(parent)
{
    m_functionDrawer = new FunctionDrawer;
    m_iterationWidget = new IterationWidget;

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);

    setLayout(m_layout);

    connect(
        m_iterationWidget,
        &IterationWidget::currentIterationChanged,
        this,
        &AlgorithmVisualizer::setIterationData
                );
}

void AlgorithmVisualizer::setFunction(Function &f, double min, double max)
{
    m_function = std::move(f);
    m_functionDrawer->setFunction(f, min, max);
}

void AlgorithmVisualizer::setAlgorithmData(const OptimizationData &data)
{
    m_data = data;
    m_iterationWidget->setMax(data.size());
    m_iterationWidget->last();
}

void AlgorithmVisualizer::setIterationData(int it)
{
    m_functionDrawer->setMarks(m_function, m_data[it]);
}
