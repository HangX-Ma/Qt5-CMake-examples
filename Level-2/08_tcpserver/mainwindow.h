#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpServer>
#include <QTcpSocket>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTextBrowser>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QHostInfo>
#include <QLineEdit>
#include <QNetworkInterface>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QTcpServer *tcpServer;
    QTcpSocket *tcpSocket;

    QPushButton *pushButton[4];
    QLabel *label[2];

    QWidget *hWidget[3];
    QHBoxLayout *hBoxLayout[4];

    QWidget *vWidget;
    QVBoxLayout *vBoxLayout;

    QTextBrowser *textBrowser;
    QComboBox *comboBox;
    QSpinBox *spinBox;
    QLineEdit *lineEdit;

    QList<QHostAddress> IPList;

    void getLocalHostIP();

private slots:
    void clientConnected();
    void startListen();
    void stopListen();
    void clearTextBrowser();
    void receiveMessages();
    void sendMessages();
    void socketStateChange(QAbstractSocket::SocketState);

};
#endif // MAINWINDOW_H
