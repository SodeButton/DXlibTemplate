//
// Created by button on 2023/12/16.
//

#ifndef DXLIBTEMPLATE_CIRCLECOLLIDERCOMPONENT_HPP
#define DXLIBTEMPLATE_CIRCLECOLLIDERCOMPONENT_HPP

#include "Component.hpp"
#include "../Commons/Vector2.hpp"

class CircleColliderComponent : public Component {
public:
    CircleColliderComponent(class GameObject* gameObject);
    [[nodiscard]] const Vector2& GetCenter() const;

private:
    float mRadius;

public:
    void SetRadius(float radius) { mRadius = radius; }
    [[nodiscard]] float GetRadius() const;

};

bool Intersect(const CircleColliderComponent& a, const CircleColliderComponent& b);

#endif //DXLIBTEMPLATE_CIRCLECOLLIDERCOMPONENT_HPP
