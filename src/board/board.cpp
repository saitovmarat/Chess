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
    Square* kingSquare = getKing(currentMoveColor);
    if(!kingSquare) {
        std::cout << "Как так?)\n";
        return false;
    }
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if(squares[row][col]->piece && squares[row][col]->piece->color != currentMoveColor){
                squares[row][col]->piece->setMoves();
                for(Coordinates move : squares[row][col]->piece->possibleMovesCoords){
                    if(move.row == kingSquare->row && move.column == kingSquare->column){
                        std::cout << "CHECK!\n";
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
Square* Board::getKing(Color color){
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            Piece* piece = squares[row][col]->piece;
            if (piece && piece->color == color && dynamic_cast<King*>(piece)) {
                Square* kingSquare = squares[row][col];
                return squares[row][col];
            }
        }
    }
    return nullptr;
}
bool Board::isPossibleMove(Square* fromSquare, Square* toSquare){
    bool result = true;
    // Piece* temp = std::move(toSquare->piece);
    // toSquare->piece = new Pawn(0, 0, fromSquare->piece->color);
    if(isCheck()) {
        result = false;
    }
    // toSquare->piece = nullptr;
    // toSquare->piece = std::move(temp);
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
    // Вывод fen
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
