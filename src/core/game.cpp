#include <core/game.hpp>

#include <cmath>
#include <raylib.h>
#include <raymath.h>

Game::Game(){}

Game::~Game(){}

bool Game::Initialize(){
    bool initialized = true;

    InitializeWindow();

    // Initialize screen texture
    screen = LoadRenderTexture(screenWidth, screenHeight);
    SetTextureWrap(screen.texture, TEXTURE_WRAP_CLAMP);

    // Scene setup
    sceneManager.Initialize(inputManager, assetManager);
    sceneManager.SetScene(SceneType::MAINMENU);
    
    // Assetmanager
    assetManager.SearchAssetPath("assets", 3);
    assetManager.SetTexturesDirectory("textures");
    assetManager.SetFontDirectory("fonts");
    // Texture
    assetManager.LoadTexture("land.png", "land");
    // Font
    assetManager.LoadFont("RobotoCondensed-Regular.ttf", "roboto", 32);

    return initialized;
}

void Game::Run(){
    while (running){
        if (WindowShouldClose()) running = false;
        float dt = GetFrameTime();
        UpdateScreen();

        // Input ----------
        inputManager.SetMouse(MapWindowToScreenPosition(GetMousePosition()));

        // Update ----------
        sceneManager.SceneTransitionLogic();
        sceneManager.currentScene->Update(dt);

        // Draw ----------
        sceneManager.currentScene->Draw(screen);

        // Draw screen to window
        DrawScreen();
    }
}

void Game::Shutdown(){
    inputManager.Cleanup();
    sceneManager.Cleanup();
    assetManager.Cleanup();

    CloseAudioDevice();
    CloseWindow(); // Close window and OpenGL context
}

// Initialize Raylib window
void Game::InitializeWindow(){
    // Pre window initialize
    SetConfigFlags(FLAG_WINDOW_HIGHDPI); // Enable High DPI scaling
    SetConfigFlags(FLAG_WINDOW_RESIZABLE); // Set window is resizable

    // Window initialize
    InitWindow(windowWidth, windowHeight, titel);

    // Audiodevice initialize
    InitAudioDevice();

    // Post window initialize
    SetWindowMinSize(minWindowWidth,minWindowHeight); // Set minimum window size
    SetTargetFPS(60); // Set 60 frames-per-second
    SetExitKey(KEY_NULL);
}

// Update screen variables to draw later
void Game::UpdateScreen(){
    // Calculate offset and scale to draw the screen to the window
    screenRenderScale = std::fminf(static_cast<float>(GetScreenWidth()) / screenWidth, static_cast<float>(GetScreenHeight()) / screenHeight);
    screenWidthScaled = std::round(static_cast<float>(screenWidth) * screenRenderScale);
    screenHeighScaled = std::round(static_cast<float>(screenHeight) * screenRenderScale);

    screenOffset = {
        (GetScreenWidth() - screenWidthScaled) * 0.5f,
        (GetScreenHeight() - screenHeighScaled) * 0.5f
    };
}

// Draw the scaled screen to the window
void Game::DrawScreen(){
    // Calculate render transforms
    Rectangle targetGameWindowRec = {
        screenOffset.x, 
        screenOffset.y, 
        static_cast<float>(screenWidthScaled), 
        static_cast<float>(screenHeighScaled)
    };
    Rectangle sourceGameWindowRec = { 
        0.0f, 
        0.0f, 
        static_cast<float>(screenWidth), 
        -static_cast<float>(screenHeight)
    };
    // Render game screen to window
    BeginDrawing();
            ClearBackground(DARKGRAY);
            DrawTexturePro(screen.texture, sourceGameWindowRec, targetGameWindowRec, {0, 0}, 0, WHITE);
    EndDrawing();
}

// Map window position to screen position
Vector2 Game::MapWindowToScreenPosition(const Vector2& original){
    // Map position
    Vector2 mapped ={
        mapped.x = static_cast<int>(std::round((original.x - screenOffset.x) / screenRenderScale)),
        mapped.y = static_cast<int>(std::round((original.y - screenOffset.y) / screenRenderScale))
    };

    // Clamp position to the screen size
    mapped = Vector2Clamp(
        mapped, 
        {0, 0}, 
        {static_cast<float>(screenWidth), static_cast<float>(screenHeight)}
    );
    return mapped;
}