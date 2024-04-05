#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include "piece.h"
#include "main.h"

class Piece;
class Square : public QGraphicsItem {
public:
  Square(int column, int row, QGraphicsItem *parent = nullptr);

  void drawImage(QPainter *painter);

  void setBackColor(int r, int g, int b);
  void setBackColor(QColor color);

  void setPiece(Piece* piece);

  void turnMarker_pressEvent();
  void eatingTarget_pressEvent();
  void castling_pressEvent();

  void endTurn();

  // Поля
  bool Pressed;
  Piece* _piece = nullptr;
  QGraphicsEllipseItem* turnMarker = nullptr;
  int _row;
  int _column;
  const int _w = 100;
  const int _h = 100;

  QColor backgroundColor;
  QPixmap _image;

protected:
  void paint(QPainter *painter, 
            const QStyleOptionGraphicsItem *option,
            QWidget *widget) override;
  QRectF boundingRect() const override;
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif