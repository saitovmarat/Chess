#include "piece.h"

Piece::Piece(){
    _color = Color::nonExistent; 
}

Piece::Piece(int row, int column, Color color){
    _row = row;
    _column = column;
    _color = color;
}
