#include "raylib.h"
#include <scenes/play_scene.hpp>

PlayScene::PlayScene(){}
PlayScene::~PlayScene(){}

void PlayScene::Enter(){

}

void PlayScene::Update(float& dt){

}

void PlayScene::Draw(RenderTexture& canvas){
    BeginTextureMode(canvas);
        ClearBackground(RED);
        DrawText("This is the PlayScene", 0, 100, 12, LIGHTGRAY);
    EndTextureMode();
}

void PlayScene::Exit(){

}