//
// Created by button on 2023/12/16.
//

#include "CircleColliderComponent.hpp"
#include "../GameObjects/GameObject.hpp"

CircleColliderComponent::CircleColliderComponent(GameObject *gameObject)
        : Component(gameObject),
          mRadius(0.0f) {
}

const Vector2& CircleColliderComponent::GetCenter() const {
    return mGameObject->GetPosition();
}

float CircleColliderComponent::GetRadius() const {
    return mGameObject->GetScale().Max() * mRadius;
}

bool Intersect(const CircleColliderComponent& a, const CircleColliderComponent& b) {
    Vector2 diff = a.GetCenter() - b.GetCenter();
    float distSq = diff.LengthSq();
    float sumRadii = a.GetRadius() + b.GetRadius();
    return distSq <= sumRadii * sumRadii;
}

