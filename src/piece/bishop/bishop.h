#ifndef BISHOP_H
#define BISHOP_H

#include "main.h"
#include "piece.h"

class Bishop:public Piece{
public:
    Bishop(int row, int column, Color color);
    
    void setDiagonalMoves(QGraphicsScene* scene);

    void setMoves(QGraphicsScene* scene) override;
    bool isValidMove(int row, int column) override;
    void clearTurns() override;

    QList<QGraphicsEllipseItem*> turns;
};

#endif 