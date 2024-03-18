#include "main.h"
#include "chessBoard.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();
    ChessBoard* board = new ChessBoard();

    board->drawBoxes(scene);

    // add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view->showMaximized();

    return app.exec();
}