#include <scenes/play_scene.hpp>

#include <iostream>
#include <raylib.h>

PlayScene::PlayScene(InputManager& input, AssetManager& assets)
    : Scene(input, assets){}

PlayScene::~PlayScene(){}

void PlayScene::Enter(){
    // Reset variables between scene changes
    toMainMenu = false;

    r_inputManager.Bind(Action::Jump, KEY_A);
    r_inputManager.Bind(Action::Shoot, KEY_S);

    // Initialize map
    state.map.SetSize(12, 12);
    for(auto& tile : state.map.data){
        tile.type = 1;
    }
}

void PlayScene::Update(float& dt){
    if(r_inputManager.IsActionTriggered(Action::Jump)){
        toMainMenu = true;
    }
}
void PlayScene::Draw(RenderTexture2D& screen){
    BeginTextureMode(screen);
        ClearBackground(DARKGRAY);

        for(int x=0; x < state.map.GetSizeX(); x++){
            for(int y=0; y < state.map.GetSizeY(); y++){
                DrawTextureEx(r_assetManager.GetTexture("test"), {static_cast<float>(x*tileSize), static_cast<float>(y*tileSize)}, 0, 2, WHITE);
            }
        }
        Font& boldpixels = r_assetManager.GetFont("boldpixels");
        

        DrawTextEx(boldpixels, "This is the PlayScene", {0.f, 100.f}, 32, 1, WHITE);

        DrawCircleV(r_inputManager.GetMouse(), 2, WHITE);
    EndTextureMode();
}

void PlayScene::Exit(){
    r_inputManager.Cleanup();
}