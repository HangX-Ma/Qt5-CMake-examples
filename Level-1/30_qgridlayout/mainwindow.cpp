#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    gWidget = new QWidget(this);
    this->setCentralWidget(gWidget);

    gridLayout = new QGridLayout();
    QList <QString> list;
    list<<"Btn 1"<<"Btn 2"<<"Btn 3"<<"Btn 4";
    for (int i = 0; i < 4; i++){
        pushButton[i] = new QPushButton();
        pushButton[i]->setText(list[i]);
        pushButton[i]->setMinimumSize(100, 30);
        pushButton[i]->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        switch (i) {
            case 0: gridLayout->addWidget(pushButton[i], 0, 0); break;
            case 1: gridLayout->addWidget(pushButton[i], 0, 1); break;
            case 2: gridLayout->addWidget(pushButton[i], 1, 0); break;
            case 3: gridLayout->addWidget(pushButton[i], 1, 1); break;
        }
    }

    gridLayout->setRowStretch(0, 2);
    gridLayout->setRowStretch(1, 3);
    gridLayout->setColumnStretch(0, 1);
    gridLayout->setColumnStretch(1, 3);
    gWidget->setLayout(gridLayout);


}

MainWindow::~MainWindow()
{
}

