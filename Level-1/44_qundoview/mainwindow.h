#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QUndoView>
#include <QUndoStack>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <command.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QHBoxLayout *hLayout;
    QVBoxLayout *vLayout;
    QWidget *mainWidget;
    QWidget *widget;
    QUndoStack *undoStack;
    QUndoView *undoView;
    QLabel *label;
    QPushButton *pushButton;
    int count;

private slots:
    void pushButtonClieked();
    void showCountValue(int);
};
#endif // MAINWINDOW_H
