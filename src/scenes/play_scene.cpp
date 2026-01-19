#include <scenes/play_scene.hpp>

#include <raylib.h>
#include <core/global.hpp>


PlayScene::PlayScene(){}
PlayScene::~PlayScene(){}

void PlayScene::Enter(){
}

void PlayScene::Update(float& dt){
    if(IsKeyPressed(KEY_A)){
        g_SceneManager.SetScene(SceneType::MAINMENU);
    }
}

void PlayScene::Draw(RenderTexture2D& gameWindow){
    BeginTextureMode(gameWindow);
        ClearBackground(RED);
        DrawText("This is the PlayScene", 0, 100, 12, LIGHTGRAY);
    EndTextureMode();
}

void PlayScene::Exit(){

}