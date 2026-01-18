
#include <raylib.h>
#include <cmath>

#include <core/game.hpp>
#include <core/scene_manager.hpp>


Game::Game(){}

Game::~Game(){}

bool Game::Initialize(){
    bool initialized = true;

    InitializeWindow();

    // Create canvas and source inverted rectangle for drawing
    canvas = LoadRenderTexture(width, height);
    sourceCanvasRectangle = { 0.0f, 0.0f, static_cast<float>(width), -static_cast<float>(height)};

    // Scene setup
    sceneManager.CreateScenes();
    sceneManager.SetScene(SceneType::MAINMENU);

    return initialized;
}

void Game::Run(){
    while (running){
        if (WindowShouldClose()) running = false;

        float dt = GetFrameTime();

        // Input ----------
        // inputManager.Update();

        // Update ----------
        sceneManager.currentScene->Update(dt);

        // Draw ----------
        sceneManager.currentScene->Draw(canvas);

        // Render canvas
        DrawCanvasToWindow();
    }
}

void Game::Shutdown(){
    sceneManager.CloseScenes();
    CloseWindow(); // Close window and OpenGL context
}

void Game::InitializeWindow(){
    // Pre window initialize
    SetConfigFlags(FLAG_WINDOW_HIGHDPI); // Enable High DPI scaling
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Set window is resizable

    // Window initialize
    InitWindow(screenWidth, screenHeight, "raylib quick start");

    // Post window initialize
    SetWindowMinSize(minScreenWidth,minScreenHeight); // Set minimum window size
    SetTargetFPS(60); // Set 60 frames-per-second
    SetExitKey(KEY_NULL);
}

void Game::DrawCanvasToWindow(){
    // Smaler value from ratio between window and gameWindow for calculating the target rectangle that is drawn to the window
    canvasScale = std::fminf(static_cast<float>(GetScreenWidth()) / width, static_cast<float>(GetScreenHeight()) / height);
    targetCanvasRectangle = {
        (GetScreenWidth() - (static_cast<float>(width) * canvasScale)) * 0.5f,
        (GetScreenHeight() - (static_cast<float>(height) * canvasScale)) * 0.5f,
        static_cast<float>(width) * canvasScale,
        static_cast<float>(height) * canvasScale
    };

    // Render the scaled game canvas to the window
    BeginDrawing();
        ClearBackground(BLACK);
        DrawTexturePro(canvas.texture, sourceCanvasRectangle, targetCanvasRectangle, {0, 0}, 0, WHITE);
    EndDrawing();
}