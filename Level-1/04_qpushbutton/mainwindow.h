#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *pushBtn1;
    QPushButton *pushBtn2;

private slots:
    void pushBtn1_clicked();
    void pushBtn2_clicked();
};
#endif // MAINWINDOW_H
