#include "mainwindow.h"
#include "QFileDialog"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    listWidget = new QListWidget(this);
    listWidget->setGeometry(0, 0, 480, 480);
    listWidget->addItem("click 'Add' to add item");

    pushButton = new QPushButton(this);
    pushButton->setGeometry(540, 200, 200, 100);
    pushButton->setText("Add");

    connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClicked()));
}

MainWindow::~MainWindow()
{
}

void MainWindow::pushButtonClicked() {
    /* 调用系统打开文件窗口，设置窗口标题为“打开文件”，过滤文件名 */
    QString fileName = QFileDialog::getOpenFileName(this,tr("Add"),"", tr("Files(*.mp3)"));

    if (fileName != NULL) {
        listWidget->addItem(fileName);
    }
}
