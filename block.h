#ifndef BLOCK_H
#define BLOCK_H

#include <array>  // For using std::array

struct Position {
    int x, y;
    Position(int px = 0, int py = 0) : x(px), y(py) {}
};

class Block {
public:
    int id;  // Unique identifier for the block
    std::array<std::array<Position, 4>, 4> cells;  // 4 rotation states, each with 4 positions

    Block() : id(0) {}

    // Move all cells of the block by (dx, dy)
    void Move(int dx, int dy) {
        for (auto& rotation : cells) {
            for (auto& cell : rotation) {
                cell.x += dx;
                cell.y += dy;
            }
        }
    }
};

#endif // BLOCK_H
