#include "mainwindow.h"
#include "QDebug"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    setPalette(QPalette(Qt::gray));
    setAutoFillBackground(true);

    timer = new QTimer(this);
    angle = 0;
    timer->start(100);
    connect(timer, SIGNAL(timeout()), this, SLOT(timerTimeOut()));

}

MainWindow::~MainWindow()
{
}

void MainWindow::timerTimeOut() {
    this->update();
}

void MainWindow::paintEvent(QPaintEvent *) {
    QPainter painter(this);

    painter.setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);

    if (angle++ == 360) {
        angle = 0;
    }

    QPixmap image;
    image.load(":/image/cd.png");

    QRectF rect((this->width() - image.width()) / 2, (this->height() - image.height()) / 2, image.width(), image.height());

    painter.translate(0 + rect.x() + rect.width() / 2, 0 + rect.y() + rect.height() / 2);
    painter.rotate(angle);
    painter.translate(0 - (rect.x() + rect.width() / 2), 0 - (rect.y() + rect.height() / 2));
    painter.drawImage(rect, image.toImage(), image.rect());
    painter.drawRect(rect.toRect());


}
