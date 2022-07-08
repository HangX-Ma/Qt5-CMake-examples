#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLCDNumber>
#include <QTimer>
#include <QTime>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLCDNumber *lcdNumber;
    QTimer *timer;

private slots:
    void timerTimeOut();
};
#endif // MAINWINDOW_H
