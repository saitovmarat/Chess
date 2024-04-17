#ifndef FORMENDGAME_H
#define FORMENDGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormEndGame 
{
public:
    QPushButton *btnGoToMainMenu;
    QPushButton *btnRestart;
    QLabel *lblWhoWin;
    void setupUi(QWidget *Form);
    void retranslateUi(QWidget *Form);

};

namespace Ui {
    class FormEndGame: public Ui_FormEndGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // FORMENDGAME_H
