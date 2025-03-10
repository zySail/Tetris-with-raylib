#pragma once

#include <array>
#include <vector>
#include <raylib.h>
#include "config.h"


class Grid{
private:
    int numRows;
    int numCols;
    int cellSize;
    std::vector<Color> gridColor;

public:
    std::array<std::array<int, GRID_COL_SIZE>, GRID_ROW_SIZE> grid;
    Grid();
    void Initialize();
    void print();
    void Draw();
    void Draw(int x, int y);
    bool isCellOutside(int row, int col);
    bool isCellOccupied(int row , int col);
    bool isRowFull(int row);
    void clearRow(int row);
    void moveRowDown(int row, int layer);
    int clearFullRow();
};