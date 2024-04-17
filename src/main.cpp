#include "main.h"
#include "board.h"
#include "boardRenderer.h"

#include "formMainMenu.h"
#include "formMenuChooseColor.h"
#include "formEndGame.h"
#include "menuController.h"

// TODO: использовать только нужные библиотеки и хедеры в каждом файле
// Узнать начсет структуры и как сделать адекватно взятие на проходе
// Исправить отрисовку ходов учитывая не цвет фигур, а то какой цвет ходит первым. 

// Костыльные конструкции:
// board.cpp 71
// Square::deletePiece()

Board* board;
int main(int argc, char* argv[]) {
    QApplication app(argc, argv);
    MenuController menuController;

    return app.exec();
}