#include "chessBoard.h"

ChessBoard::ChessBoard(QWidget* parent): QWidget{parent}
{}

void ChessBoard::drawBoxes(QGraphicsScene* scene)
{
    // Отрисовка уголков поля
    QGraphicsRectItem* rectLeftTop = new  QGraphicsRectItem();
    QGraphicsRectItem* rectLeftBottom = new  QGraphicsRectItem();
    QGraphicsRectItem* rectRightTop = new  QGraphicsRectItem();
    QGraphicsRectItem* rectRightBottom = new  QGraphicsRectItem();

    rectLeftTop->setRect(50, 50, 50, 50);
    rectLeftBottom->setRect(50, 900, 50, 50);
    rectRightTop->setRect(900, 50, 50, 50);
    rectRightBottom->setRect(900, 900, 50, 50);

    rectLeftTop->setBrush(QColor("white"));
    rectLeftBottom->setBrush(QColor("white"));
    rectRightTop->setBrush(QColor("white"));
    rectRightBottom->setBrush(QColor("white"));

    scene->addItem(rectLeftTop);
    scene->addItem(rectLeftBottom);
    scene->addItem(rectRightTop);
    scene->addItem(rectRightBottom);

    int shift = 100;
    // Отрисовка ячеек для координат
    for(int i = 0; i < 8; i++){
        QGraphicsRectItem* rectLeft = new  QGraphicsRectItem();
        QGraphicsRectItem* rectRight = new  QGraphicsRectItem();
        QGraphicsRectItem* rectTop = new  QGraphicsRectItem();
        QGraphicsRectItem* rectBottom = new  QGraphicsRectItem();

        rectLeft->setRect(50, 100+shift*i, 50, 100);
        rectRight->setRect(900, 100+shift*i, 50, 100);
        rectTop->setRect(100+shift*i, 50, 100, 50);
        rectBottom->setRect(100+shift*i, 900, 100, 50);

        rectLeft->setBrush(QColor("white"));
        rectRight->setBrush(QColor("white"));
        rectTop->setBrush(QColor("white"));
        rectBottom->setBrush(QColor("white"));

        scene->addItem(rectLeft);
        scene->addItem(rectRight);
        scene->addItem(rectTop);
        scene->addItem(rectBottom);
    }
    // Отрисовка ячеек игрового поля
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            QGraphicsRectItem* rect = new  QGraphicsRectItem();
            rect->setRect(100+shift*j, 100+shift*i, 100, 100);
            if((i+j)%2 == 0){
                rect->setBrush(QColor("lightgray"));
                
            }
            else{
                rect->setBrush(QColor("gray"));
            }
            scene->addItem(rect);
        }
    }
}
void ChessBoard::paintEvent(QPaintEvent* event){
    QPainter painter;
    painter.begin(this);

    painter.drawRect(0,0, 100,100);

    painter.end();
}