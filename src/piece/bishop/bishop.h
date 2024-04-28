#ifndef BISHOP_H
#define BISHOP_H

#include "main.h"
#include "piece.h"

class Bishop:public Piece{
public:
    Bishop(int row, int column, Color color);
    
    void setDiagonalMoves();

    void setMoves() override;
    void showMoves(QGraphicsScene* scene) override;
    void clearTurns() override;

    std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif 