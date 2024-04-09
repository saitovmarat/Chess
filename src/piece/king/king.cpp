#include "king.h"
#include "board.h"

extern Board* board;

King::King(int row, int column, Color color) : Piece(row, column, color){
    _row = row;
    _column = column;
    _color = color;
    if(color == Color::white) 
        _image = QPixmap(":/Chess/images/White_King.png");
    else 
        _image = QPixmap(":/Chess/images/Black_King.png");
}   

bool King::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}

bool King::castlingAvailable(){
    if(board->squares[7][5]->_piece->_color == Color::nonExistent
    && board->squares[7][6]->_piece->_color == Color::nonExistent
    && _firstMove == true
    && board->squares[7][7]->_piece->_firstMove == true
    && dynamic_cast<Rook*>(board->squares[7][7]->_piece) != nullptr)
        return true;
    return false;
}

void King::setMoves(QGraphicsScene* scene){
    int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
    int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

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
    if(castlingAvailable()){
        board->squares[7][7]->_piece->castlingAvailable = true;
        board->squares[7][7]->update();
    }
}