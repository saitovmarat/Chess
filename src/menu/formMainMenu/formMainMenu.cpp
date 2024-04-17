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
        btnPlayWithComputer->setGeometry(QRect(710, 530, 211, 61));
        btnPlayWithComputer->setFont(font);

        labelGameName = new QLabel(Widget);
        labelGameName->setObjectName(QString::fromUtf8("label"));
        labelGameName->setGeometry(QRect(820, 324, 71, 75));
        labelGameName->setPixmap(QPixmap(":/Chess/images/ChessLogo.png"));
        labelPicture = new QLabel(Widget);
        labelPicture->setObjectName(QString::fromUtf8("label_2"));
        labelPicture->setGeometry(QRect(890, 340, 131, 81));

        scene = new QGraphicsScene(Widget);
        QGraphicsRectItem* rectLeft = new QGraphicsRectItem(100, 50, 50, 100);
        rectLeft->setPen(Qt::NoPen);
        rectLeft->setBrush(QColor(111, 78, 55));
        scene->addItem(rectLeft);

        retranslateUi(Widget);
        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

void Ui_FormMenuChooseMode::retranslateUi(QWidget *Widget)
{
    Widget->setWindowTitle(QCoreApplication::translate("Widget", "GameMenu", nullptr));
    btnPlayWithFriend->setText(QCoreApplication::translate("Widget", "Сыграть с другом", nullptr));
    btnPlayWithComputer->setText(QCoreApplication::translate("Widget", "Сыграть с компьютером", nullptr));
    labelGameName->setText(QString());
    labelPicture->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:36pt;\">Chess</span></p></body></html>", nullptr));

    Widget->update();
} // retranslateUi