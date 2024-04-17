#include "menuController.h"
#include "boardRenderer.h"

#include "formMainMenu.h"
#include "formMenuChooseColor.h"
#include "formEndGame.h"

extern Board* board;
MenuController::MenuController(){
    start();
}

void MenuController::start(){
    windowGame = new QGraphicsView();
    // Создание стекового виджета
    stackedWidget = new QStackedWidget;

    Ui_FormMenuChooseMode ui_chooseMode;
    windowChooseMode = new QGraphicsView();
    ui_chooseMode.setupUi(windowChooseMode);

    Ui_FormMenuChooseColor ui_chooseColor;
    windowChooseColor = new QGraphicsView();
    ui_chooseColor.setupUi(windowChooseColor);

    // Добавление окон в стековый виджет
    stackedWidget->addWidget(windowChooseMode);
    stackedWidget->addWidget(windowChooseColor);
    stackedWidget->addWidget(windowGame);

    // Установка начального окна для отображения
    stackedWidget->setCurrentWidget(windowChooseMode);
    stackedWidget->showMaximized();

    QObject::connect(windowChooseMode->findChild<QPushButton*>("btnPlayWithFriend"), &QPushButton::clicked, [&](){slots btn_OpenGameWithFriend_PressEvent();});

    QObject::connect(windowChooseColor->findChild<QPushButton*>("btnChooseBlackColor"), &QPushButton::clicked, [&](){slots btn_BlackPieceColor_PressEvent();});
    QObject::connect(windowChooseColor->findChild<QPushButton*>("btnChooseWhiteColor"), &QPushButton::clicked, [&](){slots btn_WhitePieceColor_PressEvent();});
    QObject::connect(windowChooseColor->findChild<QPushButton*>("btnChooseRandomColor"), &QPushButton::clicked, [&](){slots btn_RandomPieceColor_PressEvent();});
}
void MenuController::btn_OpenGameWithFriend_PressEvent(){
    stackedWidget->setCurrentWidget(windowChooseColor);
}
void MenuController::makeGameWindow(Color color){
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor("lightblue")));
    board = new Board(scene, color);
    board->setUpBoard();
    board->outputFen();
    BoardRenderer::render(board, scene);
    windowGame->setScene(scene);
}
void MenuController::btn_WhitePieceColor_PressEvent()
{
    makeGameWindow(Color::white);
    stackedWidget->setCurrentWidget(windowGame);
}

void MenuController::btn_RandomPieceColor_PressEvent(){
    int randomNum = QRandomGenerator::global()->bounded(2);
    makeGameWindow(Color(randomNum));
    stackedWidget->setCurrentWidget(windowGame);
}
void MenuController::btn_BlackPieceColor_PressEvent(){
    makeGameWindow(Color::black);
    stackedWidget->setCurrentWidget(windowGame);
}
void MenuController::someoneWon(Color color){
    
}
