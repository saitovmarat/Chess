#include "chessPiece.h"

ChessPiece::ChessPiece(QString team, QGraphicsItem *parent){
    side = team;
    isPlaced = true;
    firstMove = true;
}