#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    widget = new QWidget(this);
    this->setCentralWidget(widget);

    /* multipage widget */
    tabWidget = new QTabWidget();

    hBoxLayout = new QHBoxLayout();

    QList <QString>strLabelList;
    strLabelList<<"Label1"<<"Label2"<<"Label3";

    QList <QString>strTabList;
    strTabList<<"Page1"<<"Page2"<<"Page3";

    QList <QString>iconList;
    iconList<<":/icons/icon1"<<":/icons/icon2"<<":/icons/icon3";

    for (int i = 0; i < 3; i++) {
        label[i] = new QLabel();
        label[i]->setText(strLabelList[i]);
        label[i]->setAlignment(Qt::AlignCenter); // Align center
        tabWidget->addTab(label[i],QIcon(iconList[i]),strTabList[i]);
    }
    //tabWidget->setTabsClosable(true);
    hBoxLayout->addWidget(tabWidget);
    widget->setLayout(hBoxLayout);

}

MainWindow::~MainWindow()
{
}

