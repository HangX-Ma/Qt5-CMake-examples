#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 800, 480);
    this->setWindowTitle("Text Browser");

    textBrowser = new QTextBrowser(this);
    this->setCentralWidget(textBrowser);

    openAction = new QAction("open",this);

    ui->menubar->addAction(openAction);
    connect(openAction, SIGNAL(triggered()),this, SLOT(openActionTriggered()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openActionTriggered() {
    QString fileName = QFileDialog::getOpenFileName(this,tr("open files"),"",tr("Files(*.txt *.cpp *.h *.html *.htm)"));

    QFile myFile(fileName);
    if(!myFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }

    QTextStream in (&myFile);
    QString myText = in.readAll();

    if(fileName.endsWith("html") || fileName.endsWith("htm")){
        textBrowser->setHtml(myText);
    } else {
        textBrowser->setPlainText(myText);
    }

    ui->statusbar->showMessage("file name:" + fileName);
}
