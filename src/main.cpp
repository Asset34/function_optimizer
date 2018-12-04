#include <QApplication>

#include "ui/mainwindow.hpp"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(400, 100);
    w.show();

    return a.exec();
}
