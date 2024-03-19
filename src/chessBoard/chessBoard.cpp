#include "chessBoard.h"

ChessBoard::ChessBoard(QWidget* parent): QWidget{parent}
{}

void ChessBoard::drawBorders(QGraphicsScene* scene){
    for(int i = 0; i < 8; i++){
        QGraphicsRectItem* rectLeft = new QGraphicsRectItem(50, 100+shift*i, 50, 100);
        QGraphicsRectItem* rectRight = new QGraphicsRectItem(900, 100+shift*i, 50, 100);
        QGraphicsRectItem* rectTop = new QGraphicsRectItem(100+shift*i, 50, 100, 50);
        QGraphicsRectItem* rectBottom = new QGraphicsRectItem(100+shift*i, 900, 100, 50);

        rectLeft->setPen(Qt::NoPen);
        rectRight->setPen(Qt::NoPen);
        rectTop->setPen(Qt::NoPen);
        rectBottom->setPen(Qt::NoPen);

        rectLeft->setBrush(QColor(111, 78, 55));
        rectRight->setBrush(QColor(111, 78, 55));
        rectTop->setBrush(QColor(111, 78, 55));
        rectBottom->setBrush(QColor(111, 78, 55));

        scene->addItem(rectLeft);
        scene->addItem(rectRight);
        scene->addItem(rectTop);
        scene->addItem(rectBottom);
    }
    // Отрисовка уголков
    QGraphicsRectItem* rectLeftTop = new QGraphicsRectItem(50, 50, 50, 50);
    QGraphicsRectItem* rectLeftBottom = new QGraphicsRectItem(50, 900, 50, 50);
    QGraphicsRectItem* rectRightTop = new QGraphicsRectItem(900, 50, 50, 50);
    QGraphicsRectItem* rectRightBottom = new QGraphicsRectItem(900, 900, 50, 50);

    rectLeftTop->setPen(Qt::NoPen);
    rectLeftBottom->setPen(Qt::NoPen);
    rectRightTop->setPen(Qt::NoPen);
    rectRightBottom->setPen(Qt::NoPen);
    
    rectLeftTop->setBrush(QColor(111, 78, 55));
    rectLeftBottom->setBrush(QColor(111, 78, 55));
    rectRightTop->setBrush(QColor(111, 78, 55));
    rectRightBottom->setBrush(QColor(111, 78, 55));

    scene->addItem(rectLeftTop);
    scene->addItem(rectLeftBottom);
    scene->addItem(rectRightTop);
    scene->addItem(rectRightBottom);
}

void ChessBoard::drawBoard(QGraphicsScene* scene){
    drawBorders(scene);

    for(int i = 0; i < 8; i++){ // Номер строки 
        for (int j = 0; j < 8; j++){ // Номер столбца
            Square* square = new  Square(
                100+shift*j, 100+shift*i, 100, 100);
            // Ячейки для белых фигур
            if(i == 6) 
                square->setImage(":/Chess/images/White_Pawn.png");
            else if((j == 0 || j == 7) && (i == 7)) 
                square->setImage(":/Chess/images/White_Rook.png");
            else if((j == 1 || j == 6) && (i == 7)) 
                square->setImage(":/Chess/images/White_Knight.png");
            else if((j == 2 || j == 5) && (i == 7)) 
                square->setImage(":/Chess/images/White_Bishop.png");
            else if((j == 3) && (i == 7)) 
                square->setImage(":/Chess/images/White_Queen.png");
            else if((j == 4) && (i == 7)) 
                square->setImage(":/Chess/images/White_King.png");
            // Ячейки для черных фигур
            else if(i == 1) 
                square->setImage(":/Chess/images/Black_Pawn.png");
            else if((j == 0 || j == 7) && (i == 0)) 
                square->setImage(":/Chess/images/Black_Rook.png");
            else if((j == 1 || j == 6) && (i == 0)) 
                square->setImage(":/Chess/images/Black_Knight.png");
            else if((j == 2 || j == 5) && (i == 0)) 
                square->setImage(":/Chess/images/Black_Bishop.png");
            else if((j == 3) && (i == 0)) 
                square->setImage(":/Chess/images/Black_Queen.png");
            else if((j == 4) && (i == 0)) 
                square->setImage(":/Chess/images/Black_King.png");
            
            if((i+j)%2 == 0){
                square->setBackColor(255, 250, 250);
            }
            else{
                square->setBackColor(138, 98, 74);
            }
            scene->addItem(square);
        }
    }
}
