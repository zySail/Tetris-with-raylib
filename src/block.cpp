#include "block.h"
#include <raylib.h>
#include "config.h"
#include "color.h"
#include "grid.h"
#include <iostream>

/* Block
-----------------------------------------------------------------------------------------*/
Block::Block(){
    id = 0;
    statusVal = 0;
    offest.setPosition(0,4);
}

void Block::addStatus(int key, std::vector<Position> pos){
    for(const Position& it : pos){
        status[key].push_back(it);
    }
}

int Block::getId(){
    return id;
}

void Block::setId(int new_id){
    id = new_id;
}

void Block::rotate(){
    statusVal = (statusVal + 1) % 4;
}

void Block::undoRotate(){
    statusVal = (statusVal + 3) % 4;
}

std::vector<Position> Block::getCellPosition(){
    std::vector<Position> cellPosition = status[statusVal];
    for(Position& cellPos : cellPosition){
        cellPos.add(offest.getRow(), offest.getCol()); //add offest to cell position
    }
    return cellPosition;
}

void Block::Draw(){
    for(const Position& cellPos : getCellPosition()){ 
        //ergodic current status's every block's position then draw the cell
        DrawRectangle(  cellPos.getCol()*GRID_CELL_SIZE + GRID_WIDTH, 
                        cellPos.getRow()*GRID_CELL_SIZE + GRID_WIDTH, 
                        GRID_CELL_SIZE - GRID_WIDTH, 
                        GRID_CELL_SIZE - GRID_WIDTH, 
                        colorVector[id] );
    }
}

void Block::move(int rowOffest, int colOffest){
    offest.add(rowOffest, colOffest);
}


/* LBlock
-----------------------------------------------------------------------------------------*/
LBlock::LBlock() : Block(){
    setId(1);
    addStatus(0, {Position(0,2), Position(1,0), Position(1,1), Position(1,2)});
    addStatus(1, {Position(0,1), Position(1,1), Position(2,1), Position(2,2)});
    addStatus(2, {Position(1,0), Position(1,1), Position(1,2), Position(2,0)});
    addStatus(3, {Position(0,0), Position(0,1), Position(1,1), Position(2,1)});
}

/* IBlock
-----------------------------------------------------------------------------------------*/JBlock::JBlock() : Block(){
    setId(2);
    addStatus(0, {Position(0,0), Position(1,0), Position(1,1), Position(1,2)});
    addStatus(1, {Position(0,1), Position(0,2), Position(1,1), Position(2,1)});
    addStatus(2, {Position(1,0), Position(1,1), Position(1,2), Position(2,2)});
    addStatus(3, {Position(0,1), Position(1,1), Position(2,0), Position(2,1)});   
}

/* IBlock
-----------------------------------------------------------------------------------------*/
IBlock::IBlock() : Block(){
    setId(3);
    addStatus(0, {Position(1,0), Position(1,1), Position(1,2), Position(1,3)});
    addStatus(1, {Position(0,2), Position(1,2), Position(2,2), Position(3,2)});
    addStatus(2, {Position(2,0), Position(2,1), Position(2,2), Position(2,3)});
    addStatus(3, {Position(0,1), Position(1,1), Position(2,1), Position(3,1)}); 
}

/* OBlock
-----------------------------------------------------------------------------------------*/
OBlock::OBlock() : Block(){
    setId(4);
    addStatus(0, {Position(0,0), Position(0,1), Position(1,0), Position(1,1)});
    addStatus(1, {Position(0,0), Position(0,1), Position(1,0), Position(1,1)});
    addStatus(2, {Position(0,0), Position(0,1), Position(1,0), Position(1,1)});
    addStatus(3, {Position(0,0), Position(0,1), Position(1,0), Position(1,1)});
}

/* SBlock
-----------------------------------------------------------------------------------------*/
SBlock::SBlock() : Block(){
    setId(5);
    addStatus(0, {Position(0,1), Position(0,2), Position(1,0), Position(1,1)});
    addStatus(1, {Position(0,1), Position(1,1), Position(1,2), Position(2,2)});
    addStatus(2, {Position(1,1), Position(1,2), Position(2,0), Position(2,1)});
    addStatus(3, {Position(0,0), Position(1,0), Position(1,1), Position(2,1)}); 
}

/* TBlock
-----------------------------------------------------------------------------------------*/
TBlock::TBlock() : Block(){
    setId(6);
    addStatus(0, {Position(0,1), Position(1,0), Position(1,1), Position(1,2)});
    addStatus(1, {Position(0,1), Position(1,1), Position(1,2), Position(2,1)});
    addStatus(2, {Position(1,0), Position(1,1), Position(1,2), Position(2,1)});
    addStatus(3, {Position(0,1), Position(1,0), Position(1,1), Position(2,1)}); 
}

/* ZBlock
-----------------------------------------------------------------------------------------*/
ZBlock::ZBlock() : Block(){
    setId(7);
    addStatus(0, {Position(0,0), Position(0,1), Position(1,1), Position(1,2)});
    addStatus(1, {Position(0,2), Position(1,1), Position(1,2), Position(2,1)});
    addStatus(2, {Position(1,0), Position(1,1), Position(2,1), Position(2,2)});
    addStatus(3, {Position(0,1), Position(1,0), Position(1,1), Position(2,0)}); 
}

