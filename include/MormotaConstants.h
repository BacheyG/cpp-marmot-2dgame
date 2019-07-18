#ifndef MORMOTACONSTANTS_H
#define MORMOTACONSTANTS_H


class MormotaConstants
{
    public:
    static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 600;
    static constexpr float epsilon = 0.001f;
    static constexpr float BIG_NUMBER = 9999999.0f;
    static constexpr float Gravity = 9.81f;
    //Player
    static constexpr float jumpForce = 10;
    static constexpr float walkAnimFreq = 0.1f;
    static constexpr float RUN_SPEED = 350;
    //Shooter
    static constexpr float projectileVelocity = 500.0f;
    static constexpr float timeBetweenFire = 2.0f;
};

#endif // MORMOTACONSTANTS_H
