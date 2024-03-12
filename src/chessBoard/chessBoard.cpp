#include "chessBoard.h"

ChessBoard::ChessBoard(){}

void ChessBoard::drawBoxes(QGraphicsScene* scene)
{
    int shift = 100;
    for(int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            // create an item to put into the scene
            QGraphicsRectItem* rect = new  QGraphicsRectItem();
            rect->setRect(shift*j, shift*i, 100, 100);
            if((i+j)%2 == 0){
                rect->setBrush(QColor("lightblue"));
            }
            else{
                rect->setBrush(QColor("white"));
            }

            // add the item to the scene
            scene->addItem(rect);
        }
    }

}