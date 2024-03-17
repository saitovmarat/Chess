#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include "main.h"
#include "chessPiece.h"

class ChessPiece;
class Square : public QGraphicsRectItem
{
public:
    Square(int x, int y, int w, int h, 
        const QString imagePath, QGraphicsItem* parent = nullptr);
    Square(QGraphicsItem* parent = nullptr);
    
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

private:
    int _x, _y, _w, _h = 0;
    QString _imagePath = "";
    bool pressed;
};

#endif