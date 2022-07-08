#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTableWidget *tableWidget;
    QTableWidgetItem *tableWidgetItem[4];

};
#endif // MAINWINDOW_H
