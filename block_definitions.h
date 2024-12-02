#ifndef BLOCK_DEFINITIONS_H
#define BLOCK_DEFINITIONS_H

#include "block.h"

// IBlock Definition
class IBlock : public Block {
public:
    IBlock() {
        id = 3;  // Unique ID for IBlock
        cells[0] = {Position(0, 1), Position(0, 2), Position(0, 3), Position(0, 4)};
        cells[1] = {Position(0, 2), Position(1, 2), Position(2, 2), Position(3, 2)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(1, 3)};
        cells[3] = {Position(0, 1), Position(1, 1), Position(2, 1), Position(3, 1)};
        Move(-1, 3);  // Initial position offset
    }
};

// JBlock Definition
class JBlock : public Block {
public:
    JBlock() {
        id = 2;  // Unique ID for JBlock
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        Move(0, 3);
    }
};

// Other blocks (LBlock, OBlock, SBlock, TBlock, ZBlock)
class LBlock : public Block {
public:
    LBlock() {
        id = 4;  // Unique ID for LBlock
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(1, 2)};
        cells[1] = {Position(0, 1), Position(0, 2), Position(1, 1), Position(2, 1)};
        cells[2] = {Position(1, 0), Position(1, 1), Position(1, 2), Position(2, 2)};
        cells[3] = {Position(0, 1), Position(1, 0), Position(1, 1), Position(2, 1)};
        Move(0, 3);
    }
};

class OBlock : public Block {
public:
    OBlock() {
        id = 5;  // Unique ID for OBlock
        cells[0] = {Position(0, 0), Position(1, 0), Position(0, 1), Position(1, 1)};
        cells[1] = cells[0];  // Same shape for all rotations
        cells[2] = cells[0];
        cells[3] = cells[0];
        Move(0, 4);
    }
};

class SBlock : public Block {
public:
    SBlock() {
        id = 6;  // Unique ID for SBlock
        cells[0] = {Position(1, 0), Position(2, 0), Position(0, 1), Position(1, 1)};
        cells[1] = {Position(0, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        cells[2] = cells[0];
        cells[3] = cells[1];
        Move(0, 3);
    }
};

class TBlock : public Block {
public:
    TBlock() {
        id = 7;  // Unique ID for TBlock
        cells[0] = {Position(1, 0), Position(0, 1), Position(1, 1), Position(2, 1)};
        cells[1] = {Position(0, 0), Position(0, 1), Position(0, 2), Position(1, 1)};
        cells[2] = {Position(0, 0), Position(1, 0), Position(2, 0), Position(1, 1)};
        cells[3] = {Position(1, 0), Position(0, 1), Position(1, 1), Position(1, 2)};
        Move(0, 3);
    }
};

class ZBlock : public Block {
public:
    ZBlock() {
        id = 8;  // Unique ID for ZBlock
        cells[0] = {Position(0, 0), Position(1, 0), Position(1, 1), Position(2, 1)};
        cells[1] = {Position(1, 0), Position(0, 1), Position(1, 1), Position(0, 2)};
        cells[2] = cells[0];
        cells[3] = cells[1];
        Move(0, 3);
    }
};

#endif // BLOCK_DEFINITIONS_H
