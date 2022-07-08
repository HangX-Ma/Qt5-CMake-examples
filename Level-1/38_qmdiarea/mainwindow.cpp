#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    pushButton = new QPushButton("New Window", this);
    pushButton->setGeometry(0, 30, 100, 30);

    mdiArea = new QMdiArea(this);
    mdiArea->setGeometry(100, 30, 700, 430);
    connect(pushButton, SIGNAL(clicked()), this, SLOT(creat_newMdiSubWindow()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::creat_newMdiSubWindow() {
    newMdiSubWindow = new QMdiSubWindow();
    newMdiSubWindow->setWindowTitle("New Window");

    /* windows will be closed and resources will be released */
    newMdiSubWindow->setAttribute(Qt::WA_DeleteOnClose);

    mdiArea->addSubWindow(newMdiSubWindow);
    newMdiSubWindow->show(); // show windows
    newMdiSubWindow->sizePolicy(); // self-adjusted window
    /* 以级联的方式排列所有窗口 */
    // mdiArea->cascadeSubWindows();
    /* 以平铺方式排列所有窗口 */
    mdiArea->tileSubWindows();

}

