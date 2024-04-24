#include "rook.h"
#include "board.h"

extern Board* board;

Rook::Rook(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Rook.png");
    else 
        image = QPixmap(":/Chess/images/Black_Rook.png");
}   

bool Rook::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}
void Rook::setLineMoves(){
    int new_row = row;
    int new_column = column;

    // Вниз    
    new_row = row+1;
    while(isValidMove(new_row, column)){
        Piece* currentMovePiece = board->squares[new_row][column]->piece;
        if(currentMovePiece->color == Color::nonExistent){
            possibleMovesCoords.push_back({new_row, column});
            new_row++;
        }
        else{
            if(currentMovePiece->color != color){
                possibleMovesCoords.push_back({new_row, column});
                currentMovePiece->isTarget = true;
            }
            break;
        }
    }

    // Вверх
    new_row = row-1;
    while(isValidMove(new_row, column)){
        Piece* currentMovePiece = board->squares[new_row][column]->piece;
        if(currentMovePiece->color == Color::nonExistent){
            possibleMovesCoords.push_back({new_row, column});
            new_row--;
        }
        else{
            if(currentMovePiece->color != color){
                possibleMovesCoords.push_back({new_row, column});
                currentMovePiece->isTarget = true;
            }
            break;
        }
    }
    // Направо
    new_column = column+1;
    while(isValidMove(row, new_column)){
        Piece* currentMovePiece = board->squares[row][new_column]->piece;
        if(currentMovePiece->color == Color::nonExistent){
            possibleMovesCoords.push_back({row, new_column});
            new_column++;
        }
        else{
            if(currentMovePiece->color != color){
                possibleMovesCoords.push_back({row, new_column});
                currentMovePiece->isTarget = true;
            }
            break;
        }
    }

    // Налево
    new_column = column-1;
    while(isValidMove(row, new_column)){
        Piece* currentMovePiece = board->squares[row][new_column]->piece;
        if(currentMovePiece->color == Color::nonExistent){
            possibleMovesCoords.push_back({row, new_column});
            new_column--;
        }
        else{
            if(currentMovePiece->color != color){
                possibleMovesCoords.push_back({row, new_column});
                currentMovePiece->isTarget = true;
            }
            break;
        }
    }
}

void Rook::setMoves(){
    setLineMoves();
}

void Rook::showMoves(QGraphicsScene* scene){
    for(Coordinates move : possibleMovesCoords){
        if(board->squares[move.row][move.column]->piece->color != Color::nonExistent){
            board->squares[move.row][move.column]->update();
        }
        else{
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+move.column*100, 88+move.row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[move.row][move.column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
        }
        
    }
}
void Rook::clearTurns(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
    for(Coordinates move : possibleMovesCoords){
        board->squares[move.row][move.column]->turnMarker = nullptr;
        board->squares[move.row][move.column]->piece->isTarget = false;
        board->squares[move.row][move.column]->update();
    }
    possibleMovesCoords.clear();
}