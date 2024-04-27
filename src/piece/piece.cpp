#include "piece.h"
#include "board.h"

extern Board* board;
Piece::Piece(){
    color = Color::nonExistent; 
}

Piece::Piece(int row, int column, Color color){
    this->row = row;
    this->column = column;
    this->color = color;
}
void Piece::setMoves() {}
void Piece::showMoves(QGraphicsScene* scene) {}
bool Piece::isValidMove(int row, int column) {return true;}
void Piece::clearTurns() {}