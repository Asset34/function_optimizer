#ifndef VECTORLISTWIDGET_HPP
#define VECTORLISTWIDGET_HPP

#include <QListWidget>

#include <QVector2D>

class VectorListWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit VectorListWidget(QWidget *parent = nullptr);

    void addVector(double x, double y);
    void addVector(const QVector2D &vec);

};

#endif // VECTORLISTWIDGET_HPP
