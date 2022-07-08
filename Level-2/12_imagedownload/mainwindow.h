#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QFile>
#include <QLabel>
#include <QPushButton>
#include <QProgressBar>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLineEdit>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QNetworkAccessManager *networkAccessManager;
    QLabel *label[3];
    QPushButton *pushButton;
    QProgressBar *progressBar;
    QHBoxLayout *hBoxLayout[2];
    QVBoxLayout *vBoxLayout;
    QWidget *hWidget[2];
    QWidget *vWidget;
    QLineEdit *lineEdit;

private slots:
    void readyReadData();
    void replyFinished();
    void imageDownloadProgress(qint64, qint64);
    void startDownload();
    void networkReplyError(QNetworkReply::NetworkError);
};
#endif // MAINWINDOW_H
