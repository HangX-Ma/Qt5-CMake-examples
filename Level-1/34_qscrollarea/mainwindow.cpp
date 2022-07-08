#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(50, 50, 700, 380);

    label = new QLabel();
    QImage image(":/images/lantingxu.png");
    label->setPixmap(QPixmap::fromImage(image));

    scrollArea->setWidget(label);


}

MainWindow::~MainWindow()
{
}

