
#include <raylib.h>

#include <core/game.hpp>
#include <core/global.hpp>

Game::Game(){}

Game::~Game(){}

bool Game::Initialize(){
    bool initialized = true;

    // Initialize RenderManager
    windowManager.CreateRaylibWindow(); // Create Raylib window
    windowManager.CreateGameWindow(); // Create Game window

    // Scene setup
    g_SceneManager.CreateScenes();
    g_SceneManager.SetScene(SceneType::MAINMENU);

    return initialized;
}

void Game::Run(){
    while (running){
        if (WindowShouldClose()) running = false;
        float dt = GetFrameTime();

        // Input ----------

        // Update ----------
        windowManager.UpdateGameWindow();
        g_SceneManager.currentScene->Update(dt);

        // Draw ----------
        g_SceneManager.currentScene->Draw(windowManager.gameWindow);

        // Render gameCanvas on the screen
        windowManager.RenderGameWindow();
    }
}

void Game::Shutdown(){
    g_SceneManager.CloseScenes();
    CloseWindow(); // Close window and OpenGL context
}