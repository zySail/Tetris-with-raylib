#include <array>
#include <vector>
#include <raylib.h>

#define GRID_ROW_SIZE    20
#define GRID_COL_SIZE    10
#define GRID_CELL_SIZE   50
#define GRID_WIDTH       1

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
};