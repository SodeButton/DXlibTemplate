//
// Created by button on 2023/12/16.
//

#ifndef DXLIBTEMPLATE_GAME_HPP
#define DXLIBTEMPLATE_GAME_HPP

#include "dxlib/DxLib.h"
#include <unordered_map>
#include <string>
#include <vector>

class Game {
public:
    Game();
    bool Initialize();
    void RunLoop();
    void Shutdown();

    void AddGameObject(class GameObject* gameObject);
    void RemoveGameObject(class GameObject* gameObject);

    void AddSprite(class SpriteComponent* sprite);
    void RemoveSprite(class SpriteComponent* sprite);

    constexpr static const float ScreenWidth = 1280.0f;
    constexpr static const float ScreenHeight = 720.0f;

private:
    static bool InitDxLib();
    void InitScene();
    void StartScene();
    void UpdateScene();
    void ProcessInput();
    void GenerateOutput();

    std::vector<class GameObject*> mGameObjects;
    std::vector<class GameObject*> mPendingGameObjects;
    std::vector<class SpriteComponent*> mSprites;

    u_int mTicksCount;
    bool mIsRunning;
    bool mUpdatingGameObjects;
    bool mGameOver;

    class Scene* mScene{};
    class Scene* mNextScene{};

public:
    [[nodiscard]] Scene* GetNextScene() const { return mNextScene; }
    void SetNextScene(Scene* nextScene) { mNextScene = nextScene; }
    [[nodiscard]] Scene* GetScene() const { return mScene; }
    void SetScene(Scene* scene) { mScene = scene; }
    [[nodiscard]] std::vector<class GameObject*> GetGameObjects() const { return mGameObjects; }
    void SetGameOver(const bool isOver) { mGameOver = isOver; }
    [[nodiscard]] bool GetGameOver() const { return mGameOver; }

};


#endif //DXLIBTEMPLATE_GAME_HPP
