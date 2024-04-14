#include "piece.h"

Piece::Piece(){
    color = Color::nonExistent; 
}

Piece::Piece(int row, int column, Color color){
    this->row = row;
    this->column = column;
    this->color = color;
}
