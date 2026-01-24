#include <core/scene_manager.hpp>

#include <iostream>
#include <scenes/main_menu_scene.hpp>
#include <scenes/play_scene.hpp>

// Forward declaration
struct MainMenuScene;
struct PlayScene;

SceneManager::SceneManager(){}
SceneManager::~SceneManager(){}

void SceneManager::Initialize(InputManager& input, AssetManager& assets){
    // Pre-create scenes
    scenes[SceneType::MAINMENU] = std::make_unique<MainMenuScene>(input, assets);
    scenes[SceneType::PLAY] = std::make_unique<PlayScene>(input, assets);
}

void SceneManager::SetScene(SceneType newSceneType){
    if (currentSceneType == newSceneType) {
        std::cout << "SceneManager: Attempted to set to the same scene type!" << std::endl;
        return; // Already in this scene
    }

    if (currentScene) {
        currentScene->Exit(); // Exit the old scene
    }

    currentSceneType = newSceneType;
    currentScene = scenes[newSceneType].get(); // Get raw pointer from unique_ptr

    if (currentScene) {
        currentScene->Enter(); // Enter the new scene
    } else {
        std::cout << "SceneManager: Attempted to set to a non-existent scene type!" << std::endl;
    }
}

void SceneManager::Cleanup(){
    for(auto& scene : scenes)
        scene.second->Exit();
}

void SceneManager::SceneTransitionLogic(){
    switch (currentSceneType) {
        case SceneType::NONE: {
            
        }break;

        case SceneType::MAINMENU: {
            MainMenuScene* scene = static_cast<MainMenuScene*>(currentScene);
            if(scene->startPlay) SetScene(SceneType::PLAY);
        }break;

        case SceneType::PLAY: {
            PlayScene* scene = static_cast<PlayScene*>(currentScene);
            if(scene->toMainMenu) SetScene(SceneType::MAINMENU);
        }break;
    }

}