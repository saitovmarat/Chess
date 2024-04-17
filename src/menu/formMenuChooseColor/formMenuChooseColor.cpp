#include "formMenuChooseColor.h"

void Ui_FormMenuChooseColor::setupUi(QWidget *FormChooseColor)
    {
        if (FormChooseColor->objectName().isEmpty())
            FormChooseColor->setObjectName(QString::fromUtf8("FormChooseColor"));
        FormChooseColor->resize(400, 300);
        FormChooseColor->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 217, 230);"));
        btnChooseRandomColor = new QPushButton(FormChooseColor);
        btnChooseRandomColor->setObjectName(QString::fromUtf8("btnChooseRandomColor"));
        btnChooseRandomColor->setGeometry(QRect(850, 430, 111, 81));
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Chess/images/NewWbk.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnChooseRandomColor->setIcon(icon);
        btnChooseRandomColor->setIconSize(QSize(65, 65));
        btnChooseBlackColor = new QPushButton(FormChooseColor);
        btnChooseBlackColor->setObjectName(QString::fromUtf8("btnChooseBlackColor"));
        btnChooseBlackColor->setGeometry(QRect(750, 440, 91, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Chess/images/bK.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnChooseBlackColor->setIcon(icon1);
        btnChooseBlackColor->setIconSize(QSize(55, 55));
        btnChooseWhiteColor = new QPushButton(FormChooseColor);
        btnChooseWhiteColor->setObjectName(QString::fromUtf8("btnChooseWhiteColor"));
        btnChooseWhiteColor->setGeometry(QRect(970, 440, 101, 61));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Chess/images/wK.svg"), QSize(), QIcon::Normal, QIcon::Off);
        btnChooseWhiteColor->setIcon(icon2);
        btnChooseWhiteColor->setIconSize(QSize(55, 55));
        lblPlayWithComputer = new QLabel(FormChooseColor);
        lblPlayWithComputer->setObjectName(QString::fromUtf8("lblPlayWithComputer"));
        lblPlayWithComputer->setGeometry(QRect(770, 330, 271, 51));
        lblPlayWithComputer->setStyleSheet(QString::fromUtf8("background: transparent;\n"""));
        retranslateUi(FormChooseColor);

        QMetaObject::connectSlotsByName(FormChooseColor);
    } // setupUi

void Ui_FormMenuChooseColor::retranslateUi(QWidget *FormChooseColor)
    {
        FormChooseColor->setWindowTitle(QCoreApplication::translate("FormChooseColor", "PlayWithComputer", nullptr));
        lblPlayWithComputer->setText(QCoreApplication::translate("FormChooseColor", "<html><head/><body><p><span style=\" font-size:16pt;\">Выберите цвет</span></p></body></html>", nullptr));
    } // retranslateUi