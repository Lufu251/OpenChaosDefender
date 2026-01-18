#include "scenes/main_menu_scene.hpp"
#include "scenes/play_scene.hpp"
#include <core/scene_manager.hpp>
#include <iostream>

SceneManager::SceneManager(){}
SceneManager::~SceneManager(){}

void SceneManager::CreateScenes(){
    // Pre-create scenes
    scenes[SceneType::MAINMENU] = std::make_unique<MainMenuScene>();
    scenes[SceneType::PLAY] = std::make_unique<PlayScene>();
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

void SceneManager::CloseScenes(){
    for(auto& scene : scenes)
        scene.second->Exit();
}