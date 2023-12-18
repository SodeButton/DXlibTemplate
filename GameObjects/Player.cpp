//
// Created by button on 2023/12/16.
//

#include "Player.hpp"
#include "../Game.hpp"
#include "../Components/SpriteComponent.hpp"
#include "../Components/CircleColliderComponent.hpp"
#include "../Scenes/Scene.hpp"

Player::Player(Game* game)
        : GameObject(game),
          mRightMove(0.0f),
          mDownMove(0.0f) {
    auto* sprite = new SpriteComponent(this);
    sprite->SetTexture(LoadGraph("../Assets/Circle.png"));

    mCollider = new CircleColliderComponent(this);
    mCollider->SetRadius(32.0f * GetScale().Max());
}

void Player::UpdateGameObject(float deltaTime) {
    GameObject::UpdateGameObject(deltaTime);

    Vector2 pos = GetPosition();
    pos.x += mRightMove * deltaTime;
    pos.y += mDownMove * deltaTime;
    SetPosition(pos);

    if (pos.x < 0.0f) {
        pos.x = 0.0f;
    } else if (pos.x > Game::ScreenWidth - 64.0f) {
        pos.x = Game::ScreenWidth - 64.0f;
    }

    if (pos.y < 0.0f) {
        pos.y = 0.0f;
    } else if (pos.y > Game::ScreenHeight - 64.0f) {
        pos.y = Game::ScreenHeight - 64.0f;
    }

    SetPosition(pos);


}

