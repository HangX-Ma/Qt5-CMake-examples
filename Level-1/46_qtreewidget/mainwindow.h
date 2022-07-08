#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QTreeWidgetItem>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTreeWidget *treeWidget;
    QTreeWidgetItem *parentItem;
    QTreeWidgetItem *subItem[3];

    void updateParentItem(QTreeWidgetItem*);

private slots:
    void treeItemChanged(QTreeWidgetItem*, int);

};
#endif // MAINWINDOW_H
