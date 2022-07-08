#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    this->setStyleSheet("QMainWindow {background-color: rgba(200, 50, 100, 100%);}");
    radioBtn1 = new QRadioButton(this);
    radioBtn2 = new QRadioButton(this);

    radioBtn1->setGeometry(300, 200, 100, 50);
    radioBtn2->setGeometry(400, 200, 100, 50);

    radioBtn1->setText("switch1");
    radioBtn2->setText("switch2");

    /* initial state setting */
    radioBtn1->setChecked(false);
    radioBtn2->setChecked(true);


}

MainWindow::~MainWindow()
{
}

