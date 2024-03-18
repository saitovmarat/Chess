#ifndef MAIN_H
#define MAIN_H

#include <QWidget>
#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <iostream>

enum pieceColor{
    white, black
};
enum pieceType{
    pawn, knight, bishop, rook, queen, king
};
enum characterCord{
    A, B, C, D, E, F, G, H
};
enum numCord{
    num1, num2, num3, num4, num5, num6, num7, num8
};

#endif // MAIN_H