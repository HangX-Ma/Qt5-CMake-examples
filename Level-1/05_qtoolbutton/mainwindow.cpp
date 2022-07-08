#include "mainwindow.h"
#include <QApplication>
#include <QStyle>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);
    toolBar = new QToolBar(this);
    toolBar->setGeometry(0, 0, 800, 100);

    QStyle *style = QApplication::style();
    QIcon icon = style->standardIcon(QStyle::SP_TitleBarContextHelpButton);

    toolButton = new QToolButton();
    toolButton->setIcon(icon);
    toolButton->setText("help");
    toolButton->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
    toolBar->addWidget(toolButton);

}

MainWindow::~MainWindow()
{
}

