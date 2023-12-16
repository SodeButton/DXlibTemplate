//
// Created by button on 2023/12/16.
//

#ifndef DXLIBTEMPLATE_GAMEOBJECT_HPP
#define DXLIBTEMPLATE_GAMEOBJECT_HPP

#include <vector>
#include "../Commons/Vector2.hpp"

class GameObject {
public:
    enum State {
        EActive,
        EPaused,
        EDead
    };

    explicit GameObject(class Game* game);
    virtual ~GameObject();

    void Update(float deltaTime);
    void UpdateComponents(float deltaTime);
    virtual void UpdateGameObject(float deltaTime);

    void AddComponent(class Component* component);
    void RemoveComponent(class Component* component);

private:
    State mState;
    Vector2 mPosition;
    Vector2 mScale;
    float mRotation;
    std::vector<class Component*> mComponents;
    class Game* mGame;

public:
    [[maybe_unused]] [[nodiscard]] State GetState() const { return mState; }
    [[maybe_unused]] void SetState(const State state) { mState = state; }
    [[maybe_unused]] [[nodiscard]] const Vector2& GetPosition() const { return mPosition; }
    [[maybe_unused]] void SetPosition(const Vector2& position) { mPosition = position; }
    [[maybe_unused]] [[nodiscard]] const Vector2& GetScale() const { return mScale; }
    [[maybe_unused]] void SetScale(const Vector2& scale) { mScale = scale; }
    [[maybe_unused]] [[nodiscard]] float GetRotation() const { return mRotation; }
    [[maybe_unused]] void SetRotation(const float rotation) { mRotation = rotation; }
    [[maybe_unused]] [[nodiscard]] class Game* GetGame() const { return mGame; }
};


#endif //DXLIBTEMPLATE_GAMEOBJECT_HPP
