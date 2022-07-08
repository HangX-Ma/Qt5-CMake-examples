#include "mainwindow.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    textEdit = new QTextEdit();
    vBoxLayout = new QVBoxLayout();
    hBoxLayout = new QHBoxLayout();

    vWidget = new QWidget();
    hWidget = new QWidget();

    openPushButton = new QPushButton();
    closePushButton = new QPushButton();

    openPushButton->setMinimumHeight(50);
    openPushButton->setMaximumWidth(120);
    closePushButton->setMinimumHeight(50);
    closePushButton->setMaximumWidth(120);

    openPushButton->setText("Open");
    closePushButton->setText("Close");
    closePushButton->setEnabled(false);

    hBoxLayout->addWidget(openPushButton);
    hBoxLayout->addWidget(closePushButton);
    hWidget->setLayout(hBoxLayout);

    vBoxLayout->addWidget(textEdit);
    vBoxLayout->addWidget(hWidget);
    vWidget->setLayout(vBoxLayout);

    setCentralWidget(vWidget);

    connect(openPushButton, SIGNAL(clicked()), this, SLOT(openFile()));
    connect(closePushButton, SIGNAL(clicked()), this, SLOT(closeFile()));
}

MainWindow::~MainWindow()
{
}

bool MainWindow::openFile() {
    QString fileName = QFileDialog::getOpenFileName(this);
    file.setFileName(fileName);

    if (!file.exists()) {
        return false;
    }

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return false;
    }

    QTextStream stream(&file);
    textEdit->setPlainText(stream.readAll());

    openPushButton->setEnabled(false);
    closePushButton->setEnabled(true);
    file.close();

    return true;
}

void MainWindow::closeFile() {
    /* 检测打开按钮是否可用，不可用时，说明已经打开了文件 */
    if (!openPushButton->isEnabled()) {
        /* 获取 textEdit 的文本内容 */
        QString str = textEdit->toPlainText();
        /* 以只读的方式打开 */
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            return;
        }

        QTextStream stream(&file);
        stream<<str;
        textEdit->clear();

        file.close();

        /* 重新设置打开和关闭按钮的属性 */
        openPushButton->setEnabled(true);
        closePushButton->setEnabled(false);
    }
}
