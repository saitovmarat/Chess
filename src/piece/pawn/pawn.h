#ifndef PAWN_H
#define PAWN_H

#include "main.h"
#include "piece.h"

class Pawn:public Piece{
public:
    Pawn(int row, int column, Color color);

    void setWhiteMoves(QGraphicsScene* scene);
    void setBlackMoves(QGraphicsScene* scene);

    void setMoves(QGraphicsScene* scene) override;
    bool isValidMove(int row, int column) override;

};

#endif