#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    horizontalSlider = new QSlider(Qt::Horizontal, this);
    horizontalSlider->setGeometry(250, 100, 200, 20);
    horizontalSlider->setRange(0, 100);

    verticalSlider = new QSlider(Qt::Vertical, this);
    verticalSlider->setGeometry(200, 50, 20, 200);
    verticalSlider->setRange(0, 100);

    label = new QLabel("Slide Bar Val: 0", this);
    label->setGeometry(250, 200, 120, 40);

    connect(horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(horizontalSliderValueChanged(int)));
    connect(verticalSlider, SIGNAL(valueChanged(int)), this, SLOT(verticalSliderValueChanged(int)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::horizontalSliderValueChanged(int val) {
    verticalSlider->setSliderPosition(val);
    QString str = "Slide Bar Val: " + QString::number(val);
    label->setText(str);
}

void MainWindow::verticalSliderValueChanged(int val) {
    horizontalSlider->setSliderPosition(val);
}
