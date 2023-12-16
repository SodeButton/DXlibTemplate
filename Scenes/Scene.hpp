//
// Created by button on 2023/12/16.
//

#ifndef DXLIBTEMPLATE_SCENE_HPP
#define DXLIBTEMPLATE_SCENE_HPP

#include "string"

class Scene {
public:
    explicit Scene(class Game* game);
    virtual ~Scene();
    virtual void Start();
    virtual void Update(float deltaTime);
    virtual void ProcessInput(const char* state);
    virtual std::string const GetSceneName();

protected:
    class Game* mGame;
};


#endif //DXLIBTEMPLATE_SCENE_HPP
