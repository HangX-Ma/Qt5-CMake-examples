#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setGeometry(0, 0, 800, 480);
    this->setWindowTitle("Picture Browser");

    graphicsView = new QGraphicsView(this);
    this->setCentralWidget(graphicsView);

    graphicsScene = new QGraphicsScene(this);
    graphicsView->setScene(graphicsScene);

    openAction = new QAction("open",this);
    ui->menubar->addAction(openAction);

    connect(openAction, SIGNAL(triggered()),this, SLOT(openActionTriggered()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openActionTriggered() {
    QString fileName = QFileDialog::getOpenFileName(this,tr("open files"), "", tr("Files(*.png *.jpg *.bmp)"));
    QPixmap image(fileName);
    if(image.isNull()) {
        return;
    }

    image = image.scaled(graphicsView->width(),
                         graphicsView->height(),
                         Qt::KeepAspectRatio,
                         Qt::FastTransformation
                         );
    graphicsScene->clear();
    graphicsScene->addPixmap(image);
    ui->statusbar->showMessage("File Name" + fileName);



}
