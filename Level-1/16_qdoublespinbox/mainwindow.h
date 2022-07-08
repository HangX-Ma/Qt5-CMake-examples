#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDoubleSpinBox>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QDoubleSpinBox *doubleSpinBox;

private slots:
    void doubleSpinBoxValueChanged(double);
};
#endif // MAINWINDOW_H
