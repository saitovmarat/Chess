#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>
#include <QWidget>
#include <QApplication>
#include <ui_mainwindow.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
    Ui::MainWindow* ui;
};

#endif // MAINWINDOW_H_