#include "rook.h"


Rook::Rook(int row, int column, Color color) : Piece(row, column, color){
    _row = row;
    _column = column;
    _color = color;
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_Rook.png");
    else 
        _image = QPixmap(":/Chess/images/Black_Rook.png");
}   

// void Rook::setMoves(){
//     std::cout << "lsls";
// }