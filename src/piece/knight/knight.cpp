#include "knight.h"

Knight::Knight(int row, int column, Color color) : Piece(row, column, color){
    _row = row;
    _column = column;
    _color = color;
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_Knight.png");
    else 
        _image = QPixmap(":/Chess/images/Black_Knight.png");
}   