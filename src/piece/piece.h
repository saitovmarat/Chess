#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "square.h"
#include "main.h"

struct Coordinates{
    int row;
    int column;
};
class Piece 
{
public:
    Piece(int row, int column, Color color);

    virtual void setMoves();
    virtual void showMoves(QGraphicsScene* scene);
    virtual void clearTurns();
    bool outOfBounds(int _row, int _column);
    
    int row;
    int column;
    Color color; 
    QPixmap image;
    bool isTarget = false;

    // Pawn and King feature 
    bool firstMove = true; 

    // Rook feature
    bool isCastlingAvailable = false;

    std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif