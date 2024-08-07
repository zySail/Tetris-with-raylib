#include "ui.h"
#include "config.h"
#include "color.h"
#include "game.h"
#include <string>


Font font;
void loadFont(){
    font = LoadFontEx("Font/PressStart2P-Regular.ttf",40,0,0);
}


void DrawUI(int score, Block nextBlock){
    DrawText("Score", 40, 2, 60);
    DrawBoxBackground(280, 100, 120);
    DrawScore(score, 35, 1, 153);
    DrawText("Next", 40, 5, 340);
    DrawBoxBackground(280, 280, 400);
    DrawText("Press R", 30, 1, 920);
    DrawText("Restart", 30, 1, 970);
    DrawNextBlock(nextBlock);
}

void DrawGameOver(){
    DrawText("Game", 45, 5, 740);
    DrawText("Over", 45, 5, 810);
}

float calculateMidX(float width){
    float sideSpace = (UI_WIDTH - width) / 2;
    return GRID_WIDTH  + GRID_OFFEST_COL + sideSpace;
}

/* Str
-----------------------------------------------------------------------------------------*/
void DrawText(const char *text, int fontSize, int fontSpace, float y){
    float fontLength = MeasureTextEx(font, text, fontSize, fontSpace).x;
    float x = calculateMidX(fontLength);
    DrawTextEx(font, text, {x,y}, fontSize, fontSpace, WHITE);

}

/* boxBackground
-----------------------------------------------------------------------------------------*/
void DrawBoxBackground(float width, float height, float y){
    float x = calculateMidX(width);
    DrawRectangleRounded({x, y, width, height}, 0.3, 6, lightBlue);
}

/* Score
-----------------------------------------------------------------------------------------*/
void DrawScore(int score, int fontSize, int fontSpace, float y){
    std::string str = std::to_string(score);
    const char *text = str.c_str();
    DrawText(text, fontSize, fontSpace, y);
}

/* NextBlock
-----------------------------------------------------------------------------------------*/
void DrawNextBlock(Block block){
    float x = 0;
    float y = 400 + 80;
    switch (block.getId())
    {
    case 3: // I-Block
        x = calculateMidX(4 * GRID_CELL_SIZE);
        y = 400 + 70;
        break;
    case 4:// O-Block
        x = calculateMidX(2 * GRID_CELL_SIZE);
        break;
    default:
        x = calculateMidX(3 * GRID_CELL_SIZE);
        break;
    }
    block.Draw(x, y); 
}