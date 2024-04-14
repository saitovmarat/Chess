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

  void turnMarker_pressEvent();
  void eatingTarget_pressEvent();
  void castling_pressEvent();

  bool checkExists();
  void blockPieces();
  void endTurn();

  void outputFen();
  char getFenPieceSymbol(const char* pieceName, Color pieceColor);

  void drawImage(QPainter *painter);

  // Поля
  bool Pressed;
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