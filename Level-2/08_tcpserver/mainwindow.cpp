#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    tcpServer = new QTcpServer(this);
    tcpSocket = new QTcpSocket(this);

    pushButton[0] = new QPushButton(); // start listening
    pushButton[1] = new QPushButton(); // stop listening
    pushButton[2] = new QPushButton(); // clear text
    pushButton[3] = new QPushButton(); // send message

    hBoxLayout[0] = new QHBoxLayout();
    hBoxLayout[1] = new QHBoxLayout();
    hBoxLayout[2] = new QHBoxLayout();
    hBoxLayout[3] = new QHBoxLayout();

    hWidget[0] = new QWidget();
    hWidget[1] = new QWidget();
    hWidget[2] = new QWidget();

    vWidget = new QWidget();
    vBoxLayout = new QVBoxLayout();

    label[0] = new QLabel();
    label[1] = new QLabel();

    lineEdit = new QLineEdit();
    comboBox = new QComboBox();
    spinBox = new QSpinBox();
    textBrowser = new QTextBrowser();

    label[0]->setText("Listening IP Address: ");
    label[1]->setText("Listening Port: ");

    label[0]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    label[1]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    spinBox->setRange(10000, 99999);
    pushButton[0]->setText("Start Listening");
    pushButton[1]->setText("Stop Listening");
    pushButton[2]->setText("Clear Text");
    pushButton[3]->setText("Send Message");

    pushButton[1]->setEnabled(false);
    lineEdit->setText("Default Content");

    hBoxLayout[0]->addWidget(pushButton[0]);
    hBoxLayout[0]->addWidget(pushButton[1]);
    hBoxLayout[0]->addWidget(pushButton[2]);

    /* widget 1 */
    hWidget[0]->setLayout(hBoxLayout[0]);

    hBoxLayout[1]->addWidget(label[0]);
    hBoxLayout[1]->addWidget(comboBox);
    hBoxLayout[1]->addWidget(label[1]);
    hBoxLayout[1]->addWidget(spinBox);

    /* widget 2 */
    hWidget[1]->setLayout(hBoxLayout[1]);

    hBoxLayout[2]->addWidget(lineEdit);
    hBoxLayout[2]->addWidget(pushButton[3]);

    /* widget 3 */
    hWidget[2]->setLayout(hBoxLayout[2]);

    vBoxLayout->addWidget(textBrowser);
    vBoxLayout->addWidget(hWidget[1]);
    vBoxLayout->addWidget(hWidget[0]);
    vBoxLayout->addWidget(hWidget[2]);

    vWidget->setLayout(vBoxLayout);

    setCentralWidget(vWidget);
    getLocalHostIP();

    connect(pushButton[0], SIGNAL(clicked()), this, SLOT(startListen()));
    connect(pushButton[1], SIGNAL(clicked()), this, SLOT(stopListen()));
    connect(pushButton[2], SIGNAL(clicked()), this, SLOT(clearTextBrowser()));
    connect(pushButton[3], SIGNAL(clicked()), this, SLOT(sendMessages()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(clientConnected()));

}

MainWindow::~MainWindow()
{
}


void MainWindow::clientConnected() {
    tcpSocket = tcpServer->nextPendingConnection();
    QString ip = tcpSocket->peerAddress().toString();
    quint16 port = tcpSocket->peerPort();
    textBrowser->append("Client connected");
    textBrowser->append("Client IP Address: " + ip);
    textBrowser->append("Client Port:" + QString::number(port));

    connect(tcpSocket, SIGNAL(readyRead()), this, SLOT(receiveMessages()));
    connect(tcpSocket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(socketStateChange(QAbstractSocket::SocketState)));
}

void MainWindow::getLocalHostIP() {
    QList<QNetworkInterface> list = QNetworkInterface::allInterfaces();

    foreach (QNetworkInterface interface, list) {
        QList<QNetworkAddressEntry> entryList = interface.addressEntries();

        foreach (QNetworkAddressEntry entry, entryList) {
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol) {
                comboBox->addItem(entry.ip().toString());
                IPList<<entry.ip();
            }
        }
    }
}

void MainWindow::startListen() {
    if (comboBox->currentIndex() != -1) {
        qDebug()<<"start listen"<<Qt::endl;
        tcpServer->listen(IPList[comboBox->currentIndex()], spinBox->value());

        pushButton[0]->setEnabled(false);
        pushButton[1]->setEnabled(true);
        comboBox->setEnabled(false);
        spinBox->setEnabled(false);

        textBrowser->append("Server IP Address: " + comboBox->currentText());
        textBrowser->append("Listening Port: " + spinBox->text());
    }
}

void MainWindow::stopListen() {
    qDebug()<<"stop listen"<<Qt::endl;
    tcpServer->close();

    if (tcpSocket->state() == tcpSocket->ConnectedState) {
        tcpSocket->disconnectFromHost();
     }

    pushButton[1]->setEnabled(false);
    pushButton[0]->setEnabled(true);
    comboBox->setEnabled(true);
    spinBox->setEnabled(true);

    textBrowser->append("Stop listening port: " + spinBox->text());
}

void MainWindow::clearTextBrowser() {
    textBrowser->clear();
}

void MainWindow::receiveMessages() {
    QString messages = "Client: " + tcpSocket->readAll();
    textBrowser->append(messages);

}

void MainWindow::sendMessages() {
    if(NULL == tcpSocket) {
        return;
    }

    if(tcpSocket->state() == tcpSocket->ConnectedState) {
        tcpSocket->write(lineEdit->text().toUtf8().data());
        textBrowser->append("Server: " + lineEdit->text());
    }
}

void MainWindow::socketStateChange(QAbstractSocket::SocketState state) {
    switch (state) {
        case QAbstractSocket::UnconnectedState: textBrowser->append("scoket State: UnconnectedState"); break;
        case QAbstractSocket::ConnectedState: textBrowser->append("scoket State: ConnectedState"); break;
        case QAbstractSocket::ConnectingState: textBrowser->append("scoket State: ConnectingState"); break;
        case QAbstractSocket::HostLookupState: textBrowser->append("scoket State: HostLookupState"); break;
        case QAbstractSocket::ClosingState: textBrowser->append("scoket State: ClosingState"); break;
        case QAbstractSocket::ListeningState: textBrowser->append("scoket State: ListeningState"); break;
        case QAbstractSocket::BoundState: textBrowser->append("scoket State: BoundState"); break;
        default: break;
     }
}
