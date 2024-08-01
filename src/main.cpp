#include <raylib.h>
#include "color.h"
#include "Grid.h"

int main()
{
    InitWindow(500, 1000, "Tetris");
    SetTargetFPS(60);

    Grid gameGrid = Grid();
    gameGrid.print();

    while(!WindowShouldClose()){
        BeginDrawing();
        ClearBackground(darkBlue);
        gameGrid.Draw();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}