#include "main.h"
//#include "square.h"

class ChessPiece:public QGraphicsPixmapItem
{
public:
    ChessPiece(QString item = "", QGraphicsItem* parent = nullptr);
    bool firstMove;

private:
    QString side;
    bool isPlaced;
    //QList <Square*> location;
};

