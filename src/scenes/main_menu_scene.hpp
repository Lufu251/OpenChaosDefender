#pragma once

#include <raylib.h>
#include <scenes/scene.hpp>

struct MainMenuScene : Scene{
    bool startPlay = false;

    MainMenuScene(InputManager& input, AssetManager& assets);
    ~MainMenuScene();

    void Enter() override;
    void Update(float& dt) override;
    void Draw(RenderTexture2D& screen) override;
    void Exit() override;
};