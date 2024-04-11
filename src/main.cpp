#include "main.h"
#include "board.h"
#include "boardRenderer.h"

#include "formMainMenu.h"
#include "formMenuChooseColor.h"
#include "formEndGame.h"


// TODO: include only needed libs

// Костыльные конструкции:
// board.cpp 71
// Square::deletePiece()

Board* board;
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor("lightblue")));
    board = new Board(scene);
    board->setUpBoard();

    BoardRenderer::render(board, scene);

    QGraphicsView* view = new QGraphicsView(scene);
    view->showMaximized();

    // QWidget windowChooseMode;
    // Ui_FormMenuChooseMode ui_chooseMode;
    // ui_chooseMode.setupUi(&windowChooseMode);
    // windowChooseMode.show();

    // QWidget windowEndGame;
    // Ui_FormEndGame ui_endGame;
    // ui_endGame.setupUi(&windowEndGame);
    // windowEndGame.show();

    // QWidget windowChooseColor;
    // Ui_FormMenuChooseColor ui_chooseColor;
    // ui_chooseColor.setupUi(&windowChooseColor);
    // windowChooseColor.show();

    return app.exec();
}