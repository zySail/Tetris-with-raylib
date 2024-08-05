#include "time.h"
#include <raylib.h>

double lastTime = 0.0;
double currentTime = 0.0;

bool eventTriggered(double interval){
    currentTime = GetTime();
    if(currentTime - lastTime >= interval){
        lastTime = currentTime;
        return true;
    }
    return false;
}