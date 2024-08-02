#include <raylib.h>
#include "color.h"
#include "grid.h"
#include "block.h"

int main()
{
    InitWindow(500 + GRID_WIDTH, 1000 + GRID_WIDTH, "Tetris");
    SetTargetFPS(60);

    Grid gameGrid = Grid();
    gameGrid.print();
    LBlock L1 = LBlock();

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(darkBlue);
        gameGrid.Draw();
        //L1.Draw();
        L1.testDrawBlock();
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}