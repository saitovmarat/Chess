#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include <QVector>

#include "chessPiece.h"
#include "main.h"

class ChessPiece;
class Square : public QGraphicsItem {
 public:
  Square(QGraphicsItem *parent = nullptr);
  Square(int x, int y, int w, int h, QGraphicsItem *parent = nullptr);

  void drawImage(QPainter *painter);

  void setBackColor(QString color);
  void setBackColor(int r, int g, int b);

  void setImage(QString imagePath);
  bool Pressed;

 protected:
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
             QWidget *widget);
  QRectF boundingRect() const;
  void mousePressEvent(QGraphicsSceneMouseEvent *event);

 private:
  int _x;
  int _y;
  int _w;
  int _h;
  QColor backgroundColor;
  QString _image;
};

#endif