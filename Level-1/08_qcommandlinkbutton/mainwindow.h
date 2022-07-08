#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCommandLinkButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QCommandLinkButton *commandLinkButton;

private slots:
    void commandLinkButtonClicked();
};
#endif // MAINWINDOW_H
