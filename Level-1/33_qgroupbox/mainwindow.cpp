#include "mainwindow.h"
#include <QList>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    groupBox = new QGroupBox(tr("QGroupBox"), this);
    groupBox->setGeometry(300, 100, 300, 200);

    vBoxLayout = new QVBoxLayout();

    QList <QString>list;

    list<<"option1"<<"option2"<<"option3";
    for(int i = 0; i < 3; i++){
        radioButton[i] = new QRadioButton();
        radioButton[i]->setText(list[i]);
        vBoxLayout->addWidget(radioButton[i]);
    }

    vBoxLayout->addStretch(1);
    groupBox->setLayout(vBoxLayout);
}

MainWindow::~MainWindow()
{
}

