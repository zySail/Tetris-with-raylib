#include "block.h"
#include <raylib.h>
#include "config.h"
#include "color.h"
#include "grid.h"

/* Block
-----------------------------------------------------------------------------------------*/
Block::Block(int id) : id(id){
    statusVal = 1;
}

void Block::addStatus(int key, std::vector<Position> pos){
    for(const Position& it : pos){
        status[key].push_back(it);
    }
}

void Block::changeStatus(){
    statusVal = (statusVal+1) % 4;
}

void Block::Draw(){
    for(Position it : status[statusVal]){ //ergodic every position
        DrawRectangle(  it.getCol()*GRID_CELL_SIZE + GRID_WIDTH, 
                        it.getRow()*GRID_CELL_SIZE + GRID_WIDTH, 
                        GRID_CELL_SIZE - GRID_WIDTH, 
                        GRID_CELL_SIZE - GRID_WIDTH, 
                        colorVertor[id] );
    }
}

void Block::setId(int new_id){
    id = new_id;
}

void Block::testDrawBlock(){
    for(int i = 0; i < 4; i++){
        changeStatus();
        Draw();
        WaitTime(2.0);
        setId(0);
        Draw();
    }
}

/* LBlock
-----------------------------------------------------------------------------------------*/
LBlock::LBlock() : Block(1){
    addStatus(0, {Position(0,2), Position(1,0), Position(1,1), Position(1,2)});
    addStatus(1, {Position(0,1), Position(1,1), Position(2,1), Position(2,2)});
    addStatus(2, {Position(1,0), Position(1,1), Position(1,2), Position(2,0)});
    addStatus(3, {Position(0,0), Position(0,1), Position(1,1), Position(2,1)});
}

/* IBlock
-----------------------------------------------------------------------------------------*/JBlock::JBlock() : Block(2){
    addStatus(0, {Position(0,0), Position(1,0), Position(1,1), Position(1,2)});
    addStatus(1, {Position(0,1), Position(0,2), Position(1,1), Position(2,1)});
    addStatus(2, {Position(1,0), Position(1,1), Position(1,2), Position(2,2)});
    addStatus(3, {Position(0,1), Position(1,1), Position(2,0), Position(2,1)});   
}

/* IBlock
-----------------------------------------------------------------------------------------*/
IBlock::IBlock() : Block(3){
    addStatus(0, {Position(1,0), Position(1,1), Position(1,2), Position(1,3)});
    addStatus(1, {Position(0,2), Position(1,2), Position(2,2), Position(3,2)});
    addStatus(2, {Position(2,0), Position(2,1), Position(2,2), Position(2,3)});
    addStatus(3, {Position(0,1), Position(1,1), Position(2,1), Position(3,1)}); 
}

/* OBlock
-----------------------------------------------------------------------------------------*/
OBlock::OBlock() : Block(4){
    addStatus(0, {Position(0,0), Position(0,1), Position(1,0), Position(1,1)});
}

/* SBlock
-----------------------------------------------------------------------------------------*/
SBlock::SBlock() : Block(5){
    addStatus(0, {Position(0,1), Position(0,2), Position(1,0), Position(1,1)});
    addStatus(1, {Position(0,1), Position(1,1), Position(1,2), Position(2,2)});
    addStatus(2, {Position(1,1), Position(1,2), Position(2,0), Position(2,1)});
    addStatus(3, {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}); 
}

/* TBlock
-----------------------------------------------------------------------------------------*/
TBlock::TBlock() : Block(6){
    addStatus(0, {Position(0,1), Position(1,0), Position(1,1), Position(1,2)});
    addStatus(1, {Position(0,1), Position(1,1), Position(1,2), Position(2,1)});
    addStatus(2, {Position(1,0), Position(1,1), Position(1,2), Position(2,1)});
    addStatus(3, {Position(0,1), Position(1,0), Position(1,1), Position(2,1)}); 
}

/* ZBlock
-----------------------------------------------------------------------------------------*/
ZBlock::ZBlock() : Block(7){
    addStatus(0, {Position(0,0), Position(0,1), Position(1,1), Position(1,2)});
    addStatus(1, {Position(0,2), Position(1,1), Position(1,2), Position(2,1)});
    addStatus(2, {Position(1,0), Position(1,1), Position(2,1), Position(2,2)});
    addStatus(3, {Position(0,1), Position(1,0), Position(1,1), Position(2,0)}); 
}

