#include "queen.h"
#include "board.h"

extern Board* board;

Queen::Queen(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Queen.png");
    else 
        image = QPixmap(":/Chess/images/Black_Queen.png");
}   

void Queen::setDiagonalMoves(){
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

void Queen::setLineMoves(){
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

void Queen::setAllMoves(){
    clearMoves();
    setDiagonalMoves();
    setLineMoves();
}

void Queen::setMoves(){
    clearMoves();
    setDiagonalMoves();
    setLineMoves();
}

void Queen::showMoves(QGraphicsScene* scene){
    for(Coordinates move : possibleMovesCoords){
        if(board->squares[move.row][move.column]->piece){
            board->squares[move.row][move.column]->piece->isTarget = true;
            board->squares[move.row][move.column]->update();
        }
        else{
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                move.column * 100 + 88, move.row * 100 + 88, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[move.row][move.column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
        }
    }
}
void Queen::clearTurns(){
    clearMoves();
    clearTurnMarkers();
}

void Queen::clearMoves(){
    for(Coordinates move : possibleMovesCoords){
        board->squares[move.row][move.column]->turnMarker = nullptr;
        if(board->squares[move.row][move.column]->piece)
            board->squares[move.row][move.column]->piece->isTarget = false;
        board->squares[move.row][move.column]->update();
    }
    possibleMovesCoords.clear();
}
void Queen::clearTurnMarkers(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
}
