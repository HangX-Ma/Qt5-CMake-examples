#include "mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    dialogButtonBox = new QDialogButtonBox(this);
    dialogButtonBox->setGeometry(300, 200, 200, 30);
    dialogButtonBox->addButton(QDialogButtonBox::Cancel);
    dialogButtonBox->button(QDialogButtonBox::Cancel)->setText("Cancel");

    pushButton = new QPushButton(tr("custom"));
    dialogButtonBox->addButton(pushButton, QDialogButtonBox::AcceptRole);

    connect(dialogButtonBox, SIGNAL(clicked(QAbstractButton*)), this, SLOT(dialogButtonBoxClicked(QAbstractButton*)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::dialogButtonBoxClicked(QAbstractButton *button) {
    if(button == dialogButtonBox->button(QDialogButtonBox::Cancel)) {
        qDebug() << "clicked 'cancel' button" << Qt::endl;
    } else if(button == pushButton) {
        qDebug() << "clicked 'custom' button" << Qt::endl;

    }

}

