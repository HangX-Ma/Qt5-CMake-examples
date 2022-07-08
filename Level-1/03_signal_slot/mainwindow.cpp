#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->resize(800,480);

    pushBtn = new QPushButton(this);

    pushBtn->setText("This is a button");

    connect(pushBtn, SIGNAL(clicked()), this, SLOT(pushButtionClicked()));
    connect(this, SIGNAL(pushButtonTextChanged()), this, SLOT(changeButtonText()));
}

MainWindow::~MainWindow()
{
    delete pushBtn;
    pushBtn = nullptr;
}

void MainWindow::pushButtionClicked() {
    emit pushButtonTextChanged();
}

void MainWindow::changeButtonText() {
    pushBtn->setText("Clicked!");
}

