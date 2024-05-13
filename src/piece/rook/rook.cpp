#include "rook.h"
#include "board.h"

extern Board* board;

Rook::Rook(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Rook.png");
    else 
        image = QPixmap(":/Chess/images/Black_Rook.png");
}   

void Rook::setLineMoves(){
    int new_row = row;
    int new_column = column;

    // Вниз    
    new_row = row+1;
    while(!outOfBounds(new_row, column)){
        Square* currentMoveSquare = board->squares[new_row][column];
        if(!currentMoveSquare->piece){
            possibleMovesCoords.push_back({new_row, column});
            new_row++;
        }
        else{
            if(currentMoveSquare->piece->color != color){
                possibleMovesCoords.push_back({new_row, column});
            }
            break;
        }
        
    }

    // Вверх
    new_row = row-1;
    while(!outOfBounds(new_row, column)){
        Square* currentMoveSquare = board->squares[new_row][column];
        if(!currentMoveSquare->piece){
            possibleMovesCoords.push_back({new_row, column});
            new_row--;
        }
        else{
            if(currentMoveSquare->piece->color != color){
                possibleMovesCoords.push_back({new_row, column});
            }
            break;
        }
        
    }
    // Направо
    new_column = column+1;
    while(!outOfBounds(row, new_column)){
        Square* currentMoveSquare = board->squares[row][new_column];
        if(!currentMoveSquare->piece){
            possibleMovesCoords.push_back({row, new_column});
            new_column++;
        }
        else{
            if(currentMoveSquare->piece->color != color){
                possibleMovesCoords.push_back({row, new_column});
            }
            break;
        }
        
    }

    // Налево
    new_column = column-1;
    while(!outOfBounds(row, new_column)){
        Square* currentMoveSquare = board->squares[row][new_column];
        if(!currentMoveSquare->piece){
            possibleMovesCoords.push_back({row, new_column});
            new_column--;
        }
        else{
            if(currentMoveSquare->piece->color != color){
                possibleMovesCoords.push_back({row, new_column});
            }
            break;

        }
        
    }
}

void Rook::setAllMoves(){
    clearMoves();
    setLineMoves();
}
void Rook::setMoves(){
    clearMoves();
    setLineMoves();
}

void Rook::showMoves(QGraphicsScene* scene){
    for(Coordinates move : possibleMovesCoords){
        if(board->squares[move.row][move.column]->piece){
            board->squares[move.row][move.column]->piece->isTarget = true;
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
    clearMoves();
    clearTurnMarkers();
}

void Rook::clearMoves(){
    for(Coordinates move : possibleMovesCoords){
        board->squares[move.row][move.column]->turnMarker = nullptr;
        if(board->squares[move.row][move.column]->piece)
            board->squares[move.row][move.column]->piece->isTarget = false;
        board->squares[move.row][move.column]->update();
    }
    possibleMovesCoords.clear();
}
void Rook::clearTurnMarkers(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
}