#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    lcdNumber = new QLCDNumber(this);
    lcdNumber->setGeometry(300, 200, 200, 50);
    lcdNumber->setDigitCount(8);
    lcdNumber->setSegmentStyle(QLCDNumber::Flat);

    QTime time = QTime::currentTime();
    lcdNumber->display(time.toString("hh:mm:ss"));

    timer = new QTimer(this);
    timer->start(1000); // 1000ms

    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeOut()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::timerTimeOut() {
    QTime time = QTime::currentTime();
    lcdNumber->display(time.toString("hh:mm:ss"));
}
