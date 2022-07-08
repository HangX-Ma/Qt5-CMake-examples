#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    progressBar = new QProgressBar(this);
    progressBar->setGeometry(300, 200, 200, 60);

    progressBar->setStyleSheet ("QProgressBar{"
                                "border:5px solid #FFFFFF;"
                                "height:10;"
//                                "border-image:url(:/share/battery.png);"
                                "text-align:center;"
                                "color:rgb(255,0,0);"
                                "font:20px;"
                                "border-radius:5px;}"
                                "QProgressBar::chunk{"
                                "border-radius:5px;"
                                "border:1px solid black;"
                                "background-color:black;"
                                "width:10px;margin:1px;}"
                                );
    progressBar->setRange(0, 100);
    value = 0;
    progressBar->setValue(value);
    progressBar->setFormat("Charging %p%");

    timer = new QTimer(this);
    timer->start(100);

    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeOut()));


}

MainWindow::~MainWindow()
{
}

void MainWindow::timerTimeOut() {
    value ++;
    progressBar->setValue(value);
    if(value>100) {
        value = 0;
    }
}
