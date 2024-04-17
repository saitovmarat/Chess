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
    Piece();
    Piece(int row, int column, Color color);

    virtual void setMoves(QGraphicsScene* scene) {}
    virtual bool isValidMove(int row, int column) { return true; }
    virtual void clearTurns() {};
    //virtual void addPossibleMoveCords(int row, int column) {};
    
    int row;
    int column;
    Color color; 
    QPixmap image;


    bool isTarget = false;

    // Pawn and King feature 
    bool firstMove = true; 

    // Rook feature
    bool castlingAvailable = false;

    //std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif