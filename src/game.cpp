#include "game.h"
#include "time.h"

static int count = 0;
static int picked[7] = {0};

Game::Game(){
    gameGrid = Grid();
    blocks = {LBlock() , JBlock(), IBlock(), OBlock(), SBlock(), TBlock(), ZBlock()};
    currenBlock = getRandonBlock();
    nextBlock = getRandonBlock();
    dropSpeed = 0.2;
}

void Game::Draw(){
    gameGrid.Draw();
    currenBlock.Draw();
    if(eventTriggered(0.5)){
        moveBlockDown();
    }
}

void Game::setDropSpeed(double newSpeed){
    dropSpeed = newSpeed;
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
        break;
    case KEY_UP:
        rotateBlock();
        break;
    default:
        break;
    }
}

bool Game::isBlockOutside(){
    for(Position cellPos : currenBlock.getCellPosition()){
        if(gameGrid.isCellOutside(cellPos.getRow(), cellPos.getCol())){
            return true; // Block has cell outside
        }
    }
    return false;
}

void Game::moveBlockLeft(){
    currenBlock.move(0,-1);
    if(isBlockOutside()){
        currenBlock.move(0,1);
    }
}

void Game::moveBlockRight(){
    currenBlock.move(0,1);
    if(isBlockOutside()){
        currenBlock.move(0,-1);
    }
}

void Game::moveBlockDown(){
    currenBlock.move(1,0);
    if(isBlockOutside()){
        currenBlock.move(-1,0);
    }
}

void Game::rotateBlock(){
    currenBlock.rotate();
    if(isBlockOutside()){
        currenBlock.undoRotate();
    }
}