#ifndef KING_H
#define KING_H

#include "main.h"
#include "piece.h"

class King:public Piece{
public:
    King(int row, int column, Color color);

    void setCastlingMoves();

    void setMoves() override;
    void setAllMoves() override;
    void showMoves(QGraphicsScene* scene) override;
    
    void clearMoves() override;
    void clearTurnMarkers() override;
    void clearTurns() override;

    std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif