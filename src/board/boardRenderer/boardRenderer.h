#include "board.h"

class BoardRenderer{
public:
    static void drawBorders(QGraphicsScene* scene);
    static void render(Board* board, QGraphicsScene* scene);
};