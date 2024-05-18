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

    std::string getCurrentFen();
    std::pair<Coordinates, Coordinates> getComputerMove(int depth);

    bool isPossibleMove(Square* fromSquare, Square* toSquare);
    bool isCheck();
    Square* getKing(Color color);

    void clearPrevPressedSquareTurns();

    void truePressSquare();

    void falsePressSquare();
    
    Color currentMoveColor;
    Color bottomPlayerColor;

    int turnsCounter = 1;
    bool isOpponentComputer;

    Square* prevPressedSquare;
    QGraphicsScene* scene;
    Square* squares[8][8];
};

#endif