#include "knight.h"
#include "board.h"

extern Board* board;

Knight::Knight(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_Knight.png");
    else 
        _image = QPixmap(":/Chess/images/Black_Knight.png");
}   

bool Knight::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}
void Knight::setMoves(QGraphicsScene* scene){
    int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    for(int i = 0; i < 8; i++){
        int new_row = _row + dx[i];
        int new_column = _column + dy[i];
        if(isValidMove(new_row, new_column)){
            Piece* currentMovePiece = board->squares[new_row][new_column]->_piece;
            if(currentMovePiece->_color == Color::nonExistent){
                QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                    88+new_column*100, 88+new_row*100, 25, 25);
                turn->setBrush(QColor(0, 174, 88));
                turn->setPen(Qt::NoPen);
                board->squares[new_row][new_column]->turnMarker = turn;
                board->turns.append(turn);
                scene->addItem(turn);
            }
            else if (currentMovePiece->_color != _color){
                currentMovePiece->isTarget = true;
                board->squares[new_row][new_column]->update();
            }
            
            
        }
        
    }
}