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
    char getFenPieceSymbol(Piece* piece, Color pieceColor);

    bool isValidMove(Square* fromSquare, Square* toSquare);
    bool isCheck();

    void clearPrevPressedSquareTurns();
    
    Color currentMoveColor;
    Color firstTurnColor;

    Square* whiteKingSquare;
    Square* blackKingSquare;

    bool Check = false;
    Square* prevPressedSquare = nullptr;
    QGraphicsScene* scene;
    Square* squares[8][8];
};

#endif