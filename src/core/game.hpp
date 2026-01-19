#pragma once

#include <raylib.h>
#include <core/scene_manager.hpp>

struct Game {
    // Logic
    bool running = true;

    // Window
    const int screenWidth = 1080;
    const int screenHeight = 720;
    const int minScreenWidth = 320;
    const int minScreenHeight = 320;
    const char* titel = "OpenChaosDefender";

    // Canvas
    const int width = 384;
    const int height = 384;
    float canvasScale;

    // Render Texture
    RenderTexture canvas;
    Rectangle sourceCanvasRectangle;
    Rectangle targetCanvasRectangle;

    Game();
    ~Game();

    bool Initialize();
    void Run();
    void Shutdown();

    void InitializeWindow();
    void DrawCanvasToWindow();
};