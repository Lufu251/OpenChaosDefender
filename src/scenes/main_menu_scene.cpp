#include <scenes/main_menu_scene.hpp>

#include <raylib.h>
#include <core/global.hpp>


MainMenuScene::MainMenuScene(){}

MainMenuScene::~MainMenuScene(){}

void MainMenuScene::Enter(){

}

void MainMenuScene::Update(float& dt){
    if(IsKeyPressed(KEY_A)){
        g_SceneManager.SetScene(SceneType::PLAY);
    }
}

void MainMenuScene::Draw(RenderTexture& canvas){
    BeginTextureMode(canvas);
        ClearBackground(BLUE);
        DrawText("This is the MainMenuScene", 0, 100, 12, LIGHTGRAY);
    EndTextureMode();
}

void MainMenuScene::Exit(){

}