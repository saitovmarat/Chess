#include "piece.h"
#include "board.h"

extern Board* board;

Piece::Piece(int row, int column, Color color){
    this->row = row;
    this->column = column;
    this->color = color;
    isTarget = false;
    firstMove = true;
    isCastlingAvailable = false;
}
bool Piece::outOfBounds(int row, int column) {
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return true;
    return false;
}