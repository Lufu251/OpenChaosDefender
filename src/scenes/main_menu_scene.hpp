#pragma once

#include <scenes/scene.hpp>

struct MainMenuScene : Scene{
    MainMenuScene();
    ~MainMenuScene();

    void Enter() override;
    void Update(float& dt) override;
    void Draw(RenderTexture& canvas) override;
    void Exit() override;
};