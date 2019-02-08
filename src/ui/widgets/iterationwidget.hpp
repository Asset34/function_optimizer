#ifndef ITERATIONWIDGET_HPP
#define ITERATIONWIDGET_HPP

#include <QWidget>

class QVBoxLayout;
class QHBoxLayout;
class QPushButton;
class IterationBox;

class IterationWidget : public QWidget
{
    Q_OBJECT

public:
    explicit IterationWidget(int current, int max, QWidget *parent = nullptr);

    int getCurrent() const;
    int getMax() const;

public slots:
    void setCurrent(int it);
    void setMax(int max);
    void next();
    void prev();

private:
    QVBoxLayout *m_mainLayout;
    QHBoxLayout *m_buttonsLayout;

    QPushButton *m_nextButton;
    QPushButton *m_prevButton;

    IterationBox *m_iterationBox;

signals:
    void currentIterationChanged(int it);
    void maxIterationChanged(int max);

};

#endif // ITERATIONWIDGET_HPP
