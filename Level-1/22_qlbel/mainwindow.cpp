#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    QPixmap pixmap(":share/logo.png");

    labelImage = new QLabel(this);
    labelImage->setGeometry(180, 150, 140, 80);
    labelImage->setPixmap(pixmap);
    labelImage->setScaledContents(true);

    labelString = new QLabel(this);
    labelString->setText("QLabel Text");
    labelString->setGeometry(300, 300, 100, 20);
}

MainWindow::~MainWindow()
{
}

