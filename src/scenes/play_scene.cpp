#include <scenes/play_scene.hpp>

#include <raylib.h>


PlayScene::PlayScene(InputManager& input, AssetManager& assets)
    : Scene(input, assets){}

PlayScene::~PlayScene(){}

void PlayScene::Enter(){
    toMainMenu = false;
}

void PlayScene::Update(float& dt){
    if(IsKeyPressed(KEY_A)){
        toMainMenu = true;
    }
}

void PlayScene::Draw(RenderTexture2D& screen){
    BeginTextureMode(screen);
        ClearBackground(RED);
        DrawText("This is the PlayScene", 0, 100, 20, LIGHTGRAY);
    EndTextureMode();
}

void PlayScene::Exit(){

}