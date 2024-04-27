#include "bishop.h"
#include "board.h"

extern Board *board;

Bishop::Bishop(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Bishop.png");
    else
        image = QPixmap(":/Chess/images/Black_Bishop.png");
}   

bool Bishop::isValidMove(int _row, int _column){
    if(_row < 0 || _row > 7 || _column < 0 || _column > 7)
        return false;
    return true;
}
void Bishop::setDiagonalMoves(){
    int new_row = row;
    int new_column = column;

    // Налево, вверх    
    new_row = row-1;
    new_column = column-1;
    while(isValidMove(new_row, new_column)){
        Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
        if(currentMovePiece->color == Color::nonExistent){
            if(board->isPossibleMove(board->squares[row][column], board->squares[new_row][new_column]))
                possibleMovesCoords.push_back({new_row, new_column});
            new_row--;
            new_column--;
        }
        else{
            if(currentMovePiece->color != color){
                if(board->isPossibleMove(board->squares[row][column], board->squares[new_row][new_column])){
                    currentMovePiece->isTarget = true;
                    possibleMovesCoords.push_back({new_row, new_column});
                }
            }
            break;
        }
    }

    // Налево, Вниз
    new_row = row+1;
    new_column = column-1;
    while(isValidMove(new_row, new_column)){
        Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
        if(currentMovePiece->color == Color::nonExistent){
            if(board->isPossibleMove(board->squares[row][column], board->squares[new_row][new_column]))
                possibleMovesCoords.push_back({new_row, new_column});
            new_row++;
            new_column--;
        }
        else{
            if(currentMovePiece->color != color){
                if(board->isPossibleMove(board->squares[row][column], board->squares[new_row][new_column])){
                    currentMovePiece->isTarget = true;
                    possibleMovesCoords.push_back({new_row, new_column});
                }
            }
            break;
        }
    }

    // Направо, вверх
    new_row = row-1;
    new_column = column+1;
    while(isValidMove(new_row, new_column)){
        Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
        if(currentMovePiece->color == Color::nonExistent){
            if(board->isPossibleMove(board->squares[row][column], board->squares[new_row][new_column]))
                possibleMovesCoords.push_back({new_row, new_column});
            new_row--;
            new_column++;
        }
        else{
            if(currentMovePiece->color != color){
                if(board->isPossibleMove(board->squares[row][column], board->squares[new_row][new_column])){
                    currentMovePiece->isTarget = true;
                    possibleMovesCoords.push_back({new_row, new_column});
                }
            }
            break;
        }
    }

    // Направо, Вниз
    new_row = row+1;
    new_column = column+1;
    while(isValidMove(new_row, new_column)){
        Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
        if(currentMovePiece->color == Color::nonExistent){
            if(board->isPossibleMove(board->squares[row][column], board->squares[new_row][new_column]))
                possibleMovesCoords.push_back({new_row, new_column});
            new_row++;
            new_column++;
        }
        else{
            if(currentMovePiece->color != color){
                if(board->isPossibleMove(board->squares[row][column], board->squares[new_row][new_column])){
                    currentMovePiece->isTarget = true;
                    possibleMovesCoords.push_back({new_row, new_column});
                }
            }
            break;
        }
    }
}

void Bishop::setMoves(){
    setDiagonalMoves();
}

void Bishop::showMoves(QGraphicsScene* scene){
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

void Bishop::clearTurns(){
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