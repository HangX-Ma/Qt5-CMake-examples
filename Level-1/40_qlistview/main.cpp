#include "mainwindow.h"

#include <QApplication>
#include <QListView>
#include <QStringListModel>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
