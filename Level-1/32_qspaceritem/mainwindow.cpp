#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    widget = new QWidget(this);
    this->setCentralWidget(widget);

    vSpacer = new QSpacerItem(10, 10, QSizePolicy::Minimum, QSizePolicy::Expanding);
    hSpacer = new QSpacerItem(10, 10, QSizePolicy::Expanding, QSizePolicy::Minimum);

    vBoxLayout = new QVBoxLayout();
    hBoxLayout = new QHBoxLayout();
    mainLayout = new QHBoxLayout();

    vBoxLayout->addSpacerItem(vSpacer);

    QList <QString>list;
    list<<"Btn 1"<<"Btn 2"<<"Btn 3"<<"Btn 4";

    for(int i = 0; i < 4 ; i++){
        bt[i] = new QPushButton();
        bt[i]->setText(list[i]);
        if (i == 0){
            bt[i]->setFixedSize(100, 100);
            vBoxLayout->addWidget(bt[i]);
        } else {
            bt[i]->setFixedSize(60, 60);
            hBoxLayout->addWidget(bt[i]);
        }
    }

    hBoxLayout->addSpacerItem(hSpacer);

    mainLayout->addLayout(vBoxLayout);
    mainLayout->addLayout(hBoxLayout);

    /* Widget space */
    mainLayout->setSpacing(50);
    widget->setLayout(mainLayout);

}

MainWindow::~MainWindow()
{
}

