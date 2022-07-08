#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QPushButton *pushButton[6];

    QWidget *hWidget;
    QWidget *vWidget;

    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;

private slots:

};
#endif // MAINWINDOW_H
