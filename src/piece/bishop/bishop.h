#ifndef BISHOP_H
#define BISHOP_H

#include "main.h"
#include "piece.h"

class Bishop:public Piece{
public:
    Bishop(int row, int column, Color color);
    
    // void setWhiteMoves(QGraphicsScene* scene) override;
    // void setBlackMoves(QGraphicsScene* scene) override;

};

#endif 