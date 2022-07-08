#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* Origin:(0,0), width x height = 800x480 */
    this->setGeometry(0, 0, 800, 480);

    pushBtn1 = new QPushButton("window skin1", this);
    pushBtn2 = new QPushButton("window skin2", this);

    pushBtn1->setGeometry(300,200,80,40);
    pushBtn2->setGeometry(400,200,80,40);

    connect(pushBtn1, SIGNAL(clicked()), this, SLOT(pushBtn1_clicked()));
    connect(pushBtn2, SIGNAL(clicked()), this, SLOT(pushBtn2_clicked()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::pushBtn1_clicked() {
    this->setStyleSheet("QMainWindow { background-color: rgba(255, 245, 238, 100%);}");
}

void MainWindow::pushBtn2_clicked() {
    this->setStyleSheet("QMainWindow { background-color: rgba(238, 122, 233, 100%);}");
}
