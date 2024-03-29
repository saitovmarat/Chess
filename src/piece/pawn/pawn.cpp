#include "pawn.h"
#include "board.h"

extern Board* board;

Pawn::Pawn(int row, int column, Color color) : Piece(row, column, color){
    _firstMove = true;
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_Pawn.png");
    else 
        _image = QPixmap(":/Chess/images/Black_Pawn.png");
}   

bool Pawn::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}
void Pawn::setWhiteMoves(QGraphicsScene* scene){
    if(_row-1 < 0) return;

    if(isValidMove(_row, _column+1)){
        if(board->squares[_row-1][_column+1]->_piece->_color == Color::black){
            board->squares[_row-1][_column+1]->_piece->isTarget = true;
            board->squares[_row-1][_column+1]->update();
        }
    }
    if(isValidMove(_row, _column-1)){
        if(board->squares[_row-1][_column-1]->_piece->_color == Color::black){
            board->squares[_row-1][_column-1]->_piece->isTarget = true;
            board->squares[_row-1][_column-1]->update();
        }
    }

    int moves = _firstMove? 2: 1;
    for(int i = 1; i <= moves; i++){
        if(board->squares[_row-i][_column]->_piece->_color != Color::nonExisted)
            break;
        
        QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
        88+_column*100, 88+(_row-i)*100, 25, 25);
        turn->setBrush(QColor(0, 174, 88));
        turn->setPen(Qt::NoPen);
        board->squares[_row-i][_column]->turnMarker = turn;
        board->turns.append(turn);
        scene->addItem(turn);
    }
}

void Pawn::setBlackMoves(QGraphicsScene* scene){
    if(_row+1 > 7) return;

    if(isValidMove(_row, _column+1)){
        if(board->squares[_row+1][_column+1]->_piece->_color == Color::white){
            board->squares[_row+1][_column+1]->_piece->isTarget = true;
            board->squares[_row+1][_column+1]->update();
        }
    }
    if(isValidMove(_row, _column-1)){
        if(board->squares[_row+1][_column-1]->_piece->_color == Color::white){
            board->squares[_row+1][_column-1]->_piece->isTarget = true;
            board->squares[_row+1][_column-1]->update();
        }
    }
    int moves = _firstMove? 2: 1;
    for(int i = 1; i <= moves; i++){
        if(board->squares[_row+i][_column]->_piece->_color != Color::nonExisted)
            break;
        QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
        88+_column*100, 88+(_row+i)*100, 25, 25);
        turn->setBrush(QColor(0, 174, 88));
        turn->setPen(Qt::NoPen);
        board->squares[_row+i][_column]->turnMarker = turn;
        board->turns.append(turn);
        scene->addItem(turn);
    }
}

void Pawn::setMoves(QGraphicsScene* scene){
    if(_color == Color::white){
        setWhiteMoves(scene);
    }
    else if(_color == Color::black){
        setBlackMoves(scene);
    }
}