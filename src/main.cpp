#include "main.h"
#include "board.h"
#include "boardRenderer.h"

// TODO: include only needed libs

// Костыльные конструкции:
// board.cpp 71
// Square::deletePiece()


Board* board;
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor("lightblue")));

    board = new Board(scene);
    board->setUpBoard();

    BoardRenderer::render(board, scene);

    // add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view->showMaximized();

    return app.exec();
}