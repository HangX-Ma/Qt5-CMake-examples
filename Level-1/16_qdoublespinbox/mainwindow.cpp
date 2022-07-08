#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    doubleSpinBox = new QDoubleSpinBox(this);
    doubleSpinBox->setGeometry((this->width() - 200) / 2, (this->height() - 30) / 2, 200, 30);

    doubleSpinBox->setPrefix("window size");
    doubleSpinBox->setSuffix("%");

    doubleSpinBox->setRange(50.00, 100.00);
    doubleSpinBox->setValue(100.00);
    doubleSpinBox->setSingleStep(0.1);
    connect(doubleSpinBox, SIGNAL(valueChanged(double)), SLOT(doubleSpinBoxValueChanged(double)));


}

MainWindow::~MainWindow()
{
}

void MainWindow::doubleSpinBoxValueChanged(double value) {
    int w = 800 * value / 100;
    int h = 480 * value / 100;

    this->setGeometry(0, 0, w, h);
    doubleSpinBox->setGeometry((this->width() - 200) / 2, (this->height() - 30) / 2, 200, 30);
}
