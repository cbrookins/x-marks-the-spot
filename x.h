#ifndef X_H
#define X_H

#include <Watchy.h>
#include "x_img.h"

class X : public Watchy{
    public:
        X();
        void drawWatchFace();
        void drawTime();
        void drawWDay();
        void drawDate();
        void drawSteps();
        void drawTemperature();
        void drawBattery();
};

#endif
