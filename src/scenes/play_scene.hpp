#pragma once

#include <scenes/scene.hpp>

struct PlayScene : Scene{
    PlayScene();
    ~PlayScene();

    void Enter() override;
    void Update(float& dt) override;
    void Draw(RenderTexture2D& gameWindow) override;
    void Exit() override;
};