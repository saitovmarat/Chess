#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QApplication>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QPushButton>


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
    void buttonClickedSlot();
private:
    Ui::Widget* ui;

    QVBoxLayout* box;
};

#endif //WIDGET_H