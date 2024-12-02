#ifndef _GAME_
#define _GAME_

#include "board.h"
#include "pieces.h"
#include "IO.h"
#include <time.h>

#define WAIT_TIME 700

class Game {
public:
    Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight);

    void InitGame();
    void DrawScene(); // Ensure this is declared
    void CreateNewPiece();

    int mPosX, mPosY;
    int mPiece, mRotation;

private:
    int mScreenHeight;
    int mNextPosX, mNextPosY;
    int mNextPiece, mNextRotation;

    Board* mBoard;
    Pieces* mPieces;
    IO* mIO;

    int GetRand(int pA, int pB);
    void DrawPiece(int pX, int pY, int pPiece, int pRotation);
    void DrawBoard();
};

#endif // _GAME_
