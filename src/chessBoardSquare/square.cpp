#include "square.h"

Square::Square(int x, int y, int w, int h, QGraphicsRectItem* parent) 
: QGraphicsRectItem(parent){
    _x = x;
    _y = y;
    _w = w;
    _h = h;
}
void Square::setBackColor(QString color){
    backgroundColor = QColor(color);
}
void Square::setBackColor(int r, int g, int b){
    backgroundColor = QColor(r, g, b);
}
void Square::setImage(QString imagePath){
    _image = imagePath;
}
QRectF Square::boundingRect() const{
    return QRectF(_x, _y, _w, _h);
}
void Square::paint(QPainter *painter, 
    const QStyleOptionGraphicsItem *option, 
    QWidget *widget){    
    painter->setBrush(backgroundColor);
    painter->setPen(Qt::NoPen);
    painter->drawRect(_x, _y, _w, _h);
    drawImage(painter);
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


