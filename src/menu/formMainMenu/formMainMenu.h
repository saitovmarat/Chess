#ifndef FORMMAINMENU_H
#define FORMMAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QLayout>
#include <QtWidgets/QGraphicsScene>
#include <QtWidgets/QGraphicsRectItem>
#include <QPainter>
#include <QPaintEvent>
QT_BEGIN_NAMESPACE

class Ui_FormMenuChooseMode
{
public:
    QPushButton *btnPlayWithFriend;
    QPushButton *btnPlayWithComputer;
    QLabel *labelGameName;
    QLabel *labelPicture;
    QGraphicsScene *scene;
    QPainter painter;

    void setupUi(QWidget *Widget);
    
    void retranslateUi(QWidget *Widget);

    void paint(QGraphicsView *window);
};


namespace Ui {
    class FormMenuChooseMode: public Ui_FormMenuChooseMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORMMAINMENU_H
