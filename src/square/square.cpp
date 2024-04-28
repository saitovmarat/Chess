#include "square.h"
#include "board.h"

#define shift 100

extern Board *board;

Square::Square(int column, int row, QGraphicsItem* parent) 
: QGraphicsItem(parent){
    this->column = column;
    this->row = row;
    isPressed = false;
    piece = nullptr;
    turnMarker = nullptr;
}

void Square::setPiece(Piece* newPiece) {
    if(piece) piece = nullptr;
    newPiece->clearTurns();
    piece = newPiece;
    image = piece->image;
    piece->row = row;
    piece->column = column;
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
    setPiece(board->prevPressedSquare->piece);
    piece->firstMove = false;
    turnMarker = nullptr;
}

void Square::consumeTarget() {    
    setPiece(board->prevPressedSquare->piece);
    piece->firstMove = false;
    piece->isTarget = false;
}

void Square::performCastling(){
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

    board->currentMoveColor = (board->currentMoveColor == Color::white)?
        Color::black : Color::white;
    board->outputFen();
    //if(board->isCheck()) std::cout << "CHECK" << std::endl;
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