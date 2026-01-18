#include <scenes/main_menu_scene.hpp>

MainMenuScene::MainMenuScene(){}

MainMenuScene::~MainMenuScene(){}

void MainMenuScene::Enter(){

}

void MainMenuScene::Update(float& dt){
}

void MainMenuScene::Draw(RenderTexture& canvas){
    BeginTextureMode(canvas);
        ClearBackground(BLUE);
        DrawText("This is the MainMenuScene", 0, 100, 12, LIGHTGRAY);
    EndTextureMode();
}

void MainMenuScene::Exit(){

}