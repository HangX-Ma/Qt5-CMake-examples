#include "mainwindow.h"
#include <QNetworkInterface>
#include <QHostInfo>
#include <QThread>
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    pushButton[0] = new QPushButton();
    pushButton[1] = new QPushButton();

    pushButton[0]->setText("Get host info");
    pushButton[1]->setText("Clear text");

    /*The size of the button adapts to the text*/
    pushButton[0]->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    pushButton[1]->setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);

    hWidget = new QWidget();
    vWidget = new QWidget();

    hBoxLayout = new QHBoxLayout();
    vBoxLayout = new QVBoxLayout();

    textBrowser = new QTextBrowser();

    hBoxLayout->addWidget(pushButton[0]);
    hBoxLayout->addWidget(pushButton[1]);
    hWidget->setLayout(hBoxLayout);

    vBoxLayout->addWidget(textBrowser);
    vBoxLayout->addWidget(hWidget);
    vWidget->setLayout(vBoxLayout);
    setCentralWidget(vWidget);

    timer = new QTimer();

    connect(pushButton[0], SIGNAL(clicked()), this, SLOT(timerStart()));
    connect(pushButton[1], SIGNAL(clicked()), this, SLOT(clearHostInfo()));
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeOut()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::timerStart() {
    textBrowser->clear();
    timer->start(1000);
}

void MainWindow::timerTimeOut() {
    showHostInfo();
    timer->stop();
}

QString MainWindow::getHostInfo() {
    QString str = "Host name:" + QHostInfo::localHostName() + "\n";
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();
    foreach (QNetworkInterface interface, list) {
        str+= "Netwrok Device:" + interface.name() + "\n";
        str+= "MAC Address:" + interface.hardwareAddress() + "\n";

        QList<QNetworkAddressEntry> entryList = interface.addressEntries();

        foreach (QNetworkAddressEntry entry, entryList) {
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                str+= "IP Address:" + entry.ip().toString() + "\n";
                str+= "Subnet mask:" + entry.netmask().toString() + "\n";
                str+= "Broadcast Address:" + entry.broadcast().toString() + "\n\n";
            }
        }
    }
    return str;
}

void MainWindow::showHostInfo() {
    textBrowser->insertPlainText(getHostInfo());
}

void MainWindow::clearHostInfo() {
    if (!textBrowser->toPlainText().isEmpty()) {
        textBrowser->clear();
    }
}
