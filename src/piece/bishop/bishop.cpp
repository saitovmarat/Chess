#include "bishop.h"
#include "board.h"

extern Board *board;

Bishop::Bishop(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Bishop.png");
    else
        image = QPixmap(":/Chess/images/Black_Bishop.png");
}   

bool Bishop::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}
void Bishop::setDiagonalMoves(QGraphicsScene* scene){
    int new_row = row;
    int new_column = column;

    // Налево, вверх    
    new_row = row-1;
    new_column = column-1;
    while(isValidMove(new_row, new_column)){
        Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
        if(currentMovePiece->color == color) break;
        else if(currentMovePiece->color == Color::nonExistent){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+new_column*100, 88+new_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[new_row][new_column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
            new_row--;
            new_column--;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[new_row][new_column]->update();
            break;
        }
    }

    // Налево, Вниз
    new_row = row+1;
    new_column = column-1;
    while(isValidMove(new_row, new_column)){
        Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
        if(currentMovePiece->color == color) break;
        else if(currentMovePiece->color == Color::nonExistent){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+new_column*100, 88+new_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[new_row][new_column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
            new_row++;
            new_column--;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[new_row][new_column]->update();
            break;
        }
    }

    // Направо, вверх
    new_row = row-1;
    new_column = column+1;
    while(isValidMove(new_row, new_column)){
        Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
        if(currentMovePiece->color == color) break;
        else if(currentMovePiece->color == Color::nonExistent){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+new_column*100, 88+new_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[new_row][new_column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
            new_row--;
            new_column++;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[new_row][new_column]->update();
            break;
        }
    }

    // Направо, Вниз
    new_row = row+1;
    new_column = column+1;
    while(isValidMove(new_row, new_column)){
        Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
        if(currentMovePiece->color == color) break;
        else if(currentMovePiece->color == Color::nonExistent){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+new_column*100, 88+new_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[new_row][new_column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
            new_row++;
            new_column++;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[new_row][new_column]->update();
            break;
        }
    }
}

void Bishop::setMoves(QGraphicsScene* scene){
    setDiagonalMoves(scene);
}

void Bishop::clearTurns(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
}