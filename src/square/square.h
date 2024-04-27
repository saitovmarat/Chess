#ifndef CHESS_SQUARE_H
#define CHESS_SQUARE_H

#include "piece.h"
#include "main.h"

class Piece;
class Square : public QGraphicsItem {
public:
  Square(int column, int row, QGraphicsItem *parent = nullptr);

  void setBackColor(int r, int g, int b);

  void setPiece(Piece* piece);
  void clearSquare();

  void turnMarkerPressEvent();
  void consumeTarget();
  void performCastling();

  void endTurn();

  void drawImage(QPainter *painter);

  // Поля
  bool isPressed;
  Piece* piece = nullptr;
  QGraphicsEllipseItem* turnMarker = nullptr;
  int row;
  int column;
  const int w = 100;
  const int h = 100;

  QColor backgroundColor;
  QPixmap image;

protected:
  void paint(QPainter *painter, 
            const QStyleOptionGraphicsItem *option,
            QWidget *widget) override;
  QRectF boundingRect() const override;
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
};

#endif