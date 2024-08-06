#include "game.h"
#include "time.h"
#include <iostream>

static int count = 0;
static int picked[7] = {0};

Game::Game(){
    gameGrid = Grid();
    blocks = getBlocks();
    currentBlock = getRandonBlock();
    nextBlock = getRandonBlock();
    dropSpeed = 0.1;
    gameOverFlag = false;
    score = 0;
}

void Game::loop(){
    gameGrid.Draw();
    currentBlock.Draw();
    dropBlock();
}

std::vector<Block> Game::getBlocks(){
    return {LBlock() , JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
}

void Game::setDropSpeed(double newSpeed){
    dropSpeed = newSpeed;
}

void Game::dropBlock(){
    if(eventTriggered(dropSpeed)){
        moveBlockDown();
    }
}

Block Game::getRandonBlock(){
    int index;
    do{
        index = rand() % blocks.size();
    } while(picked[index] != 0);
    Block block = blocks[index]; //all blocks must be picked in a loop
    // pick block
    picked[index] = 1; 
    count++;
    // check if all blocks are picked
    if(count == 7){ 
        count = 0;
        for(int i = 0; i < 7; i++) picked[i] = 0;
    }
    return block;
}

void Game::HandleInput(){
    int keyPressed = GetKeyPressed();
    switch (keyPressed)
    {
    case KEY_LEFT:
        moveBlockLeft();
        break;
    case KEY_RIGHT:
        moveBlockRight();
        break;
    case KEY_DOWN:
        moveBlockDown();
        calculateScore(0,1);
        break;
    case KEY_UP:
        rotateBlock();
        break;
    case KEY_R:
        reset();
    default:
        break;
    }
}

bool Game::isBlockOutside(){
    for(const Position& cellPos : currentBlock.getCellPosition()){
        if(gameGrid.isCellOutside(cellPos.getRow(), cellPos.getCol())){
            return true; // Block has cell outside
        }
    }
    return false;
}

void Game::moveBlockLeft(){
    if(!gameOverFlag){
        currentBlock.move(0,-1);
        if(isBlockOutside() || isBlockCollision()){
            currentBlock.move(0,1);
        }
    }
}

void Game::moveBlockRight(){
    if(!gameOverFlag){
        currentBlock.move(0,1);
        if(isBlockOutside() || isBlockCollision()){
            currentBlock.move(0,-1);
        }
    }
}

void Game::moveBlockDown(){
    if(!gameOverFlag){
        currentBlock.move(1,0);
        if(isBlockOutside() || isBlockCollision()){
            currentBlock.move(-1,0);
            lockBlock();
        }
    }
}

void Game::rotateBlock(){
    if(!gameOverFlag){
        currentBlock.rotate();
        if(isBlockOutside() || isBlockCollision()){
            currentBlock.undoRotate();
        }
    }
}

void Game::lockBlock(){
    for(const Position& cellPos : currentBlock.getCellPosition()){
        gameGrid.grid[cellPos.getRow()][cellPos.getCol()] = currentBlock.getId();
    }
    int linesCleared = gameGrid.clearFullRow();
    calculateScore(linesCleared, 0);
    currentBlock = nextBlock;
    nextBlock = getRandonBlock();
    if(isBlockCollision()){
        gameOverFlag = true;
    }
}

bool Game::isBlockCollision(){
    for(const Position& cellPos : currentBlock.getCellPosition()){
        if(gameGrid.isCellOccupied(cellPos.getRow(), cellPos.getCol())){
            return true;
        }
    }
    return false; 
}

void Game::reset(){
    gameGrid.Initialize();
    blocks = getBlocks();
    currentBlock = getRandonBlock();
    nextBlock = getRandonBlock();
    score = 0;
}

void Game::calculateScore(int linesCleared, int moveDownPoints){
    switch (linesCleared)
    {
    case 1:
        score += 100;
        break;
    case 2:
        score += 300;
        break;
    case 3:
        score += 500;
        break;
    default:
        break;
    }
    score += moveDownPoints;
    return;
}