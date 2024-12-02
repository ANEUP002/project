#ifndef _BOARD_
#define _BOARD_

#include "pieces.h"

#define BOARD_WIDTH 10
#define BOARD_HEIGHT 20
#define BLOCK_SIZE 30
#define BOARD_POSITION 320
#define BOARD_LINE_WIDTH 6

class Board {
public:
    Board(Pieces* pPieces, int pScreenHeight);

    void InitBoard();
    void StorePiece(int pX, int pY, int pPiece, int pRotation);
    void DeletePossibleLines();
    bool IsFreeBlock(int pX, int pY);
    bool IsPossibleMovement(int pX, int pY, int pPiece, int pRotation);
    bool IsGameOver();
    int GetXPosInPixels(int pPos);
    int GetYPosInPixels(int pPos);

private:
    enum { POS_FREE, POS_FILLED };
    int mBoard[BOARD_WIDTH][BOARD_HEIGHT];
    Pieces* mPieces;
    int mScreenHeight;

    void DeleteLine(int pY);
};

#endif // _BOARD_
