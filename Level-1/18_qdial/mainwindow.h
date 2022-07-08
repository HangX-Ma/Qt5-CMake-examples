#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDial>
#include <QLabel>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QDial *dial;
    QLabel *label;

private slots:
    void dialValueChanged(int);

};
#endif // MAINWINDOW_H
