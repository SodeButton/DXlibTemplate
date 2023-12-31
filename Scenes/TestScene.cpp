//
// Created by button on 2023/12/16.
//

#include "TestScene.hpp"
#include "Scene.hpp"
#include "../Game.hpp"
#include "../GameObjects/GameObject.hpp"
#include "../Components/SpriteComponent.hpp"

TestScene::TestScene(class Game* game)
        : Scene(game) {
}

TestScene::~TestScene() = default;


void TestScene::Start() {
    mGame->SetGameOver(false);
    mTestMsg = new GameObject(mGame);
    mTestMsg->SetPosition(Vector2(100, 100));
    mTestMsg->SetScale(Vector2(0.5f, 0.5f));
    auto* sprite = new SpriteComponent(mTestMsg, 100);
    sprite->SetTexture(LoadGraph("../Assets/Circle.png"));
}

void TestScene::Update(float deltaTime) {
    int mouseX, mouseY;
    GetMousePoint(&mouseX, &mouseY);
    mTestMsg->SetPosition(Vector2(mouseX, mouseY));
}

void TestScene::Draw() {
    int posX, posY;
    posX = (int)mTestMsg->GetPosition().x;
    posY = (int)mTestMsg->GetPosition().y;

    DrawCircle(posX, posY, 64, GetColor(0, 255, 0), FALSE);
}

void TestScene::ProcessInput(const char* state) {
    if (state[KEY_INPUT_SPACE]) {
        printf("hello\n");
    }
}

std::string const TestScene::GetSceneName() {
    return "TestScene";
}