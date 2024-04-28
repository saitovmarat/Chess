#include "board.h"

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
            // Ходы нижнего игрока
            if(row == 6) 
                square->setPiece(new Pawn(row, column, bottom_playerColor));
            else if((column == 0 || column == 7) && (row == 7)) 
                square->setPiece(new Rook(row, column, bottom_playerColor));           
            else if((column == 1 || column == 6) && (row == 7)) 
                square->setPiece(new Knight(row, column, bottom_playerColor));            
            else if((column == 2 || column == 5) && (row == 7)) 
                square->setPiece(new Bishop(row, column, bottom_playerColor));            
            else if((column == 3) && (row == 7)) 
                square->setPiece(new Queen(row, column, bottom_playerColor));            
            else if((column == 4) && (row == 7)) 
                square->setPiece(new King(row, column, bottom_playerColor));
            // Ходы верхнего игрока          
            else if(row == 1) 
                square->setPiece(new Pawn(row, column, top_playerColor));
            else if((column == 0 || column == 7) && (row == 0)) 
                square->setPiece(new Rook(row, column, top_playerColor));
            else if((column == 1 || column == 6) && (row == 0)) 
                square->setPiece(new Knight(row, column, top_playerColor));
            else if((column == 2 || column == 5) && (row == 0)) 
                square->setPiece(new Bishop(row, column, top_playerColor));
            else if((column == 3) && (row == 0)) 
                square->setPiece(new Queen(row, column, top_playerColor));
            else if((column == 4) && (row == 0)) 
                square->setPiece(new King(row, column, top_playerColor));
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

void Board::clearPrevPressedSquareTurns(){
    prevPressedSquare->isPressed = false;
    if(prevPressedSquare->piece)
        prevPressedSquare->piece->clearTurns();
    prevPressedSquare->update();
}

bool Board::isCheck(){
    Square* kingSquare = getKing(currentMoveColor);
    if(!kingSquare) return false;
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if(squares[row][col]->piece && squares[row][col]->piece->color != currentMoveColor){
                squares[row][col]->piece->setMoves();
                for(Coordinates move : squares[row][col]->piece->possibleMovesCoords){
                    if(move.row == kingSquare->row && move.column == kingSquare->column)
                        return true;
                }
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
    
    if(isCheck()){
        result = false;
    }
    return result;
}

void Board::outputFen(){
    std::string fen;
    for(int i = 0; i < 8; i++){
        int emptyCount = 0;
        for(int j = 0; j < 8; j++){
            if(!squares[i][j]->piece){
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