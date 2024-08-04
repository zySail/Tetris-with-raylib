#include <raylib.h>
#include "color.h"
#include "grid.h"
#include "block.h"
#include <thread>
#include <chrono>

int main()
{
    InitWindow(500 + GRID_WIDTH, 1000 + GRID_WIDTH, "Tetris");
    SetTargetFPS(1);

    Grid gameGrid = Grid();
    gameGrid.print();

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(darkBlue);
        gameGrid.Draw();
        EndDrawing();
    }
    
    EndDrawing();

    
    CloseWindow();
    return 0;
}