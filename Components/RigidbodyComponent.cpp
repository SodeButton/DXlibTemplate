//
// Created by button on 2023/12/17.
//

#include "RigidbodyComponent.hpp"
#include "../GameObjects/GameObject.hpp"
#include "../Game.hpp"

RigidbodyComponent::RigidbodyComponent(GameObject* gameObject, float mass)
        : Component(gameObject),
          mMass(mass),
          mVelocity(0.0f, 0.0f) {
}

void RigidbodyComponent::Update(float deltaTime) {

    Vector2 pos = GetGameObject()->GetPosition();
    pos += mVelocity * deltaTime;
    mVelocity.y += 9.8f * deltaTime;
    GetGameObject()->SetPosition(pos);
}