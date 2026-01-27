#include <scenes/main_menu_scene.hpp>

#include <raylib.h>

MainMenuScene::MainMenuScene(InputManager& input, AssetManager& assets)
    : Scene(input, assets) {}

MainMenuScene::~MainMenuScene(){}

void MainMenuScene::Enter(){
    // Reset variables between scene changes
    startPlay = false;

    r_inputManager.Bind(Action::Jump, KEY_A);
}

void MainMenuScene::Update(float& dt){
    if(r_inputManager.IsActionTriggered(Action::Jump)){
        startPlay = true;
    }
}

void MainMenuScene::Draw(RenderTexture2D& screen){
    BeginTextureMode(screen);
        ClearBackground(DARKGRAY);
        DrawText("This is the MainMenuScene", 0, 100, 36, BLACK);
        DrawCircleV(r_inputManager.GetMouse(), 2, WHITE);
    EndTextureMode();
}

void MainMenuScene::Exit(){
    r_inputManager.Cleanup();
}