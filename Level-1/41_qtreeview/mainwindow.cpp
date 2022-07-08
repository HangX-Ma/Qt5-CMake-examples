#include "mainwindow.h"
#include <QStandardItemModel>
#include <QStandardItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    treeView = new QTreeView(this);
    setCentralWidget(treeView);

    QStandardItemModel *sdiModel = new QStandardItemModel(treeView);
    sdiModel->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("Title")<< QStringLiteral("Name"));
    for(int i = 0; i < 5; i++) {
        /* 一级标题 */
        QList<QStandardItem*> items1;
        QStandardItem* item1 = new QStandardItem(QString::number(i));
        QStandardItem* item2 = new QStandardItem(QStringLiteral("Level1 Title"));
        items1.append(item1);
        items1.append(item2);
        /* appendRow 方法添加到 model 上 */
        sdiModel->appendRow(items1);
        for(int j = 0; j < 5; j++) {
            /* 在一级标题后面插入二级标题 */
            QList<QStandardItem*> items2;
            QStandardItem* item3 = new QStandardItem(QString::number(j));
            QStandardItem* item4 = new QStandardItem(QStringLiteral("Level2 Title"));
            items2.append(item3);
            items2.append(item4);
            /* 使用 appendRow 方法添加到 item1 上 */
            item1->appendRow(items2);
        }
    }
    treeView->setModel(sdiModel);


}

MainWindow::~MainWindow()
{
}

