#include "main.h"
//#include "chessPiece.h"

class Square : public QGraphicsRectItem
{
public:

    // Constructors
    Square(QGraphicsRectItem* parent = nullptr);
    ~Square();

    void setColor(QColor color);
    //void setHasChessPiece(bool value, Piece *piece = 0);
    void setPieceColor(QString value);
    //Piece* currentPiece;

private:
    QBrush brush;
    bool hasChessPiece;
    QString chessPieceColor;
};