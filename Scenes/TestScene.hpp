//
// Created by button on 2023/12/16.
//

#ifndef DXLIBTEMPLATE_TESTSCENE_HPP
#define DXLIBTEMPLATE_TESTSCENE_HPP

#include "Scene.hpp"

class TestScene : public Scene {
public:
    explicit TestScene(class Game* game);
    ~TestScene() override;

    void Draw() override;
    void Start() override;
    void Update(float deltaTime) override;
    void ProcessInput(const char* state) override;
    std::string const GetSceneName() override;

private:
    class GameObject* mTestMsg{};
};


#endif //DXLIBTEMPLATE_TESTSCENE_HPP
