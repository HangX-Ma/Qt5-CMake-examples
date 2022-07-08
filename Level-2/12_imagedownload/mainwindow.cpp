#include "mainwindow.h"
#include <QMessageBox>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    label[0] = new QLabel(); // download image
    label[1] = new QLabel(); // url
    label[2] = new QLabel(); // download progress

    lineEdit = new QLineEdit(); // url input
    pushButton = new QPushButton(); // download button
    progressBar = new QProgressBar(); // download progress bar

    hBoxLayout[0] = new QHBoxLayout();
    hBoxLayout[1] = new QHBoxLayout();

    vBoxLayout = new QVBoxLayout();

    hWidget[0] = new QWidget();
    hWidget[1] = new QWidget();

    vWidget = new QWidget();

    label[1]->setText("URL Link: ");
    label[2]->setText("Download Progress: ");

    pushButton->setText("Download");

    lineEdit->setText("https://ss0.bdstatic.com/70cFuHSh_Q1YnxGkpoWK1HF6hhy/it/u=4271087328,1384669424&fm=11&gp=0.jpg");

    label[0]->setMinimumSize(this->width(), this->height() * 0.75);

    label[1]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    label[2]->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    pushButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    hBoxLayout[0]->addWidget(label[1]);
    hBoxLayout[0]->addWidget(lineEdit);
    hBoxLayout[0]->addWidget(pushButton);
    hWidget[0]->setLayout(hBoxLayout[0]);


    hBoxLayout[1]->addWidget(label[2]);
    hBoxLayout[1]->addWidget(progressBar);
    hWidget[1]->setLayout(hBoxLayout[1]);

    vBoxLayout->addWidget(label[0]);
    vBoxLayout->addWidget(hWidget[0]);
    vBoxLayout->addWidget(hWidget[1]);

    vWidget->setLayout(vBoxLayout);
    setCentralWidget(vWidget);

    networkAccessManager = new QNetworkAccessManager(this);
    connect(pushButton, SIGNAL(clicked()), this, SLOT(startDownload()));


}

MainWindow::~MainWindow()
{
}

void MainWindow::startDownload() {
    QUrl newUrl(QUrl(lineEdit->text()));
    if (!newUrl.isValid()) {
        QMessageBox::information(this, "error", "invalid url");
        return;
    }

    QNetworkRequest networkRequest;
    networkRequest.setUrl(newUrl);
    QNetworkReply *newReply = networkAccessManager->get(networkRequest);

    connect(newReply, SIGNAL(finished()), this, SLOT(replyFinished()));
    connect(newReply, SIGNAL(readyRead()), this, SLOT(readyReadData()));
    connect(newReply, SIGNAL(downloadProgress(qint64,qint64)), this, SLOT(imageDownloadProgress(qint64,qint64)));
    connect(newReply, SIGNAL(error(QNetworkReply::NetworkError)), this, SLOT(networkReplyError(QNetworkReply::NetworkError)));
}

void MainWindow::readyReadData() {
    pushButton->setEnabled(false);
    QNetworkReply *reply = (QNetworkReply *)sender();
    QFile imageFile;
    imageFile.setFileName(QCoreApplication::applicationDirPath() + "/download.jpg");

    if (imageFile.exists()) {
        imageFile.remove();
    }

    QByteArray data = reply->readAll();

    if (data.isEmpty()) {
        qDebug()<<"data is null, please try it again!"<< Qt::endl;
        return;
    }

    if (! (data[0] == (char)0xff && data[1] == (char)0xd8 && data[data.size() - 2] == (char)0xff && data[data.size() - 1] == (char)0xd9)) {
        qDebug()<<"not JPG data, please try it again!"<<Qt::endl;
        return;
    }

    QPixmap pixmap;
    pixmap.loadFromData(data);
    pixmap.save(imageFile.fileName());


}


void MainWindow::replyFinished() {
    QNetworkReply *reply = (QNetworkReply *)sender();
    reply->deleteLater();
    QFile imageFile(QCoreApplication::applicationDirPath() + "/download.jpg");

    if (imageFile.exists()) {
        label[0]->setPixmap(QPixmap(imageFile.fileName()));
        qDebug() <<"Download successfully. File Path: "<<imageFile.fileName()<<Qt::endl;
    } else {
        label[0]->clear();
    }

    pushButton->setEnabled(true);
}


void MainWindow::imageDownloadProgress(qint64 bytes, qint64 totalBytes) {
    progressBar->setMaximum(totalBytes);
    progressBar->setValue(bytes);
}

// deal with the Reply ERROR
void MainWindow::networkReplyError(QNetworkReply::NetworkError error) {
    switch (error) {
        case QNetworkReply::ConnectionRefusedError:
            qDebug()<<"Remote host refuse connection."<<Qt::endl;
            break;
        case QNetworkReply::HostNotFoundError:
            qDebug()<<"Can not find the remote host name."<<Qt::endl;
            break;
        case QNetworkReply::TimeoutError:
            qDebug()<<"Remote host onnection timeout."<<Qt::endl;
            break;
        default:
        break;
    }
}























