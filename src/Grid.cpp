#include "Grid.h"
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
            //DrawRectangleLines(x, y, cellSize, cellSize, WHITE);
            DrawRectangle(x + GRID_WIDTH, y + GRID_WIDTH, cellSize - GRID_WIDTH, cellSize - GRID_WIDTH, gridColor[cellValue]);
        }
    }     
}