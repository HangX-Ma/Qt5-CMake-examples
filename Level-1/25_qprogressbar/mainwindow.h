#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QProgressBar *progressBar;
    QTimer *timer;
    int value;

private slots:
    void timerTimeOut();
};
#endif // MAINWINDOW_H
