#include "menuController.h"
#include "boardRenderer.h"

#include "formMainMenu.h"
#include "formMenuChooseColor.h"
#include "formEndGame.h"
#include "formChooseFigure.h"

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
    makeDesignForWindowChooseMode();

    // Ui_ChooseFigure  ui_chooseFigure;
    // ui_chooseFigure.setupUi(windowChooseMode);

    Ui_FormMenuChooseColor ui_chooseColor;
    windowChooseColor = new QGraphicsView();
    ui_chooseColor.setupUi(windowChooseColor);
    // ui_chooseColor.setupUi()
    makeDesignForWindowChooseColor();

    // Добавление окон в стековый виджет
    stackedWidget->addWidget(windowChooseMode);
    stackedWidget->addWidget(windowChooseColor);
    stackedWidget->addWidget(windowGame);
    

    // Установка начального окна для отображения
    stackedWidget->setCurrentWidget(windowChooseMode);
    stackedWidget->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowTitleHint | Qt::WindowCloseButtonHint | Qt::WindowMinimizeButtonHint);
    stackedWidget->showMaximized();
    QObject::connect(windowChooseMode->findChild<QPushButton*>("btnPlayWithFriend"), &QPushButton::clicked, [&](){slots btn_OpenGameWithFriend_PressEvent();});
    QObject::connect(windowChooseMode->findChild<QPushButton*>("btnPlayWithComputer"), &QPushButton::clicked, [&](){slots btn_OpenGameWithComputer_PressEvent();});
    QObject::connect(windowChooseColor->findChild<QPushButton*>("btnChooseBlackColor"), &QPushButton::clicked, [&](){slots btn_BlackPieceColor_PressEvent();});
    QObject::connect(windowChooseColor->findChild<QPushButton*>("btnChooseWhiteColor"), &QPushButton::clicked, [&](){slots btn_WhitePieceColor_PressEvent();});
    QObject::connect(windowChooseColor->findChild<QPushButton*>("btnChooseRandomColor"), &QPushButton::clicked, [&](){slots btn_RandomPieceColor_PressEvent();});
}

void MenuController::btn_OpenGameWithFriend_PressEvent(){
    isOpponentComputer = false;
    stackedWidget->setCurrentWidget(windowChooseColor);
}
void MenuController::btn_OpenGameWithComputer_PressEvent(){
    isOpponentComputer = true;
    makeGameWindow(Color::white);
    stackedWidget->setCurrentWidget(windowGame);
}
void MenuController::makeGameWindow(Color color){
    QGraphicsScene* scene = new QGraphicsScene();
    scene->setBackgroundBrush(QBrush(QColor(55, 189, 128)));
    board = new Board(scene, color, isOpponentComputer);
    board->setUpBoard();
    BoardRenderer::render(board, scene);
    windowGame->setScene(scene);
}
void MenuController::btn_WhitePieceColor_PressEvent(){
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
void MenuController::makeDesignForWindowChooseMode(){
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsRectItem* rectLeft = new QGraphicsRectItem(0, 0, 600, 500);
    rectLeft->setBrush(QBrush(QColor(189,236,182)));
    scene->addItem(rectLeft);
    windowChooseMode->setScene(scene);
}
void MenuController::makeDesignForWindowChooseColor(){
    QGraphicsScene* scene = new QGraphicsScene();
    QGraphicsRectItem* rectLeft = new QGraphicsRectItem(0, 0, 600, 500);
    rectLeft->setBrush(QBrush(QColor(189,236,182)));
    scene->addItem(rectLeft);
    windowChooseColor->setScene(scene);
}
void MenuController::someoneWon(Color color){
    
}

void MenuController::сhangePawn(Color color, int row, int column){
    this->color = color;
    this->row = row;
    this->column = column;
    stackedWidget->setCurrentWidget(windowChooseColor);
    Ui_ChooseFigure ui_chooseFigure;
    ui_chooseFigure.setupUi(windowGame, color);
    stackedWidget->setCurrentWidget(windowGame);
        
    QObject::connect(windowGame->findChild<QPushButton*>("btnChooseBishop"), &QPushButton::clicked, [&](){slots btn_ChooseBishop_PressEvent();});
    QObject::connect(windowGame->findChild<QPushButton*>("btnChooseRook"), &QPushButton::clicked, [&](){slots btn_ChooseRook_PressEvent();});
    QObject::connect(windowGame->findChild<QPushButton*>("btnChooseKnight"), &QPushButton::clicked, [&](){slots btn_ChooseKnight_PressEvent();});
    QObject::connect(windowGame->findChild<QPushButton*>("btnChooseQueen"), &QPushButton::clicked, [&](){slots btn_ChooseQueen_PressEvent();});
    board->lockAllPieces();
}
void MenuController::btn_ChooseBishop_PressEvent(){
    board->squares[row][column]->setPiece(new Bishop(row, column, color));
    board->unlockAllPieces();
    deleteButtons();
}

void MenuController::btn_ChooseRook_PressEvent(){
    board->squares[row][column]->setPiece(new Rook(row, column, color));
    board->unlockAllPieces();
    deleteButtons();
}
void MenuController::btn_ChooseKnight_PressEvent(){
    board->squares[row][column]->setPiece(new Knight(row, column, color));
    board->unlockAllPieces();
    deleteButtons();
}
void MenuController::btn_ChooseQueen_PressEvent(){
    board->squares[row][column]->setPiece(new Queen(row, column, color));
    board->unlockAllPieces();
    deleteButtons();
}
void MenuController::deleteButtons(){
    delete windowGame->findChild<QPushButton*>("btnChooseBishop");
    delete windowGame->findChild<QPushButton*>("btnChooseRook");
    delete windowGame->findChild<QPushButton*>("btnChooseKnight");
    delete windowGame->findChild<QPushButton*>("btnChooseQueen");
}