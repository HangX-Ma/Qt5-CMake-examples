#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void pushButtonTextChanged();

public slots:
    void changeButtonText();

    void pushButtionClicked();

private:
    QPushButton *pushBtn;
};
#endif // MAINWINDOW_H
