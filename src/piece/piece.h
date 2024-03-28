#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "main.h"
#include "square.h"

class Piece 
{
public:
    Piece();
    Piece(int row, int column, Color color);

    virtual void setWhiteMoves(QGraphicsScene* scene) {}
    virtual void setBlackMoves(QGraphicsScene* scene) {}
    int _row;
    int _column;
    Color _color; 
    QPixmap _image;
    bool _firstMove = true; 
};

#endif