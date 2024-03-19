#include "main.h"
#include "chessBoard.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    // create a scene
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor("lightblue")));
    ChessBoard* board = new ChessBoard();

    board->drawBoard(scene);

    // add a view
    QGraphicsView* view = new QGraphicsView(scene);
    view->showMaximized();

    return app.exec();
}