#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    comboBox = new QComboBox(this);
    comboBox->setGeometry(300, 200, 150, 30);
    comboBox->addItem("GuangDong");
    comboBox->addItem("Hunan");
    comboBox->addItem("SiChuan");

    connect(comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(comboBoxIndexChanged(int)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::comboBoxIndexChanged(int index) {
    qDebug()<<"Selected province is "<< comboBox->itemText(index)<< Qt::endl;
}
