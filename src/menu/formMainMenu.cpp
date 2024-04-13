#include "formMainMenu.h"
#include <QObject>
void Ui_FormMenuChooseMode::setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(463, 381);
        Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 217, 230);"));
        btnPlayWithFriend = new QPushButton(Widget);
        btnPlayWithFriend->setObjectName(QString::fromUtf8("btnPlayWithFriend"));
        btnPlayWithFriend->setGeometry(QRect(230, 230, 221, 61));
        // QObject::connect(btnPlayWithFriend, &QPushButton::clicked, [&](){slots onBtnPlayWithFriendClicked();});

        QFont font;
        font.setPointSize(12);
        font.setItalic(true);
        btnPlayWithFriend->setFont(font);
        btnPlayWithComputer = new QPushButton(Widget);
        btnPlayWithComputer->setObjectName(QString::fromUtf8("btnPlayWithComputer"));
        btnPlayWithComputer->setEnabled(true);
        btnPlayWithComputer->setGeometry(QRect(10, 230, 211, 61));
        btnPlayWithComputer->setFont(font);
        btnPlayWithComputer->setLayoutDirection(Qt::LeftToRight);
        btnPlayWithComputer->setStyleSheet(QString::fromUtf8(""));
        btnPlayWithComputer->setFlat(false);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(120, 24, 71, 75));
        label->setPixmap(QPixmap(":/Chess/images/ChessLogo.png"));
        label->setScaledContents(false);
        label->setMargin(0);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(190, 40, 131, 81));

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

void Ui_FormMenuChooseMode::retranslateUi(QWidget *Widget)
{
    Widget->setWindowTitle(QCoreApplication::translate("Widget", "GameMenu", nullptr));
    btnPlayWithFriend->setText(QCoreApplication::translate("Widget", "\320\241\321\213\320\263\321\200\320\260\321\202\321\214 \321\201 \320\264\321\200\321\203\320\263\320\276\320\274", nullptr));
    btnPlayWithComputer->setText(QCoreApplication::translate("Widget", "\320\241\321\213\320\263\321\200\320\260\321\202\321\214 \321\201 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\276\320\274", nullptr));
    label->setText(QString());
    label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:36pt;\">Chess</span></p></body></html>", nullptr));
} // retranslateUi
