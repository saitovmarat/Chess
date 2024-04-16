#include <random>
#include <QRandomGenerator>
#include "main.h"
#include "board.h"
class MenuController{
public:
    MenuController();
    void someoneWon(Color color);
private:
    void makeGameWindow(Color color);
    void start();
    QStackedWidget *stackedWidget;
    QGraphicsView* windowGame;
    QGraphicsView* windowChooseMode;
    QGraphicsView* windowChooseColor;

private slots:
    void btn_OpenGameWithFriend_PressEvent(); 
    void btn_WhitePieceColor_PressEvent();
    void btn_BlackPieceColor_PressEvent();
    void btn_RandomPieceColor_PressEvent();
};