//
// Created by button on 2023/12/16.
//

#include "Component.hpp"
#include "../GameObjects/GameObject.hpp"

Component::Component(GameObject* gameObject, int updateOrder)
    : mGameObject(gameObject)
    , mUpdateOrder(updateOrder) {
    mGameObject->AddComponent(this);
}

Component::~Component() {
    mGameObject->RemoveComponent(this);
}

void Component::Update(float deltaTime) { }