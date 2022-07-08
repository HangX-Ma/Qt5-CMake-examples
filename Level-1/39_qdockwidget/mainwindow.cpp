#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    dockWidget = new QDockWidget("dockWidget", this);

    textEdit = new QTextEdit(dockWidget);
    textEdit->setText("test");

    dockWidget->setWidget(textEdit);
    this->addDockWidget(Qt::TopDockWidgetArea, dockWidget);

}

MainWindow::~MainWindow()
{
}

