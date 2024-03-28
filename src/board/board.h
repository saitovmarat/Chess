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
    Board(QGraphicsScene* scene, QWidget *parent = nullptr);

    void setUpBoard();
    void clearTurns();

    void clearPrevPressedSquare();

    Color currentMoveColor;
    bool isAnySquarePressed;

    Square* prevPressedSquare;
    QGraphicsScene* _scene;
    Square* squares[8][8];
    QList<QGraphicsEllipseItem*> turns;
};

#endif