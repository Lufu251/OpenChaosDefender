#include <raylib.h>

#include <cmath>
#include <core/game.hpp>

Game::Game(){}

Game::~Game(){}

bool Game::Initialize(){
    bool initialized = true;

    // Initialize screen texture
    screen = LoadRenderTexture(screenWidth, screenHeight);

    // Scene setup
    sceneManager.Initialize(inputManager, assetManager);
    sceneManager.SetScene(SceneType::MAINMENU);

    return initialized;
}

void Game::Run(){
    while (running){
        if (WindowShouldClose()) running = false;
        float dt = GetFrameTime();

        // Input ----------
        inputManager.CalculateGameMousePosition();

        // Update ----------
        sceneManager.SceneTransitionLogic();
        sceneManager.currentScene->Update(dt);

        // Draw ----------
        sceneManager.currentScene->Draw(screen);

        // Update and draw game screen to window
        DrawGameScreen();
    }
}

void Game::Shutdown(){
    inputManager.Cleanup();
    sceneManager.Cleanup();

    CloseAudioDevice();
    CloseWindow(); // Close window and OpenGL context
}

void Game::DrawGameScreen(){
    // Calculate game screen render size and offset for drawing to the window
    gameScreenRenderScale = std::fminf(static_cast<float>(GetScreenWidth()) / screenWidth, static_cast<float>(GetScreenHeight()) / screenHeight);
    gameScreenOffset = {
        (GetScreenWidth() - static_cast<float>(screenWidth) * gameScreenRenderScale) * 0.5f,
        (GetScreenHeight() - static_cast<float>(screenHeight) * gameScreenRenderScale) * 0.5f
    };

    Rectangle targetGameWindowRec = {
        gameScreenOffset.x,
        gameScreenOffset.y,
        static_cast<float>(screenWidth) * gameScreenRenderScale,
        static_cast<float>(screenHeight) * gameScreenRenderScale
    };

    // Render game screen to window
    Rectangle sourceGameWindowRec = { 0.0f, 0.0f, static_cast<float>(screenWidth), -static_cast<float>(screenHeight)};
    BeginDrawing();
            ClearBackground(BLACK);
            DrawTexturePro(screen.texture, sourceGameWindowRec, targetGameWindowRec, {0, 0}, 0, WHITE);
    EndDrawing();
}