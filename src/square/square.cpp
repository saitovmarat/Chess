#include <unistd.h>

#include "square.h"
#include "board.h"
#include "fenProcessing.h"

#define shift 100

extern Board *board;
extern FEN* fen;
Square::Square(int column, int row, QGraphicsItem* parent) 
: QGraphicsItem(parent){
    this->column = column;
    this->row = row;
    isPressed = false;
    piece = nullptr;
    turnMarker = nullptr;
}

void Square::setPiece(Piece* newPiece) {
    if(piece){
        piece = nullptr;
        image = {};
    } 
    if(newPiece){
        newPiece->clearTurns();
        piece = newPiece;
        image = piece->image;
        piece->row = row;
        piece->column = column;
    } 
    update();
}

void Square::clearSquare(){
    piece = nullptr;
    image = {};
}

void Square::setBackColor(int r, int g, int b){
    backgroundColor = QColor(r, g, b);
    update();
}

QRectF Square::boundingRect() const{
    return QRectF(50+shift*column, 50+shift*row, w, h);
}

void Square::turnMarkerPressEvent(){
    Pawn *pawn = dynamic_cast<Pawn*>(board->prevPressedSquare->piece);
    if(pawn){
        fen->halfmoveClock = 0;
        if(abs(row - board->prevPressedSquare->row) == 2){
            fen->enPassantTargetSquare = this;
        }
        else fen->enPassantTargetSquare = nullptr;
    }
    else{
        fen->halfmoveClock++;
        fen->enPassantTargetSquare = nullptr;
    }
    setPiece(board->prevPressedSquare->piece);
    piece->firstMove = false;
    turnMarker = nullptr;
}

void Square::consumeTarget() {    
    setPiece(board->prevPressedSquare->piece);
    piece->firstMove = false;
    piece->isTarget = false;

    fen->halfmoveClock = 0;
    fen->enPassantTargetSquare = nullptr;
}

void Square::performCastling(){
    fen->halfmoveClock++;
    int rookDestColumn = (column == 7)? 5 : 3;
    int kingDestColumn = (column == 7)? 6 : 2;
    // rook
    board->squares[row][rookDestColumn]->setPiece(piece);
    board->squares[row][rookDestColumn]->piece->firstMove = false;
    clearSquare();
    // king
    board->squares[row][kingDestColumn]->setPiece(board->squares[row][4]->piece);
    board->squares[row][kingDestColumn]->piece->firstMove = false;
    board->squares[row][4]->clearSquare();
}


void Square::endTurn(){
    isPressed = false;
    board->prevPressedSquare->clearSquare();
    board->prevPressedSquare->update();

    if(board->currentMoveColor == Color::black) fen->fullmoveNumber++;
    
    if(board->isOpponentComputer){
        board->currentMoveColor = (board->currentMoveColor == Color::white)?
            Color::black : Color::white;
        if(board->currentMoveColor == Color::black) fen->fullmoveNumber++;
        std::pair<Coordinates, Coordinates> computerMove = board->getComputerMove(15);
        Coordinates fromSquareCords = computerMove.first;
        Coordinates toSquareCords = computerMove.second;
        
        std::cout << "Ход компьютера: \n";
        std::cout << fromSquareCords.row << fromSquareCords.column << " -> "  << toSquareCords.row << toSquareCords.column << "\n";
        
        Square* fromSquare = board->squares[fromSquareCords.row][fromSquareCords.column];
        Square* toSquare = board->squares[toSquareCords.row][toSquareCords.column];
        toSquare->setPiece(fromSquare->piece);
        if(fromSquare->piece) fromSquare->clearSquare();
        fromSquare->update();
        board->currentMoveColor = (board->currentMoveColor == Color::white)?
            Color::black : Color::white;

    }   
    else{
        board->currentMoveColor = (board->currentMoveColor == Color::white)?
            Color::black : Color::white;
    }
    //std::cout << fen->getCurrentFen().toStdString() << std::endl;
}


void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(!piece){
        // Нажатие на маркер хода
        if(turnMarker){
            turnMarkerPressEvent();
            endTurn();
        }
    }
    else{
        // Нажатие на ячейку с красным фоном
        if(piece->isTarget){
            consumeTarget();
            endTurn();
        }
        // Нажатие на ячейку с желтым фоном
        else if(piece->isCastlingAvailable){
            performCastling();
            endTurn();
        }
        // Нажатие на фигуру
        else if(!isPressed && !image.isNull() && piece->color == board->currentMoveColor) {
            if(board->prevPressedSquare) board->clearPrevPressedSquareTurns();
            isPressed = true;
            board->prevPressedSquare = this;
        }
        // Повторное нажатие на прошлую нажатую фигуру
        else if(isPressed && board->prevPressedSquare == this){
            board->clearPrevPressedSquareTurns();
        }
    }
    update();
}

void Square::paint(QPainter *painter, 
    const QStyleOptionGraphicsItem *option, 
    QWidget *widget)
{  
    QColor temp_backgroundColor = backgroundColor;
    if(piece){
        if(isPressed){
            temp_backgroundColor = QColor(0, 174, 88);
            piece->setMoves();
            piece->showMoves(board->scene);
        }
        else{
            if(piece->isTarget)
                temp_backgroundColor = QColor(155, 17, 30);
            else if(piece->isCastlingAvailable)
                temp_backgroundColor = QColor(255, 255, 58);
        }
    }
    painter->setBrush(temp_backgroundColor);
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
    drawImage(painter);
}

void Square::drawImage(QPainter *painter){
    if(!image.isNull())
        painter->drawPixmap(boundingRect().toRect(), 
            image.scaled(w, h, Qt::KeepAspectRatio));
}