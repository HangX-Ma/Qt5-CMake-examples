#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QHBoxLayout>
#include <QListWidget>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *widget;
    QHBoxLayout *hBoxLayout;
    QListWidget *listWidget;
    QStackedWidget *stackedWidget;
    QLabel *label[3];
};
#endif // MAINWINDOW_H
