#include "computerOpponent.h"
#include "fenProcessing.h"

extern FEN* fen;

void ComputerOpponent::makeMove(Board* board){
    if(board->currentMoveColor == Color::black) fen->fullmoveNumber++;
    std::pair<Coordinates, Coordinates> computerMove = board->getComputerMove(15);
    Coordinates fromSquareCords = computerMove.first;
    Coordinates toSquareCords = computerMove.second;
    
    std::cout << "Ход компьютера: \n";
    std::cout << fromSquareCords.row << fromSquareCords.column << " -> "  << toSquareCords.row << toSquareCords.column << "\n";
    
    Square* fromSquare = board->squares[fromSquareCords.row][fromSquareCords.column];
    Square* toSquare = board->squares[toSquareCords.row][toSquareCords.column];
    if(fromSquare->piece){
        if(dynamic_cast<Pawn*>(fromSquare->piece)){
            if(abs(toSquareCords.row - fromSquareCords.row) == 2){
                fen->enPassantTargetSquare = toSquare;
            }
            else fen->enPassantTargetSquare = nullptr;
        }
        else fen->enPassantTargetSquare = nullptr;
    }
    toSquare->setPiece(fromSquare->piece);
    if(fromSquare->piece) fromSquare->clearPieceInSquare();
    fromSquare->update();
    board->currentMoveColor = (board->currentMoveColor == Color::white)?
        Color::black : Color::white;
}