#ifndef BOARD_H
#define BOARD_H

#include "piece.h"
#include "bishop.h"
#include "king.h"
#include "knight.h"
#include "pawn.h"
#include "queen.h"
#include "rook.h"

#include "main.h"

class Square;

class Board{
public:
    Board(QGraphicsScene* scene, Color firstTurnColor);

    void setUpBoard();
    void clearTurns();

    void outputFen();
    char getFenPieceSymbol(const char* pieceName, Color pieceColor);

    void clearPrevPressedSquare();
    

    Color currentMoveColor;
    Color firstTurnColor;

    bool isAnySquarePressed;

    Square* prevPressedSquare;
    QGraphicsScene* scene;
    Square* squares[8][8];
};

#endif