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
                square->setPiece(king_w);
            }
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
                square->setPiece(king_b);
            }
            else{
                // Костыль для обработки фигур у ф-ии setMoves();
                Piece* piece = new Piece();  
                square->setPiece(piece);
            }
            // Цвет квадратиков
            if((row+column)%2 == 0){
                square->setBackColor(240, 217, 181);
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
    Square* kingSquare = getKing(currentMoveColor);
    if(!kingSquare) return false;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* piece = squares[row][col]->piece;
            if (piece->color != currentMoveColor &&
                piece->color != Color::nonExistent) {
                piece->setMoves();
                if(kingSquare->piece->isTarget){
                    piece->clearTurns();
                    std::cout << "Check\n";
                    return true;
                } 
                piece->clearTurns();
            }
        }
    }
    return false;
}
Square* Board::getKing(Color color){
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* piece = squares[row][col]->piece;
            if (piece->color == color && dynamic_cast<King*>(piece)) {
                Square* kingSquare = squares[row][col];
                return kingSquare;
            }
        }
    }
    return nullptr;
}
bool Board::isPossibleMove(Square* fromSquare, Square* toSquare){
    bool result = true;
    const Color tempfromSquareColor = fromSquare->piece->color;
    const Color temptoSquareColor  = toSquare->piece->color;

    fromSquare->piece->color = Color::nonExistent;
    toSquare->piece->color = tempfromSquareColor;
    if(isCheck()){
        result = false;
    }
    fromSquare->piece->color = tempfromSquareColor;
    toSquare->piece->color = temptoSquareColor;
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
                fen += getFenPieceSymbol(squares[i][j]->piece,
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

char Board::getFenPieceSymbol(Piece* piece, Color pieceColor){
    char pieceSymb;
    if(dynamic_cast<Bishop*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'B' : 'b';
    else if(dynamic_cast<King*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'K' : 'k';
    else if(dynamic_cast<Knight*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'N' : 'n';
    else if(dynamic_cast<Pawn*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'P' : 'p';
    else if(dynamic_cast<Queen*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'Q' : 'q';
    else if(dynamic_cast<Rook*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'R' : 'r';

    return pieceSymb;
}