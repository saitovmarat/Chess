#include "knight.h"
#include "board.h"

extern Board* board;

Knight::Knight(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Knight.png");
    else 
        image = QPixmap(":/Chess/images/Black_Knight.png");
}   

bool Knight::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}
void Knight::setMoves(){
    int dx[8] = { -2, -1, 1, 2, -2, -1, 1, 2 };
    int dy[8] = { -1, -2, -2, -1, 1, 2, 2, 1 };

    for(int i = 0; i < 8; i++){
        int new_row = row + dx[i];
        int new_column = column + dy[i];
        if(isValidMove(new_row, new_column)){
            Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
            if(currentMovePiece->color != color){
                possibleMovesCoords.push_back({new_row, new_column});      
                if(currentMovePiece->color != Color::nonExistent){
                    currentMovePiece->isTarget = true;
                }
            }
        } 
    }
}
void Knight::showMoves(QGraphicsScene* scene){
    for(Coordinates move : possibleMovesCoords){
        if(board->squares[move.row][move.column]->piece->color != Color::nonExistent){
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
void Knight::clearTurns(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
    for(Coordinates move : possibleMovesCoords){
        board->squares[move.row][move.column]->turnMarker = nullptr;
        board->squares[move.row][move.column]->piece->isTarget = false;
        board->squares[move.row][move.column]->update();
    }
    possibleMovesCoords.clear();
}