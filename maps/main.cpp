#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MapOfSattelite w;
    w.show();
    return a.exec();
}
