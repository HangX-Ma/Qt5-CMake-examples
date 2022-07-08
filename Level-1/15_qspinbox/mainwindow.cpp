#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    this->setStyleSheet("QMainWindow{background-color: rgba(100, 100, 100, 100%) }");

    spinBox = new QSpinBox(this);
    spinBox->setGeometry(350, 200, 150, 30);
    spinBox->setRange(0, 100);
    spinBox->setSingleStep(10);
    spinBox->setValue(100);
    spinBox->setSuffix("%transparent");

    connect(spinBox,SIGNAL(valueChanged(int)), this, SLOT(spinBoxValueChanged(int)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::spinBoxValueChanged(int opacity) {
    double doubleopacity = (double)opacity / 100;
    this->setWindowOpacity(doubleopacity);
}
