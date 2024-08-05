#include <raylib.h>
#include "color.h"
#include "grid.h"
#include "block.h"
#include "game.h"

int main()
{
    InitWindow(500 + GRID_WIDTH, 1000 + GRID_WIDTH, "Tetris");
    SetTargetFPS(60);
    Game game = Game();
    //gameGrid.print();

    while(!WindowShouldClose()){
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.Draw();
        EndDrawing();
    }
    
    EndDrawing();

    CloseWindow();
    return 0;
}