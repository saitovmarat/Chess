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
    Board(QGraphicsScene* scene, Color firstTurnColor, bool isOpponentComputer);
    void setUpBoard();

    std::pair<Coordinates, Coordinates> getComputerMove(int depth);

    bool isPossibleMove(Square* fromSquare, Square* toSquare);
    bool isCheck();
    Coordinates getKing(Color color);

    void clearPrevPressedSquareTurns();

    void lockAllPieces();
    void unlockAllPieces();
    
    Color currentMoveColor;
    Color bottomPlayerColor;

    bool isOpponentComputer;

    Square* prevPressedSquare;
    QGraphicsScene* scene;
    Square* squares[8][8];
};

#endif