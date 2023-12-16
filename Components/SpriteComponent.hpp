//
// Created by button on 2023/12/16.
//

#ifndef DXLIBTEMPLATE_SPRITECOMPONENT_HPP
#define DXLIBTEMPLATE_SPRITECOMPONENT_HPP

#include "../Components/Component.hpp"
#include "../dxlib/DxLib.h"

class SpriteComponent : public Component {
public:
    explicit SpriteComponent(GameObject* gameObject, int drawOrder = 100);
    ~SpriteComponent() override;

    virtual void Draw();
    virtual void SetTexture(int textureId);

protected:
    int mTextureId;
    int mDrawOrder;
    int mTexWidth;
    int mTexHeight;

public:
    [[nodiscard]] int GetDrawOrder() const { return mDrawOrder; }
    [[nodiscard]] int GetTexWidth() const { return mTexWidth; }
    [[nodiscard]] int GetTexHeight() const { return mTexHeight; }
};


#endif //DXLIBTEMPLATE_SPRITECOMPONENT_HPP
