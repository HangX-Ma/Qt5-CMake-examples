#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    tableWidget = new QTableWidget(this);
    setCentralWidget(tableWidget);
    tableWidget->setColumnCount(2);
    tableWidget->setRowCount(2);
    tableWidget->setHorizontalHeaderLabels(QStringList()<<"Name"<<"Gender");
    QList <QString> strList;
    strList << "Ming" << "Hong" << "Man" << "Woman";

    for (int i = 0; i < 4; i++) {
        tableWidgetItem[i] = new QTableWidgetItem(strList[i]);
        tableWidgetItem[i]->setTextAlignment(Qt::AlignCenter);
    }
    tableWidget->setItem(0, 0, tableWidgetItem[0]);
    tableWidget->setItem(1, 0, tableWidgetItem[1]);
    tableWidget->setItem(0, 1, tableWidgetItem[2]);
    tableWidget->setItem(1, 1, tableWidgetItem[3]);

}

MainWindow::~MainWindow()
{
}

