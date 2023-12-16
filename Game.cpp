//
// Created by button on 2023/12/16.
//

#include "Game.hpp"
#include "GameObjects/GameObject.hpp"
#include "Components/SpriteComponent.hpp"
//#include "Commons/Math.hpp"
#include "Scenes/TestScene.hpp"
#include <algorithm>

Game::Game()
        : mTicksCount(0),
          mIsRunning(true),
          mUpdatingGameObjects(false),
          mGameOver(false) {
}

bool Game::Initialize() {
    if (!InitDxLib()) {
        printf("Failed to initialize DxLib\n");
        return false;
    }

    mTicksCount = GetNowHiPerformanceCount();
    mFpsCheckTime = GetNowHiPerformanceCount();
    mFps = 0;


    InitScene();

    return true;
}

bool Game::InitDxLib() {
    ChangeWindowMode(TRUE);
    SetMainWindowText("DxLib Template");
    SetGraphMode((int)ScreenWidth, (int)ScreenHeight, 32);
    SetWaitVSyncFlag(TRUE);

    bool success = DxLib_Init() != -1;
    if (!success) return false;

    return true;
}

void Game::InitScene() {
}

void Game::RunLoop() {
    mScene = new TestScene(this);
    mNextScene = mScene;
    StartScene();

    while (mIsRunning) {
        UpdateScene();

        if (mScene->GetSceneName() != mNextScene->GetSceneName()) {
            delete mScene;
            mScene = mNextScene;
            StartScene();
        }
    }
}

void Game::StartScene() {
    mScene->Start();
}

void Game::UpdateScene() {
    ProcessInput();

    float deltaTime = (float)(GetNowHiPerformanceCount() - mTicksCount) / 1000000.0f ;
    if (deltaTime > 0.05f) {
        deltaTime = 0.05f;
    }

    mFpsCount++;
    if (mTicksCount - mFpsCheckTime >= 1000000) {
        mFps = mFpsCount;
        mFpsCount = 0;
        mFpsCheckTime = mTicksCount;
    }

    mTicksCount = GetNowHiPerformanceCount();
    clsDx();
    printfDx("DeltaTime:%f\n", deltaTime);
    printfDx("FPS:%d", mFps);

    mUpdatingGameObjects = true;
    for (auto gameObject : mGameObjects) {
        gameObject->Update(deltaTime);
    }
    mUpdatingGameObjects = false;

    for (auto pending : mPendingGameObjects) {
        mGameObjects.emplace_back(pending);
    }
    mPendingGameObjects.clear();

    mScene->Update(deltaTime);

    std::vector<GameObject*> deadObjects;
    for (auto gameObject : mGameObjects) {
        if (gameObject->GetState() == GameObject::EDead) {
            deadObjects.emplace_back(gameObject);
        }
    }
    for (auto dead : deadObjects) {
        delete dead;
    }

    GenerateOutput();
}

void Game::ProcessInput() {
    char key[256];
    GetHitKeyStateAll(key);

    if (ProcessMessage() != 0) {
        mIsRunning = false;
    }

    if (key[KEY_INPUT_ESCAPE] == 1) {
        mIsRunning = false;
    }

    mScene->ProcessInput(key);
}

void Game::GenerateOutput() {
    ClearDrawScreen();

    SetDrawScreen( DX_SCREEN_BACK ) ;
    for (auto sprite : mSprites) {
        sprite->Draw();
    }

    mScene->Draw();

    ScreenFlip();
}

void Game::Shutdown() {
    while (!mGameObjects.empty()) {
        delete mGameObjects.back();
    }
    DxLib_End();
}

void Game::AddGameObject(GameObject *gameObject) {
    if (mUpdatingGameObjects) {
        mPendingGameObjects.emplace_back(gameObject);
    } else {
        mGameObjects.emplace_back(gameObject);
    }
}

void Game::RemoveGameObject(GameObject *gameObject) {
    auto iter = std::find(mPendingGameObjects.begin(), mPendingGameObjects.end(), gameObject);
    if (iter != mPendingGameObjects.end()) {
        mPendingGameObjects.erase(iter);
    }

    iter = std::find(mGameObjects.begin(), mGameObjects.end(), gameObject);
    if (iter != mGameObjects.end()) {
        mGameObjects.erase(iter);
    }
}

void Game::AddSprite(SpriteComponent *sprite) {
    int myDrawOrder = sprite->GetDrawOrder();
    auto iter = mSprites.begin();
    for (; iter != mSprites.end(); ++iter) {
        if (myDrawOrder < (*iter)->GetDrawOrder()) {
            break;
        }
    }
    mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent *sprite) {
    auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
    mSprites.erase(iter);
}

