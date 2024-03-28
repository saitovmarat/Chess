#include "bishop.h"
#include "board.h"

extern Board *board;

Bishop::Bishop(int row, int column, Color color) : Piece(row, column, color){
    _row = row;
    _column = column;
    _color = color;
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_Bishop.png");
    else
        _image = QPixmap(":/Chess/images/Black_Bishop.png");
}   

// void Bishop::setMoves(QGraphicsScene* scene){
//     QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
//         38+_column*100, 38+_row*100, 25, 25);
    
//     board->turns.append(turn);
//     turn->setBrush(QColor(0, 174, 88));
//     turn->setPen(Qt::NoPen);
//     scene->addItem(turn);
//     board->squares[_row][_column];
// }