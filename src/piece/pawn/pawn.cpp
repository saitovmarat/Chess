#include "pawn.h"

Pawn::Pawn(int row, int column, Color color) : Piece(row, column, color){
    _row = row;
    _column = column;
    _color = color;
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_Pawn.png");
    else 
        _image = QPixmap(":/Chess/images/Black_Pawn.png");
}   