#include "pawn.h"
#include "board.h"

extern Board* board;

Pawn::Pawn(int row, int column, Color color) : Piece(row, column, color){
    firstMove = true;
    if(color == Color::white) 
        image = QPixmap(":/Chess/images/White_Pawn.png");
    else 
        image = QPixmap(":/Chess/images/Black_Pawn.png");
}   

bool Pawn::isValidMove(int row, int column){
    if(row < 0 || row > 7 || column < 0 || column > 7)
        return false;
    return true;
}
void Pawn::set_BottomPlayerMoves(QGraphicsScene* scene){
    Color enemyColor = (board->currentMoveColor == Color::white)? Color::black : Color::white;
    if(row-1 < 0) return;

    if(isValidMove(row, column+1)){
        if(board->squares[row-1][column+1]->piece->color == enemyColor){
            board->squares[row-1][column+1]->piece->isTarget = true;
            board->squares[row-1][column+1]->update();
        }
    }
    if(isValidMove(row, column-1)){
        if(board->squares[row-1][column-1]->piece->color == enemyColor){
            board->squares[row-1][column-1]->piece->isTarget = true;
            board->squares[row-1][column-1]->update();
        }
    }

    int moves = firstMove? 2: 1;
    for(int i = 1; i <= moves; i++){
        if(board->squares[row-i][column]->piece->color != Color::nonExistent)
            break;
        
        QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
        88+column*100, 88+(row-i)*100, 25, 25);
        turn->setBrush(QColor(0, 174, 88));
        turn->setPen(Qt::NoPen);
        board->squares[row-i][column]->turnMarker = turn;
        turns.append(turn);
        scene->addItem(turn);
    }
}

void Pawn::set_TopPlayerMoves(QGraphicsScene* scene){
    Color enemyColor = (board->currentMoveColor == Color::white)? Color::black : Color::white;
    if(row+1 > 7) return;

    if(isValidMove(row, column+1)){
        if(board->squares[row+1][column+1]->piece->color == enemyColor){
            board->squares[row+1][column+1]->piece->isTarget = true;
            board->squares[row+1][column+1]->update();
        }
    }
    if(isValidMove(row, column-1)){
        if(board->squares[row+1][column-1]->piece->color == enemyColor){
            board->squares[row+1][column-1]->piece->isTarget = true;
            board->squares[row+1][column-1]->update();
        }
    }
    int moves = firstMove? 2: 1;
    for(int i = 1; i <= moves; i++){
        if(board->squares[row+i][column]->piece->color != Color::nonExistent)
            break;
        QGraphicsEllipseItem* turn = new QGraphicsEllipseItem(
        88+column*100, 88+(row+i)*100, 25, 25);
        turn->setBrush(QColor(0, 174, 88));
        turn->setPen(Qt::NoPen);
        board->squares[row+i][column]->turnMarker = turn;
        turns.append(turn);
        scene->addItem(turn);
    }
}

void Pawn::setMoves(QGraphicsScene* scene){
    if(board->currentMoveColor == board->firstTurnColor){
        set_BottomPlayerMoves(scene);
    }
    else{
        set_TopPlayerMoves(scene);
    }
}

void Pawn::clearTurns(){
    while(!turns.isEmpty()) {
        delete turns.at(0);
        turns.removeAt(0);
    }
}