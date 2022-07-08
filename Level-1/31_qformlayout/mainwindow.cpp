#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    fWidget = new QWidget(this);
    fWidget->setGeometry(250, 100, 300, 200);

    userLineEdit = new QLineEdit();
    passwordLineEdit = new QLineEdit();

    formLayout = new QFormLayout();
    formLayout->addRow("username:", userLineEdit);
    formLayout->addRow("password:", passwordLineEdit);

    formLayout->setSpacing(10);
    formLayout->setMargin(20);

    fWidget->setLayout(formLayout);
}

MainWindow::~MainWindow()
{
}

