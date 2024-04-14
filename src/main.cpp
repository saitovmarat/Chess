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

    QGraphicsView* windowGame = new QGraphicsView(scene);
    
    // Создание стекового виджета
    QStackedWidget *stackedWidget = new QStackedWidget;

    Ui_FormMenuChooseMode ui_chooseMode;
    QGraphicsView* windowChooseMode = new QGraphicsView();
    ui_chooseMode.setupUi(windowChooseMode);

    Ui_FormMenuChooseColor ui_chooseColor;
    QGraphicsView* windowChooseColor = new QGraphicsView();
    ui_chooseColor.setupUi(windowChooseColor);

    // Добавление окон в стековый виджет
    stackedWidget->addWidget(windowChooseMode);
    stackedWidget->addWidget(windowChooseColor);
    stackedWidget->addWidget(windowGame);
    

    // Установка начального окна для отображения
    stackedWidget->setCurrentWidget(windowChooseMode);
    stackedWidget->showMaximized();

    //Подключение кнопки "Далее" для переключения на следующее окно
    QObject::connect(windowChooseMode->findChild<QPushButton*>("btnPlayWithFriend"), &QPushButton::clicked, [stackedWidget](){
        stackedWidget->setCurrentIndex(stackedWidget->currentIndex() + 1);
    });


    QObject::connect(windowChooseColor->findChild<QPushButton*>("btnChooseRandomColor"), &QPushButton::clicked, [stackedWidget](){
        stackedWidget->setCurrentIndex(stackedWidget->currentIndex() + 1);
    });
    QObject::connect(windowChooseColor->findChild<QPushButton*>("btnChooseRandomColor"), &QPushButton::clicked, [stackedWidget](){
        stackedWidget->setCurrentIndex(stackedWidget->currentIndex() + 1);
    });
    QObject::connect(windowChooseColor->findChild<QPushButton*>("btnChooseBlackColor"), &QPushButton::clicked, [stackedWidget](){
        stackedWidget->setCurrentIndex(stackedWidget->currentIndex() + 1);
    });





    // QWidget windowEndGame;
    // Ui_FormEndGame ui_endGame;
    // ui_endGame.setupUi(&windowEndGame);
    // windowEndGame.show();


    return app.exec();
}