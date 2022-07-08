#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QScrollBar>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QScrollBar *horizontalScrollBar;
    QScrollBar *verticalScrollBar;
    QLabel *label;

};
#endif // MAINWINDOW_H
