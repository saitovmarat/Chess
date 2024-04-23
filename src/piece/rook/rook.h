#ifndef ROOK_H
#define ROOK_H

#include "main.h"
#include "piece.h"

class Rook:public Piece{
public:
    Rook(int row, int column, Color color);

    void setLineMoves();

    void setMoves() override;
    void showMoves(QGraphicsScene* scene) override;
    bool isValidMove(int row, int column) override;
    void clearTurns() override;

    std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif