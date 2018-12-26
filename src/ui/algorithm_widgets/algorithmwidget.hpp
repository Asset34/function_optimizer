#ifndef ALGORITHMWIDGET_HPP
#define ALGORITHMWIDGET_HPP

#include <QWidget>

#include <parser/Functions/function.hpp>
#include <algorithms/optimizealgorithm.hpp>

class AlgorithmWidget : public QWidget
{
    Q_OBJECT
public:
    explicit AlgorithmWidget(QWidget *parent = nullptr);
    virtual ~AlgorithmWidget() = default;

    virtual bool optimize(const Function &func) = 0;

protected:
    OptimizeAlgorithm *m_algorithm;

};

#endif // ALGORITHMWIDGET_HPP
