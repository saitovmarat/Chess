#include "rook.h"
#include "board.h"

extern Board* board;

Rook::Rook(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_Rook.png");
    else 
        _image = QPixmap(":/Chess/images/Black_Rook.png");
}   

bool Rook::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}
void Rook::setMoves(QGraphicsScene* scene){
    int new_row = _row;
    int new_column = _column;

    // Вниз    
    new_row = _row+1;
    while(isValidMove(new_row, _column)){
        Piece* currentMovePiece = board->squares[new_row][_column]->_piece;
        if(currentMovePiece->_color == _color) break;
        else if(currentMovePiece->_color == Color::nonExisted){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+_column*100, 88+new_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[new_row][_column]->turnMarker = turn;
            board->turns.append(turn);
            scene->addItem(turn);
            new_row++;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[new_row][_column]->update();
            break;
        }
    }

    // Вверх
    new_row = _row-1;
    while(isValidMove(new_row, _column)){
        Piece* currentMovePiece = board->squares[new_row][_column]->_piece;
        if(currentMovePiece->_color == _color) break;
        else if(currentMovePiece->_color == Color::nonExisted){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+_column*100, 88+new_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[new_row][_column]->turnMarker = turn;
            board->turns.append(turn);
            scene->addItem(turn);
            new_row--;
        }
        else{
            board->squares[new_row][_column]->_piece->isTarget = true;
            board->squares[new_row][_column]->update();
            break;
        }

    }

    // Направо
    new_column = _column+1;
    while(isValidMove(_row, new_column)){
        Piece* currentMovePiece = board->squares[_row][new_column]->_piece;
        if(currentMovePiece->_color == _color) break;
        else if(currentMovePiece->_color == Color::nonExisted){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+new_column*100, 88+_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[_row][new_column]->turnMarker = turn;
            board->turns.append(turn);
            scene->addItem(turn);
            new_column++;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[_row][new_column]->update();
            break;
        }
    }

    // Налево
    new_column = _column-1;
    while(isValidMove(_row, new_column)){
        Piece* currentMovePiece = board->squares[_row][new_column]->_piece;
        if(currentMovePiece->_color == _color) break;
        else if(currentMovePiece->_color == Color::nonExisted){
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                88+new_column*100, 88+_row*100, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[_row][new_column]->turnMarker = turn;
            board->turns.append(turn);
            scene->addItem(turn);
            new_column--;
        }
        else{
            currentMovePiece->isTarget = true;
            board->squares[_row][new_column]->update();
            break;
        }
    }
}