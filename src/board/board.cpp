#include "board.h"

#define shift 100

Board::Board(QGraphicsScene* scene, QWidget* parent) : QWidget(parent){
    for(int row = 0; row < 8; row++){
        for(int column = 0; column < 8; column++){
            Square* square = new Square(row, column);
            squares[row][column] = square;
        }
    }
    _scene = scene;
    currentMoveColor = Color::white;
    isAnySquarePressed = false;
}

void Board::setUpBoard(){
    for(int row = 0; row < 8; row++){
        for(int column = 0; column < 8; column++){
            Square* square = new Square(column, row);
            // Ячейки для белых фигур
            if(row == 6) {
                Pawn* pawn_w = new Pawn(row, column, Color::white);
                square->setPiece(pawn_w);
            }
            else if((column == 0 || column == 7) && (row == 7)) {
                Rook* rook_w = new Rook(row, column, Color::white);
                square->setPiece(rook_w);
            }
            else if((column == 1 || column == 6) && (row == 7)) {
                Knight* knight_w = new Knight(row, column, Color::white);
                square->setPiece(knight_w);
            }
            else if((column == 2 || column == 5) && (row == 7)) {
                Bishop* bishop_w = new Bishop(row, column, Color::white);
                square->setPiece(bishop_w);
            }
            else if((column == 3) && (row == 7)) {
                Queen* queen_w = new Queen(row, column, Color::white);
                square->setPiece(queen_w);
            }
            else if((column == 4) && (row == 7)) {
                King* king_w = new King(row, column, Color::white);
                square->setPiece(king_w);
            }
            // Ячейки для черных фигур
            else if(row == 1) {
                Pawn* pawn_b = new Pawn(row, column, Color::black);
                square->setPiece(pawn_b);
            }
            else if((column == 0 || column == 7) && (row == 0)) {
                Rook* rook_b = new Rook(row, column, Color::black);
                square->setPiece(rook_b);
            }
            else if((column == 1 || column == 6) && (row == 0)) {
                Knight* knight_b = new Knight(row, column, Color::black);
                square->setPiece(knight_b);
            }
            else if((column == 2 || column == 5) && (row == 0)) {
                Bishop* bishop_b = new Bishop(row, column, Color::black);
                square->setPiece(bishop_b);
            }
            else if((column == 3) && (row == 0)) {
                Queen* queen_b = new Queen(row, column, Color::black);
                square->setPiece(queen_b);
            }
            else if((column == 4) && (row == 0)) {
                King* king_b = new King(row, column, Color::black);
                square->setPiece(king_b);
            }
            else{
                // Костыль для обработки фигур у ф-ии setMoves();
                Piece* piece = new Piece();  
                square->setPiece(piece);
            }
            // Цвет квадратиков
            if((row+column)%2 == 0)
                square->setBackColor(255, 250, 250);
            else
                square->setBackColor(138, 98, 74);

            squares[row][column] = square;
        }
    }
}

void Board::clearTurns(){
    for(int row = 0; row < 8; row++){
        for(int column = 0; column < 8; column++){
            squares[row][column]->Pressed = false;
            squares[row][column]->turnMarker = nullptr;
            squares[row][column]->_piece->isTarget = false;
            squares[row][column]->update();
        }
    }
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
    
    isAnySquarePressed = false;
}

void Board::clearPrevPressedSquare(){
    prevPressedSquare->_piece = new Piece();
    prevPressedSquare->_image = QPixmap(); 
}
