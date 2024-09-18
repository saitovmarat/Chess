#include "main.h"
#include "board.h"

class FEN{
public:
    FEN();
    void updateFen();
    QString getCurrentFen();

    int getColumnFromChar(QString str);
    std::string getColumnFromNum(int num);
    char getFenPieceSymbol(Piece* piece, Color pieceColor);

    void updatePossibilitiesToCastle();
    std::string getSquareName(Square* square);
    
    Square* enPassantTargetSquare;
    bool whiteCanCastleKingside;
    bool whiteCanCastleQueenside;
    bool blackCanCastleKingside;
    bool blackCanCastleQueenside;

    int halfmoveClock;
    int fullmoveNumber;

private:
    QString _fen;
};