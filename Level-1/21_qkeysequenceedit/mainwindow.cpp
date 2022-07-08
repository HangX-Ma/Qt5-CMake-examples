#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    keySequenceEdit = new QKeySequenceEdit(this);
    keySequenceEdit->setGeometry(350, 200, 150, 30);

    connect(keySequenceEdit, SIGNAL(keySequenceChanged(const QKeySequence &)), this, SLOT(KSEKeySequenceChanged(const QKeySequence &)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::KSEKeySequenceChanged(const QKeySequence &keySequence) {
    if(keySequence == QKeySequence(tr("Ctrl+Q"))) {
        this->close();
    }else {
        qDebug()<<keySequence.toString()<< Qt::endl;
    }
}
