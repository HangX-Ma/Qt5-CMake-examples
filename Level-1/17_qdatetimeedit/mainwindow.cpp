#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    dateTimeEdit = new QDateTimeEdit(QDateTime::currentDateTime(),this);
    dateTimeEdit->setGeometry(300, 200, 200, 30);

    timeEdit = new QTimeEdit(QTime::currentTime(),this);
    timeEdit->setGeometry(300, 240, 200, 30);

    dateEdit = new QDateEdit(QDate::currentDate(),this);
    dateEdit->setGeometry(300, 280, 200, 30);
}

MainWindow::~MainWindow()
{
}

