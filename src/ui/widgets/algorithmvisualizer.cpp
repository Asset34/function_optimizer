#include "algorithmvisualizer.hpp"

#include <QVBoxLayout>

#include <ui/widgets/functiondrawer.hpp>
#include <ui/widgets/iterationwidget.hpp>

//#include <QDebug>

AlgorithmVisualizer::AlgorithmVisualizer(QWidget *parent)
    : QWidget(parent)
{
    m_functionDrawer = new FunctionDrawer;
    m_functionDrawer->resize(1, 1);
    m_functionDrawer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    m_iterationWidget = new IterationWidget;
    m_iterationWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    m_layout = new QVBoxLayout;
    m_layout->setContentsMargins(0, 0, 0, 0);
    m_layout->addWidget(m_functionDrawer);
    m_layout->addWidget(m_iterationWidget);

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
    m_min = min;
    m_max = max;

    m_functionDrawer->setFunction(m_function, min, max);
}


void AlgorithmVisualizer::setAlgorithmData(const OptimizationData &data)
{
//    int i = 0;
//    for (auto &set : data) {
//        qDebug() << i << "-----------------------";
//        for (auto &vec : set) {
//            qDebug() << QString::fromStdString(vec.toString());
//        }

//        i++;
//    }

    m_layout->removeWidget(m_functionDrawer);
    delete m_functionDrawer;
    m_functionDrawer = new FunctionDrawer;
    m_functionDrawer->resize(1, 1);
    m_functionDrawer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    m_layout->insertWidget(0, m_functionDrawer);
    m_functionDrawer->setFunction(m_function, m_min, m_max);

//    m_functionDrawer->clearMarks();
    for (auto &set : data) {
        m_functionDrawer->addMarkSet(m_function, set);
    }

    m_iterationWidget->setMax(data.size() - 1);
    m_iterationWidget->first();
}

void AlgorithmVisualizer::clear()
{
    m_iterationWidget->clear();
    m_functionDrawer->clear();
}

void AlgorithmVisualizer::setIterationData(int it)
{
    m_functionDrawer->selectMarkSet(it);
}
