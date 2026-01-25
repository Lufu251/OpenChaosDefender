#include <scenes/play_scene.hpp>

#include <raylib.h>

PlayScene::PlayScene(InputManager& input, AssetManager& assets)
    : Scene(input, assets){}

PlayScene::~PlayScene(){}

void PlayScene::Enter(){
    // Reset variables between scene changes
    toMainMenu = false;

    r_inputManager.Bind(Action::Jump, KEY_A);
}

void PlayScene::Update(float& dt){
    if(r_inputManager.IsActionTriggered(Action::Jump)){
        toMainMenu = true;
    }
}
void PlayScene::Draw(RenderTexture2D& screen){
    BeginTextureMode(screen);
        ClearBackground(RED);
        DrawText("This is the PlayScene", 0, 100, 20, LIGHTGRAY);
        DrawCircleV(r_inputManager.GetMouse(), 5, WHITE);
    EndTextureMode();
}

void PlayScene::Exit(){
    r_inputManager.Cleanup();
}