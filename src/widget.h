#ifndef WIDGET_H
#define WIDGET_H

#include <QtGui>
#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include "ui_widget.h"


class QVBoxLayout;
class QLineEdit;
class QPushButton;


QT_BEGIN_NAMESPACE
namespace Ui{class Widget; }
QT_BEGIN_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
private:
    Ui::Widget* ui;

    QVBoxLayout* box;
};

#endif //WIDGET_H