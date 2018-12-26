#include <QApplication>

#include "ui/mainwindow.hpp"

//#include <QtDataVisualization>

//using namespace QtDataVisualization;

//double f(double x1, double x2) {
//    return x1*x1 + x2*x2;
//}

#include <ui/functiondrawer.hpp>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MathParser parser;
    Function func = parser.parse("x^2 - y^2");

    FunctionDrawer drawer;
    drawer.setFunction(func, -100.0, 100.0, -100.0, 100.0);
    drawer.resize(500, 500);
    drawer.show();

    QVector<QVector3D> marks;
    marks << QVector3D(5.0, 3.0, -2.0);
    marks << QVector3D(12.2, 55.2, 3.0);
    marks << QVector3D(-5.0, 12.5, 17.0);
    drawer.setMarks(marks);


    return a.exec();
}
