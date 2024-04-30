#include "formMenuChooseColor.h"

void Ui_FormMenuChooseColor::setupUi(QWidget *FormChooseColor)
    {
        if (FormChooseColor->objectName().isEmpty())
            FormChooseColor->setObjectName(QString::fromUtf8("FormChooseColor"));
        FormChooseColor->resize(400, 300);
        FormChooseColor->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 189, 128);"));
        btnChooseRandomColor = new QPushButton(FormChooseColor);
        btnChooseRandomColor->setObjectName(QString::fromUtf8("btnChooseRandomColor"));
        btnChooseRandomColor->setGeometry(QRect(900, 530, 111, 81));
        btnChooseRandomColor->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(169, 169, 169); }");
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/Chess/images/Wbk.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnChooseRandomColor->setIcon(icon);
        btnChooseRandomColor->setIconSize(QSize(65, 65));
        btnChooseBlackColor = new QPushButton(FormChooseColor);
        btnChooseBlackColor->setObjectName(QString::fromUtf8("btnChooseBlackColor"));
        btnChooseBlackColor->setGeometry(QRect(800, 540, 91, 61));
        btnChooseBlackColor->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(169, 169, 169); }");
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/Chess/images/Black_King.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnChooseBlackColor->setIcon(icon1);
        btnChooseBlackColor->setIconSize(QSize(55, 55));
        btnChooseWhiteColor = new QPushButton(FormChooseColor);
        btnChooseWhiteColor->setObjectName(QString::fromUtf8("btnChooseWhiteColor"));
        btnChooseWhiteColor->setGeometry(QRect(1020, 540, 101, 61));
        btnChooseWhiteColor->setStyleSheet("QPushButton { background-color: rgb(255, 255, 255); } QPushButton:hover { background-color: rgb(169, 169, 169); }");
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/Chess/images/White_King.png"), QSize(), QIcon::Normal, QIcon::Off);
        btnChooseWhiteColor->setIcon(icon2);
        btnChooseWhiteColor->setIconSize(QSize(55, 55));
        lblChooseColor = new QLabel(FormChooseColor);
        lblChooseColor->setObjectName(QString::fromUtf8("lblChooseColor"));
        lblChooseColor->setGeometry(QRect(860, 360, 271, 51));
        lblChooseColor->setStyleSheet(QString::fromUtf8("background: transparent;\n"""));
        retranslateUi(FormChooseColor);

        QMetaObject::connectSlotsByName(FormChooseColor);
    } // setupUi

void Ui_FormMenuChooseColor::retranslateUi(QWidget *FormChooseColor)
    {
        FormChooseColor->setWindowTitle(QCoreApplication::translate("FormChooseColor", "PlayWithComputer", nullptr));
        lblChooseColor->setText(QCoreApplication::translate("FormChooseColor", "<html><head/><body><p><span style=\" font-size:20pt;\">Выберите цвет</span></p></body></html>", nullptr));
    } // retranslateUi