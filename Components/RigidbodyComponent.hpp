//
// Created by button on 2023/12/17.
//

#ifndef DXLIBTEMPLATE_RIGIDBODYCOMPONENT_HPP
#define DXLIBTEMPLATE_RIGIDBODYCOMPONENT_HPP

#include "Component.hpp"
#include "../Commons/Vector2.hpp"

class RigidbodyComponent : public Component {
public:
    explicit RigidbodyComponent(class GameObject* gameObject, float mass = 1.0f);
    ~RigidbodyComponent() override = default;

    void Update(float deltaTime) override;

private:
    float mMass;
    Vector2 mVelocity;

public:
    [[nodiscard]] float GetMass() const { return mMass; }
    void SetMass(const float mass) { mMass = mass; }
    [[nodiscard]] const Vector2& GetVelocity() const { return mVelocity; }
    void SetVelocity(const Vector2& velocity) { mVelocity = velocity; }
};


#endif //DXLIBTEMPLATE_RIGIDBODYCOMPONENT_HPP
