#include "piece.h"
#include "board.h"

extern Board* board;

Piece::Piece(int row, int column, Color color){
    this->row = row;
    this->column = column;
    this->color = color;
}
void Piece::setMoves() {}
void Piece::showMoves(QGraphicsScene* scene) {}
bool Piece::outOfBounds(int _row, int _column) {
    if(_row < 0 || _row > 7 || _column < 0 || _column > 7)
        return true;
    return false;
}
void Piece::clearTurns() {}