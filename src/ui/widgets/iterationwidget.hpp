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
    explicit IterationWidget(int current = 0, int max = 0, QWidget *parent = nullptr);

    int getCurrent() const;
    int getMax() const;

public slots:
    void setCurrent(int it);
    void setMax(int max);

    void first();
    void last();
    void next();
    void prev();

    void clear();

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
