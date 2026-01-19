#include <core/window_manager.hpp>

#include <raylib.h>
#include <cmath>

WindowManager::WindowManager(){}
WindowManager::~WindowManager(){}

void WindowManager::CreateRaylibWindow(){
    // Pre window initialize
    SetConfigFlags(FLAG_WINDOW_HIGHDPI); // Enable High DPI scaling
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Set window is resizable

    // Window initialize
    InitWindow(screenWidth, screenHeight, titel);

    // Post window initialize
    SetWindowMinSize(minScreenWidth,minScreenHeight); // Set minimum window size
    SetTargetFPS(60); // Set 60 frames-per-second
    SetExitKey(KEY_NULL);
}

void WindowManager::CreateGameWindow(){
    // Create canvas and source inverted rectangle for drawing
    gameWindow = LoadRenderTexture(gameWindowWidth, gameWindowHeight);
    
}

void WindowManager::UpdateGameWindow(){
    Vector2 window = {static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight())};

    // Smaler value from ratio between window and gameWindow for calculating the target rectangle that is drawn to the window
    float targetGameWindowScale = std::fminf(static_cast<float>(GetScreenWidth()) / gameWindowWidth, static_cast<float>(GetScreenHeight()) / gameWindowHeight);
    
    targetGameWindowRec = {
        (window.x - (static_cast<float>(gameWindowWidth) * targetGameWindowScale)) * 0.5f,
        (window.y - (static_cast<float>(gameWindowHeight) * targetGameWindowScale)) * 0.5f,
        static_cast<float>(gameWindowWidth) * targetGameWindowScale,
        static_cast<float>(gameWindowHeight) * targetGameWindowScale
    };
}

void WindowManager::RenderGameWindow(){
    Rectangle sourceGameWindowRec = { 0.0f, 0.0f, static_cast<float>(gameWindowWidth), -static_cast<float>(gameWindowHeight)};
    
    BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(gameWindow.texture, sourceGameWindowRec, targetGameWindowRec, {0, 0}, 0, WHITE);
    EndDrawing();
}