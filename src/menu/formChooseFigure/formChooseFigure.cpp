#include "formChooseFigure.h"

extern Board* board;

void Ui_ChooseFigure::setupUi(QWidget *ChooseFigure, Color color)
{
    btnChooseBishop = new QPushButton(ChooseFigure);
    btnChooseBishop->setObjectName(QString::fromUtf8("btnChooseBishop"));
    if ((board->bottomPlayerColor == Color::white && color == Color::black) || (board->bottomPlayerColor == Color::black && color == Color::white)){
        btnChooseBishop->setGeometry(QRect(10, 880, 111, 91));
    }
    else{
        btnChooseBishop->setGeometry(QRect(10, 30, 111, 91));
    }
    QIcon icon;
    if (color == Color::black){
        icon.addFile(QString::fromUtf8(":/Chess/images/Black_Bishop.png"), QSize(), QIcon::Normal, QIcon::Off);
    }
    else if (color == Color::white){
        icon.addFile(QString::fromUtf8(":/Chess/images/White_Bishop.png"), QSize(), QIcon::Normal, QIcon::Off);
    }
    btnChooseBishop->setIcon(icon);
    btnChooseBishop->setIconSize(QSize(75, 75));
    btnChooseRook = new QPushButton(ChooseFigure);
    btnChooseRook->setObjectName(QString::fromUtf8("btnChooseRook"));
    if ((board->bottomPlayerColor == Color::white && color == Color::black) || (board->bottomPlayerColor == Color::black && color == Color::white)){
        btnChooseRook->setGeometry(QRect(130, 880, 111, 91));
    }
    else{
        btnChooseRook->setGeometry(QRect(130, 30, 111, 91));
    }
    QIcon icon1;
    if (color == Color::black){
        icon1.addFile(QString::fromUtf8(":/Chess/images/Black_Rook.png"), QSize(), QIcon::Normal, QIcon::Off);
    }
    else if (color == Color::white){
        icon1.addFile(QString::fromUtf8(":/Chess/images/White_Rook.png"), QSize(), QIcon::Normal, QIcon::Off);
    }
    btnChooseRook->setIcon(icon1);
    btnChooseRook->setIconSize(QSize(75, 75));
    btnChooseKnight = new QPushButton(ChooseFigure);
    btnChooseKnight->setObjectName(QString::fromUtf8("btnChooseKnight"));
    if ((board->bottomPlayerColor == Color::white && color == Color::black) || (board->bottomPlayerColor == Color::black && color == Color::white)){
        btnChooseKnight->setGeometry(QRect(370, 880, 111, 91));
    }
    else{
        btnChooseKnight->setGeometry(QRect(370, 30, 111, 91));
    }
    QIcon icon2;
    if (color == Color::black){
        icon2.addFile(QString::fromUtf8(":/Chess/images/Black_Knight.png"), QSize(), QIcon::Normal, QIcon::Off);
    }
    else if (color == Color::white){
        icon2.addFile(QString::fromUtf8(":/Chess/images/White_Knight.png"), QSize(), QIcon::Normal, QIcon::Off);
    }
    btnChooseKnight->setIcon(icon2);
    btnChooseKnight->setIconSize(QSize(75, 75));
    btnChooseQueen = new QPushButton(ChooseFigure);
    btnChooseQueen->setObjectName(QString::fromUtf8("btnChooseQueen"));
    if ((board->bottomPlayerColor == Color::white && color == Color::black) || (board->bottomPlayerColor == Color::black && color == Color::white)){
        btnChooseQueen->setGeometry(QRect(250, 880, 111, 91));
    }
    else{
        btnChooseQueen->setGeometry(QRect(250, 30, 111, 91));
    }
    QIcon icon3;
    if (color == Color::black){
        icon3.addFile(QString::fromUtf8(":/Chess/images/Black_Queen.png"), QSize(), QIcon::Normal, QIcon::Off);
    }
    else if (color == Color::white){
        icon3.addFile(QString::fromUtf8(":/Chess/images/White_Queen.png"), QSize(), QIcon::Normal, QIcon::Off);
    }
    btnChooseQueen->setIcon(icon3);
    btnChooseQueen->setIconSize(QSize(75, 75));

        retranslateUi(ChooseFigure);

        QMetaObject::connectSlotsByName(ChooseFigure);
} // setupUi

void Ui_ChooseFigure::retranslateUi(QWidget *ChooseFigure)
{
    ChooseFigure->setWindowTitle(QCoreApplication::translate("ChooseFigure", "ChooseFigure", nullptr));
    btnChooseBishop->setText(QString());
    btnChooseRook->setText(QString());
    btnChooseKnight->setText(QString());
    btnChooseQueen->setText(QString());
} // retranslateUi