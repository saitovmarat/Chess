#include "fenProcessing.h"
#include "board.h"

extern Board* board;
FEN::FEN(){
    _fen = "";
    whiteCanCastleKingside = false;
    whiteCanCastleQueenside = false;
    blackCanCastleKingside = false;
    blackCanCastleQueenside = false;
    enPassantTargetSquare = nullptr;

    halfmoveClock = 0;
    fullmoveNumber = 1;
}

QString FEN::getCurrentFen(){
    updateFen();
    return _fen;
}


void FEN::updateFen(){
    std::string fen;
    for(int i = 0; i < 8; i++){
        int emptyCount = 0;
        for(int j = 0; j < 8; j++){
            if(!board->squares[i][j]->piece){
                emptyCount++;
            }
            else{
                if(emptyCount > 0){
                    fen += std::to_string(emptyCount);
                    emptyCount = 0;
                }
                fen += getFenPieceSymbol(board->squares[i][j]->piece,
                                        board->squares[i][j]->piece->color);   
            }
        }
        if(emptyCount > 0){
            fen += std::to_string(emptyCount);
        }
        fen += '/';
    }
    fen.pop_back();
    fen += ' ';

    char currentTurnColor_symb = board->currentMoveColor;
    //(board->currentMoveColor == Color::white)? 'b' : 'w';
    fen += currentTurnColor_symb;

    // Add castling rights
    updatePossibilitiesToCastle();
    std::string castlingRights;
    if (whiteCanCastleKingside) castlingRights += "K";
    if (whiteCanCastleQueenside) castlingRights += "Q";
    if (blackCanCastleKingside) castlingRights += "k";
    if (blackCanCastleQueenside) castlingRights += "q";
    if (castlingRights.empty()) castlingRights = "-";
    fen += " " + castlingRights;

    // Add en passant target square
    fen += " " + (enPassantTargetSquare ? getSquareName(enPassantTargetSquare) : "-");

    // Add halfmove clock and fullmove number
    fen += " " + std::to_string(halfmoveClock) + " " + std::to_string(fullmoveNumber);

    _fen = QString::fromStdString(fen);
    
    std::cout << fen << "\n";
}

void FEN::updatePossibilitiesToCastle(){
    King* bottomKing = dynamic_cast<King*>(board->squares[7][4]->piece);
    King* topKing = dynamic_cast<King*>(board->squares[0][4]->piece);
    Rook* bottomLeftRook = dynamic_cast<Rook*>(board->squares[7][0]->piece);
    Rook* bottomRightRook = dynamic_cast<Rook*>(board->squares[7][7]->piece);
    Rook* topLeftRook = dynamic_cast<Rook*>(board->squares[0][0]->piece);
    Rook* topRightRook = dynamic_cast<Rook*>(board->squares[0][7]->piece);
    
    bool topPlayerCanShortCastle = false;
    bool topPlayerCanLongCastle = false;
    bool bottomPlayerCanShortCastle = false;
    bool bottomPlayerCanLongCastle = false;

    if(bottomKing && bottomRightRook 
    && bottomKing->firstMove && bottomRightRook->firstMove
    && !board->squares[7][5]->piece && !board->squares[7][6]->piece)
        bottomPlayerCanShortCastle = true;

    if(topKing && topRightRook 
    && !board->squares[0][5]->piece && !board->squares[0][6]->piece)
        topPlayerCanShortCastle = true;

    if(bottomKing && bottomLeftRook 
    && !board->squares[7][1]->piece && !board->squares[7][2]->piece && !board->squares[7][3]->piece)
        bottomPlayerCanLongCastle = true;

    if(topKing && topLeftRook 
    && !board->squares[0][1]->piece && !board->squares[0][2]->piece && !board->squares[0][3]->piece)
        topPlayerCanLongCastle = true;

    whiteCanCastleKingside = (board->bottomPlayerColor == Color::white)? bottomPlayerCanShortCastle : topPlayerCanShortCastle; 
    whiteCanCastleQueenside = (board->bottomPlayerColor == Color::white)? bottomPlayerCanLongCastle : topPlayerCanLongCastle;
    blackCanCastleKingside = (board->bottomPlayerColor == Color::black)? bottomPlayerCanShortCastle : topPlayerCanShortCastle;
    blackCanCastleQueenside = (board->bottomPlayerColor == Color::black)? bottomPlayerCanLongCastle : topPlayerCanLongCastle;
}

char FEN::getFenPieceSymbol(Piece* piece, Color pieceColor){
    char pieceSymb;
    if(dynamic_cast<Bishop*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'B' : 'b';
    else if(dynamic_cast<King*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'K' : 'k';
    else if(dynamic_cast<Knight*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'N' : 'n';
    else if(dynamic_cast<Pawn*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'P' : 'p';
    else if(dynamic_cast<Queen*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'Q' : 'q';
    else if(dynamic_cast<Rook*>(piece))
        pieceSymb = (pieceColor == Color::white)? 'R' : 'r';

    return pieceSymb;
}

int FEN::getColumnFromChar(QString str){
    if (str == "a") return 0;
    else if (str == "b") return 1;
    else if (str == "c") return 2;
    else if (str == "d") return 3;
    else if (str == "e") return 4;
    else if (str == "f") return 5;
    else if (str == "g") return 6;
    else if (str == "h") return 7;
    else return -1; // Return an error value if the input is not valid
}
std::string FEN::getColumnFromNum(int num){
    if (num == 0) return "a";
    else if (num == 1) return "b";
    else if (num == 2) return "c";
    else if (num == 3) return "d";
    else if (num == 4) return "e";
    else if (num == 5) return "f";
    else if (num == 6) return "g";
    else if (num == 7) return "h";
    else return ""; // Return an error value if the input is not valid
}
std::string FEN::getSquareName(Square* square){
    std::string row = std::to_string(8 - square->row);
    std::string column = getColumnFromNum(square->column);
    return column + row;
}
