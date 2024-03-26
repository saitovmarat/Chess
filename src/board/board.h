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

class Board : public QWidget{
    Q_OBJECT
public:
    Board(QWidget *parent = nullptr);

    void setSquare(Square* square);
    void setUpBoard();

    void clearTurns();

    bool Pressed = false;
    Square* squares[8][8];

};

#endif