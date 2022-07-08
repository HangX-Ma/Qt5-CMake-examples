#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    fontComboBox = new QFontComboBox(this);
    label = new QLabel(this);

    fontComboBox->setGeometry(280, 200, 200, 30);
    label->setGeometry(280, 250, 300, 50);

    connect(fontComboBox, SIGNAL(currentFontChanged(QFont)), this, SLOT(fontComboBoxFontChanged(QFont)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::fontComboBoxFontChanged(QFont font) {
    label->setFont(font);
    QString str = "Font Renderer\n Current font is：" + fontComboBox->itemText(fontComboBox->currentIndex());

    label->setText(str);
}
