#include <raylib.h>
#include "color.h"
#include "grid.h"
#include "block.h"
#include "game.h"

int main()
{
    InitWindow( GRID_WIDTH  + GRID_OFFEST_COL  + UI_WIDTH, 
                GRID_LENGTH + 2 * GRID_OFFEST_ROW , 
                "Tetris");
    SetTargetFPS(60);
    Game game = Game();

    while(!WindowShouldClose()){
        game.HandleInput();
        BeginDrawing();
        ClearBackground(darkBlue);
        game.loop();

        //DrawTextEx(font, "hello", (Vector2){550,100}, 70, 0, WHITE);

        EndDrawing();
    }

    CloseWindow();
    return 0;
}