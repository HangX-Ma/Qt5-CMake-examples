#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBox>
#include <QGroupBox>
#include <QToolButton>
#include <QVBoxLayout>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QToolBox *toolBox;
    QGroupBox *groupBox[2];
    QVBoxLayout *vBoxLayout[2];
    QToolButton *toolButton[4];

};
#endif // MAINWINDOW_H
