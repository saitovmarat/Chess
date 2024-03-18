#include "chessBoard.h"

ChessBoard::ChessBoard(QWidget* parent): QWidget{parent}
{}

void ChessBoard::drawBoard(QGraphicsScene* scene)
{
    // Отрисовка уголков поля
    Square* rectLeftTop = new Square(50, 50, 50, 50);
    Square* rectLeftBottom = new Square(50, 900, 50, 50);
    Square* rectRightTop = new Square(900, 50, 50, 50);
    Square* rectRightBottom = new Square(900, 900, 50, 50);

    rectLeftTop->setBackColor("white");
    rectLeftBottom->setBackColor("white");
    rectRightTop->setBackColor("white");
    rectRightBottom->setBackColor("white");

    scene->addItem(rectLeftTop);
    scene->addItem(rectLeftBottom);
    scene->addItem(rectRightTop);
    scene->addItem(rectRightBottom);

    int shift = 100;
    QVector<char> charCords = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};
    QVector<char> numCords = {'1', '2', '3', '4', '5', '6', '7', '8'};
    // Отрисовка ячеек для координат
    for(int i = 0; i < 8; i++){
        Square* rectLeft = new Square(50, 100+shift*i, 50, 100);
        Square* rectRight = new Square(900, 100+shift*i, 50, 100);
        Square* rectTop = new Square(100+shift*i, 50, 100, 50);
        Square* rectBottom = new Square(100+shift*i, 900, 100, 50);

        rectLeft->setCord(QString(numCords[7-i]));
        rectRight->setCord(QString(numCords[7-i]));
        rectTop->setCord(QString(charCords[i]));
        rectBottom->setCord(QString(charCords[i]));

        rectLeft->setBackColor("white");
        rectRight->setBackColor("white");
        rectTop->setBackColor("white");
        rectBottom->setBackColor("white");

        scene->addItem(rectLeft);
        scene->addItem(rectRight);
        scene->addItem(rectTop);
        scene->addItem(rectBottom);
    }
    // Отрисовка ячеек игрового поля
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
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
                rect->setBackColor("lightgray");
            }
            else{
                rect->setBackColor("gray");
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