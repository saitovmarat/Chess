#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "main.h"
#include "square.h"

class Piece 
{
public:
    Piece();
    Piece(int row, int column, Color color);

    int _row;
    int _column;
    Color _color; 
    QPixmap _image; 
};

#endif