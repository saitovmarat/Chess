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
        btnPlayWithFriend->setGeometry(QRect(930, 530, 221, 61));
        // QObject::connect(btnPlayWithFriend, &QPushButton::clicked, [&](){slots onBtnPlayWithFriendClicked();});
         
        QFont font;
        font.setPointSize(12);
        font.setItalic(true);
        btnPlayWithFriend->setFont(font);
        btnPlayWithComputer = new QPushButton(Widget);
        btnPlayWithComputer->setObjectName(QString::fromUtf8("btnPlayWithComputer"));
        btnPlayWithComputer->setEnabled(true);
        btnPlayWithComputer->setGeometry(QRect(710, 530, 211, 61));
        btnPlayWithComputer->setFont(font);
        btnPlayWithComputer->setLayoutDirection(Qt::LeftToRight);
        btnPlayWithComputer->setStyleSheet(QString::fromUtf8(""));
        btnPlayWithComputer->setFlat(false);
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(820, 324, 71, 75));
        label->setPixmap(QPixmap(":/Chess/images/ChessLogo.png"));
        label->setScaledContents(false);
        label->setMargin(0);
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(890, 340, 131, 81));
        mainLayout = new QGridLayout;

        // Добавление виджетов в центральную компоновку
        // mainLayout->addWidget(btnPlayWithFriend);
        // mainLayout->addWidget(btnPlayWithComputer);
        // mainLayout->addWidget(label, 0, 1);
        // mainLayout->addWidget(label_2, 0, 2);
        // mainLayout->addItem(spacer1, 0, 0);
        // mainLayout->addItem(spacer2, 0, 3);
        // mainLayout->addItem(spacer3, 1, 0);
        // mainLayout->addItem(spacer4, 1, 3);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

void Ui_FormMenuChooseMode::retranslateUi(QWidget *Widget)
{
    Widget->setWindowTitle(QCoreApplication::translate("Widget", "GameMenu", nullptr));
    btnPlayWithFriend->setText(QCoreApplication::translate("Widget", "Сыграть с другом", nullptr));
    btnPlayWithComputer->setText(QCoreApplication::translate("Widget", "Сыграть с компьютером", nullptr));
    label->setText(QString());
    label_2->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:36pt;\">Chess</span></p></body></html>", nullptr));

    Widget->setLayout(mainLayout);
} // retranslateUi
