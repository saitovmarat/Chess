#ifndef KNIGHT_H
#define KNIGHT_H

#include "main.h"
#include "piece.h"

class Knight:public Piece{
public:
    Knight(int row, int column, Color color);

    void setMoves() override;
    void showMoves(QGraphicsScene* scene) override;
    void clearTurns() override;

    std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif