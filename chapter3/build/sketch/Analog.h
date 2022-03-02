#line 1 "/Users/qbae/Workspace/Arduino/chapter3/analog/ex03/Analog.h"
#ifndef ANALOG_H
#define ANALOG_H

#pragma once
#include <Arduino.h>

class Analog
{
protected:
    int pin;
    int to_min;
    int to_max;
    int from_min;
    int from_max;

public:
    Analog(int pin, int to_min = 0, int to_max = 255);
    void setRange(int to_min, int to_max);
    int read();

private:
};

#endif