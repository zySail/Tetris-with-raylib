#pragma once

#include "grid.h"
#include "block.h"
#include <raylib.h>
#include <random>
#include <vector>

class Game{
private:
    Grid gameGrid;
    Block currentBlock;
    Block nextBlock;
    std::vector<Block> blocks;
    double dropSpeed;
    int score;
    bool gameOverFlag;
public: 
    Game();
    void loop();
    Block getRandonBlock();
    bool isBlockOutside();
    bool isBlockCollision();
    void HandleInput();
    void moveBlockLeft();
    void moveBlockRight();
    void moveBlockDown();
    void rotateBlock();
    void setDropSpeed(double newSpeed);
    void dropBlock();
    void lockBlock();
};