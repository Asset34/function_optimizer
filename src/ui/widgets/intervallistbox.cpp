#include "intervallistbox.hpp"

#include <QVBoxLayout>

IntervallistBox::IntervallistBox(const QVector<QString> &names, QWidget *parent)
    : QWidget(parent)
{
    initIntervals(names);
}

void IntervallistBox::initIntervals(const QVector<QString> &names)
{
    // Create new layout
    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(0, 0, 0, 0);

    // Reset interval vector
    m_intervalBoxes.clear();
    m_intervalBoxes.reserve(names.size());

    IntervalBox *box;
    for (QString name : names) {
        box = new IntervalBox(name);

        m_intervalBoxes.push_back(box);
        layout->addWidget(box);
    }

    setLayout(layout);
}

QVector<Interval> IntervallistBox::getIntervals() const
{
    QVector<Interval> intervals;
    intervals.reserve(m_intervalBoxes.size());

    for (IntervalBox *box : m_intervalBoxes) {
        intervals.push_back(box->getInternal());
    }

    return intervals;
}
