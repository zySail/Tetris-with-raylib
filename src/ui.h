#pragma once
#include <raylib.h>
#include "block.h"

extern Font font;

void loadFont();
void DrawUI(int score, Block nextBlock);
void DrawGameOver();

float calculateMidX(float width);
void DrawText(const char *text, int fontSize, int fontSpace, float y);
void DrawBoxBackground(float width, float height, float y);
void DrawScore(int score, int fontSize, int fontSpace, float y);
void DrawNextBlock(Block block);


