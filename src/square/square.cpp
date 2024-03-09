#include "square.h"

Square::Square(QGraphicsRectItem* parent){
    setRect(0,0, 100, 100);
    brush.setStyle(Qt::SolidPattern);
    setZValue(-1);
    setPieceColor("NONE");
    //currentPiece = NULL;
}

Square::~Square(){
    delete this;
}

void Square::setPieceColor(QString value)
{
    chessPieceColor = value;
}