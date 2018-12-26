#include "vectorlistwidget.hpp"

VectorListWidget::VectorListWidget(QWidget *parent)
    : QListWidget(parent)
{

}

void VectorListWidget::addVector(double x, double y)
{
    // Build string
    QString vecStr;
    vecStr.append("(");
    vecStr.append(QString::number(x));
    vecStr.append(", ");
    vecStr.append(QString::number(y));
    vecStr.append(")");

    addItem(vecStr);
}

void VectorListWidget::addVector(const QVector2D &vec)
{
    addVector(vec.x(), vec.y());
}
