#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    listView = new QListView(this);
    setCentralWidget(listView);

    QStringList strList;
    strList << "Class1" << "Class2" << "Class3";

    stringListModel = new QStringListModel(strList);

    listView->setModel(stringListModel);
    listView->setViewMode(QListView::IconMode);
    listView->setDragEnabled(false); // fixed, drag disable


}

MainWindow::~MainWindow()
{
}

