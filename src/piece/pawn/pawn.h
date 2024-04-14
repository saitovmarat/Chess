#ifndef PAWN_H
#define PAWN_H

#include "main.h"
#include "piece.h"

class Pawn:public Piece{
public:
    Pawn(int row, int column, Color color);

    void set_BottomPlayerMoves(QGraphicsScene* scene);
    void set_TopPlayerMoves(QGraphicsScene* scene);

    void setMoves(QGraphicsScene* scene) override;
    bool isValidMove(int row, int column) override;
    void clearTurns() override;



    QList<QGraphicsEllipseItem*> turns;
};

#endif