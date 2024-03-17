#include "square.h"

Square::Square(int x, int y, int w, int h, const QString imagePath, QGraphicsItem* parent) 
: QGraphicsRectItem(parent){
    _x, _y, _w, _h, _imagePath = x, y, w, h, imagePath;
}
Square::Square(QGraphicsItem* parent)
: QGraphicsRectItem(parent){}

QRectF Square::boundingRect() const{
    return QRectF(0, 0, _w, _h);
}
void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::lightGray);
    painter->drawRect(boundingRect());
    if (!_imagePath.isEmpty()) {
        QPixmap image(_imagePath);
        painter->drawPixmap(boundingRect().toRect(), 
            image.scaled(_w, _h, Qt::KeepAspectRatio));
    }
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}

void Square::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    pressed = false;
    update();
    QGraphicsItem::mouseReleaseEvent(event);
}


