#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    toolBox = new QToolBox(this);
    toolBox->setGeometry(300, 50, 200, 250);

    /*Tool box style*/
    toolBox->setStyleSheet("QToolBox {background-color:rgba(0, 0, 0, 30%);}");

    for(int i = 0; i < 2; i++){
        vBoxLayout[i] = new QVBoxLayout();
        groupBox[i] = new QGroupBox(this);
    }

    QList <QString>strList;
    strList<<"icon0"<<"icon1"<<"icon2"<<"icon3";

    QList <QString>iconsList;
    iconsList<<":/icons/icon0.jpg" <<":/icons/icon1.jpg"<<":/icons/icon2.jpg" <<":/icons/icon3.jpg";

    for(int i = 0; i < 4; i++){
        toolButton[i] = new QToolButton();
        toolButton[i]->setIcon(QIcon(iconsList[i]));
        toolButton[i]->setText(strList[i]);
        toolButton[i]->setFixedSize(150, 40);
        toolButton[i]->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
        if( i < 3 ) {
            vBoxLayout[0]->addWidget(toolButton[i]);
            vBoxLayout[0]->addStretch(1);
        } else {
            vBoxLayout[1]->addWidget(toolButton[i]);
            vBoxLayout[1]->addStretch(1);
        }
    }

    groupBox[0]->setLayout(vBoxLayout[0]);
    groupBox[1]->setLayout(vBoxLayout[1]);

    toolBox->addItem(groupBox[0],"Friends");
    toolBox->addItem(groupBox[1],"BlackLists");

}

MainWindow::~MainWindow()
{
}

