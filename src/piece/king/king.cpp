#include "king.h"
#include "board.h"

extern Board* board;

King::King(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_King.png");
    else 
        image = QPixmap(":/Chess/images/Black_King.png");
}   

bool King::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}

void King::setCastlingMoves(){
    if(board->currentMoveColor == board->firstTurnColor){
        // short castling
        if(board->squares[7][5]->piece->color == Color::nonExistent
        && board->squares[7][6]->piece->color == Color::nonExistent
        && firstMove == true
        && board->squares[7][7]->piece->firstMove == true
        && dynamic_cast<Rook*>(board->squares[7][7]->piece) != nullptr)
        {
            board->squares[7][7]->piece->castlingAvailable = true;
            board->squares[7][7]->update();
        }
        // long castling
        if(board->squares[7][3]->piece->color == Color::nonExistent
        && board->squares[7][2]->piece->color == Color::nonExistent
        && board->squares[7][1]->piece->color == Color::nonExistent
        && firstMove == true
        && board->squares[7][0]->piece->firstMove == true
        && dynamic_cast<Rook*>(board->squares[7][0]->piece) != nullptr)
        {
            board->squares[7][0]->piece->castlingAvailable = true;
            board->squares[7][0]->update();
        }
    }
    else{
        // short castling
        if(board->squares[0][5]->piece->color == Color::nonExistent
        && board->squares[0][6]->piece->color == Color::nonExistent
        && firstMove == true
        && board->squares[0][7]->piece->firstMove == true
        && dynamic_cast<Rook*>(board->squares[0][7]->piece) != nullptr)
        {
            board->squares[0][7]->piece->castlingAvailable = true;
            board->squares[0][7]->update();
        }
        // long castling
        if(board->squares[0][3]->piece->color == Color::nonExistent
        && board->squares[0][2]->piece->color == Color::nonExistent
        && board->squares[0][1]->piece->color == Color::nonExistent
        && firstMove == true
        && board->squares[0][0]->piece->firstMove == true
        && dynamic_cast<Rook*>(board->squares[0][0]->piece) != nullptr)
        {
            board->squares[0][0]->piece->castlingAvailable = true;
            board->squares[0][0]->update();
        }
    }
}

void King::setMoves(QGraphicsScene* scene){
    int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
    int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

    for(int i = 0; i < 8; i++){
        int new_row = row + dx[i];
        int new_column = column + dy[i];
        if(isValidMove(new_row, new_column)){
            Piece* currentMovePiece = board->squares[new_row][new_column]->piece;
            if(currentMovePiece->color == Color::nonExistent){
                QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                    88+new_column*100, 88+new_row*100, 25, 25);
                turn->setBrush(QColor(0, 174, 88));
                turn->setPen(Qt::NoPen);
                board->squares[new_row][new_column]->turnMarker = turn;
                turns.append(turn);
                scene->addItem(turn);
            }
            else if (currentMovePiece->color != color){
                currentMovePiece->isTarget = true;
                board->squares[new_row][new_column]->update();
            }
        } 
    }
    // При возможности показывает ходы для рокировки
    setCastlingMoves();
}

void King::clearTurns(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
}