#include "Player.h"

const float PLAYER_HEIGHT = 150;
const float PLAYER_WIDTH = 150;

const float START_SCROLLING_BORDER = 250;
const float RUNNING_LIMIT = 30;

Player::Player() : PhysicsEnabled{PLAYER_HEIGHT}
{
    sprite = std::make_shared<SpriteRenderer>("resources/player.png", sf::Vector2f(PLAYER_WIDTH, PLAYER_HEIGHT));
    AddComponent(sprite);
    collider = std::make_shared<BoxCollider>(false, false, sf::Vector2f(0.3f, 0.9f));
    AddComponent(collider);
    GetTransform().SetOrigin(75, 75);
    GetTransform().SetPosition(200, 500 - PLAYER_HEIGHT / 2);
    PlayerSingleton::getInstance().player = this;
}

//ugras&eses
bool isOffGround = false;
float groundLevel = 500;
float airTimer;
float verticalVelocity = 0;


void Player::setWalkTexture(){
    if (GameTimer::getElapsedTime() - walkTimer > MormotaConstants::WALK_ANIM_FREQUENCY){
        walkAnimID++;
        if (walkAnimID > 2) walkAnimID = 0;
        walkTimer = GameTimer::getElapsedTime();
    }
    switch (walkAnimID){
        case 0:     sprite.get()->setTexture("resources/player_walk1.png"); break;
        case 1:     sprite.get()->setTexture("resources/player.png"); break;
        case 2:     sprite.get()->setTexture("resources/player_walk2.png"); break;
        default:    printf("ERROR! Bad anim index.");
    }

}

void Player::Update()
{
    PhysicsEnabled::Update();
    if (!isHurt){
    if (GetTransform().GetPosition().y < collider.get()->getTopLimit() + PLAYER_HEIGHT / 2 + MormotaConstants::EPSILON && isOffGround){
        verticalVelocity = (float)(-fabs(verticalVelocity));
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && !isOffGround)
    {
        isOffGround = true;
        airTimer = GameTimer::getTimeStamp();
        verticalVelocity = MormotaConstants::JUMP_FORCE;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && collider.get()->getLeftLimit() < GetTransform().GetPosition().x - RUNNING_LIMIT)
    {
        GetTransform().Translate(-MormotaConstants::RUN_SPEED * GameTimer::getDeltaTime(), 0);
        GetTransform().SetScale(-0.5f, 0.5f);
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && collider.get()->getRightLimit() > GetTransform().GetPosition().x - RUNNING_LIMIT)
    {
        GetTransform().Translate(MormotaConstants::RUN_SPEED * GameTimer::getDeltaTime(), 0);
        GetTransform().SetScale(0.5f, 0.5f);
    }
    if (collider.get()->IsHitEnemy()){
        isHurt = true;
        collider.get()->SetStatic(true);
        collider.get()->SetBottomLimit(MormotaConstants::BIG_NUMBER);
    }
    //Anim
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        sprite.get()->setTexture("resources/player_walk1.png");
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        setWalkTexture();
    else
        sprite.get()->setTexture("resources/player.png");
    }

    //scroll jobbra
    if (GetTransform().GetPosition().x > window->getView().getCenter().x + MormotaConstants::WINDOW_WIDTH / 2 - START_SCROLLING_BORDER)
    {
        sf::View view = window->getView();
        view.move(GetTransform().GetPosition().x - (window->getView().getCenter().x + MormotaConstants::WINDOW_WIDTH  / 2 - START_SCROLLING_BORDER), 0);
        window->setView(view);
    }
    //scroll balra
    if (GetTransform().GetPosition().x < window->getView().getCenter().x - MormotaConstants::WINDOW_WIDTH  / 2 + START_SCROLLING_BORDER)
    {
        sf::View view = window->getView();
        view.move(GetTransform().GetPosition().x - (window->getView().getCenter().x - MormotaConstants::WINDOW_WIDTH  / 2 + START_SCROLLING_BORDER), 0);
        window->setView(view);
    }
}

float Player::getScreenOffset() const{
    return screenOffset;
}

bool Player::IsGameOver() const{
    return isHurt;
}
