#include "mainwindow.h"
#include <QList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    hWidget = new QWidget(this);
    hWidget->setGeometry(0, 0, 800, 240);

    vWidget = new QWidget(this);
    vWidget->setGeometry(0, 240, 800, 240);

    hLayout = new QHBoxLayout();
    vLayout = new QVBoxLayout();

    QList <QString>list;
    list<<"one"<<"two"<<"three"<<"four"<<"five"<<"six";

    for(int i = 0; i < 6; i++){
        pushButton[i] = new QPushButton();
        pushButton[i]->setText(list[i]);
        if(i < 3) {
            hLayout->addWidget(pushButton[i]);
        } else {
            vLayout->addWidget(pushButton[i]);
        }
    }
    hLayout->setSpacing(50);

    hWidget->setLayout(hLayout);
    vWidget->setLayout(vLayout);

}

MainWindow::~MainWindow()
{
}

