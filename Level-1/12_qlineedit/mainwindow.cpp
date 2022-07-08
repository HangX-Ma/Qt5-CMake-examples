#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    lineEdit = new QLineEdit(this);
    lineEdit->setGeometry(280, 200, 200, 20);

    pushButton = new QPushButton(this);
    pushButton->setGeometry(500, 200, 50, 20);
    pushButton->setText("Confirm");

    label = new QLabel(this);
    label->setGeometry(280, 250, 400, 20);
    label->setText("Your input content is: ");

    connect(pushButton,SIGNAL(clicked()), this, SLOT(pushButtonClicked()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::pushButtonClicked() {
    QString str;

    str = "Your input content is: ";
    str += lineEdit->text();
    label->setText(str);

    /* clear lineEdit input area after 'confirm' is clicked */
    lineEdit->clear();
}
