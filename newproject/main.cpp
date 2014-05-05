#include "mainwindow.h"
#include <QApplication>
#include <QtSql>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedHeight(320);
    w.setFixedWidth(480);

    w.show();

    return a.exec();
}
