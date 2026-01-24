#pragma once

#include <raylib.h>
#include <core/scene_manager.hpp>
#include <core/input_manager.hpp>

struct Game {
    // Logic
    bool running = true;

    // Game Window
    const int screenWidth = 384;
    const int screenHeight = 384;
    RenderTexture screen;

    float gameScreenRenderScale;
    Vector2 gameScreenOffset;

    // Managers
    InputManager inputManager;
    AssetManager assetManager;
    SceneManager sceneManager;


    Game();
    ~Game();

    bool Initialize();
    void Run();
    void Shutdown();

    void DrawGameScreen();
};