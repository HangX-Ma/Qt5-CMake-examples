#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    /* set main window size and sytle */
    this->setGeometry(0,0,800,480);
    this->setStyleSheet("QMainWindow {background-color: rgba(100, 100, 100, 100%);}");

    checkbox = new QCheckBox(this);

    checkbox->setGeometry(350, 200, 250, 50);

    /* set initial state */
    checkbox->setCheckState(Qt::Checked);
    checkbox->setText("initialize to 'Cheked' state");
    checkbox->setTristate();

    connect(checkbox, SIGNAL(stateChanged(int)), this, SLOT(checkBoxStateChanged(int)));
}

MainWindow::~MainWindow()
{
}

void MainWindow::checkBoxStateChanged(int state) {
    switch(state) {
        case Qt::Checked:
            checkbox->setText("Checked"); break;
        case Qt::Unchecked:
            checkbox->setText("Unchecked"); break;
        case Qt::PartiallyChecked:
            checkbox->setText("PartiallyChecked"); break;
        default:
            break;
    }
}

