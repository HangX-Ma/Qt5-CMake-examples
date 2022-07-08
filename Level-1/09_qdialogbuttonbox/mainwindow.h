#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialogButtonBox>
#include <QPushButton>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QDialogButtonBox *dialogButtonBox;
    QPushButton *pushButton;

private slots:
    void dialogButtonBoxClicked(QAbstractButton *);
};
#endif // MAINWINDOW_H
