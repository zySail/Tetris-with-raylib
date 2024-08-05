#pragma once

#include "grid.h"
#include "block.h"
#include <raylib.h>
#include <random>
#include <vector>

class Game{
private:
    Grid gameGrid;
    Block currenBlock;
    Block nextBlock;
    std::vector<Block> blocks;
    double dropSpeed;
public: 
    Game();
    void Draw();
    Block getRandonBlock();
    bool isBlockOutside();
    void HandleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
    void rotateBlock();
    void setDropSpeed(double newSpeed);
};