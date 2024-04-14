#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "square.h"
#include "main.h"


class Piece 
{
public:
    Piece();
    Piece(int row, int column, Color color);

    virtual void setMoves(QGraphicsScene* scene) {}
    virtual bool isValidMove(int row, int column) { return true; }
    virtual void clearTurns() {};
    
    int row;
    int column;
    Color color; 
    QPixmap image;

    bool isTarget = false;

    // Pawn and King feature 
    bool firstMove = true; 

    // Rook feature
    bool castlingAvailable = false;

    QList<QGraphicsEllipseItem*> turns;
};

#endif