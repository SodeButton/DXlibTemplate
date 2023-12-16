//
// Created by button on 2023/12/16.
//

#include "Scene.hpp"
#include "../Game.hpp"

Scene::Scene(class Game *game)
        : mGame(game) {
}

Scene::~Scene() = default;

void Scene::Draw() {}

void Scene::Start() {}

void Scene::Update(float deltaTime) {}

void Scene::ProcessInput(const char *state) {}

std::string const Scene::GetSceneName() {
    return "";
}