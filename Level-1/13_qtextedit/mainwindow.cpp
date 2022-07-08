#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    textEdit = new QTextEdit(this);
    textEdit->setGeometry(0, 0, 800, 400);

    pushButtonSelectAll = new QPushButton(this);
    pushButtonSelectAll->setGeometry(200, 420, 50, 20);
    pushButtonSelectAll->setText("select all");

    pushButtonClearAll = new QPushButton(this);
    pushButtonClearAll->setGeometry(500, 420, 50, 20);
    pushButtonClearAll->setText("clear");

    connect(pushButtonSelectAll, SIGNAL(clicked()), this, SLOT(pushButtonSelectAllClicked()));
    connect(pushButtonClearAll, SIGNAL(clicked()), this, SLOT(pushButtonClearAllClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::pushButtonSelectAllClicked() {
    /* set focus point */
    textEdit->setFocus();

    if(!textEdit->toPlainText().isEmpty()){
        textEdit->selectAll();
    }
}

void MainWindow::pushButtonClearAllClicked() {
    textEdit->clear();
}
