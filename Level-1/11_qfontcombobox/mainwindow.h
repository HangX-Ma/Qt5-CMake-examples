#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontComboBox>
#include <QLabel>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QFontComboBox *fontComboBox;
    QLabel *label;

private slots:
    void fontComboBoxFontChanged(QFont);
};
#endif // MAINWINDOW_H
