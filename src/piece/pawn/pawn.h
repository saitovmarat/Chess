#ifndef PAWN_H
#define PAWN_H

#include "main.h"
#include "piece.h"

class Pawn:public Piece{
public:
    Pawn(int row, int column, Color color);

    void set_BottomPlayerMoves();
    void set_TopPlayerMoves();

    void setAllMoves() override;
    void setMoves() override;
    
    void showMoves(QGraphicsScene* scene) override;
    
    void clearMoves() override;
    void clearTurnMarkers() override;
    void clearTurns() override;

    bool madeFirstMove;

    std::vector<Coordinates> possibleMovesCoords;
    QList<QGraphicsEllipseItem*> turns;
};

#endif