#include "formEndGame.h"

void Ui_FormEndGame::setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QString::fromUtf8("Form"));
        Form->resize(400, 300);
        Form->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 217, 230);"));
        btnGoToMainMenu = new QPushButton(Form);
        btnGoToMainMenu->setObjectName(QString::fromUtf8("btnGoToMainMenu"));
        btnGoToMainMenu->setGeometry(QRect(190, 180, 171, 41));
        QFont font;
        font.setPointSize(12);
        font.setItalic(true);
        btnGoToMainMenu->setFont(font);
        btnRestart = new QPushButton(Form);
        btnRestart->setObjectName(QString::fromUtf8("btnRestart"));
        btnRestart->setEnabled(true);
        btnRestart->setGeometry(QRect(30, 180, 151, 41));
        btnRestart->setFont(font);
        btnRestart->setLayoutDirection(Qt::LeftToRight);
        btnRestart->setStyleSheet(QString::fromUtf8(""));
        btnRestart->setFlat(false);
        lblWhoWin = new QLabel(Form);
        lblWhoWin->setObjectName(QString::fromUtf8("lblWhoWin"));
        lblWhoWin->setGeometry(QRect(90, 50, 271, 51));

        retranslateUi(Form);
        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void Ui_FormEndGame::retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        btnGoToMainMenu->setText(QCoreApplication::translate("Form", "\320\222 \320\263\320\273\320\260\320\262\320\275\320\276\320\265 \320\274\320\265\320\275\321\216", nullptr));
        btnRestart->setText(QCoreApplication::translate("Form", "\320\240\320\265\320\262\320\260\320\275\321\210", nullptr));
        lblWhoWin->setText(QCoreApplication::translate("Form", "<html><head/><body><p><span style=\" font-size:20pt; color:#ffffff;\">\320\221\320\265\320\273\321\213\320\265 \320\262\321\213\320\270\320\263\321\200\320\260\320\273\320\270</span></p></body></html>", nullptr));
    } // retranslateUi