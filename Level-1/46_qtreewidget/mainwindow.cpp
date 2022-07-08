#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    treeWidget = new QTreeWidget(this);
    setCentralWidget(treeWidget); // center
    treeWidget->clear(); // clear list

    parentItem = new QTreeWidgetItem(treeWidget); // instantiate top tree node
    parentItem->setText(0, "comrade"); // unchecked
    parentItem->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
    parentItem->setCheckState(0, Qt::Unchecked);

    QList <QString> strList;
    strList<<"Liu"<<"Guan"<<"Zhang";
    for (int i = 0; i < 3; i++){
        subItem[i] = new QTreeWidgetItem(parentItem);
        subItem[i]->setText(0, strList[i]);
        subItem[i]->setFlags(Qt::ItemIsUserCheckable | Qt::ItemIsEnabled | Qt::ItemIsSelectable);
        subItem[i]->setCheckState(0,Qt::Unchecked);
    }
    connect(treeWidget,SIGNAL(itemChanged(QTreeWidgetItem*,int)),this, SLOT(treeItemChanged(QTreeWidgetItem*,int)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::updateParentItem(QTreeWidgetItem *item) {
    QTreeWidgetItem* parent = item->parent();
    if(parent == NULL){
        return;
    }
    int selectCount = 0; // selected items number
    int childCount = parent->childCount(); // child nodes number
    for(int i = 0; i < childCount; i ++){
        QTreeWidgetItem* childItem =parent->child(i);
        /* 判断当前子节点的状是否为选中状态，如果是，则加一 */
        if(childItem->checkState(0) == Qt::Checked) {
            selectCount ++;
        }
    }
    /* 根据 selectCount 来判断树节点的状态 */
    /* 当选中的子节点小于或等于 0 时，则为设置树节点为未选中状态 */
    if (selectCount <= 0) {
        parent->setCheckState(0, Qt::Unchecked);
    } else if (selectCount > 0 && selectCount < childCount) {
        parent->setCheckState(0, Qt::PartiallyChecked);
    } else if (selectCount == childCount){
        parent->setCheckState(0, Qt::Checked);
    }
}


void MainWindow::treeItemChanged(QTreeWidgetItem *item, int) {
    int count = item->childCount();
    if(Qt::Checked == item->checkState(0) ) {
        if (count > 0) {
            for (int i = 0; i < count; i++) {
                item->child(i)->setCheckState(0, Qt::Checked);
            } // select all child nodes
        } else {
            updateParentItem(item);
        }
    } else if (Qt::Unchecked == item->checkState(0)) {
        if (count > 0){
            for (int i = 0; i < count; i++) {
                item->child(i)->setCheckState(0, Qt::Unchecked);
            }
        } else {
            updateParentItem(item);
        }
    }
}
