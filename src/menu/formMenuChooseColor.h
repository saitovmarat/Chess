#ifndef FORMMENUCHOOSECOLOR_H
#define FORMMENUCHOOSECOLOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormMenuChooseColor
{
public:
    QPushButton *btnChooseRandomColor;
    QPushButton *btnChooseBlackColor;
    QPushButton *btnChooseWhiteColor;
    QLabel *lblPlayWithComputer;

    void setupUi(QWidget *FormChooseColor);

    void retranslateUi(QWidget *FormChooseColor);

};

namespace Ui {
    class formMenuChooseColor: public Ui_FormMenuChooseColor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORMMENUCHOOSECOLOR_H
