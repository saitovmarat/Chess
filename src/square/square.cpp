#include "square.h"
#include "board.h"

#define shift 100

extern Board *board;

Square::Square(int column, int row, QGraphicsItem* parent) 
: QGraphicsItem(parent){
    this->column = column;
    this->row = row;
    isPressed = false;
}

void Square::setPiece(Piece* newPiece){
    piece = newPiece;
    image = newPiece->image;
    piece->row = row;
    piece->column = column;
}

void Square::clearSquare(){
    setPiece(new Piece());
}

void Square::setBackColor(int r, int g, int b){
    backgroundColor = QColor(r, g, b);
    update();
}

QRectF Square::boundingRect() const{
    return QRectF(50+shift*column, 50+shift*row, w, h);
}

void Square::turnMarkerPressEvent(){
    Piece* prevPressedPiece = board->prevPressedSquare->piece;
    setPiece(prevPressedPiece);
    piece->firstMove = false;
    turnMarker = nullptr;
}

void Square::consumeTarget() {
    Piece* prevPressedPiece = board->prevPressedSquare->piece;
    setPiece(prevPressedPiece);
    piece->firstMove = false;
    piece->isTarget = false;
}

void Square::performCastling(){
    const int rookColumn = (column == 7) ? 5 : 3;
    const int kingDestColumn = (column == 7) ? 6 : 2;
    const int kingSourceColumn = 4;

    Square* rookSquare = board->squares[row][rookColumn];
    Square* kingSquare = board->squares[row][kingDestColumn];
    Piece* rook = rookSquare->piece;
    Piece* king = board->squares[row][kingSourceColumn]->piece;
    
    rookSquare->setPiece(piece);
    rook->column = rookColumn;
    rook->firstMove = false;
    clearSquare();

    kingSquare->setPiece(king);
    king->column = kingDestColumn;
    king->firstMove = false;
    board->squares[row][kingSourceColumn]->clearSquare();
}


void Square::endTurn(){
    isPressed = false;

    board->prevPressedSquare->clearSquare();
    board->clearTurns();
    
    board->currentMoveColor = (board->currentMoveColor == Color::white)?
        Color::black : Color::white;
    board->outputFen();
}


void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Нажатие на маркер хода
    if(turnMarker){
        turnMarkerPressEvent();
        endTurn();
    }
    // Нажатие на ячейку с красным фоном
    else if(piece->isTarget){
        consumeTarget();
        endTurn();
    }
    // Нажатие на ячейку с желтым фоном
    else if(piece->castlingAvailable){
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
    update();
}

void Square::paint(QPainter *painter, 
    const QStyleOptionGraphicsItem *option, 
    QWidget *widget)
{  
    QColor temp_backgroundColor;
    if(isPressed){
        temp_backgroundColor = QColor(0, 174, 88);
        piece->setMoves();
        piece->showMoves(board->scene);
    }
    else{
        if(piece->isTarget)
            temp_backgroundColor = QColor(155, 17, 30);
        else if(piece->castlingAvailable)
            temp_backgroundColor = QColor(255, 255, 58);
        else
            temp_backgroundColor = backgroundColor;
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