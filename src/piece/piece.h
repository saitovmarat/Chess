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

    virtual void setMoves() = 0;
    virtual void setAllMoves() = 0;
    virtual void showMoves(QGraphicsScene* scene) = 0;

    virtual void clearMoves() = 0;
    virtual void clearTurnMarkers() = 0;
    virtual void clearTurns() = 0;
    
    static bool outOfBounds(int row, int column);
    
    int row;
    int column;
    Color color; 
    QPixmap image;
    bool isTarget;

    // Pawn and King feature 
    bool firstMove; 

    // Rook feature
    bool isCastlingAvailable = false;

    std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif