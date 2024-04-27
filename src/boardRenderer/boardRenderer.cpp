#include "boardRenderer.h"
#include "square.h"

#define shift 100

void BoardRenderer::drawBorders(QGraphicsScene* scene){
    for(int i = 0; i < 8; i++){
        QGraphicsRectItem* rectLeft = new QGraphicsRectItem(0, 50+shift*i, 50, 100);
        QGraphicsRectItem* rectRight = new QGraphicsRectItem(850, 50+shift*i, 50, 100);
        QGraphicsRectItem* rectTop = new QGraphicsRectItem(50+shift*i, 0, 100, 50);
        QGraphicsRectItem* rectBottom = new QGraphicsRectItem(50+shift*i, 850, 100, 50);

        rectLeft->setPen(Qt::NoPen);
        rectRight->setPen(Qt::NoPen);
        rectTop->setPen(Qt::NoPen);
        rectBottom->setPen(Qt::NoPen);

        rectLeft->setBrush(QColor(111, 78, 55));
        rectRight->setBrush(QColor(111, 78, 55));
        rectTop->setBrush(QColor(111, 78, 55));
        rectBottom->setBrush(QColor(111, 78, 55));

        scene->addItem(rectLeft);
        scene->addItem(rectRight);
        scene->addItem(rectTop);
        scene->addItem(rectBottom);
    }
    // Отрисовка уголков
    QGraphicsRectItem* rectLeftTop = new QGraphicsRectItem(0, 0, 50, 50);
    QGraphicsRectItem* rectLeftBottom = new QGraphicsRectItem(0, 850, 50, 50);
    QGraphicsRectItem* rectRightTop = new QGraphicsRectItem(850, 0, 50, 50);
    QGraphicsRectItem* rectRightBottom = new QGraphicsRectItem(850, 850, 50, 50);

    rectLeftTop->setPen(Qt::NoPen);
    rectLeftBottom->setPen(Qt::NoPen);
    rectRightTop->setPen(Qt::NoPen);
    rectRightBottom->setPen(Qt::NoPen);
    
    rectLeftTop->setBrush(QColor(111, 78, 55));
    rectLeftBottom->setBrush(QColor(111, 78, 55));
    rectRightTop->setBrush(QColor(111, 78, 55));
    rectRightBottom->setBrush(QColor(111, 78, 55));

    scene->addItem(rectLeftTop);
    scene->addItem(rectLeftBottom);
    scene->addItem(rectRightTop);
    scene->addItem(rectRightBottom);
    
}

void BoardRenderer::render(Board* board, QGraphicsScene* scene){
    drawBorders(scene);
    for(int row = 0; row < 8; row++){
        for(int column = 0; column < 8; column++){
            scene->addItem(board->squares[row][column]);
        }
    }
}