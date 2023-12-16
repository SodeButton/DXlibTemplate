//
// Created by button on 2023/12/16.
//

#include "SpriteComponent.hpp"
#include "../Game.hpp"
#include "../GameObjects/GameObject.hpp"
#include "../Commons/Math.hpp"

SpriteComponent::SpriteComponent(GameObject *gameObject, int drawOrder) :
        Component(gameObject),
        mTextureId(-1),
        mDrawOrder(drawOrder),
        mTexWidth(0),
        mTexHeight(0) {
    mGameObject->GetGame()->AddSprite(this);
}

SpriteComponent::~SpriteComponent() {
    mGameObject->GetGame()->RemoveSprite(this);
}

void SpriteComponent::Draw() {
    if (mTextureId == -1) {
        return;
    }

    Vector2 position = mGameObject->GetPosition();
    float rotation = mGameObject->GetRotation();
    Vector2 origin = Vector2((float)mTexWidth / 2.0f, (float)mTexHeight / 2.0f);
    Vector2 scale = mGameObject->GetScale();

    DrawRotaGraph3F(
            static_cast<float>(position.x),
            static_cast<float>(position.y),
            static_cast<float>(origin.x),
            static_cast<float>(origin.y),
            static_cast<float>(scale.x),
            static_cast<float>(scale.y),
            static_cast<float>(rotation),
            mTextureId,
            TRUE,
            FALSE
    );
}

void SpriteComponent::SetTexture(int textureId) {
    mTextureId = textureId;
    GetGraphSize(mTextureId, &mTexWidth, &mTexHeight);
}