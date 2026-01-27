#pragma once

#include <scenes/scene.hpp>
#include <game/game_state.hpp>

struct PlayScene : Scene{
    bool toMainMenu = false;

    GameState state;

    int tileSize = 64;

    PlayScene(InputManager& input, AssetManager& assets);
    ~PlayScene();

    void Enter() override;
    void Update(float& dt) override;
    void Draw(RenderTexture2D& screen) override;
    void Exit() override;
};