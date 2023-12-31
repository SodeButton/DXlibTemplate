//
// Created by button on 2023/12/16.
//

#include "GameObject.hpp"
#include <algorithm>
#include "../Game.hpp"
#include "../Components/Component.hpp"
#include "../Components/SpriteComponent.hpp"

GameObject::GameObject(Game* game) :
        mState(EActive),
        mPosition(Vector2::Zero),
        mScale(Vector2::One),
        mRotation(0.0f),
        mGame(game) {
    mGame->AddGameObject(this);
}

GameObject::~GameObject() {
    mGame->RemoveGameObject(this);
    while (!mComponents.empty()) {
        delete mComponents.back();
    }
}

void GameObject::Update(float deltaTime) {
    if (mState == EActive) {
        UpdateComponents(deltaTime);
        UpdateGameObject(deltaTime);
    }
}

void GameObject::UpdateComponents(float deltaTime) {
    for (auto component : mComponents) {
        component->Update(deltaTime);
    }
}

void GameObject::UpdateGameObject(float deltaTime) { }

void GameObject::AddComponent(Component* component) {
    int order = component->GetUpdateOrder();
    auto iter = mComponents.begin();
    for (; iter != mComponents.end(); ++iter) {
        if (order < (*iter)->GetUpdateOrder()) {
            break;
        }
    }
    mComponents.insert(iter, component);
}

void GameObject::RemoveComponent(Component* component) {
    auto iter = std::find(mComponents.begin(), mComponents.end(), component);
    if (iter != mComponents.end()) {
        mComponents.erase(iter);
    }
}