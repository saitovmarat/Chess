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
        QGraphicsItem* parent = nullptr);
    Square(QGraphicsItem* parent = nullptr);

    void drawImage(QPainter *painter);
    void drawCord(QPainter *painter);

    void setBackColor(QString color);
    void setImage(QString imagePath);
    void setCord(QString cord);

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
    QString backgroundColor = "white";
    QString _image = "";
    QString _cord = NULL;
    bool pressed;
};

#endif