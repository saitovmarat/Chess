#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H

#include "chessPiece.h"
#include "main.h"

class ChessBoard:public QWidget{
    Q_OBJECT
public:

    explicit ChessBoard(QWidget* parent = nullptr);

    void drawBoxes(QGraphicsScene* scene);
    void getParameters(float *dx, float *dy, float *sizeBoard, float *rectX, float *rectY, QVector<char> *character, QVector<char> *numbers);
    void paintImage(QGraphicsScene* scene);

    void paintEvent(QPaintEvent* event);

    void setUpWhite();
    void setUpBlack();

private:

    QList <ChessPiece *> white;
    QList <ChessPiece *> black;
};

#endif