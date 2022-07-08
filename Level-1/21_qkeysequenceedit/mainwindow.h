#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QKeySequenceEdit>


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    QKeySequenceEdit *keySequenceEdit;

private slots:
    void KSEKeySequenceChanged(const QKeySequence &);

};
#endif // MAINWINDOW_H
