#ifndef INTERVALLISTBOX_HPP
#define INTERVALLISTBOX_HPP

#include <QWidget>

#include "intervalbox.hpp"

class IntervallistBox : public QWidget
{
    Q_OBJECT

public:
    explicit IntervallistBox(
            const QVector<QString> &names = {},
            QWidget *parent = nullptr
            );

    void initIntervals(const QVector<QString> &names);

    QVector<Interval> getIntervals() const;

private:
    QVector<IntervalBox*> m_intervalBoxes;

};

#endif // INTERVALLISTBOX_HPP
