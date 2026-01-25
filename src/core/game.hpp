#pragma once

#include <raylib.h>
#include <core/scene_manager.hpp>
#include <core/input_manager.hpp>

struct Game {
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
    const int screenWidth = 384;
    const int screenHeight = 384;
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

    Vector2 MapWindowToScreenPosition(const Vector2& original);
};