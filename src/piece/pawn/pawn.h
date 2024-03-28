#ifndef PAWN_H
#define PAWN_H

#include "main.h"
#include "piece.h"

class Pawn:public Piece{
public:
    Pawn(int row, int column, Color color);

    void setWhiteMoves(QGraphicsScene* scene) override;
    void setBlackMoves(QGraphicsScene* scene) override;
};

#endif