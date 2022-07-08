#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void paintEvent(QPaintEvent *);

private:
    QTimer *timer;
    int angle;

private slots:
    void timerTimeOut();
};
#endif // MAINWINDOW_H
