#include "mainwindow.h"
#include <QDesktopServices>
#include <QUrl>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    commandLinkButton = new QCommandLinkButton("open /home directory", "click and open the nautilus addressed in /home", this);

    commandLinkButton->setGeometry(300, 200, 250, 60);

    connect(commandLinkButton, SIGNAL(clicked()), this, SLOT(commandLinkButtonClicked()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::commandLinkButtonClicked() {
    QDesktopServices::openUrl(QUrl("file:////home/") );
}
