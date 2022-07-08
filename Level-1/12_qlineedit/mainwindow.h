#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QLabel *label;

private slots:
    void pushButtonClicked();
};
#endif // MAINWINDOW_H
