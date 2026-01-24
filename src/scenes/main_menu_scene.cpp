#include <scenes/main_menu_scene.hpp>

#include <raylib.h>

MainMenuScene::MainMenuScene(InputManager& input, AssetManager& assets)
    : Scene(input, assets) {}

MainMenuScene::~MainMenuScene(){}

void MainMenuScene::Enter(){
    startPlay = false;

    //g_InputManager.Bind(Action::Jump, KEY_A);
}

void MainMenuScene::Update(float& dt){
    /*if(g_InputManager.IsActionTriggered(Action::Jump)){
        startPlay = true;
    }*/
}

void MainMenuScene::Draw(RenderTexture2D& screen){
    BeginTextureMode(screen);
        ClearBackground(BLUE);
        DrawText("This is the MainMenuScene", 0, 100, 20, LIGHTGRAY);
        //DrawCircleV(g_InputManager.GetGameMousePosition(), 10, RED);
    EndTextureMode();
}

void MainMenuScene::Exit(){
    //g_InputManager.Cleanup();
}