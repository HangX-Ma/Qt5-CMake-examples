#include "mainwindow.h"
#include <QStandardItemModel>
#include <QHeaderView>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    tableView = new QTableView(this);
    setCentralWidget(tableView);

    tableView->setShowGrid(true);

    QStandardItemModel* model = new QStandardItemModel();
    QStringList labels = QObject::tr("Chinese,Math,English").simplified().split(",");
    model->setHorizontalHeaderLabels(labels);

    QStandardItem* item = 0;

    for(int i = 0; i < 5; i++){
        item = new QStandardItem("80");
        model->setItem(i, 0, item);
        item = new QStandardItem("99");
        model->setItem(i, 1, item);
        item = new QStandardItem("100");
        model->setItem(i, 2, item);
    }
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView->verticalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
}

