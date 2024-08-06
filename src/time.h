//if need to use more than one Trigger, it should be defined as a class
//in this case, this is only used to drop block, so, yeah I'm lazy

#pragma once

extern double lastTime;
extern double currentTime;

bool eventTriggered(double interval);