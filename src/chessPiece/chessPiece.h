#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "main.h"
#include "square.h"

class Square;
class ChessPiece:public QGraphicsPixmapItem
{
public:
    ChessPiece(QString item = "", QGraphicsItem* parent = nullptr);
    bool firstMove;

protected:
    Square* currentBox;
    QString side;
    bool isPlaced;
    QList <Square*> location;
};

#endif