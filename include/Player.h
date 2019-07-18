#ifndef PLAYER_H
#define PLAYER_H
#include "PhysicsEnabled.h"
#include "GameObject.h"
#include "SpriteRenderer.h"
#include "GameTimer.h"
#include "BoxCollider.h"
#include "MormotaConstants.h"
#include "PlayerSingleton.h"

class Player : public PhysicsEnabled
{
    public:
        Player();
        void Update() override;
        float getScreenOffset() const;
        bool IsGameOver() const;
    private:
        float screenOffset = 0;
        bool isHurt = false;
        std::shared_ptr<SpriteRenderer> sprite;
        void setWalkTexture();
        float walkTimer = 0;
        int walkAnimID = 0;
};

#endif // PLAYER_H
