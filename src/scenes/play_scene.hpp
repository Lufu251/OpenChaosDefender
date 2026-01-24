#pragma once

#include <scenes/scene.hpp>

struct PlayScene : Scene{
    bool toMainMenu = false;

    PlayScene(InputManager& input, AssetManager& assets);
    ~PlayScene();

    void Enter() override;
    void Update(float& dt) override;
    void Draw(RenderTexture2D& screen) override;
    void Exit() override;
};