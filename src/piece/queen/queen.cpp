#include "queen.h"

Queen::Queen(int row, int column, Color color) : Piece(row, column, color){
    _row = row;
    _column = column;
    _color = color;
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_Queen.png");
    else 
        _image = QPixmap(":/Chess/images/Black_Queen.png");
}   