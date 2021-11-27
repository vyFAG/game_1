#include "mapwindow.h"

#include <QApplication>
#include <QDebug>

int main(int argc, char *argv[])
{
    //qDebug() << argv[0];
    QApplication a(argc, argv);
    MapWindow w;
    w.show();
    return a.exec();
}
