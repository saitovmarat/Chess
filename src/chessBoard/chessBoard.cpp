#include "chessBoard.h"

ChessBoard::ChessBoard(QWidget* parent): QWidget{parent}
{}

void ChessBoard::drawBorders(QGraphicsScene* scene){
    for(int i = 0; i < 8; i++){
        Square* rectLeft = new Square(50, 100+shift*i, 50, 100);
        Square* rectRight = new Square(900, 100+shift*i, 50, 100);
        Square* rectTop = new Square(100+shift*i, 50, 100, 50);
        Square* rectBottom = new Square(100+shift*i, 900, 100, 50);

        rectLeft->setBackColor(111, 78, 55);
        rectRight->setBackColor(111, 78, 55);
        rectTop->setBackColor(111, 78, 55);
        rectBottom->setBackColor(111, 78, 55);

        scene->addItem(rectLeft);
        scene->addItem(rectRight);
        scene->addItem(rectTop);
        scene->addItem(rectBottom);
    }
    // Отрисовка уголков
    Square* rectLeftTop = new Square(50, 50, 50, 50);
    Square* rectLeftBottom = new Square(50, 900, 50, 50);
    Square* rectRightTop = new Square(900, 50, 50, 50);
    Square* rectRightBottom = new Square(900, 900, 50, 50);

    rectLeftTop->setBackColor(111, 78, 55);
    rectLeftBottom->setBackColor(111, 78, 55);
    rectRightTop->setBackColor(111, 78, 55);
    rectRightBottom->setBackColor(111, 78, 55);

    scene->addItem(rectLeftTop);
    scene->addItem(rectLeftBottom);
    scene->addItem(rectRightTop);
    scene->addItem(rectRightBottom);
}

void ChessBoard::drawBoard(QGraphicsScene* scene)
{
    drawBorders(scene);
    for(int i = 0; i < 8; i++){ // Номер строки 
        for (int j = 0; j < 8; j++){ // Номер столбца
            Square* rect = new  Square(
                100+shift*j, 100+shift*i, 100, 100);
            // Ячейки для белых фигур
            if(i == 6) 
                rect->setImage(":/Chess/images/White_Pawn.png");
            else if((j == 0 || j == 7) && (i == 7)) 
                rect->setImage(":/Chess/images/White_Rook.png");
            else if((j == 1 || j == 6) && (i == 7)) 
                rect->setImage(":/Chess/images/White_Knight.png");
            else if((j == 2 || j == 5) && (i == 7)) 
                rect->setImage(":/Chess/images/White_Bishop.png");
            else if((j == 3) && (i == 7)) 
                rect->setImage(":/Chess/images/White_Queen.png");
            else if((j == 4) && (i == 7)) 
                rect->setImage(":/Chess/images/White_King.png");
            // Ячейки для черных фигур
            else if(i == 1) 
                rect->setImage(":/Chess/images/Black_Pawn.png");
            else if((j == 0 || j == 7) && (i == 0)) 
                rect->setImage(":/Chess/images/Black_Rook.png");
            else if((j == 1 || j == 6) && (i == 0)) 
                rect->setImage(":/Chess/images/Black_Knight.png");
            else if((j == 2 || j == 5) && (i == 0)) 
                rect->setImage(":/Chess/images/Black_Bishop.png");
            else if((j == 3) && (i == 0)) 
                rect->setImage(":/Chess/images/Black_Queen.png");
            else if((j == 4) && (i == 0)) 
                rect->setImage(":/Chess/images/Black_King.png");
            
            if((i+j)%2 == 0){
                rect->setBackColor(255, 250, 250);
            }
            else{
                rect->setBackColor(138, 98, 74);
            }
            scene->addItem(rect);
        }
    }
}
