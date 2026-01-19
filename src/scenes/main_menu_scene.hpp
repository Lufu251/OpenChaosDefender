#pragma once

#include <raylib.h>
#include <scenes/scene.hpp>

struct MainMenuScene : Scene{
    MainMenuScene();
    ~MainMenuScene();

    void Enter() override;
    void Update(float& dt) override;
    void Draw(RenderTexture2D& gameWindow) override;
    void Exit() override;
};