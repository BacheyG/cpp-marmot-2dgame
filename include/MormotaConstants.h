#ifndef MORMOTACONSTANTS_H
#define MORMOTACONSTANTS_H


class MormotaConstants
{
    public:
    static const int WINDOW_WIDTH = 800;
    static const int WINDOW_HEIGHT = 600;
    static constexpr float EPSILON = 0.001f;
    static constexpr float BIG_NUMBER = 9999999.0f;
    static constexpr float GRAVITY = 9.81f;
    //Player
    static constexpr float JUMP_FORCE = 10;
    static constexpr float WALK_ANIM_FREQUENCY = 0.1f;
    static constexpr float RUN_SPEED = 350;
    //Shooter
    static constexpr float PROJECTILE_VELOCITY = 500.0f;
    static constexpr float FIRE_RATE = 2.0f;
};

#endif // MORMOTACONSTANTS_H
