#ifndef OPTIMIZATIONRESULTWIDGET_HPP
#define OPTIMIZATIONRESULTWIDGET_HPP

#include <QWidget>

#include <algorithms/optimizationalgorithm.hpp>

class QFormLayout;
class QLabel;

class OptimizationResultWidget : public QWidget
{
    Q_OBJECT

public:
    explicit OptimizationResultWidget(QWidget *parent = nullptr);

    void setResult(const OptimizationResult &result);

private:
    QFormLayout *m_layout;

    QLabel *m_iterationsLabel;
    QLabel *m_argumentLabel;
    QLabel *m_valueLabel;

};

#endif // OPTIMIZATIONRESULTWIDGET_HPP
