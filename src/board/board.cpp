#include "board.h"
#include <cxxabi.h>

#define shift 100

Board::Board(QGraphicsScene* scene, Color firstTurnColor){
    for(int row = 0; row < 8; row++){
        for(int column = 0; column < 8; column++){
            squares[row][column] = new Square(row, column);
        }
    }
    this->scene = scene;
    currentMoveColor = firstTurnColor;
    this->firstTurnColor = firstTurnColor;
}

void Board::setUpBoard(){
    Color bottom_playerColor = currentMoveColor;
    Color top_playerColor = (currentMoveColor == Color::white)? Color::black: Color::white; 
    
    for(int row = 0; row < 8; row++){
        for(int column = 0; column < 8; column++){
            Square* square = new Square(column, row);
            // Ячейки для белых фигур
            if(row == 6) {
                Pawn* pawn_w = new Pawn(row, column, bottom_playerColor);
                square->setPiece(pawn_w);
            }
            else if((column == 0 || column == 7) && (row == 7)) {
                Rook* rook_w = new Rook(row, column, bottom_playerColor);
                square->setPiece(rook_w);
            }
            else if((column == 1 || column == 6) && (row == 7)) {
                Knight* knight_w = new Knight(row, column, bottom_playerColor);
                square->setPiece(knight_w);
            }
            else if((column == 2 || column == 5) && (row == 7)) {
                Bishop* bishop_w = new Bishop(row, column, bottom_playerColor);
                square->setPiece(bishop_w);
            }
            else if((column == 3) && (row == 7)) {
                Queen* queen_w = new Queen(row, column, bottom_playerColor);
                square->setPiece(queen_w);
            }
            else if((column == 4) && (row == 7)) {
                King* king_w = new King(row, column, bottom_playerColor);
                if(bottom_playerColor == Color::white) whiteKingSquare = square;
                else blackKingSquare = square;
                square->setPiece(king_w);
            }
            // Ячейки для черных фигур
            else if(row == 1) {
                Pawn* pawn_b = new Pawn(row, column, top_playerColor);
                square->setPiece(pawn_b);
            }
            else if((column == 0 || column == 7) && (row == 0)) {
                Rook* rook_b = new Rook(row, column, top_playerColor);
                square->setPiece(rook_b);
            }
            else if((column == 1 || column == 6) && (row == 0)) {
                Knight* knight_b = new Knight(row, column, top_playerColor);
                square->setPiece(knight_b);
            }
            else if((column == 2 || column == 5) && (row == 0)) {
                Bishop* bishop_b = new Bishop(row, column, top_playerColor);
                square->setPiece(bishop_b);
            }
            else if((column == 3) && (row == 0)) {
                Queen* queen_b = new Queen(row, column, top_playerColor);
                square->setPiece(queen_b);
            }
            else if((column == 4) && (row == 0)) {
                King* king_b = new King(row, column, top_playerColor);
                if(top_playerColor == Color::white) whiteKingSquare = square;
                else blackKingSquare = square;
                square->setPiece(king_b);
            }
            else{
                // Костыль для обработки фигур у ф-ии setMoves();
                Piece* piece = new Piece();  
                square->setPiece(piece);
            }
            // Цвет квадратиков
            if((row+column)%2 == 0){
                square->setBackColor(255, 250, 250);
            }
            else{
                square->setBackColor(138, 98, 74);
            }
            squares[row][column] = square;
        }
    }
}

void Board::clearTurns(){
    for(int row = 0; row < 8; row++){
        for(int column = 0; column < 8; column++){
            squares[row][column]->isPressed = false;
            squares[row][column]->turnMarker = nullptr;
            squares[row][column]->piece->isTarget = false;
            squares[row][column]->piece->castlingAvailable = false;
            squares[row][column]->piece->clearTurns();
            squares[row][column]->update();

        }
    }
}

void Board::clearPrevPressedSquareTurns(){
    prevPressedSquare->isPressed = false;
    prevPressedSquare->piece->clearTurns();
    prevPressedSquare->update();
}

bool Board::isCheck(){
    // Отрисовка всех ходов
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(squares[i][j]->piece->color == currentMoveColor){
                squares[i][j]->piece->setMoves();
            }
        }
    }
    
    
    return false;
}
bool Board::isValidMove(Square* fromSquare, Square* toSquare){
    bool result = true;

    Color tempColor = toSquare->piece->color;
    fromSquare->piece->color = Color::nonExistent;
    toSquare->piece->color = currentMoveColor;
    if(isCheck())
        result = false;

    fromSquare->piece->color = currentMoveColor;
    toSquare->piece->color = tempColor;
    return result;
}

void Board::outputFen(){
    std::string fen;
    for(int i = 0; i < 8; i++){
        int emptyCount = 0;
        for(int j = 0; j < 8; j++){
            if(squares[i][j]->piece->color == Color::nonExistent){
                emptyCount++;
            }
            else{
                if(emptyCount > 0){
                    fen += std::to_string(emptyCount);
                    emptyCount = 0;
                }
                fen += getFenPieceSymbol(typeid(*squares[i][j]->piece).name(),
                                        squares[i][j]->piece->color);   
            }
        }
        if(emptyCount > 0){
            fen += std::to_string(emptyCount);
        }
        fen += '/';
    }
    fen.pop_back();
    fen += ' ';

    char currentTurnColor_symb = (currentMoveColor == Color::white)? 'w': 'b';
    fen += currentTurnColor_symb;

    // Доделать этот момент
    fen += " KQkq - 0 1";

    std::cout << fen << std::endl;
}

char Board::getFenPieceSymbol(const char* pieceName, Color pieceColor){
    // Удаления числа в начале строки 
    int status;
    char* demangledName = abi::__cxa_demangle(pieceName, nullptr, nullptr, &status);
    std::string demangled_pieceName = (status == 0) ? demangledName : pieceName;
    free(demangledName);

    char pieceSymb;
    if(demangled_pieceName == "Bishop")
        pieceSymb = (pieceColor == Color::white)? 'B' : 'b';
    else if(demangled_pieceName == "King")
        pieceSymb = (pieceColor == Color::white)? 'K' : 'k';
    else if(demangled_pieceName == "Knight")
        pieceSymb = (pieceColor == Color::white)? 'N' : 'n';
    else if(demangled_pieceName == "Pawn")
        pieceSymb = (pieceColor == Color::white)? 'P' : 'p';
    else if(demangled_pieceName == "Queen")
        pieceSymb = (pieceColor == Color::white)? 'Q' : 'q';
    else if(demangled_pieceName == "Rook")
        pieceSymb = (pieceColor == Color::white)? 'R' : 'r';

    return pieceSymb;
}