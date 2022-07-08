#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QSpacerItem>
#include <QBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *bt[4];
    QSpacerItem *vSpacer;
    QSpacerItem *hSpacer;

    QWidget *widget;

    QHBoxLayout *mainLayout;
    QVBoxLayout *vBoxLayout;
    QHBoxLayout *hBoxLayout;
};
#endif // MAINWINDOW_H
