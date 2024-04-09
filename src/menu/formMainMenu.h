#ifndef FORMMAINMENU_H
#define FORMMAINMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMenuChooseMode
{
public:
    QPushButton *btnPlayWithFriend;
    QPushButton *btnPlayWithComputer;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QWidget *Widget);

    void retranslateUi(QWidget *Widget);
private slots:
    void onBtnPlayWithFriendClicked();
};


namespace Ui {
    class FormMenuChooseMode: public Ui_FormMenuChooseMode {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORMMAINMENU_H
