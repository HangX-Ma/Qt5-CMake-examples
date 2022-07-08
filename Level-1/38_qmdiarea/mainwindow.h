#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiSubWindow>
#include <QMdiArea>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QMdiArea *mdiArea;
    QMdiSubWindow *newMdiSubWindow;
    QPushButton *pushButton; // create new windows

private slots:
    void creat_newMdiSubWindow();

};
#endif // MAINWINDOW_H
