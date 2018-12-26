#include <QApplication>

#include "ui/mainwindow.hpp"

#include <QtDataVisualization>

using namespace QtDataVisualization;

double f(double x1, double x2) {
    return x1*x1 + x2*x2;
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

//    MainWindow w;
//    w.resize(400, 100);
//    w.show();

    Q3DSurface surface;

    double min = -100.0;
    double max = 100.0;
    double step = 0.1;

    QSurfaceDataRow *row;
    QSurfaceDataArray *data = new QSurfaceDataArray;
    QVector3D vec;
    for (int x = min; x < max; x += step) {
        row = new QSurfaceDataRow;
        for (int y = min; y < max; y += step) {
            vec.setX(x);
            vec.setY(y);
            vec.setZ(f(x, y));

            *row << vec;
        }

        *data << row;
    }

    QSurface3DSeries *series = new QSurface3DSeries;
    series->dataProxy()->resetArray(data);
    surface.addSeries(series);
    surface.show();

    return a.exec();
}
