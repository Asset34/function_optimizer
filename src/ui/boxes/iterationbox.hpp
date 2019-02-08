#ifndef ITERATIONBOX_HPP
#define ITERATIONBOX_HPP

#include <QWidget>

class QHBoxLayout;
class QSpinBox;
class QLabel;

class IterationBox : public QWidget
{
    Q_OBJECT

public:
    explicit IterationBox(int current, int max, QWidget *parent = nullptr);

    int getCurrent() const;
    int getMax() const;

public slots:
    void setCurrent(int it);
    void setMax(int max);
    void next();
    void prev();

private:
    QHBoxLayout *m_layout;

    QSpinBox *m_curIterationSpinBox;

    QLabel *m_separator;
    QLabel *m_maxIterationLabel;

    int m_current;
    int m_max;

signals:
    void currentIterationChanged(int it);
    void maxIterationChanged(int max);

};

#endif // ITERATIONBOX_HPP
