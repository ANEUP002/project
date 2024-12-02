#include "game.h"

#ifdef _WIN32
#include <windows.h>
#endif

#include <SDL2/SDL.h> // Include SDL2 headers for both platforms

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
#else
int main(int argc, char* argv[]) {
#endif
    IO mIO;
    int mScreenHeight = mIO.GetScreenHeight();

    Pieces mPieces;
    Board mBoard(&mPieces, mScreenHeight);
    Game mGame(&mBoard, &mPieces, &mIO, mScreenHeight);

    unsigned long mTime1 = SDL_GetTicks();

    while (!mIO.IsKeyDown(SDLK_ESCAPE)) {
        mIO.ClearScreen();
        mGame.DrawScene();
        mIO.UpdateScreen();

        int mKey = mIO.Pollkey();

        switch (mKey) {
        case (SDLK_RIGHT):
            if (mBoard.IsPossibleMovement(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation)) {
                mGame.mPosX++;
            }
            break;

        case (SDLK_LEFT):
            if (mBoard.IsPossibleMovement(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation)) {
                mGame.mPosX--;
            }
            break;

        case (SDLK_DOWN):
            if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation)) {
                mGame.mPosY++;
            }
            break;

        case (SDLK_x):
            while (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) {
                mGame.mPosY++;
            }
            mBoard.StorePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);
            mBoard.DeletePossibleLines();
            if (mBoard.IsGameOver()) {
                exit(0);
            }
            mGame.CreateNewPiece();
            break;
        }

        unsigned long mTime2 = SDL_GetTicks();
        if ((mTime2 - mTime1) > WAIT_TIME) {
            if (mBoard.IsPossibleMovement(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation)) {
                mGame.mPosY++;
            } else {
                mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);
                mBoard.DeletePossibleLines();
                if (mBoard.IsGameOver()) {
                    exit(0);
                }
                mGame.CreateNewPiece();
            }
            mTime1 = SDL_GetTicks();
        }
    }

    return 0;
}
