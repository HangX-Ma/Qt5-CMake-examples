#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    widget = new QWidget(this);
    this->setCentralWidget(widget);

    hBoxLayout = new QHBoxLayout();
    stackedWidget = new QStackedWidget();
    listWidget = new QListWidget();

    QList <QString>strListWidgetList;
    strListWidgetList<<"window1"<<"window2"<<"window3";

    for (int i = 0; i < 3; i++){
        listWidget->insertItem(i,strListWidgetList[i]);
    }

    QList <QString>strLabelList;
    strLabelList<<"Label1"<<"Label2"<<"Label3";
    for (int i = 0; i < 3; i++){
        label[i] = new QLabel();
        label[i]->setText(strLabelList[i]);
        label[i]->setAlignment(Qt::AlignCenter);
        stackedWidget->addWidget(label[i]);
    }
    listWidget->setMaximumWidth(200);
    hBoxLayout->addWidget(listWidget);
    hBoxLayout->addWidget(stackedWidget);
    widget->setLayout(hBoxLayout);

    connect(listWidget, SIGNAL(currentRowChanged(int)),stackedWidget, SLOT(setCurrentIndex(int)));

}

MainWindow::~MainWindow()
{
}

