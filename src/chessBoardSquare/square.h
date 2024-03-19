#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include "main.h"
#include "chessPiece.h"
#include <QVector>


class ChessPiece;
class Square : public QGraphicsRectItem
{
public:
    Square(int x, int y, int w, int h, 
        QGraphicsRectItem* parent = nullptr);

    void drawImage(QPainter *painter);

    void setBackColor(QString color);
    void setBackColor(int r, int g, int b);

    void setImage(QString imagePath);

protected:
    void paint(QPainter *painter, 
        const QStyleOptionGraphicsItem *option,
        QWidget *widget);
    QRectF boundingRect() const;
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);

private:
    int _x;
    int _y;
    int _w;
    int _h;
    QColor backgroundColor;
    QString _image;
    bool pressed;
};

#endif