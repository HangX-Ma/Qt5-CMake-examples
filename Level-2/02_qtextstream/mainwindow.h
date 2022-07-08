#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QFile>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTextEdit *textEdit;
    QFile file;
    QHBoxLayout *hBoxLayout;
    QVBoxLayout *vBoxLayout;

    QWidget *hWidget;
    QWidget *vWidget;

    QPushButton *openPushButton;
    QPushButton *closePushButton;

private slots:
    bool openFile();
    void closeFile();
};
#endif // MAINWINDOW_H
