#ifndef ROOK_H
#define ROOK_H

#include "main.h"
#include "piece.h"

class Rook:public Piece{
public:
    Rook(int row, int column, Color color);

    void setLineMoves();

    void setAllMoves() override;
    void setMoves() override;
    
    void showMoves(QGraphicsScene* scene) override;
    
    void clearMoves() override;
    void clearTurnMarkers() override;
    void clearTurns() override;

    std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif