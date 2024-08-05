#include "grid.h"
#include <iostream>
#include "color.h"

Grid::Grid() :  numRows(GRID_ROW_SIZE), 
                numCols(GRID_COL_SIZE), 
                cellSize(GRID_CELL_SIZE )
{
    Initialize();
    gridColor = {BLACK, green, red, orange, yellow, purple, cyan, blue};
}

void Grid::Initialize(){
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            grid[i][j] = 0;
        }
    }
}

void Grid::print(){
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }    
}

void Grid::Draw(){
    for(int i = 0; i < numRows; i++){
        for(int j = 0; j < numCols; j++){
            int cellValue = grid[i][j];
            int x = j * cellSize;
            int y = i * cellSize;
            DrawRectangle(x + GRID_WIDTH, y + GRID_WIDTH, cellSize - GRID_WIDTH, cellSize - GRID_WIDTH, gridColor[cellValue]);
        }
    }     
}

void Grid::Draw(int x, int y){
    DrawRectangle(  x*GRID_CELL_SIZE + GRID_WIDTH, 
                    y*GRID_CELL_SIZE + GRID_WIDTH, 
                    cellSize - GRID_WIDTH, 
                    cellSize - GRID_WIDTH, gridColor[1]);
}

bool Grid::isCellOutside(int row, int col){
    if(row >= 0 && row < numRows && col >= 0 && col < GRID_COL_SIZE){
        return false;
    }
    return true;
}

bool Grid::isCellOccupied(int row, int col){
    if(grid[row][col] != 0){
        return true;
    }
    return false;
}

bool Grid::isRowFull(int row){
    for(int j = 0; j < numCols; j++){
        if(grid[row][j] == 0){
            return false;
        }
    }
    return true;
}

void Grid::clearRow(int row){
    for(int j = 0; j < numCols; j++){
            grid[row][j] = 0;
    }   
}

void Grid::moveRowDown(int row, int layer){
    int newRow = row + layer;
    for(int j = 0; j < numCols; j++){
        grid[newRow][j] = grid[row][j];
    }
    clearRow(row);
}

int Grid::clearFullRow(){
    int completed = 0;
    for(int i = numRows - 1; i >= 0; i--){
        if(isRowFull(i)){
            clearRow(i);
            completed++;
        }
        else if(completed > 0){
            moveRowDown(i , completed);
        }
    }
    return completed;
}