#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include "main.h"
#include "chessPiece.h"

class ChessPiece;
class Square : public QGraphicsRectItem
{
public:

    // Constructors
    Square(QGraphicsRectItem* parent = 0);
    ~Square();

    void setPieceColor(QString value);

    int rowLoc;
    int colLoc;

    ChessPiece* currentPiece;

private:
    QBrush brush;
    QColor originalColor;
    bool hasChessPiece;
    QString chessPieceColor;
};

#endif