#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextBrowser>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTimer>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    /* get or clear txet */
    QPushButton *pushButton[2];

    QTextBrowser *textBrowser;

    QWidget *hWidget;
    QWidget *vWidget;

    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;

    QTimer *timer;
    QString getHostInfo();

private slots:
    void timerTimeOut();
    void showHostInfo();
    void timerStart();
    void clearHostInfo();
};
#endif // MAINWINDOW_H
