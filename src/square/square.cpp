#include "square.h"
#include "board.h"

#define shift 100

extern Board *board;

Square::Square(QGraphicsItem* parent)
: QGraphicsItem(parent){}

Square::Square(int column, int row, QGraphicsItem* parent) 
: QGraphicsItem(parent){
    _column = column;
    _row = row;
    Pressed = false;
}

void Square::setPiece(Piece* piece){
    _piece = piece;
    _image = _piece->_image; // seg here
}

void Square::deletePiece(){
    board->prevPressedSquare->_piece = new Piece();
    board->prevPressedSquare->_image = QPixmap();
}

void Square::setBackColor(int r, int g, int b){
    backgroundColor = QColor(r, g, b);
}
QRectF Square::boundingRect() const{
    return QRectF(100+shift*_column, 100+shift*_row, _w, _h);
}
void Square::paint(QPainter *painter, 
    const QStyleOptionGraphicsItem *option, 
    QWidget *widget){  
    if(Pressed){
        painter->setBrush(QColor(0, 174, 88));
        if(board->currentMoveColor == Color::white)
            _piece->setWhiteMoves(board->_scene);
        else if(board->currentMoveColor == Color::black)
            _piece->setBlackMoves(board->_scene);
    }
    else{
        painter->setBrush(backgroundColor);
    }
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
    drawImage(painter);
}

void Square::drawImage(QPainter *painter){
    if(!_image.isNull())
        painter->drawPixmap(boundingRect().toRect(), 
            _image.scaled(_w, _h, Qt::KeepAspectRatio));
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    if(turnMarker != nullptr){
        setPiece(board->prevPressedSquare->_piece);
        _piece->_row = _row;
        _piece->_column = _column;
        _piece->_firstMove = false;

        board->clearPrevPressedSquare();
        board->clearTurns();
        
        board->currentMoveColor = (board->currentMoveColor == Color::white)?
            Color::black : Color::white;

        Pressed = false;
        turnMarker = nullptr;
    }
    // Очищение ходов
    else if((Pressed) && board->isAnySquarePressed){
        board->clearTurns();
        Pressed = false;
    } 
    // Показ ходов
    else if(!Pressed && !_image.isNull() && _piece->_color == board->currentMoveColor) {
        if(board->isAnySquarePressed) board->clearTurns();
        board->isAnySquarePressed = true;
        Pressed = true;
        board->prevPressedSquare = this;
    }
    update();
    QGraphicsItem::mousePressEvent(event); // Возможно не надо
}



