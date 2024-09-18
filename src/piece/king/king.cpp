#include "king.h"
#include "board.h"

extern Board* board;

King::King(int row, int column, Color color) : Piece(row, column, color){
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_King.png");
    else 
        image = QPixmap(":/Chess/images/Black_King.png");
}   

void King::setCastlingMoves(){
    if(board->currentMoveColor == board->bottomPlayerColor){
        // short castling
        if(!board->squares[7][5]->piece
        && !board->squares[7][6]->piece
        && firstMove == true
        && board->squares[7][7]->piece->firstMove == true
        && dynamic_cast<Rook*>(board->squares[7][7]->piece) != nullptr)
        {
            possibleMovesCoords.push_back({7, 7});
        }
        // long castling
        if(!board->squares[7][3]->piece
        && !board->squares[7][2]->piece
        && !board->squares[7][1]->piece
        && firstMove == true
        && board->squares[7][0]->piece->firstMove == true
        && dynamic_cast<Rook*>(board->squares[7][0]->piece) != nullptr)
        {
            possibleMovesCoords.push_back({7, 0});
        }
    }
    else{
        // short castling
        if(!board->squares[0][5]->piece
        && !board->squares[0][6]->piece
        && firstMove == true
        && board->squares[0][7]->piece->firstMove == true
        && dynamic_cast<Rook*>(board->squares[0][7]->piece) != nullptr)
        {
            possibleMovesCoords.push_back({0, 7});
        }
        // long castling
        if(!board->squares[0][3]->piece
        && !board->squares[0][2]->piece
        && !board->squares[0][1]->piece
        && firstMove == true
        && board->squares[0][0]->piece->firstMove == true
        && dynamic_cast<Rook*>(board->squares[0][0]->piece) != nullptr)
        {
            possibleMovesCoords.push_back({0, 0});
        }
    }
}

void King::setAllMoves(){
    clearMoves();
    int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
    int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

    for(int i = 0; i < 8; i++){
        int new_row = row + dx[i];
        int new_column = column + dy[i];
        if(!outOfBounds(new_row, new_column)){
            Square* currentMoveSquare = board->squares[new_row][new_column];
            if(currentMoveSquare->piece){
                if(currentMoveSquare->piece->color != color)
                    possibleMovesCoords.push_back({new_row, new_column});
            }
            else
                possibleMovesCoords.push_back({new_row, new_column});
        } 
    }
    // При возможности показывает ходы для рокировки
    setCastlingMoves();
}
void King::setMoves(){
    clearMoves();
    int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
    int dy[8] = { -1, 0, 1, -1, 0, 1, -1, 1 };

    for(int i = 0; i < 8; i++){
        int new_row = row + dx[i];
        int new_column = column + dy[i];
        if(!outOfBounds(new_row, new_column)){
            Square* currentMoveSquare = board->squares[new_row][new_column];
            if(currentMoveSquare->piece){
                if(currentMoveSquare->piece->color != color)
                    possibleMovesCoords.push_back({new_row, new_column});
            }
            else
                possibleMovesCoords.push_back({new_row, new_column});
        } 
    }
    // При возможности показывает ходы для рокировки
    setCastlingMoves();
}

void King::showMoves(QGraphicsScene* scene){
    for(Coordinates move : possibleMovesCoords){
        if(board->squares[move.row][move.column]->piece){
            Piece* currentMovePiece = board->squares[move.row][move.column]->piece;
            if(currentMovePiece->color != color)
                currentMovePiece->isTarget = true;
            else
                currentMovePiece->isCastlingAvailable = true;
            board->squares[move.row][move.column]->update();
        }
        else{
            QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
                move.column * 100 + 88, move.row * 100 + 88, 25, 25);
            turn->setBrush(QColor(0, 174, 88));
            turn->setPen(Qt::NoPen);
            board->squares[move.row][move.column]->turnMarker = turn;
            turns.append(turn);
            scene->addItem(turn);
        }
        
    }
}
void King::clearTurns(){
    clearMoves();
    clearTurnMarkers();
}

void King::clearMoves(){
    for(Coordinates move : possibleMovesCoords){
        board->squares[move.row][move.column]->turnMarker = nullptr;
        if(board->squares[move.row][move.column]->piece){
            board->squares[move.row][move.column]->piece->isCastlingAvailable = false;
            board->squares[move.row][move.column]->piece->isTarget = false;
        }
        board->squares[move.row][move.column]->update();
    }
    possibleMovesCoords.clear();
}
void King::clearTurnMarkers(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
}