#include "queen.h"
#include "board.h"

extern Board* board;

Queen::Queen(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Queen.png");
    else 
        image = QPixmap(":/Chess/images/Black_Queen.png");
}   

bool Queen::isValidMove(int _row, int _column){
    if(_row < 0 || _row > 7 || _column < 0 || _column > 7)
        return false;
    return true;
}
void Queen::setDiagonalMoves(QGraphicsScene* scene){
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

void Queen::setLineMoves(QGraphicsScene* scene){
    int new_row = row;
    int new_column = column;

    // Вниз    
    new_row = row+1;
    while(isValidMove(new_row, column)){
        Piece* currentMovePiece = board->squares[new_row][column]->piece;
        if(currentMovePiece->color == color) break;
        else if(currentMovePiece->color == Color::nonExistent){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+column*100, 88+new_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[new_row][column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
            new_row++;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[new_row][column]->update();
            break;
        }
    }

    // Вверх
    new_row = row-1;
    while(isValidMove(new_row, column)){
        Piece* currentMovePiece = board->squares[new_row][column]->piece;
        if(currentMovePiece->color == color) break;
        else if(currentMovePiece->color == Color::nonExistent){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+column*100, 88+new_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[new_row][column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
            new_row--;
        }
        else{
            board->squares[new_row][column]->piece->isTarget = true;
            board->squares[new_row][column]->update();
            break;
        }

    }

    // Направо
    new_column = column+1;
    while(isValidMove(row, new_column)){
        Piece* currentMovePiece = board->squares[row][new_column]->piece;
        if(currentMovePiece->color == color) break;
        else if(currentMovePiece->color == Color::nonExistent){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+new_column*100, 88+row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[row][new_column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
            new_column++;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[row][new_column]->update();
            break;
        }
    }

    // Налево
    new_column = column-1;
    while(isValidMove(row, new_column)){
        Piece* currentMovePiece = board->squares[row][new_column]->piece;
        if(currentMovePiece->color == color) break;
        else if(currentMovePiece->color == Color::nonExistent){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+new_column*100, 88+row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[row][new_column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
            new_column--;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[row][new_column]->update();
            break;
        }
    }
}

void Queen::setMoves(QGraphicsScene* scene){
    setDiagonalMoves(scene);
    setLineMoves(scene);
}

void Queen::clearTurns(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
}