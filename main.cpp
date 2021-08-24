#include "mainwindow.h"
#include "secondwin.h"
#include <QApplication>
#include "accessdb.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    secondwin s;
    w.show();

    QObject::connect(&w,SIGNAL(loadsuccess()),&s,SLOT(logged()));

    return a.exec();
}

