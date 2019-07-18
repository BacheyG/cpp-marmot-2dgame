#ifndef GAMETIMER_H
#define GAMETIMER_H
#include <ctime>
#include "MormotaConstants.h"

class GameTimer
{
    public:
        void UpdateValues();
        GameTimer();
        static float getDeltaTime();
        static float getElapsedTime();
        static float getFPS();
        static float getTimeStamp();
    private:
        float startTimeStamp;
        float prevTimeStamp;
        static float deltaTime;
        static float elapsedTime;
        static float FPS;
};

#endif // GAMETIMER_H
