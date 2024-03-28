#include "pawn.h"
#include "board.h"

extern Board* board;

Pawn::Pawn(int row, int column, Color color) : Piece(row, column, color){
    _row = row;
    _column = column;
    _color = color;
    _firstMove = true;
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_Pawn.png");
    else 
        _image = QPixmap(":/Chess/images/Black_Pawn.png");
}   

void Pawn::setWhiteMoves(QGraphicsScene* scene){
    if(_row-1 < 0) return;

    int moves = _firstMove? 2: 1;
    for(int i = 0; i < moves; i++){
        if(board->squares[_row-(i+1)][_column]->_piece->_color == Color::white)
            break;
        QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
        38+(_column+1)*100, 38+(_row-i)*100, 25, 25);
        turn->setBrush(QColor(0, 174, 88));
        turn->setPen(Qt::NoPen);
        board->squares[_row-(i+1)][_column]->turnMarker = turn;
        board->turns.append(turn);
        scene->addItem(turn);
    }
}

void Pawn::setBlackMoves(QGraphicsScene* scene){
    if(_row+1 > 7) return;

    int moves = _firstMove? 2: 1;
    for(int i = 0; i < moves; i++){
        if(board->squares[_row+(i+2)][_column]->_piece->_color == Color::black)
            break;
        QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
        38+(_column+1)*100, 38+(_row+(i+2))*100, 25, 25);
        turn->setBrush(QColor(0, 174, 88));
        turn->setPen(Qt::NoPen);
        board->squares[_row+(i+2)][_column]->turnMarker = turn;
        board->turns.append(turn);
        scene->addItem(turn);
    }
}