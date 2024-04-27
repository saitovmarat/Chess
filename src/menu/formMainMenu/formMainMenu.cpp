#include "formMainMenu.h"
#include <QObject>
#include <QDesktopWidget>

void Ui_FormMenuChooseMode::setupUi(QWidget *Widget){
    if (Widget->objectName().isEmpty())
        Widget->setObjectName(QString::fromUtf8("Widget"));
    Widget->resize(463, 381);
    Widget->setStyleSheet(QString::fromUtf8("background-color: rgb(55, 189, 128);"));
    btnPlayWithFriend = new QPushButton(Widget);
    btnPlayWithFriend->setObjectName(QString::fromUtf8("btnPlayWithFriend"));
    btnPlayWithFriend->setGeometry(QRect(980, 530, 220, 61));
    btnPlayWithFriend->setStyleSheet("background-color: rgb(255, 255, 255);");

    QFont font;
    font.setPointSize(12);
    font.setItalic(true);
    btnPlayWithFriend->setFont(font);
    btnPlayWithComputer = new QPushButton(Widget);
    btnPlayWithComputer->setObjectName(QString::fromUtf8("btnPlayWithComputer"));
    btnPlayWithComputer->setGeometry(QRect(710, 530, 220, 61));
    btnPlayWithComputer->setFont(font);
    btnPlayWithComputer->setStyleSheet("background-color: rgb(255, 255, 255);");
    labelGameName = new QLabel(Widget);
    labelGameName->setObjectName(QString::fromUtf8("label"));
    labelGameName->setGeometry(QRect(850, 324, 71, 75));
    labelGameName->setPixmap(QPixmap(":/Chess/images/ChessLogo.png"));
    labelGameName->setStyleSheet(QString::fromUtf8("background: transparent;\n"""));
    labelPicture = new QLabel(Widget);
    labelPicture->setObjectName(QString::fromUtf8("label_2"));
    labelPicture->setGeometry(QRect(920, 340, 131, 81));
    labelPicture->setStyleSheet(QString::fromUtf8("background: transparent;\n"""));
    scene = new QGraphicsScene(Widget);

    QGraphicsRectItem* rectLeft = new QGraphicsRectItem(100, 50, 50, 100);
    rectLeft->setPen(Qt::NoPen);
    rectLeft->setBrush(QColor(111, 78, 55));
    scene->addItem(rectLeft);
    retranslateUi(Widget);
    QMetaObject::connectSlotsByName(Widget);
} // setupUi

void Ui_FormMenuChooseMode::retranslateUi(QWidget *Widget){
    Widget->setWindowTitle(QCoreApplication::translate("Widget", "GameMenu", nullptr));
    btnPlayWithFriend->setText(QCoreApplication::translate("Widget", "Сыграть с другом", nullptr));
    btnPlayWithComputer->setText(QCoreApplication::translate("Widget", "Сыграть с компьютером", nullptr));
    labelGameName->setText(QString());
    labelPicture->setText(QCoreApplication::translate("Widget", "<html><head/><body><p><span style=\" font-size:36pt;\">Chess</span></p></body></html>", nullptr));

    Widget->update();
} // retranslateUi