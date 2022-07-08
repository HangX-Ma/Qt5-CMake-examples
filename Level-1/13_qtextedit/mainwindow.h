#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTextEdit *textEdit;
    QPushButton *pushButtonSelectAll;
    QPushButton *pushButtonClearAll;

private slots:
    void pushButtonSelectAllClicked();
    void pushButtonClearAllClicked();
};
#endif // MAINWINDOW_H
