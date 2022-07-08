#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QPushButton>
#include <QTextBrowser>
#include <QTextEdit>
#include <QVBoxLayout>
#include <QLabel>
#include <QComboBox>
#include <QGridLayout>
#include <QMessageBox>
#include <QDebug>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
};
#endif // MAINWINDOW_H
