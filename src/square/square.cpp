#include "square.h"
#include "board.h"

#define shift 100

extern Board *board;

Square::Square(int column, int row, QGraphicsItem* parent) 
: QGraphicsItem(parent){
    _column = column;
    _row = row;
    Pressed = false;
}

void Square::setPiece(Piece* piece){
    _piece = piece;
    _image = _piece->_image;
}

void Square::setBackColor(int r, int g, int b){
    backgroundColor = QColor(r, g, b);
    update();
}
void Square::setBackColor(QColor color){
    backgroundColor = color;
    update();
}
QRectF Square::boundingRect() const{
    return QRectF(50+shift*_column, 50+shift*_row, _w, _h);
}

void Square::endTurn(){
    Pressed = false;
    board->clearPrevPressedSquare();
    board->clearTurns();
    board->currentMoveColor = (board->currentMoveColor == Color::white)?
        Color::black : Color::white;
}

void Square::turnMarker_pressEvent(){
    setPiece(board->prevPressedSquare->_piece);
    _piece->_row = _row;
    _piece->_column = _column;
    _piece->_firstMove = false;
    turnMarker = nullptr;
    endTurn();
}

void Square::eatingTarget_pressEvent(){
    setPiece(board->prevPressedSquare->_piece);
    _piece->_row = _row;
    _piece->_column = _column;
    _piece->_firstMove = false;
    _piece->isTarget = false;
    endTurn();
}

void Square::castling_pressEvent(){
    //short castling
    if(_column == 7){
        // rook
        board->squares[_row][5]->setPiece(_piece);
        board->squares[_row][5]->_piece->_column = 5;
        board->squares[_row][5]->_piece->_firstMove = false;
        setPiece(new Piece());

        // king
        board->squares[_row][6]->setPiece(board->squares[_row][4]->_piece);
        board->squares[_row][6]->_piece->_column = 6;
        board->squares[_row][6]->_piece->_firstMove = false;
        board->squares[_row][4]->setPiece(new Piece());
    }
    // long castling
    else if(_column == 0){
        // rook
        board->squares[_row][3]->setPiece(_piece);
        board->squares[_row][3]->_piece->_column = 3;
        board->squares[_row][3]->_piece->_firstMove = false;
        setPiece(new Piece());

        // king
        board->squares[_row][2]->setPiece(board->squares[_row][4]->_piece);
        board->squares[_row][2]->_piece->_column = 2;
        board->squares[_row][2]->_piece->_firstMove = false;
        board->squares[_row][4]->setPiece(new Piece());
    }

    endTurn();
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Нажатие на маркер хода
    if(turnMarker != nullptr){
        turnMarker_pressEvent();
    }
    // Нажатие на ячейку с красным фоном
    else if(_piece->isTarget){
        eatingTarget_pressEvent();
    }
    // Нажатие на ячейку с желтым фоном
    else if(_piece->castlingAvailable){
        castling_pressEvent();
    }
    // Нажатие на фигуру
    else if(!Pressed && !_image.isNull() && _piece->_color == board->currentMoveColor) {
        if(board->isAnySquarePressed) board->clearTurns();
        board->isAnySquarePressed = true;
        Pressed = true;
        board->prevPressedSquare = this;
    }
    // Повторное нажатие на прошлую нажатую фигуру
    else if(Pressed && board->isAnySquarePressed){
        board->clearTurns();
        Pressed = false;
    } 
    update();
    QGraphicsItem::mousePressEvent(event); // Возможно не надо
}

void Square::paint(QPainter *painter, 
    const QStyleOptionGraphicsItem *option, 
    QWidget *widget){  
        
    if(Pressed){
        painter->setBrush(QColor(0, 174, 88));
        _piece->setMoves(board->_scene);
    }
    else{
        if(_piece->isTarget)
            painter->setBrush(QColor(155, 17, 30));
        else if(_piece->castlingAvailable)
            painter->setBrush(QColor(255, 255, 58));
        else
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