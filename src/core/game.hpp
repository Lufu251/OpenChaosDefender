#pragma once

#include <raylib.h>
#include <core/scene_manager.hpp>
#include <core/input_manager.hpp>
#include <core/asset_manager.hpp>

struct Game {
    int i = 2;
    // Logic
    bool running = true;

    // Window
    const char* titel = "OpenChaosDefender";
    const int windowWidth = 1080;
    const int windowHeight = 720;
    const int minWindowWidth = 320;
    const int minWindowHeight = 320;

    // Game screen
    RenderTexture screen;
    const int screenWidth = 1200;
    const int screenHeight = 768;
    int screenWidthScaled;
    int screenHeighScaled;
    float screenRenderScale;
    Vector2 screenOffset;

    // Managers
    InputManager inputManager;
    AssetManager assetManager;
    SceneManager sceneManager;

    Game();
    ~Game();

    bool Initialize();
    void Run();
    void Shutdown();

    void InitializeWindow();

    void UpdateScreen();
    void DrawScreen();

    // Helpers
    Vector2 MapWindowToScreenPosition(const Vector2& original);
};