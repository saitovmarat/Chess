/********************************************************************************
** Form generated from reading UI file 'choosefigure.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEFIGURE_H
#define UI_CHOOSEFIGURE_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "board.h"

QT_BEGIN_NAMESPACE

class Ui_ChooseFigure
{
public:
    QPushButton *btnChooseBishop;
    QPushButton *btnChooseRook;
    QPushButton *btnChooseKnight;
    QPushButton *btnChooseQueen;

    void setupUi(QWidget *ChooseFigure, Color color);

    void retranslateUi(QWidget *ChooseFigure);

};

namespace Ui {
    class ChooseFigure: public Ui_ChooseFigure {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEFIGURE_H
