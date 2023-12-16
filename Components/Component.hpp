//
// Created by button on 2023/12/16.
//

#ifndef DXLIBTEMPLATE_COMPONENT_HPP
#define DXLIBTEMPLATE_COMPONENT_HPP


class Component {
public:
    explicit Component(class GameObject* owner, int updateOrder = 100);
    virtual ~Component();

    virtual void Update(float deltaTime);

protected:
    class GameObject* mGameObject;
    int mUpdateOrder;

public:
    [[nodiscard]] int GetUpdateOrder() const { return mUpdateOrder; }
};


#endif //DXLIBTEMPLATE_COMPONENT_HPP
