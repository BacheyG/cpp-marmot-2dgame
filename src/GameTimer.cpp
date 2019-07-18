#include "GameTimer.h"
#include <cstdio>
//statikus valtozok
float GameTimer::deltaTime = 0;
float GameTimer::elapsedTime = 0;
float GameTimer::FPS = 0;

GameTimer::GameTimer()
{
    startTimeStamp = clock();
}

float GameTimer::getDeltaTime(){
    if (deltaTime > MormotaConstants::BIG_NUMBER || deltaTime < -MormotaConstants::BIG_NUMBER)
        return 0;
    return deltaTime;
}

float GameTimer::getElapsedTime(){
    return elapsedTime;
}

float GameTimer::getFPS(){
    return FPS;
}

float GameTimer::getTimeStamp(){
    return (float)clock() / CLOCKS_PER_SEC;
}

void GameTimer::UpdateValues(){
    GameTimer::deltaTime = (float)(clock() - prevTimeStamp) / CLOCKS_PER_SEC;
    GameTimer::elapsedTime = (float)(clock() - startTimeStamp) / CLOCKS_PER_SEC;
    GameTimer::FPS = CLOCKS_PER_SEC / (float)(clock() - prevTimeStamp);
    //printf("FPS: %f\n", FPS);
    prevTimeStamp = clock();
}

