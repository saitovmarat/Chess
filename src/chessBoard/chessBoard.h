#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "chessPiece.h"
#include "main.h"

class ChessBoard{
public:
    ChessBoard();

    void drawBoxes(QGraphicsScene* scene);

    void setUpWhite();
    void setUpBlack();

private:
    QList <ChessPiece *> white;
    QList <ChessPiece *> black;
};

#endif