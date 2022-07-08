#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGridLayout>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QWidget *gWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton[4];



};
#endif // MAINWINDOW_H
