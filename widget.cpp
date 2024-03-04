#include "widget.h"
#include "ui_widget.h"



Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    box = new QVBoxLayout;
    this->setLayout(box);

    for(int i = 1; i < 5; i++){
        QPushButton* btn = new QPushButton(QString::number(i), this);
        box->addWidget(btn);
        QString name = "btn_" + QString::number(i);
        btn->setObjectName(name);
        connect(btn, &QPushButton::clicked, this, &Widget::buttonClickedSlot);
    }

}

Widget::~Widget()
{
    delete ui;
}

void Widget::buttonClickedSlot(){

}