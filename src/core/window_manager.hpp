#pragma once

#include <raylib.h>

struct WindowManager{
    // Raylib Window
    const int screenWidth = 1080;
    const int screenHeight = 720;
    const int minScreenWidth = 320;
    const int minScreenHeight = 320;
    const char* titel = "OpenChaosDefender";

    // Game Window
    const int gameWindowWidth = 384;
    const int gameWindowHeight = 384;
    RenderTexture gameWindow;
    
    float targetGameWindowScale;
    Rectangle targetGameWindowRec;

    WindowManager();
    ~WindowManager();

    void CreateRaylibWindow();
    void CreateGameWindow();
    void UpdateGameWindow();
    void RenderGameWindow();
};