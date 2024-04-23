#ifndef QUEEN_H
#define QUEEN_H

#include "main.h"
#include "piece.h"

class Queen:public Piece{
public:
    Queen(int row, int column, Color color);

    void setDiagonalMoves();
    void setLineMoves();

    void setMoves() override;
    void showMoves(QGraphicsScene* scene) override;
    bool isValidMove(int row, int column) override;
    void clearTurns() override;

    std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif