#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "chessPiece.h"
#include "main.h"

class ChessBoard:public QWidget{
    Q_OBJECT
public:

    explicit ChessBoard(QWidget* parent = nullptr);

    void drawBoard(QGraphicsScene* scene);
    void drawBorders(QGraphicsScene* scene);
    static bool isAnySquarePressed;

private:
    Square squares[8][8];
};

#endif