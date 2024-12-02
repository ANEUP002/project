#include "game.h"

Game::Game(Board* pBoard, Pieces* pPieces, IO* pIO, int pScreenHeight)
    : mBoard(pBoard), mPieces(pPieces), mIO(pIO), mScreenHeight(pScreenHeight) {
    InitGame();
}

void Game::InitGame() {
    srand(static_cast<unsigned>(time(nullptr)));
    mPiece = GetRand(0, 6);
    mRotation = GetRand(0, 3);
    mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
    mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
}
void Game::CreateNewPiece() {
    // Assign the next piece to the current piece
    mPiece = mNextPiece;
    mRotation = mNextRotation;
    mPosX = (BOARD_WIDTH / 2) + mPieces->GetXInitialPosition(mPiece, mRotation);
    mPosY = mPieces->GetYInitialPosition(mPiece, mRotation);

    // Randomly generate the next piece
    mNextPiece = GetRand(0, 6);
    mNextRotation = GetRand(0, 3);
}

int Game::GetRand(int pA, int pB) {
    return rand() % (pB - pA + 1) + pA;
}


void Game::DrawBoard() {
    // Draw the board's stored blocks
    for (int i = 0; i < BOARD_WIDTH; i++) {
        for (int j = 0; j < BOARD_HEIGHT; j++) {
            if (!mBoard->IsFreeBlock(i, j)) {
                int x = mBoard->GetXPosInPixels(i);
                int y = mBoard->GetYPosInPixels(j);
                mIO->DrawRectangle(x, y, x + BLOCK_SIZE, y + BLOCK_SIZE, RED); // Example: RED color for stored blocks
            }
        }
    }
}

void Game::DrawPiece(int pX, int pY, int pPiece, int pRotation) {
    for (int i = 0; i < PIECE_BLOCKS; i++) {
        for (int j = 0; j < PIECE_BLOCKS; j++) {
            if (mPieces->GetBlockType(pPiece, pRotation, j, i) != 0) {
                int x = mBoard->GetXPosInPixels(pX + i);
                int y = mBoard->GetYPosInPixels(pY + j);
                mIO->DrawRectangle(x, y, x + BLOCK_SIZE, y + BLOCK_SIZE, GREEN); // Example: GREEN color for active pieces
            }
        }
    }
}

void Game::DrawScene() {
    mIO->ClearScreen();
    DrawBoard();
    DrawPiece(mPosX, mPosY, mPiece, mRotation); // Draw the current piece
    DrawPiece(mNextPosX, mNextPosY, mNextPiece, mNextRotation); // Draw the next piece preview
    mIO->UpdateScreen();
}
