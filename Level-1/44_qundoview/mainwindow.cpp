#include "mainwindow.h"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setGeometry(0, 0, 800, 480);

    hLayout = new QHBoxLayout();
    vLayout = new QVBoxLayout();

    mainWidget = new QWidget();
    widget = new QWidget();

    widget->setMinimumSize(400, 480);

    undoStack = new QUndoStack(this);
    undoView = new QUndoView(undoStack);

    pushButton = new QPushButton();
    label = new QLabel();

    hLayout->addWidget(widget);
    hLayout->addWidget(undoView);

    count = 0;
    label->setText("Result:" + QString::number(count));
    label->setAlignment(Qt::AlignCenter);
    label->setMaximumHeight(this->height() / 5);

    vLayout->addWidget(label);
    vLayout->addWidget(pushButton);

    pushButton->setMaximumHeight(this->height() / 5);
    pushButton->setText("Add 1");

    widget->setLayout(vLayout);
    mainWidget->setLayout(hLayout);

    this->setCentralWidget(mainWidget);

    connect(pushButton, SIGNAL(clicked()), this, SLOT(pushButtonClieked()));
    connect(undoStack, SIGNAL(indexChanged(int)),this, SLOT(showCountValue(int)));

}

MainWindow::~MainWindow()
{
}

void MainWindow::pushButtonClieked() {
    count++;
    int *value = &count;

    QUndoCommand *add = new addCommand(value);
    undoStack->push(add);
}

void MainWindow::showCountValue(int) {
    label->setText("Result:" + QString::number(count));
}
