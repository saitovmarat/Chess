#ifndef MAIN_H
#define MAIN_H

#include <QApplication>
#include <QBrush>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QWidget>

#include <iostream>

#define shift 100

enum Color { white, black };
enum pieceType { pawn, knight, bishop, rook, queen, king };
enum Row { A, B, C, D, E, F, G, H };
enum numCord { num1, num2, num3, num4, num5, num6, num7, num8 };

#endif  // MAIN_H