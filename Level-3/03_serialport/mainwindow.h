#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QSerialPort *serialPort;
    QTextBrowser *textBrowser;  // received data display module
    QTextEdit *textEdit;        // data sender
    QPushButton *pushButton[2];
    QComboBox *comboBox[5];     // selection box
    QLabel *label[5];
    QVBoxLayout *vboxLayout;
    QGridLayout *gridLayout;
    QWidget *mainWidget;
    QWidget *funcWidget;

    /* 布局初始化 */
    void layoutInit();

    /* 扫描系统可用串口 */
    void scanSerialPort();

    /* 波特率项初始化 */
    void baudRateItemInit();

    /* 数据位项初始化 */
    void dataBitsItemInit();

    /* 检验位项初始化 */
    void parityItemInit();

    /* 停止位项初始化 */
    void stopBitsItemInit();

private slots:
    void sendPushButtonClicked();
    void openSerialPortPushButtonClicked();
    void serialPortReadyRead();

};
#endif // MAINWINDOW_H
