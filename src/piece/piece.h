#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "main.h"
#include "square.h"

class Piece 
{
public:
    Piece();
    Piece(int row, int column, Color color);

    virtual void setMoves(QGraphicsScene* scene) {}
    virtual bool isValidMove(int row, int column) { return true; }
    
    int _row;
    int _column;
    Color _color; 
    QPixmap _image;

    bool isTarget = false;

    // Pawn and King feature 
    bool _firstMove = true; 

    // Rook feature
    bool castlingAvailable = false;
};

#endif