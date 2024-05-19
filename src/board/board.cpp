#include "board.h"
#include "fenProcessing.h"

#include <QProcess>
#include <QDebug>

#define shift 100

FEN* fen;
Board::Board(QGraphicsScene* scene, Color bottomPlayerColor, bool isOpponentComputer){
    for(int row = 0; row < 8; row++){
        for(int column = 0; column < 8; column++){
            squares[row][column] = new Square(row, column);
        }
    }
    this->scene = scene;
    this->isOpponentComputer = isOpponentComputer;
    currentMoveColor = Color::white;
    this->bottomPlayerColor = bottomPlayerColor;
    prevPressedSquare = nullptr;
    fen = new FEN();
    
}

void Board::setUpBoard(){
    Color bottom_playerColor = bottomPlayerColor;
    Color top_playerColor = (bottom_playerColor == Color::white)? Color::black: Color::white; 
    for(int row = 0; row < 8; row++){
        for(int column = 0; column < 8; column++){
            Square* square = new Square(column, row);
            // Фигуры нижнего игрока 
            if(row == 6) 
                square->setPiece(new Pawn(row, column, bottom_playerColor));
            else if((column == 0 || column == 7) && (row == 7)) 
                square->setPiece(new Rook(row, column, bottom_playerColor));           
            else if((column == 1 || column == 6) && (row == 7)) 
                square->setPiece(new Knight(row, column, bottom_playerColor));            
            else if((column == 2 || column == 5) && (row == 7)) 
                square->setPiece(new Bishop(row, column, bottom_playerColor));            
            else if((column == 3) && (row == 7)) 
                square->setPiece(new Queen(row, column, bottom_playerColor));            
            else if((column == 4) && (row == 7)) 
                square->setPiece(new King(row, column, bottom_playerColor));
            // Фигуры верхнего игрока         
            else if(row == 1) 
                square->setPiece(new Pawn(row, column, top_playerColor));
            else if((column == 0 || column == 7) && (row == 0)) 
                square->setPiece(new Rook(row, column, top_playerColor));
            else if((column == 1 || column == 6) && (row == 0)) 
                square->setPiece(new Knight(row, column, top_playerColor));
            else if((column == 2 || column == 5) && (row == 0)) 
                square->setPiece(new Bishop(row, column, top_playerColor));
            else if((column == 3) && (row == 0)) 
                square->setPiece(new Queen(row, column, top_playerColor));
            else if((column == 4) && (row == 0)) 
                square->setPiece(new King(row, column, top_playerColor));
            // Цвет квадратиков
            if((row+column)%2 == 0){
                square->setBackColor(240, 217, 181);
            }
            else{
                square->setBackColor(138, 98, 74);
            }
            squares[row][column] = square;
        }
    }
}

void Board::clearPrevPressedSquareTurns(){
    prevPressedSquare->isPressed = false;
    if(prevPressedSquare->piece)
        prevPressedSquare->piece->clearTurns();
    prevPressedSquare->update();
}

bool Board::isCheck(){
    Coordinates king = getKing(currentMoveColor);
    if(king.row == -1 && king.column == -1){
        std::cout << "Как так?)\n";
        return false;
    }
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if(squares[row][col]->piece && squares[row][col]->piece->color != currentMoveColor){
                squares[row][col]->piece->setAllMoves();
                for(Coordinates move : squares[row][col]->piece->possibleMovesCoords){
                    if(move.row == king.row && move.column == king.column){
                        std::cout << "CHECK!\n";
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
Coordinates Board::getKing(Color color){
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* piece = squares[row][col]->piece;
            if (piece && piece->color == color){
                if(dynamic_cast<King*>(piece)) {
                    return Coordinates{row, col};
                }
            }
        }
    }
    return Coordinates{-1, -1};
}
bool Board::isPossibleMove(Square* fromSquare, Square* toSquare){
    bool result = true;
    Piece* temp_toSquarePiece = std::move(toSquare->piece);
    Piece* temp_fromSquarePiece = std::move(fromSquare->piece);

    toSquare->piece = new Pawn(toSquare->row, toSquare->column, fromSquare->piece->color);
    fromSquare->piece = nullptr;
    if(isCheck()) {
        result = false;
    }
    toSquare->piece = std::move(temp_toSquarePiece);
    fromSquare->piece = std::move(temp_fromSquarePiece);
    return result;
}


std::pair<Coordinates, Coordinates> getBestMove(QString processOutput) {
    std::pair<Coordinates, Coordinates> bestMove = std::make_pair(Coordinates{}, Coordinates{});
    QList<QString> list = processOutput.split(" ");
    for (int i = 0; i < list.size(); i++) {
        if (list[i] == "pv") {
            int columnFrom = fen->getColumnFromChar(QString(list[i + 1][0]));
            int rowFrom = 8 - QString(list[i + 1][1]).toInt();
            int columnTo = fen->getColumnFromChar(QString(list[i + 1][2]));
            int rowTo = 8 - QString(list[i + 1][3]).toInt();
            bestMove = std::make_pair(Coordinates{rowFrom, columnFrom}, Coordinates{rowTo, columnTo});
            break;
        }
    }
    return bestMove;
}


std::pair<Coordinates, Coordinates> Board::getComputerMove(int depth){
    QProcess process;
    QStringList arguments;
    process.start("stockfish", arguments);
    process.waitForStarted();
    QByteArray data = QByteArray("position fen ") + fen->getCurrentFen().toUtf8() + "\n";
    process.write(data);
    process.waitForBytesWritten();
    process.waitForReadyRead();
    QString output;
    for(int i = 0; i < depth; i++){
        process.write("go\n");
        process.waitForBytesWritten();
        process.waitForReadyRead();
        output = process.readAll();
    }
    process.terminate();
    process.waitForFinished(); 
    return getBestMove(output);
}

void Board::falsePressSquare(){
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            squares[row][col]->m_mousePressEventEnabled = false;
        }
    }
}
void Board::truePressSquare(){
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            squares[row][col]->m_mousePressEventEnabled = true;
        }
    }
    fen->updateFen();
}