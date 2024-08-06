#include <raylib.h>
#include "color.h"
#include "grid.h"
#include "block.h"
#include "game.h"

int main()
{
    InitWindow( GRID_WIDTH  + 2 * GRID_OFFEST_COL + GRID_LINE_WIDTH + UI_WIDTH, 
                GRID_LENGTH + 2 * GRID_OFFEST_ROW + GRID_LINE_WIDTH, 
                "Tetris");
    SetTargetFPS(60);
    Game game = Game();

    while(!WindowShouldClose()){
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.loop();
        EndDrawing();
    }

    CloseWindow();
    return 0;
}