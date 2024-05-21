#include <random>
#include <QRandomGenerator>
#include "main.h"
#include "board.h"
class MenuController{
public:
    MenuController();
    void someoneWon(Color color);
    QGraphicsView* windowGame;
    void сhangePawn(Color color, int row, int column);
    void deleteButtons();
private:
    void makeGameWindow(Color color);
    void start();
    void makeDesignForWindowChooseMode();
    void makeDesignForWindowChooseColor();
    QStackedWidget *stackedWidget;
    // QGraphicsView* windowGameWithFriend;
    // QGraphicsView* windowGameWithComputer;
    QGraphicsView* windowChooseMode;
    QGraphicsView* windowChooseColor;
    int row;
    int column;
    Color color;
    bool isOpponentComputer;


private slots:
    void btn_OpenGameWithFriend_PressEvent(); 
    void btn_OpenGameWithComputer_PressEvent();
    void btn_WhitePieceColor_PressEvent();
    void btn_BlackPieceColor_PressEvent();
    void btn_RandomPieceColor_PressEvent();
    void btn_ChooseBishop_PressEvent();
    void btn_ChooseRook_PressEvent();
    void btn_ChooseKnight_PressEvent();
    void btn_ChooseQueen_PressEvent();
    
};