#include "piece.h"

Piece::Piece(){
    _row = 123;
    _column = 123;
    _color = Color::white;
}

Piece::Piece(int row, int column, Color color){
    _row = row;
    _column = column;
    _color = color;
}