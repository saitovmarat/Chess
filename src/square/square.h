#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include <QVector>

#include "piece.h"
#include "main.h"

class Piece;

class Square : public QGraphicsItem {
public:
  Square(QGraphicsItem *parent = nullptr);
  Square(int x, int y, int w, int h, 
        QGraphicsItem *parent = nullptr);

  void drawImage(QPainter *painter);

  void setBackColor(QString color);
  void setBackColor(int r, int g, int b);

  void setPiece(Piece* piece);
  void setImage(QString imagePath);

  // Поля
  bool Pressed;
  Piece* _piece;
  int _x;
  int _y;
  int _w;
  int _h;
  QColor backgroundColor;
  QPixmap _image;

protected:
  void paint(QPainter *painter, 
            const QStyleOptionGraphicsItem *option,
            QWidget *widget) override;
  QRectF boundingRect() const override;
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;


private:


};

#endif