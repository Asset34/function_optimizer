#ifndef INTERVALBOX_HPP
#define INTERVALBOX_HPP

#include <QWidget>

#include <QString>
#include <QPair>

class QHBoxLayout;
class QLabel;
class QLineEdit;

using Interval = QPair<double, double>;

class IntervalBox : public QWidget
{
    Q_OBJECT

public:
    explicit IntervalBox(
            const QString &name = QString(),
            double left = 0.0,
            double right = 0.0,
            QWidget *parent = nullptr
            );

    Interval getInternal() const;

private:
    QHBoxLayout *m_layout;

    QLabel *m_nameLabel;
    QLabel *m_separatorLabel;

    QLineEdit *m_leftLineEdit;
    QLineEdit *m_rightLineEdit;

};

#endif // INTERVALBOX_HPP
