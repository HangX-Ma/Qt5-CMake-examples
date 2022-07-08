#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    dial = new QDial(this);
    dial->setGeometry(300, 100, 200, 200);

    dial->setPageStep(10);
    dial->setNotchesVisible(true);
    dial->setNotchTarget(1.00);
    dial->setRange(0,100);
    dial->setWrapping(true);

    label = new QLabel(this);
    label->setGeometry(370, 300, 200, 50);

    label->setText("0km/h");

    connect(dial, SIGNAL(valueChanged(int)), this, SLOT(dialValueChanged(int)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::dialValueChanged(int val) {
    /* QString::number()转换成字符串 */
    label->setText(QString::number(val) + "km/h");
}
