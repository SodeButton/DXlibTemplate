//
// Created by button on 2023/12/16.
//

#ifndef DXLIBTEMPLATE_PLAYER_HPP
#define DXLIBTEMPLATE_PLAYER_HPP

#include "GameObject.hpp"

class Player : public GameObject {
public:
    Player(class Game* game);
    void UpdateGameObject(float deltaTime) override;
    void ProcessKeyboard(const char* state);

private:
    float mRightMove;
    float mDownMove;

    const float PlayerSpeed = 480.0f;

    class CircleColliderComponent* mCollider;
};


#endif //DXLIBTEMPLATE_PLAYER_HPP
