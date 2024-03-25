#include "square.h"

Square::Square(QGraphicsItem* parent)
: QGraphicsItem(parent){}

Square::Square(int x, int y, int w, int h, QGraphicsItem* parent) 
: QGraphicsItem(parent){
    _x = x;
    _y = y;
    _w = w;
    _h = h;
    Pressed = false;
}

void Square::setPiece(Piece* piece){
    _piece = piece;
    _image = _piece->_image;
}

void Square::setBackColor(QString color){
    backgroundColor = QColor(color);
}
void Square::setBackColor(int r, int g, int b){
    backgroundColor = QColor(r, g, b);
}
void Square::setImage(QString imagePath){
    _image = QPixmap(imagePath);
}
QRectF Square::boundingRect() const{
    return QRectF(_x, _y, _w, _h);
}
void Square::paint(QPainter *painter, 
    const QStyleOptionGraphicsItem *option, 
    QWidget *widget){  
    if(Pressed){
        painter->setBrush(QColor(0, 174, 88));
    }
    else{
        painter->setBrush(backgroundColor);
        Pressed = false;
    }
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
    drawImage(painter);
}

void Square::drawImage(QPainter *painter){
    if(!_image.isNull())
        painter->drawPixmap(boundingRect().toRect(), 
            _image.scaled(_w, _h, Qt::KeepAspectRatio));
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(Pressed) Pressed = false;
    else if(!Pressed && !_image.isNull()) Pressed = true;
    update();
    QGraphicsItem::mousePressEvent(event);
}



