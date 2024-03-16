#include "chessBoard.h"

ChessBoard::ChessBoard(QWidget* parent): QWidget{parent}
{}

void ChessBoard::drawBoxes(QGraphicsScene* scene)
{
    int shift = 100;
    // Отрисовка ячеек для координат
    for(int i = 0; i < 8; i++){
        QGraphicsRectItem* rectLeft = new  QGraphicsRectItem();
        QGraphicsRectItem* rectRight = new  QGraphicsRectItem();
        QGraphicsRectItem* rectTop = new  QGraphicsRectItem();
        QGraphicsRectItem* rectBottom = new  QGraphicsRectItem();

        rectLeft->setRect(70, 100+shift*i, 30, 100);
        rectRight->setRect(900, 100+shift*i, 30, 100);
        rectTop->setRect(100+shift*i, 70, 100, 30);
        rectBottom->setRect(100+shift*i, 900, 100, 30);

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
void ChessBoard::paintImage(characterCord character, numCord number, pieceType type, pieceColor color){
    QImage figureImage = QImage(":/images/White_Pawn.png");
    QRect rect(0,0,100,100);
    QPainter painter(this);
    painter.setPen(QPen(Qt::transparent, 1, Qt::SolidLine, Qt::RoundCap));
    painter.drawImage(rect, figureImage);
}