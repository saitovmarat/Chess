#include "king.h"


King::King(int row, int column, Color color) : Piece(row, column, color){
    _row = row;
    _column = column;
    _color = color;
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_King.png");
    else 
        _image = QPixmap(":/Chess/images/Black_King.png");
}   

// void King::setMoves(){
//     std::cout << "lsls";
// }