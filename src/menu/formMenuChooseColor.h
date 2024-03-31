#ifndef FORMMENUCHOOSECOLOR_H
#define FORMMENUCHOOSECOLOR_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_formMenuChooseColor
{
public:
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QLabel *label_2;

    void setupUi(QWidget *Form123);

    void retranslateUi(QWidget *Form123);

};

namespace Ui {
    class formMenuChooseColor: public Ui_formMenuChooseColor {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORMMENUCHOOSECOLOR_H
