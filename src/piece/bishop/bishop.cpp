#include "bishop.h"
#include "board.h"

extern Board *board;

Bishop::Bishop(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Bishop.png");
    else
        image = QPixmap(":/Chess/images/Black_Bishop.png");
}   

void Bishop::setDiagonalMoves(){
    int new_row = row;
    int new_column = column;

    // Налево, вверх    
    new_row = row-1;
    new_column = column-1;
    while(!outOfBounds(new_row, new_column)){
        Square* currentMoveSquare = board->squares[new_row][new_column];
        if(!currentMoveSquare->piece){
            possibleMovesCoords.push_back({new_row, new_column});
            new_row--;
            new_column--;
        }
        else{
            if(currentMoveSquare->piece->color != color){
                possibleMovesCoords.push_back({new_row, new_column});
            }
            break;
        }
    }

    // Налево, Вниз
    new_row = row+1;
    new_column = column-1;
    while(!outOfBounds(new_row, new_column)){
        Square* currentMoveSquare = board->squares[new_row][new_column];
        if(!currentMoveSquare->piece){
            possibleMovesCoords.push_back({new_row, new_column});
            new_row++;
            new_column--;
        }
        else{
            if(currentMoveSquare->piece->color != color){
                possibleMovesCoords.push_back({new_row, new_column});
                
            }
            break;
        }
    }

    // Направо, вверх
    new_row = row-1;
    new_column = column+1;
    while(!outOfBounds(new_row, new_column)){
        Square* currentMoveSquare = board->squares[new_row][new_column];
        if(!currentMoveSquare->piece){
            possibleMovesCoords.push_back({new_row, new_column});
            new_row--;
            new_column++;
        }
        else{
            if(currentMoveSquare->piece->color != color){
                possibleMovesCoords.push_back({new_row, new_column});
                
            }
            break;
        }
    }
    // Направо, Вниз
    new_row = row+1;
    new_column = column+1;
    while(!outOfBounds(new_row, new_column)){
        Square* currentMoveSquare = board->squares[new_row][new_column];
        if(!currentMoveSquare->piece){
            possibleMovesCoords.push_back({new_row, new_column});
            new_row++;
            new_column++;
        }
        else{
            if(currentMoveSquare->piece->color != color){
                possibleMovesCoords.push_back({new_row, new_column});
                
            }
            break;
        }
    }
}

void Bishop::setMoves() {
    setDiagonalMoves();
    // // Remove invalid moves
    // for (auto it = possibleMovesCoords.begin(); it != possibleMovesCoords.end(); ) {
    //     if (!board->isPossibleMove(board->squares[row][column], board->squares[it->row][it->column])) {
    //         it = possibleMovesCoords.erase(it);
    //     } else {
    //         ++it;
    //     }
    // }
}

void Bishop::showMoves(QGraphicsScene* scene){
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

void Bishop::clearTurns(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
    for(Coordinates move : possibleMovesCoords){
        board->squares[move.row][move.column]->turnMarker = nullptr;
        if(board->squares[move.row][move.column]->piece)
            board->squares[move.row][move.column]->piece->isTarget = false;
        board->squares[move.row][move.column]->update();
    }
    possibleMovesCoords.clear();
}