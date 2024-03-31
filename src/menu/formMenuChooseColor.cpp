#include "formMenuChooseColor.h"

void Ui_formMenuChooseColor::setupUi(QWidget *Form123)
    {
        if (Form123->objectName().isEmpty())
            Form123->setObjectName(QString::fromUtf8("Form123"));
        Form123->resize(400, 300);
        Form123->setStyleSheet(QString::fromUtf8("background-color: rgb(173, 217, 230);"));
        pushButton_2 = new QPushButton(Form123);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(150, 130, 111, 81));
        QIcon icon;
        icon.addFile(QString::fromUtf8("../\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\270/NewWbk.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon);
        pushButton_2->setIconSize(QSize(65, 65));
        pushButton_4 = new QPushButton(Form123);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(50, 140, 91, 61));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8("../\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\270/bK.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_4->setIcon(icon1);
        pushButton_4->setIconSize(QSize(55, 55));
        pushButton_5 = new QPushButton(Form123);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(270, 140, 101, 61));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8("../\320\227\320\260\320\263\321\200\321\203\320\267\320\272\320\270/wK.svg"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_5->setIcon(icon2);
        pushButton_5->setIconSize(QSize(55, 55));
        label_2 = new QLabel(Form123);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setEnabled(true);
        label_2->setGeometry(QRect(70, 30, 271, 51));
        label_2->setAcceptDrops(false);
        label_2->setAutoFillBackground(false);
        label_2->setStyleSheet(QString::fromUtf8("background: transparent;\n"
""));
        label_2->setFrameShadow(QFrame::Plain);
        label_2->setScaledContents(false);
        label_2->setWordWrap(false);
        label_2->setOpenExternalLinks(false);

        retranslateUi(Form123);

        QMetaObject::connectSlotsByName(Form123);
} // setupUi

void Ui_formMenuChooseColor::retranslateUi(QWidget *Form123)
    {
        Form123->setWindowTitle(QCoreApplication::translate("Form123", "PlayWithComputer", nullptr));
        pushButton_2->setText(QString());
        pushButton_4->setText(QString());
        pushButton_5->setText(QString());
        label_2->setText(QCoreApplication::translate("Form123", "<html><head/><body><p><span style=\" font-size:16pt;\">\320\241\321\213\320\263\321\200\320\260\321\202\321\214 \321\201 \320\272\320\276\320\274\320\277\321\214\321\216\321\202\320\265\321\200\320\276\320\274</span></p></body></html>", nullptr));
    } // retranslateUi