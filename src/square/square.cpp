#include "square.h"
#include "board.h"

#define shift 100

extern Board *board;

Square::Square(int column, int row, QGraphicsItem* parent) 
: QGraphicsItem(parent){
    this->column = column;
    this->row = row;
    Pressed = false;
}

void Square::setPiece(Piece* piece){
    this->piece = piece;
    this->image = piece->image;
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

void Square::turnMarker_pressEvent(){
    setPiece(board->prevPressedSquare->piece);
    piece->row = row;
    piece->column = column;
    piece->firstMove = false;
    turnMarker = nullptr;
}

void Square::eatingTarget_pressEvent(){
    setPiece(board->prevPressedSquare->piece);
    piece->row = row;
    piece->column = column;
    piece->firstMove = false;
    piece->isTarget = false;
}

void Square::castling_pressEvent(){
    //short castling
    if(column == 7){
        // rook
        board->squares[row][5]->setPiece(piece);
        board->squares[row][5]->piece->column = 5;
        board->squares[row][5]->piece->firstMove = false;
        clearSquare();

        // king
        board->squares[row][6]->setPiece(board->squares[row][4]->piece);
        board->squares[row][6]->piece->column = 6;
        board->squares[row][6]->piece->firstMove = false;
        board->squares[row][4]->clearSquare();
    }
    // long castling
    else if(column == 0){
        // rook
        board->squares[row][3]->setPiece(piece);
        board->squares[row][3]->piece->column = 3;
        board->squares[row][3]->piece->firstMove = false;
        clearSquare();

        // king
        board->squares[row][2]->setPiece(board->squares[row][4]->piece);
        board->squares[row][2]->piece->column = 2;
        board->squares[row][2]->piece->firstMove = false;
        board->squares[row][4]->clearSquare();
    }
}

void Square::endTurn(){
    Pressed = false;
    if(checkExist()){
        blockPieces();
    }
    board->clearTurns();
    board->clearPrevPressedSquare();
    board->currentMoveColor = (board->currentMoveColor == Color::white)?
        Color::black : Color::white;
}

bool Square::checkExist(){
    // Отрисовка всех ходов
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(board->squares[i][j]->piece->color == board->currentMoveColor){
                board->squares[i][j]->piece->setMoves(board->scene);
            }
        }
    }
    // Поиск Короля
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(dynamic_cast<King*>(board->squares[i][j]->piece) 
            && board->squares[i][j]->piece->color != board->currentMoveColor
            && board->squares[i][j]->piece->isTarget){
                return true;
            }
        }
    }
    return false;
}

void Square::blockPieces(){
    std::cout << "CHECK!\n";
}

void Square::mousePressEvent(QGraphicsSceneMouseEvent *event){
    // Нажатие на маркер хода
    if(turnMarker != nullptr){
        turnMarker_pressEvent();
        endTurn();
    }
    // Нажатие на ячейку с красным фоном
    else if(piece->isTarget){
        eatingTarget_pressEvent();
        endTurn();
    }
    // Нажатие на ячейку с желтым фоном
    else if(piece->castlingAvailable){
        castling_pressEvent();
        endTurn();
    }
    // Нажатие на фигуру
    else if(!Pressed && !image.isNull() && piece->color == board->currentMoveColor) {
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
        piece->setMoves(board->scene);
    }
    else{
        if(piece->isTarget)
            painter->setBrush(QColor(155, 17, 30));
        else if(piece->castlingAvailable)
            painter->setBrush(QColor(255, 255, 58));
        else
            painter->setBrush(backgroundColor);
    }
    painter->setPen(Qt::NoPen);
    painter->drawRect(boundingRect());
    drawImage(painter);
}

void Square::drawImage(QPainter *painter){
    if(!image.isNull())
        painter->drawPixmap(boundingRect().toRect(), 
            image.scaled(w, h, Qt::KeepAspectRatio));
}