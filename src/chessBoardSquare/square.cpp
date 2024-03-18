#include "square.h"

Square::Square(int x, int y, int w, int h, QGraphicsItem* parent) 
: QGraphicsRectItem(parent){
    _x = x;
    _y = y;
    _w = w;
    _h = h;
}
Square::Square(QGraphicsItem* parent)
: QGraphicsRectItem(parent){
    _x = 0;
    _y = 0;
    _w = 100;
    _h = 100;
}
void Square::setBackColor(QString color){
    backgroundColor = color;
}
void Square::setImage(QString imagePath){
    _image = imagePath;
}
void Square::setCord(QString cord){
    _cord = cord;
}
QRectF Square::boundingRect() const{
    return QRectF(_x, _y, _w, _h);
}
void Square::paint(QPainter *painter, 
    const QStyleOptionGraphicsItem *option, 
    QWidget *widget){    
    painter->setBrush(QColor(backgroundColor));
    painter->drawRect(_x, _y, _w, _h);
    drawImage(painter);
    drawCord(painter);
}

void Square::drawCord(QPainter *painter){
    if (!_cord.isNull()){
        QString cord = QString(_cord);
        painter->drawText(
            boundingRect().toRect(), Qt::AlignCenter, cord);
    }
}
void Square::drawImage(QPainter *painter){
    QPixmap image(_image);
    if(!image.isNull())
        painter->drawPixmap(boundingRect().toRect(), 
            image.scaled(_w, _h, Qt::KeepAspectRatio));
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


