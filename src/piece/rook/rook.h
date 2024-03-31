#ifndef ROOK_H
#define ROOK_H

#include "main.h"
#include "piece.h"

class Rook:public Piece{
public:
    Rook(int row, int column, Color color);

    void setLineMoves(QGraphicsScene* scene);

    void setMoves(QGraphicsScene* scene) override;
    bool isValidMove(int row, int column) override;

};

#endif