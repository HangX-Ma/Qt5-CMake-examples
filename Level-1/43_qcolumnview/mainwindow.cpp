#include "mainwindow.h"
#include <QStandardItem>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    QStandardItemModel *model = new QStandardItemModel;

    QStandardItem *province = new QStandardItem("GuangDong");
    QStandardItem *city1 = new QStandardItem("MaoMing");
    QStandardItem *city2 = new QStandardItem("ZhongShan");
    province->appendRow(city1);
    province->appendRow(city2);

    QStandardItem *town1 = new QStandardItem("DianBai");
    QStandardItem *town2 = new QStandardItem("NanTou");
    city1->appendRow(town1);
    city2->appendRow(town2);

    columnView = new QColumnView;
    model->appendRow(province);
    columnView->setModel(model);
    setCentralWidget(columnView);
}

MainWindow::~MainWindow()
{
}

